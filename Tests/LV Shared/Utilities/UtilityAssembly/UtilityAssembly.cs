using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Threading;
using System.Windows.Forms;
using Microsoft.Win32;

namespace Utilities
{
	/// <summary>
	/// Summary description for Class1.
	/// </summary>
	public class ManipulateLabVIEW
	{
		private class WindowWrapper : System.Windows.Forms.IWin32Window
		{
			private IntPtr _hwnd;

			public WindowWrapper(IntPtr handle)
			{
				_hwnd = handle;
			}

			public IntPtr Handle
			{
				get { return _hwnd; }
			}
		}

		private bool PromptToStopLVProcesses(IntPtr parentHWnd, int timeoutInSeconds)
		{
			// First, make sure there are no LV processes running.  If they are, close all of them.
			Process[] LabVIEWProcesses = Process.GetProcessesByName("LabVIEW");
			if (LabVIEWProcesses.Length > 0)
			{
				string message = "The following LabVIEW processes are running:\n";
				string title = "LabVIEW Process(es) Running";

				foreach (Process lvProc in LabVIEWProcesses)
				{
					ProcessModule lvModule = lvProc.MainModule;
					message = message + lvProc.MainWindowTitle + " Version " +	lvModule.FileVersionInfo.ProductVersion + "\n";
				}
				message = message + "\nDo you want us to close them or kill them?";

				TimedDialog dlg = new TimedDialog(title, message, timeoutInSeconds, "Close", "Kill");
				DialogResult result = dlg.ShowDialog(new WindowWrapper(parentHWnd));
				if (result == DialogResult.Cancel)
					return false;

				if (result != DialogResult.Yes)
				{
					foreach (Process lvProc in LabVIEWProcesses)
						lvProc.Kill();

					Thread.Sleep(1000);
				}
				else
				{
					StopLabVIEW(parentHWnd, false, timeoutInSeconds);
				}
			}

			return true;
		}

		public bool LaunchLabVIEW(string lvVersion, IntPtr parentHWnd, int timeoutInSeconds, out string errorMsg)
		{
			errorMsg = "";

			if (!RunningInLV() && !PromptToStopLVProcesses(parentHWnd, timeoutInSeconds))
				return false;

			// Launch given LabVIEW version
			string lvInfoKey = "Software\\National Instruments\\LabVIEW\\" + lvVersion;
			RegistryKey localMachineRegKey = Registry.LocalMachine;
			RegistryKey lvVersionRegKey = localMachineRegKey.OpenSubKey(lvInfoKey);

			if (lvVersionRegKey == null)
			{
				errorMsg = "Registry key '" + lvInfoKey + "' not found.";
				return false;
			}

			string lvExePath = (string)lvVersionRegKey.GetValue("Path", "");
			if (lvExePath.Length == 0)
			{
				errorMsg = "Path string not found under registry key '" + lvInfoKey + "'.";
				return false;
			}

			lvExePath = lvExePath + "\\LabVIEW.exe";
			if (!File.Exists(lvExePath))
			{
				errorMsg = "Path Not Found: " + lvExePath;
				return false;
			}

			Process lvProcess = Process.Start(lvExePath);

			return true;
		}

		public bool StopLabVIEW(IntPtr parentHWnd, bool prompt, int timeoutInSeconds)
		{
			bool stopStatus = true;
			if (prompt)
				PromptToStopLVProcesses(parentHWnd, timeoutInSeconds);
			else
			{
				Process[] LabVIEWProcesses = Process.GetProcessesByName("LabVIEW");
				if (LabVIEWProcesses.Length > 0)
				{
					// First, attemp to shutdown the LV processes gracefully
					Module module = Assembly.GetExecutingAssembly().GetModule("UtilityAssembly.dll");
					string exitLVPath = Path.GetDirectoryName(module.FullyQualifiedName) + "\\Run ExitLabVIEW.vi";
					int numOfLVProcesses = LabVIEWProcesses.Length;
					for (int i = 0; i < numOfLVProcesses; i++)
					{
						{
							LabVIEW.ApplicationClass lv = new LabVIEW.ApplicationClass();
							LabVIEW.VirtualInstrument vi = lv.GetVIReference(exitLVPath, "", true, 0);

							string[] paramNames = new string[0];
							object[] paramVals = new object[0];
							object paramNamesArg = paramNames;
							object paramValsArg = paramVals;

							vi.Call2(ref paramNamesArg, ref paramValsArg, false, true, false, false);
						}

						// Give LV about 10 seconds to shutdown.
						int counter = 0;
						while (counter < 10 && Process.GetProcessesByName("LabVIEW").Length == numOfLVProcesses - i)
						{
							Thread.Sleep(1000);
							counter++;
						}
					}

					// If there are any LV process running after trying to shut them down gracefully,
					// just kill them
					Process[] LabVIEWProcessesRemaining = Process.GetProcessesByName("LabVIEW");
					if (LabVIEWProcessesRemaining.Length > 0)
					{
						foreach (Process lvProc in LabVIEWProcessesRemaining)
							lvProc.Kill();

						stopStatus = false;
						Thread.Sleep(1000);
					}
				}
			}
			return stopStatus;
		}

		static public bool RunningInLV()
		{
			string moduleName = Process.GetCurrentProcess().MainModule.ModuleName;
			return	string.Compare(moduleName, "LabVIEW.exe", true) == 0 || 
					string.Compare(moduleName, "lvre.exe", true) == 0 ||
					string.Compare(moduleName, "lvde.exe", true) == 0;
		}

		static public string GetDirectoryName(string path)
		{
			return Path.GetDirectoryName(path);
		}

		static public string GetTimeStampForReport()
		{
			return "ReportForRunOn" + System.DateTime.Now.ToString("[h m ss tt][M d yyyy]");
		}

		static public string FindLatestReportDirecotry(string path)
		{
			DirectoryInfo dir = new DirectoryInfo(path);
			DirectoryInfo[] rgDirectories = dir.GetDirectories();
			DirectoryInfo curDir = rgDirectories[0];
			foreach(DirectoryInfo iterDir in rgDirectories)
			{
				if(iterDir.CreationTime>curDir.CreationTime)
					curDir=iterDir;
			}
			return curDir.ToString();

		}

		static public string GetPathForLVRTEVersion(string lvVersion, bool getFFRTE)
		{
			// Launch given LabVIEW version
			string lvInfoKey = "Software\\National Instruments\\LabVIEW Run-Time\\" + lvVersion;
			RegistryKey localMachineRegKey = Registry.LocalMachine;
			RegistryKey lvVersionRegKey = localMachineRegKey.OpenSubKey(lvInfoKey);

			if (lvVersionRegKey == null)
				return "";

			// The LabVIEW Run-Time Engine 8.0 does not install the VersionString key, which means
			// that TestStand cannot use it. 
			string lvRTEPath = (string)lvVersionRegKey.GetValue("Path", "");
			string lvVersionString = (string)lvVersionRegKey.GetValue("VersionString", "");
			if (lvRTEPath.Length == 0 || lvVersionString.Length == 0)
				return "";

			if (lvRTEPath[lvRTEPath.Length-1] != Path.DirectorySeparatorChar)
				lvRTEPath += "\\";

			if (getFFRTE)
				return lvRTEPath + "lvffrt.dll";

			return lvRTEPath + "lvrt.dll";
		}

		static public string GetDirPathForLVVersion(string lvVersion)
		{
			// Launch given LabVIEW version
			string lvInfoKey = "Software\\National Instruments\\LabVIEW\\" + lvVersion;
			RegistryKey localMachineRegKey = Registry.LocalMachine;
			RegistryKey lvVersionRegKey = localMachineRegKey.OpenSubKey(lvInfoKey);

			if (lvVersionRegKey == null)
				return "";

			string lvPath = (string)lvVersionRegKey.GetValue("Path", "");
			if (lvPath.Length == 0)
				return "";

			if (lvPath[lvPath.Length-1] != Path.DirectorySeparatorChar)
				lvPath += "\\";

			return lvPath;
		}

		static public bool ShouldProvidersBeMovedFromLVFolder(string lvVersion)
		{
			string lvPath = GetDirPathForLVVersion(lvVersion);
			string ffrtePath = GetPathForLVRTEVersion(lvVersion, true);

			return ffrtePath.StartsWith(lvPath);
		}

		static public void AddAllowRTDownloadRegistryKey(string tsVersion)
		{
			string tsInfoKey = "Software\\National Instruments\\TestStand\\" + tsVersion;
			RegistryKey localMachineRegKey = Registry.LocalMachine;
			RegistryKey tsVersionRegKey = localMachineRegKey.OpenSubKey(tsInfoKey, true);

			tsVersionRegKey.DeleteValue("EnableLVRT80Support", false);
			tsVersionRegKey.SetValue("EnableLVRT80Support", 1);
		}

		/////////////////////////////////////////////////////////////////////
		///
		/// LV Version functions
		/// 
		/////////////////////////////////////////////////////////////////////

		public struct LVVersionInfo
		{
			public string	mVersion;
			public string	mDisplayVersion;
			public string	mLocationDir;

			public LVVersionInfo(string version, string displayVersion, string locationDir)
			{
				this.mVersion = version;
				this.mDisplayVersion = displayVersion;
				this.mLocationDir = locationDir;
			}
		}

		private class LVInfoComparer : IComparer
		{
			public LVInfoComparer() {}

			public int Compare (object x, object y) 
			{
                LVVersionInfo lvVersionInfo1 = (LVVersionInfo)x;
                LVVersionInfo lvVersionInfo2 = (LVVersionInfo)y;

                Version ver_mVersion1 = new Version(lvVersionInfo1.mVersion);
                Version ver_mVersion2 = new Version(lvVersionInfo2.mVersion);

                return ver_mVersion1.CompareTo(ver_mVersion2);
			}
		}

		static public bool GetTheLatestLVVesionInstalled(string minimumVersion, out string lvVersion, out string errorMessage)
		{
			LVVersionInfo[] lvVersionInfoArray;

			// Get all the LabVIEW versions installed.  They are sorted by version number
			// in ascending order
			GetLVRTVersions(out lvVersionInfoArray, true, minimumVersion);

			if (lvVersionInfoArray != null && lvVersionInfoArray.Length > 0)
			{
				errorMessage = string.Empty;
				lvVersion = lvVersionInfoArray[lvVersionInfoArray.Length - 1].mVersion;
				return true;
			}

			lvVersion = string.Empty;
			errorMessage = "No LabVIEW Development System installed.";
			return false;
		}

		static public bool GetTheLatestLVVersionInstalled(out string lvVersion, out string errorMessage)
		{
			return GetTheLatestLVVesionInstalled("", out lvVersion, out errorMessage);
		}

		public class LVRTEPermutations
		{
			public string[][] Permutations;

			public LVRTEPermutations(long permutations)
			{
				this.Permutations = new string[permutations][];
			}

			public int NumOfPermutations
			{
				get { return this.Permutations.Length; }
			}

			public void GetPermutation(int index, out string[] permutation)
			{
				permutation = this.Permutations[index];
			}
		}

		static public void GetPermuationsOfAllPathsForALLLVRTVersions(string mimimumVersion, out LVRTEPermutations lvrtePermutations)
		{
			LVVersionInfo[] lvVersions;
			GetLVRTVersions(out lvVersions, false, mimimumVersion);

			List<string> rtePathList = new List<string>(lvVersions.Length);
			for (int i = 0; i < lvVersions.Length; i++)
			{
				string lvrtPath = Path.Combine(lvVersions[i].mLocationDir, "lvrt.dll");
				if (File.Exists(lvrtPath))
					rtePathList.Add(lvrtPath);
			}

			Permutations<string> permutations = new Permutations<string>(rtePathList);
			
			lvrtePermutations = new LVRTEPermutations(permutations.Count);
			int index = 0;
			foreach (List<string> permutation in permutations)
			{
				lvrtePermutations.Permutations[index] = permutation.ToArray();
				index++;
			}
		}

        static public void GetLVVersionsInstalled(out string[] lvVersions, bool getLVDevInfo, string minimumVersion)
        {
            LVVersionInfo[] lvVer;
            GetLVRTVersions(out lvVer, getLVDevInfo, minimumVersion);
            ArrayList lvVersionArray = new ArrayList(lvVer.Length);

            for (int i = 0; i < lvVer.Length; i++)
            {
                lvVersionArray.Add(lvVer[i].mVersion);
            }
            lvVersions = (string[])lvVersionArray.ToArray(typeof(string));
        }
// Added by Ravi for CAR 219302
        static public void GetLVVersionsInstalledWithRev(out string[] lvVersions, bool IsDev, out string[] lvVersionsWithRev)
        {
            LVVersionInfo[] lvVer;
            GetLVRTVersions(out lvVer, IsDev, "");
            ArrayList lvVersionArray = new ArrayList(lvVer.Length);

            for (int i = 0; i < lvVer.Length; i++)
            {
                lvVersionArray.Add(lvVer[i].mVersion);
            }
            lvVersions = (string[])lvVersionArray.ToArray(typeof(string));// Provides 1 digit info ex "10.0" %1f

            lvVersionArray.Clear();

            for (int i = 0; i < lvVer.Length; i++)
            {
                lvVersionArray.Add(lvVer[i].mDisplayVersion);
            }
            lvVersionsWithRev = (string[])lvVersionArray.ToArray(typeof(string));// Provides information like is SP1 or Fx

        }
 
        // Added by Ravi for CAR 219302
        static public void GetRevInformation(string LVversionIn, out string LVversionWithRevout, bool IsDev)
        {
            LVVersionInfo[] lvVer;
            string Lvout ="";
            GetLVRTVersions(out lvVer, IsDev, "");
 
            for (int i = 0; i < lvVer.Length; i++)
            {

                if (string.Compare(lvVer[i].mVersion, LVversionIn) == 0)
                {
                    //string.Copy(LVversionWithRevout, lvVer[i].mDisplayVersion);
                    Lvout = string.Copy(lvVer[i].mDisplayVersion);
                }

            }
            LVversionWithRevout= string.Copy(Lvout);

         }


   		// Get all the LabVIEW Run-Time Versions installed and sort them by version number in ascending order
		static private void GetLVRTVersions(out LVVersionInfo [] lvVersions, bool getLVDevInfo, string mimimumVersionToGet)
		{
			string lvInfoKey; 
			if (getLVDevInfo)
				lvInfoKey = "Software\\National Instruments\\LabVIEW";
			else
				lvInfoKey = "Software\\National Instruments\\LabVIEW Run-Time";

			RegistryKey localMachineRegKey = Registry.LocalMachine;
			RegistryKey lvVersionsRegKey = localMachineRegKey.OpenSubKey(lvInfoKey);

			Version mimimumVersion = null;
			if (!string.IsNullOrEmpty(mimimumVersionToGet))
				mimimumVersion = new Version(mimimumVersionToGet);

			lvVersions = null;

			if (lvVersionsRegKey != null)
			{
				string[] keyNames = lvVersionsRegKey.GetSubKeyNames();
				ArrayList lvVersionArray = new ArrayList(keyNames.Length);
				NumberFormatInfo formatProvider = new NumberFormatInfo();

				foreach (string keyName in keyNames)
				{
					Version currentVersion = null;

					// First, make sure the keyName is a valid numeric value
					float lvVersionNumber = -1;

					try
					{
						lvVersionNumber = System.Convert.ToSingle(keyName, formatProvider);
						currentVersion = new Version(keyName);
					}
					catch (Exception)
					{
                        // The registry key name is not a valid number.  Just ignore the error 
                        // and continue with the next entry.
                        lvVersionNumber = -1;
					}

					// If valid numeric value, then try to get the version information
					if (lvVersionNumber > 0 && (mimimumVersion == null || currentVersion >= mimimumVersion))
					{
						RegistryKey lvVersionRegKey = lvVersionsRegKey.OpenSubKey(keyName);

						if (lvVersionRegKey != null)
						{
							string lvPath = (string)lvVersionRegKey.GetValue("Path", "");
							string lvDisplayVersion = (string)lvVersionRegKey.GetValue("VersionString");

							if (lvPath != null && lvPath.Length > 0)
								lvVersionArray.Add(new LVVersionInfo(keyName, lvDisplayVersion, lvPath));
						}
					}
				}

				if (lvVersionArray.Count > 0)
				{
					lvVersionArray.Sort(new LVInfoComparer());
					lvVersions = (LVVersionInfo[])lvVersionArray.ToArray(typeof(LVVersionInfo));
				}
			}
		}
	}
}

using System;
using System.Collections.Generic;
using System.Text;
using NationalInstruments.TestStand.Interop.API;    // TestStand Core API.  Add <TestStand>\API\DotNet\Assemblies\CurrentVersion\NationalInstruments.TestStand.Interop.API.dll to your project as a reference.
using System.Runtime.InteropServices;

namespace VS2010
{
    public class Class1
    {
        public void ExistingMethod(SequenceContext seqContext, out String reportText, out bool errorOccurred, out int errorCode, out String errorMsg)
        {
            reportText = String.Empty;
            errorOccurred = false;
            errorCode = 0;
            errorMsg = String.Empty;

            try
            {
                // INSERT YOUR SPECIFIC TEST CODE HERE

                // The following code shows how to access properties and variables via the TestStand API
                // PropertyObject propertyObject = seqContext.AsPropertyObject();
                // String lastUserName = propertyObject.GetValString("StationGlobals.TS.LastUserName", 0);
            }
            catch (COMException e)
            {
                errorOccurred = true;
                errorMsg = e.Message;
                errorCode = e.ErrorCode;
            }
        }
    }
}

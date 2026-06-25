using System;
using System.Collections.Generic;
using System.Text;

namespace NETTest
{
	public struct NETInside
	{
		public int number;
		public bool booleanValue;
	}

	public struct NETOutside
	{
		public string name;
		public NETInside Inside;
	}

	public class NETObject
	{
		public void AddedParameters (string string1, long number, string string2, long number2)
		{
		}

		public void RemovedParameters (string string1, long number2)
		{
		}

		public void ChangedParameters(string string1, long number2, string string2, long number1)
		{
		}

		public void ArrayClustersParameters()
		{
		}
	}
}

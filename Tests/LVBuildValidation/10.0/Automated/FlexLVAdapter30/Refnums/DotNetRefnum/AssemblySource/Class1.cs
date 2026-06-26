using System;
using System.Runtime.Remoting;

namespace labviewDNTest
{
	/// <summary>
	/// Summary description for Class1.
	/// </summary>
	public class LVTestClass : MarshalByRefObject
	{
		private string m_str;
		private int m_int;
		private double m_dbl;

		public LVTestClass(string str, int intNum, double dblNum)
		{
			m_str = str;
			m_int = intNum; 
			m_dbl = dblNum;
		}

		public double add (double x, double y)
		{
			return x+y;
		}

		public string str
		{
			get
			{
				return m_str;
			}
			set
			{
				m_str = value;
			}
		}

		public int intProp
		{
			get
			{
				return m_int;
			}
			set
			{
				m_int = value;
			}
		}

		public string Append(string str)
		{
			m_str += str;
			return m_str;
		}

		public void GCClean()
		{
			GC.Collect();
		}
		

	}
}

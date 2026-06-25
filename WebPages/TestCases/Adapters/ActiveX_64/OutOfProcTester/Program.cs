using System;
using System.Collections.Generic;
using System.Text;

namespace OutOfProcTester
{
	class Program
	{
		static void Main(string[] args)
		{
			// Run the out-of-process COM server
			CSExeCOMServer.ExeCOMServer.Instance.Run();
		}
	}
}

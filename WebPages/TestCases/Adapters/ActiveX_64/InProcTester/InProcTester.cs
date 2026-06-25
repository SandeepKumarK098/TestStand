using System;

namespace InProcTester
{
	public interface IInProcTester
	{
		int GetIntPointerSize();

		void ReturnVoid();
		bool ReturnBool(bool val1, bool val2);
		int ReturnInt32(int val1, int val2);
		long ReturnInt64(long val1, long val2);
		float ReturnFloat(float val1, float val2);
		double ReturnDouble(double val1, double val2);
		byte SumUnt8s(byte [] array);
		int SumInt32s(int [] array);
		double SumDoubles(double[] array);

		void ThrowException();
	}

	public class InProcTester : IInProcTester
	{
		int IInProcTester.GetIntPointerSize()
		{
			return IntPtr.Size;
		}

		void IInProcTester.ReturnVoid() {}
		bool IInProcTester.ReturnBool(bool val1, bool val2) { return val1 && !val2; } 
		int IInProcTester.ReturnInt32(int val1, int val2) { return val1 + val2; }
		long IInProcTester.ReturnInt64(long val1, long val2) { return val1 + val2; }
		float IInProcTester.ReturnFloat(float val1, float val2) { return val1 + val2; }
		double IInProcTester.ReturnDouble(double val1, double val2) { return val1 + val2; }

		byte IInProcTester.SumUnt8s(byte[] array)
		{
			byte sum = 0;

			for (int ii = 0; ii < array.Length; ++ii)
			{
				sum += array[ii];
			}

			return sum;
		}

		int IInProcTester.SumInt32s(int[] array)
		{
			int sum = 0;

			for (int ii = 0; ii < array.Length; ++ii)
			{
				sum += array[ii];
			}

			return sum;
		}

		double IInProcTester.SumDoubles(double[] array)
		{
			double sum = 0;

			for (int ii = 0; ii < array.Length; ++ii)
			{
				sum += array[ii];
			}

			return sum;
		}

		void IInProcTester.ThrowException()
		{
			throw new System.OverflowException();
		}
	}
}

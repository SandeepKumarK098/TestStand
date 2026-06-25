using System;
using System.Collections.Generic;
using System.Text;

namespace DotNetMultipleSelection
{
	/// <summary>
	/// This class is for testing multiple selections
	/// </summary>
	public class TestMultipleSelection
	{
		/// <summary>
		/// Default Constructor
		/// </summary>
		public TestMultipleSelection() 
		{
			this.mNumericProperty = 0;
		}

		/// <summary>
		/// Numeric Field
		/// </summary>
		private int mNumericProperty;
		/// <summary>
		/// Numeric Property - accessor to private field mNumericProperty
		/// </summary>
		public int NumericProperty { get { return this.mNumericProperty; } }

		/// <summary>
		/// Returns new TestMultipleSelection object.
		/// </summary>
		/// <returns>New TestMultipleSelection object.</returns>
		public TestMultipleSelection GetNewObject()
		{
			return new TestMultipleSelection();
		}

		/// <summary>
		/// Returns new DifferentClass object.
		/// </summary>
		/// <returns>New DifferentClass object.</returns>
		public DifferentClass GetDifferentClassObject()
		{
			return new DifferentClass();
		}

		/// <summary>
		/// Method with different types of numeric parameters
		/// </summary>
		/// <param name="number1">Int32</param>
		/// <param name="number2">Float</param>
		/// <param name="number3">Short</param>
		/// <param name="number4">Double</param>
		public void VariousNumbers(int number1, float number2, short number3, double number4) { }
		/// <summary>
		/// Method with different types of parameters
		/// </summary>
		/// <param name="type1">Int32</param>
		/// <param name="type2">String</param>
		/// <param name="type3">Char</param>
		/// <param name="type4">Float</param>
		/// <param name="type5">Char array</param>
		public void VariousTypes(int type1, string type2, char type3, float type4, char[] type5) { }

		/// <summary>
		/// Num Test with 1 param
		/// </summary>
		/// <param name="number1">param 1</param>
		public void NumericTest1(int number1) { }
		/// <summary>
		/// Num Test with 2 params
		/// </summary>
		/// <param name="number1">param 1</param>
		/// <param name="number2">param 2</param>
		public void NumericTest2(int number1, int number2) { }
		/// <summary>
		/// Num Test with 3 params
		/// </summary>
		/// <param name="number1">param 1</param>
		/// <param name="number2">param 2</param>
		/// <param name="number3">param 3</param>
		public void NumericTest3(int number1, int number2, int number3) { }
		/// <summary>
		/// Num Test with 4 params
		/// </summary>
		/// <param name="number1">param 1</param>
		/// <param name="number2">param 2</param>
		/// <param name="number3">param 3</param>
		/// <param name="number4">param 4</param>
		public void NumericTest4(int number1, int number2, int number3, int number4) { }
		/// <summary>
		/// Num Test with 5 params
		/// </summary>
		/// <param name="number1">param 1</param>
		/// <param name="number2">param 2</param>
		/// <param name="number3">param 3</param>
		/// <param name="number4">param 4</param>
		/// <param name="number5">param 5</param>
		public void NumericTest5(int number1, int number2, int number3, int number4, int number5) { }
		/// <summary>
		/// Num Test with 6 params
		/// </summary>
		/// <param name="number1">param 1</param>
		/// <param name="number2">param 2</param>
		/// <param name="number3">param 3</param>
		/// <param name="number4">param 4</param>
		/// <param name="number5">param 5</param>
		/// <param name="number6">param 6</param>
		public void NumericTest6(int number1, int number2, int number3, int number4, int number5, int number6) { }

		/// <summary>
		/// String Test with 1 param
		/// </summary>
		/// <param name="string1">param 1</param>
		public void StringTest1(string string1) { }
		/// <summary>
		/// String Test with 2 params
		/// </summary>
		/// <param name="string1">param 1</param>
		/// <param name="string2">param 2</param>
		public void StringTest2(string string1, string string2) { }
		/// <summary>
		/// String Test with 3 params
		/// </summary>
		/// <param name="string1">param 1</param>
		/// <param name="string2">param 2</param>
		/// <param name="string3">param 3</param>
		public void StringTest3(string string1, string string2, string string3) { }
		/// <summary>
		/// String Test with 4 params
		/// </summary>
		/// <param name="string1">param 1</param>
		/// <param name="string2">param 2</param>
		/// <param name="string3">param 3</param>
		/// <param name="string4">param 4</param>
		public void StringTest4(string string1, string string2, string string3, string string4) { }
		/// <summary>
		/// String Test with 5 params
		/// </summary>
		/// <param name="string1">param 1</param>
		/// <param name="string2">param 2</param>
		/// <param name="string3">param 3</param>
		/// <param name="string4">param 4</param>
		/// <param name="string5">param 5</param>
		public void StringTest5(string string1, string string2, string string3, string string4, string string5) { }
		/// <summary>
		/// String Test with 6 params
		/// </summary>
		/// <param name="string1">param 1</param>
		/// <param name="string2">param 2</param>
		/// <param name="string3">param 3</param>
		/// <param name="string4">param 4</param>
		/// <param name="string5">param 5</param>
		/// <param name="string6">param 6</param>
		public void StringTest6(string string1, string string2, string string3, string string4, string string5, string string6) { }
	}

	/// <summary>
	/// Different Class
	/// </summary>
	public class DifferentClass
	{
		/// <summary>
		/// Default constructor
		/// </summary>
		public DifferentClass() { }

		/// <summary>
		/// Method with int param
		/// </summary>
		/// <param name="number">int32 param</param>
		public void DifferentMethod(int number) { }

		/// <summary>
		/// Returns new TestMultipleSelection object.
		/// </summary>
		/// <returns>New TestMultipleSelection object</returns>
		public TestMultipleSelection GetTestMultipleSelectionObject()
		{
			return new TestMultipleSelection();
		}
	}
}

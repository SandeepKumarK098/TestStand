using System;
using System.Collections.Generic;
using System.Text;

namespace LoadPrototypeFromMetadataToken
{
	/// <summary>
	/// This class will test the possible members, constructors, and properties
	/// to make sure using the metadata token works properly
	/// </summary>
	public class TestClass
	{
		#region Constructors
		/// <summary>
		/// No param Constructor
		/// </summary>
		public TestClass() { }
		/// <summary>
		/// 1 param int constructor
		/// </summary>
		/// <param name="x">param1 int</param>
		public TestClass(int x) { }
		/// <summary>
		/// 1 param string constructor
		/// </summary>
		/// <param name="x">param1 string</param>
		public TestClass(string x) { }
		/// <summary>
		/// 1 param struct constructor
		/// </summary>
		/// <param name="x">param 1 struct</param>
		public TestClass(TestStruct x) { }
		/// <summary>
		/// 3 param constructor
		/// </summary>
		/// <param name="x">param1 int</param>
		/// <param name="y">param2 string</param>
		/// <param name="z">param3 struct</param>
		public TestClass(int x, string y, TestStruct z) { }
		#endregion

		#region Methods
		/// <summary>
		/// Method with no params
		/// </summary>
		public void Method() { }
		/// <summary>
		/// Method with 1 param int
		/// </summary>
		/// <param name="x">param1 int</param>
		public void Method(int x) { }
		/// <summary>
		/// Method with 1 param int array
		/// </summary>
		/// <param name="x">param1 int array</param>
		public void Method(int[] x) { }
		/// <summary>
		/// Method with 1 param string
		/// </summary>
		/// <param name="x">param1 string</param>
		public void Method(string x) { }
		/// <summary>
		/// Method with 1 param struct
		/// </summary>
		/// <param name="x">param1 struct</param>
		public void Method(TestStruct x) { }
		/// <summary>
		/// Method with 3 params
		/// </summary>
		/// <param name="x">param1 int</param>
		/// <param name="y">param2 string</param>
		/// <param name="z">param3 struct</param>
		public void Method(int x, string y, TestStruct z) { }
		#endregion

		#region Properties
		/// <summary>
		/// struct field
		/// </summary>
		public TestStruct mStructField;
		/// <summary>
		/// struct parameter
		/// </summary>
		public TestStruct StructProperty
		{
			get { return this.mStructField; }
			set { this.mStructField = value; }
		}

		/// <summary>
		/// int field
		/// </summary>
		public int mIntField;
		/// <summary>
		/// int property
		/// </summary>
		public int IntProperty
		{
			get { return this.mIntField; }
			set { this.mIntField = value; }
		}

		/// <summary>
		/// int array field
		/// </summary>
		public int[] mIntArrayField;
		/// <summary>
		/// int array property
		/// </summary>
		public int[] IntArrayField
		{
			get { return this.mIntArrayField; }
			set { this.mIntArrayField = value; }
		}
		/// <summary>
		/// indexer
		/// </summary>
		/// <param name="index"></param>
		/// <returns></returns>
		public int this[int index]
		{
			get { return this.mIntArrayField[index]; }
			set { this.mIntArrayField[index] = value; }
		}

		/// <summary>
		/// bool field
		/// </summary>
		public bool mBoolField;
		/// <summary>
		/// bool property
		/// </summary>
		public bool BoolProperty
		{
			get { return this.mBoolField; }
			set { this.mBoolField = value; }
		}

		/// <summary>
		/// string field
		/// </summary>
		public String mStringField;
		/// <summary>
		/// string property
		/// </summary>
		public String StringProperty
		{
			get { return this.mStringField; }
			set { this.mStringField = value; }
		}

		/// <summary>
		/// object field
		/// </summary>
		public Object mObjectField;
		/// <summary>
		/// object property
		/// </summary>
		public Object ObjectProperty
		{
			get { return this.mObjectField; }
			set { this.mObjectField = value; }
		}
		#endregion
	}

	public struct TestStruct
	{
		/// <summary>
		/// struct constructor
		/// </summary>
		/// <param name="intValue">param1 int</param>
		/// <param name="stringValue">param2 string</param>
		/// <param name="objectValue">param3 object</param>
		public TestStruct(int intValue, String stringValue, Object objectValue)
		{
			this.mIntField = intValue;
			this.mStringField = stringValue;
			this.mObjectField = objectValue;
		}

		/// <summary>
		/// int field
		/// </summary>
		public int mIntField;
		/// <summary>
		/// int property
		/// </summary>
		public int IntProperty
		{
			get { return this.mIntField; }
			set { this.mIntField = value; }
		}

		/// <summary>
		/// string field
		/// </summary>
		public String mStringField;
		/// <summary>
		/// string property
		/// </summary>
		public String StringProperty
		{
			get { return this.mStringField; }
			set { this.mStringField = value; }
		}

		/// <summary>
		/// object field
		/// </summary>
		public Object mObjectField;
		/// <summary>
		/// object property
		/// </summary>
		public Object ObjectProperty
		{
			get { return this.mObjectField; }
			set { this.mObjectField = value; }
		}
	}
}

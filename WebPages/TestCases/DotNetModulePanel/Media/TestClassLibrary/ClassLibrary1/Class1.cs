using System;
using System.Collections.Generic;
using System.Text;

namespace ClassLibrary1
{
	

    public static class StaticClass1
	{
		public static void Method1() { }
	}

	public enum Enum1
	{
		EnumElement1, EnumElement2, EnumElement3
	}

	public class EmptyClass { }

	public interface EmptyInterface { }

    // type parameter T in angle brackets
    public class GenericList<T>
    {
        // The nested class is also generic on T
        private class Node
        {
            // T used in non-generic constructor
            public Node(T t)
            {
                next = null;
                data = t;
            }

            private Node next;
            public Node Next
            {
                get { return next; }
                set { next = value; }
            }

            // T as private member data type
            private T data;

            // T as return type of property
            public T Data
            {
                get { return data; }
                set { data = value; }
            }
        }

        private Node head;

        // constructor
        public GenericList()
        {
            head = null;
        }

        // T as method parameter type:
        public void AddHead(T t)
        {
            Node n = new Node(t);
            n.Next = head;
            head = n;
        }

        public IEnumerator<T> GetEnumerator()
        {
            Node current = head;

            while (current != null)
            {
                yield return current.Data;
                current = current.Next;
            }
        }
    }


	public class Class1
	{

        public static int AddThroughDepend()
        {
            DependOnMe.Depend foo = new DependOnMe.Depend();
            return foo.Suma(4, 5);
            
        }

        public static void UseDepend(DependOnMe.Depend value)
        {

        }

        public static void TakeMultiArray(int[,] value)
        {
        }

        public enum Days { Sat, Sun, Mon, Tue, Wed, Thu, Fri };

        public static Days ReturnDay()
        {
            return Days.Fri;
        }

        public static void TakeJaggedArray(int[][] value)
        {
        }

        public static void SquareIt(ref int x)
        // The parameter x is passed by reference.
        // Changes to x will affect the original value of myInt.
        {
            x *= x;
            Console.WriteLine("The value inside the method: {0}", x);
        }


        public struct NestedStruct
		{
			int x;
			string y;
			double[] myDoubleArray;
			EvenMoreNestedStruct myEvenMoreNestedStruct;
		}

		public struct EvenMoreNestedStruct
		{
			Int64[] myInt64Array;
			UInt64[] myUInt64Array;
		}

		public struct TestStruct
		{
			
			string myString;
			int[] myIntArray;
			NestedStruct myNestedStruct;
			int myInt;

		}

		public static TestStruct TakeAndReturnStruct(TestStruct myStruct)
		{
			return myStruct;
		}

		public static void ChangeParametersOrder(float boo, float c,int a)
		{
		}

        public static void LongVeryLongVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryVeryLong()
        {
        }

        public static void dummy1()
        {
        }

        public static void dummy2()
        {
        }
        public static void dummy3()
        {
        }
        public static void dummy4()
        {
        }
        public static void dummy5()
        {
        }
        public static void dummy6()
        {
        }
        public static void dummy7()
        {
        }
        public static void dummy8()
        {
        }
        public static void dummy9()
        {
        }
        public static void dummy10()
        {
        }
        public static void dummy11()
        {
        }
        public static void dummy12()
        {
        }
        public static void dummy13()
        {
        }
        public static void dummy14()
        {
        }
        public static void dummy15()
        {
        }

        public static void dummy16()
        {
        }

        public static void dummy17()
        {
        }
        public static void dummy18()
        {
        }
        public static void dummy19()
        {
        }
        public static void dummy20()
        {
        }
        public static void dummy21()
        {
        }
        public static void dummy22()
        {
        }
        public static void dummy23()
        {
        }
        public static void dummy24()
        {
        }
        public static void dummy25()
        {
        }
        public static void dummy26()
        {
        }
        public static void dummy27()
        {
        }
        public static void dummy28()
        {
        }
        public static void dummy29()
        {
        }
        public static void dummy30()
        {
        }

        public static void dummy31()
        {
        }

        public static void dummy32()
        {
        }
        public static void dummy33()
        {
        }
        public static void dummy34()
        {
        }
        public static void dummy35()
        {
        }
        public static void dummy36()
        {
        }
        public static void dummy37()
        {
        }
        public static void dummy38()
        {
        }
        public static void dummy39()
        {
        }
        public static void dummy40()
        {
        }
        public static void dummy41()
        {
        }
        public static void dummy42()
        {
        }
        public static void dummy43()
        {
        }
        public static void dummy44()
        {
        }
        public static void dummy45()
        {
        }
        public static void dummy46()
        {
        }
        public static void dummy47()
        {
        }
        public static void dummy48()
        {
        }
        public static void dummy49()
        {
        }
        public static void dummy50()
        {
        }


		public static void NestedStructTest(NestedStruct nested) { }

		public static void StaticIntParam(int x) { }

		public static void StaticMethod1(Class1 class1, Interface1 interface1) { }

		private MyStruct myStruct;
		public MyStruct MethodReturningMyStruct() { return myStruct; }

		public int field1;
		public string field2;
		public Interface1 Property1
		{
			set { }
		}

		public void GenericParams(List<int> a, Queue<double> b, Stack<char> c) { }

		public List<string> StringListMethod() 
		{			
			return new List<string>(); 
		}

		public void VoidMethod() { }

		public Class2 Class2Field;
		public Class3 Class3Field;

		public List<Class2> mClass2List;
		public List<Class2> Class2List
		{
			get { return mClass2List; }
			set { mClass2List = value; }
		}

		public Class2[] Class2Array
		{
			get { return mClass2List.ToArray(); }
			set { }
		}

		public int ReadOnlyProp
		{
			//get { return 1; }
			set { }
		}

		public int WriteOnlyProp
		{
			set { }
		}

		public Class2 this[int index]
		{
			get { return mClass2List[index]; }
			set { }
		}

		public Class2 this[string s, int i]
		{
			get { return null; }
		}

		public void Method1(int param1, double param2, out string param3, ref Class1 param4, int x)
		{
			param3 = "test";
		}

		public void Method1(string a, string b, int x)
		{

		}

		public Struct1 Method2(Struct1 s1, Struct2 s2, Enum1 enum1)
		{
			return new Struct1();
		}

		public void EnumMethod(Enum1 enumParameter, Enum1[] enumArrayParameter, double aaa)
		{

		}

		public Boolean[] ArrayOfBooleanTest() { return new Boolean[2]; }

		public String[] ArrayOfStringOutput()
		{
			String[] array = new String[50];
			for (int i = 0; i < 50; i++)
			{
				array[i] = "Some text that might be really long";
			}
			return array;
		}

		public void ArrayOfStringInput(String[] arrayInput)
		{

		}

		public void CrashTestMethod(Struct1 struct1Param, Enum1[] enumArrayParam)
		{

		}

		public void ArrayTest(String[, ,] s, String[, , , , , ,] s2, Array a, Array[] a2) { }
		
		public void Method2(List<Class2> classList)
		{

		}

		public Class2 MethodReturningClass2()
		{
			return new Class2();
		}

		public Class3 MethodReturningClass3()
		{
			return new Class3();
		}

		public List<Class2> GetClass2List()
		{
			return mClass2List;
		}
	}

	public class Class2
	{
		public Class1 Class1Field;
		public Class3 Class3Field;

		public Class1 MethodReturningClass1(Struct1 structParam, Class2 class2Param)
		{
			return new Class1();
		}

		public Class3 MethodReturningClass3()
		{
			return new Class3();
		}
	}

	public class Class3
	{
		private Struct1 mProp1;
		public Struct1 Property1
		{
			get { return mProp1; }
			set { mProp1 = value; }
		}

		public Class1 Class1Field;
		public Class2 Class2Field;

		public Class1 MethodReturningClass1(Struct1 structParam, Class2 class2Param)
		{
			return new Class1();
		}

		public Class2 MethodReturningClass2()
		{
			return new Class2();
		}
	}

	public struct Struct1
	{
		public int x;
		public string y;
		public Struct2 z;
	}

	public struct Struct2
	{
		public double a;
		public bool b;
	}

	public interface Interface1
	{
		void InterfaceMeth1(int x, bool y);
	}

	public interface Interface2
	{
		bool InterfaceMeth2(double a, string b);
	}

	public class MyClass
	{
		private static MyClass sMyClassInstance;
		public static MyClass GetMyClassInstance()
		{
			if (sMyClassInstance == null)
				sMyClassInstance = new MyClass();
			return sMyClassInstance;
		}
	}

	public struct MyStruct
	{
		int x;
		double y;
		string z;

		Class1 class1;

		public Class1 GetClass1() { return class1; }
		public void SetX(int xToSet) { x = xToSet; }
	}
}

using System;
using Dependency;

namespace PublicLibrary
{
    public class Class1
    {
        public Class1() { }

        public void Class1Method()
        {
        }

        public static void TakesSructA(ref StructA val)
        {
            val.DoSomething();
        }

        public StructA mSructA;

        public int mMyInt = 47;
    }
}

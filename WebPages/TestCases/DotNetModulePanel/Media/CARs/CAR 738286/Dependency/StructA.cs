using System;

namespace Dependency
{
    public struct StructA
    {
        public void StructAMethod() { }

        public int mInt;

        public void DoSomething()
        {
            this.mInt = 101;

            mIntrernalClass = new InternalClass();
            //mInternalStruct = new InternalStruct();

            mIntrernalClass.mInt = 42;
            mIntrernalClass.mFloat = 96;
            mInternalStruct.mUInt = 88;
            mInternalStruct.mDouble = 66;
            mInternalEnum = InternalEnum.MumboJumbo;
        }

        private InternalClass mIntrernalClass;
        private InternalStruct mInternalStruct;
        private InternalEnum mInternalEnum;
    }

    internal class InternalClass
    {
        public int mInt;
        public float mFloat;
    }

    internal struct InternalStruct
    {
        public uint mUInt;
        public double mDouble;
    }

    internal enum InternalEnum
    {
        Secret,
        Code,
        Crypto,
        MumboJumbo
    }
}

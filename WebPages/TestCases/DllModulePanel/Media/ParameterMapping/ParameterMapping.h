extern void  __declspec(dllexport) __stdcall Test(long myLong,
                        char *myChar, int myInt, float myFloat,
                        double myDouble, short myShort);
extern void  __declspec(dllexport) __stdcall Rotate(float myFloat,
                        double myDouble, short myShort, long myLong,
                        char *myChar, int myInt);
extern void  __declspec(dllexport) __stdcall SameTypeAndPosition(long myLongA,
                        char *myCharA, int myIntA, float myFloatA,
                        double myDoubleA, short myShortA);
extern void  __declspec(dllexport) __stdcall LessParameters(char *myChar,
                        int myInt, double myDouble);
extern void  __declspec(dllexport) __stdcall MoreParameters(long myLong,
                        char *myChar, short myOtherShort, int myInt,
                        double myDouble, short myShort, long myOtherLong,
                        float myFloat);

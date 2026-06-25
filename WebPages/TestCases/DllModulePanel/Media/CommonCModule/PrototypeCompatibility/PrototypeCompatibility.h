// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PROTOTYPECOMPATIBILITY_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PROTOTYPECOMPATIBILITY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PROTOTYPECOMPATIBILITY_EXPORTS
#define PROTOTYPECOMPATIBILITY_API __declspec(dllexport)
#else
#define PROTOTYPECOMPATIBILITY_API __declspec(dllimport)
#endif

// This class is exported from the PrototypeCompatibility.dll
class PROTOTYPECOMPATIBILITY_API CPrototypeCompatibility {
public:
	CPrototypeCompatibility(void);
	// TODO: add your methods here.
};

extern PROTOTYPECOMPATIBILITY_API int nPrototypeCompatibility;

PROTOTYPECOMPATIBILITY_API int fnPrototypeCompatibility(void);

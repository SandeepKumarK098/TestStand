// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the VS2012_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// VS2012_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef VS2012_EXPORTS
#define VS2012_API __declspec(dllexport)
#else
#define VS2012_API __declspec(dllimport)
#endif

// This class is exported from the VS2012.dll
class VS2012_API CVS2012 {
public:
	CVS2012(void);
	// TODO: add your methods here.
};

extern VS2012_API int nVS2012;

VS2012_API int fnVS2012(void);

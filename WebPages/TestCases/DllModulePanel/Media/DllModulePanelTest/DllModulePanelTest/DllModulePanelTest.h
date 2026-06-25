// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DLLMODULEPANELTEST_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DLLMODULEPANELTEST_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DLLMODULEPANELTEST_EXPORTS
#define DLLMODULEPANELTEST_API __declspec(dllexport)
#else
#define DLLMODULEPANELTEST_API __declspec(dllimport)
#endif

// This class is exported from the DllModulePanelTest.dll
class DLLMODULEPANELTEST_API CDllModulePanelTest {
public:
	CDllModulePanelTest(void);
	// TODO: add your methods here.
};

extern DLLMODULEPANELTEST_API int nDllModulePanelTest;

DLLMODULEPANELTEST_API int fnDllModulePanelTest(void);

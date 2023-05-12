// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the MIRCDLLTEMPLATE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// MIRCDLLTEMPLATE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MIRCDLLTEMPLATE_EXPORTS
#define MIRCDLLTEMPLATE_API __declspec(dllexport)
#else
#define MIRCDLLTEMPLATE_API __declspec(dllimport)
#endif

#include <tchar.h>

// This class is exported from the dll
class MIRCDLLTEMPLATE_API CmIRCDLLtemplate {
public:
	CmIRCDLLtemplate(void);
	// TODO: add your methods here.
};

extern MIRCDLLTEMPLATE_API int nmIRCDLLtemplate;

MIRCDLLTEMPLATE_API int fnmIRCDLLtemplate(void);

MIRCDLLTEMPLATE_API int __stdcall foo(HWND mWnd, HWND aWnd, TCHAR* data, TCHAR* parms, BOOL show, BOOL nopause);
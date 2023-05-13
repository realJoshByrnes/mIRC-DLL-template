// mIRC-DLL-template.cpp : Defines the exported functions for the DLL.

#include <cstdio>
#include "mIRC-DLL-template.h"

DWORD mVersion;
HWND  mHwnd;
DWORD mBeta;
DWORD mBytes;

#ifdef _WIN64
int mBits = 64;
#else
int mBits = 32;
#endif

MIRCDLLTEMPLATE_API void WINAPI LoadDll(LOADINFO* li) {
    li->mKeep = true; // You can set mKeep to FALSE to make mIRC unload the DLL after the call.
#ifdef _UNICODE
    li->mUnicode = true; // Indicates that strings are Unicode as opposed to ANSI.
#endif
    mVersion = li->mVersion; // Contains the mIRC version number in the low and high words.
    mHwnd = li->mHwnd; // Contains the window handle to the main mIRC window.
    mBeta = li->mBeta; // Contains the mIRC beta version number, for public betas.
    mBytes = li->mBytes; // Specifies the maximum number of bytes allowed in the data and parms variables.
}

MIRCDLLTEMPLATE_API int WINAPI UnloadDll(int mTimeout) {
    return 1; // Always allow the DLL to unload.
}

MIRCDLLTEMPLATE_API int WINAPI foo(HWND mWnd, HWND aWnd, TCHAR *data, TCHAR *parms, BOOL show, BOOL nopause) {
    _stprintf_s(data, mBytes, _T("%d-bit DLL called on mIRC v%d.%d."), mBits, LOWORD(mVersion), HIWORD(mVersion));
    return 3;
}
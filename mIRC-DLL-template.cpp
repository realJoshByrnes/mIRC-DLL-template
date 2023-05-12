// mIRC-DLL-template.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "mIRC-DLL-template.h"


// This is an example of an exported variable
MIRCDLLTEMPLATE_API int nmIRCDLLtemplate=0;

// This is an example of an exported function.
MIRCDLLTEMPLATE_API int fnmIRCDLLtemplate(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CmIRCDLLtemplate::CmIRCDLLtemplate()
{
    return;
}

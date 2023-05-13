# mIRC-DLL-template

This project is a template/starter project for those wishing to create a mIRC / AdiIRC Dynamic Link Library (DLL).

The project is written in C++ using Microsoft Visual Studio Community 2002.


## mIRC
* All versions of mIRC require 32-bit DLLs at the time of writing as there is no 64-bit version of mIRC released, although this is planned.

## AdiIRC
* AdiIRC comes in both 32-bit and 64-bit, and you should set your target appropriately.
* AdiIRC reports an incorrect version in the **mVersion** DWORD. This is likely to encourage compatibility with DLLs designed for mIRC.

# Example Script

The following script can be used in both mIRC and AdiIRC in order to test your compiled DLL.  You should change the location of the file to match your system.

```msl
alias dlltest {
  ; Bare filename - use %TARGET% for x86\Win32 directory
  var %file = C:\Users\jd\Documents\Projects\mIRC-DLL-template\%TARGET%\Release\mIRCDLLtemplate.dll

  var %file $qt($replace(%file, $chr(37) $+ TARGET%, $iif($bits == 64, x64, Win32)))
  echo $color(info) -taq DLL Pre-loaded: $iif($dll(%file), $true, $false)
  echo $color(info2) -ta DLL Result: $dll(%file, foo, )
  echo $color(info) -taq LOADINFO->mKeep: $iif($dll(%file), $true, $false)
  dll -u %file
  echo $color(info) -taq DLL Unloaded.
}
```

# Output file size

While there may be some modications that you can make to the compiler settings to decrease the output binary size (feel free to contribute your findings), I have had success decreasing the binary size by using [UPX](https://github.com/upx/upx).

```
                       Ultimate Packer for eXecutables
                          Copyright (C) 1996 - 2023
UPX 4.0.2       Markus Oberhumer, Laszlo Molnar & John Reiser   Jan 30th 2023

        File size         Ratio      Format      Name
   --------------------   ------   -----------   -----------
      8192 ->      6144   75.00%    win32/pe     mIRCDLLtemplate.dll
     10240 ->      7168   70.00%    win64/pe     mIRCDLLtemplate.dll
```

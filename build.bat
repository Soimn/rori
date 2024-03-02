@echo off
setlocal

if "%Platform%" neq "x64" (
    echo ERROR: Platform is not "x64" - please run this from the MSVC x64 native tools command prompt.
    exit /b 1
)

cd %~dp0
if not exist build mkdir build
cd build

if "%1" neq "" (
	echo Illegal number of arguments^, expected^: build
	goto end
)

cl /GS- /c /O2 /W3 ..\src\loader.c
link /ENTRY:EfiMain /ALIGN:16 /SUBSYSTEM:EFI_APPLICATION /OUT:bootx64.efi loader.obj
if not exist EFI mkdir EFI
if not exist EFI\BOOT mkdir EFI\BOOT
copy bootx64.efi EFI\BOOT\bootx64.efi

:end
endlocal

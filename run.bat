@echo off
setlocal

cd %~dp0

if "%1" neq "" (
	echo Illegal number of arguments^, expected^: run
	goto end
)

start "" "qemu-system-x86_64" -name rori -serial stdio -bios OVMF.fd -drive format=raw,file=fat:rw:build

:end
endlocal

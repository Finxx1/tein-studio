@echo off
setlocal

pushd ..\..

call build\win32\findvs.bat
call build\win32\config.bat

if %BuildMode%==Release ( python tools\packgpak.py resources binary\win32\editor.gpak )

call %VSDevPath% -no_logo -arch=%Architecture%

if not exist binary\win32 mkdir binary\win32
pushd binary\win32

if %BuildMode%==Release rc -nologo -i %ResourcePath% %ResourceFile%

call ..\..\build\win32\timer.bat "cl %IncludeDirs% %Defines% %CompilerFlags% %CompilerWarnings% -Fe%OutputExecutable% %InputSource% -link %LinkerFlags% %LinkerWarnings% %LibraryDirs% %Libraries% %InputResource%"

if %BuildMode%==Release del %ResourcePath%*.res
del *.ilk *.res *.obj *.exp *.lib

popd
popd

endlocal

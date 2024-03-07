@echo off

set MYCD=%cd%
mkdir debug
pushd debug

set SRC=..\src\*.c
set LINC=%MYCD%\inc
set RAYLIB=%MYCD%\lib\raylib.lib

clang-cl -I%LINC% %SRC% %RAYLIB% msvcrt.lib winmm.lib user32.lib shell32.lib gdi32.lib kernel32.lib /link /NODEFAULTLIB:libcmt /SUBSYSTEM:CONSOLE

popd
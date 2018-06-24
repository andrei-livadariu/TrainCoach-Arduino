@echo off
echo This script will create some symlinks from the Arduino libraries folder to the libraries in this repository.
echo Therefore, you will be able to keep your code here and still have it included by the Arduino compiler.
echo Remember to run this installer script as an administrator.
echo Please choose the Arduino libraries path, e.g. C:\Program Files (x86)\Arduino\libraries

setlocal
set "psCommand="(new-object -COM 'Shell.Application')^
.BrowseForFolder(0,'Please choose the Arduino libraries path, e.g. C:\Program Files (x86)\Arduino\libraries',0,0).self.path""

for /f "usebackq delims=" %%I in (`powershell %psCommand%`) do set "folder=%%I"

setlocal enabledelayedexpansion
endlocal

@echo on

for %%L in (TrainCoach; Reactduino; LEGOPowerFunctions) do mklink /D "%folder%\%%L" "%~dp0%%L"
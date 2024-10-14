@echo off
setlocal EnableDelayedExpansion

:: Hardcoded base directory (D:\DSA_Master_cpp)
set "basePath=D:\DSA_Master_cpp"
set "logFile=%basePath%\process_log.txt"

:: Create or clear the log file
echo Log started on %date% at %time% > "%logFile%"
echo Processing files in base folder: "%basePath%" >> "%logFile%"

:: Check if the base folder exists
if not exist "%basePath%" (
    echo Base folder does not exist: "%basePath%" >> "%logFile%"
    exit /b
)

:: Loop through each subdirectory in the base path
for /d %%D in ("%basePath%\*") do (
    call :process_folder "%%D"
)

exit /b

:process_folder
set "currentFolder=%~1"

:: Log the current folder being checked
echo Checking folder: "%currentFolder%" >> "%logFile%"

:: Check if the current folder is outside the base path
echo %currentFolder% | findstr /i /b /c:"%basePath%" >nul
if errorlevel 1 (
    echo Skipping folder "%currentFolder%" as it is outside the base path. >> "%logFile%"
    exit /b
)

:: Exempt certain folders from processing
for %%F in (".git" ".vscode") do (
    echo "%currentFolder%" | findstr /i /c:%%F >nul
    if not errorlevel 1 (
        echo Skipping folder "%currentFolder%" as it is %%F folder. >> "%logFile%"
        exit /b
    )
)

:: Check if the current folder exists
if not exist "%currentFolder%" (
    echo Folder does not exist: "%currentFolder%" >> "%logFile%"
    exit /b
)

:: Create output folder if it doesn't exist in the current folder
if not exist "%currentFolder%\output" (
    echo Creating output folder in "%currentFolder%" >> "%logFile%"
    mkdir "%currentFolder%\output"
)

:: Check for .exe files in the current folder
echo Checking for .exe files in "%currentFolder%" >> "%logFile%"
set "foundExe=0"
for %%E in ("%currentFolder%\*.exe") do (
    echo Found .exe file: %%E >> "%logFile%"
    set "foundExe=1"
)

:: Move all .exe files from the current folder to the output folder
if !foundExe! == 1 (
    echo Moving .exe files to output folder >> "%logFile%"
    move "%currentFolder%\*.exe" "%currentFolder%\output" >> "%logFile%" 2>&1
    echo .exe files moved to "%currentFolder%\output". >> "%logFile%"
) else (
    echo No .exe files found in "%currentFolder%" >> "%logFile%"
)

:: Avoid recursive processing of output folders
if "%currentFolder%\output" == "%currentFolder%\output" (
    echo Skipping output folder: "%currentFolder%\output" >> "%logFile%"
    exit /b
)

:: Recursively process all subfolders within the current folder
echo Searching for subfolders in "%currentFolder%" >> "%logFile%"
for /d %%F in ("%currentFolder%\*") do (
    if exist "%%F" (
        echo Found subfolder: "%%F" >> "%logFile%"
        call :process_folder "%%F"
    )
)

exit /b

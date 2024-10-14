@echo off
setlocal

:: Hardcoded base directory (D:\DSA_Master_cpp)
set "basePath=D:\DSA_Master_cpp"
set "logFile=%basePath%\delete_log.txt"

:: Create or clear the log file
echo Log started on %date% at %time% > "%logFile%"
echo Searching for output folders in: "%basePath%" >> "%logFile%"

:: Check if the base folder exists
if not exist "%basePath%" (
    echo Base folder does not exist: "%basePath%" >> "%logFile%"
    exit /b
)

:: Loop through each subdirectory in the base path
for /d %%D in ("%basePath%\*") do (
    call :delete_output_folders "%%D"
)

echo Deletion completed. >> "%logFile%"
exit /b

:delete_output_folders
set "currentFolder=%~1"

:: Check for the output folder in the current directory
if exist "%currentFolder%\output" (
    echo Deleting folder: "%currentFolder%\output" >> "%logFile%"
    rmdir /s /q "%currentFolder%\output"
    echo Folder deleted: "%currentFolder%\output" >> "%logFile%"
)

:: Recursively check for output folders in subdirectories
for /d %%F in ("%currentFolder%\*") do (
    call :delete_output_folders "%%F"
)

exit /b

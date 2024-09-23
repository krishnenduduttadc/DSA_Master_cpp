@echo off
setlocal

REM Loop through all folders and subfolders
for /r %%d in (.) do (
    pushd %%d
    REM Define the output folder in the current directory
    set "outputFolder=output"

    REM Check if the output folder exists; if not, create it
    if not exist "%outputFolder%" (
        mkdir "%outputFolder%"
    )

    REM Move all .exe files to the output folder
    move *.exe "%outputFolder%" 2>nul

    popd
)

echo All executables have been moved to the output folders in their respective directories.


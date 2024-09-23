@echo off
set "target_folder=D:\DSA_Master_cpp"
echo Deleting all .exe files in the folder: %target_folder% and its subfolders...
for /r "%target_folder%" %%x in (*.exe) do (
    echo Deleting %%x
    del "%%x"
)
echo All .exe files have been deleted.

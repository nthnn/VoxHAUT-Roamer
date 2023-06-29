@echo off
cls
cd ../src
rmdir /s "./app/Talk2VoxHAUT-Sketch/.cache"
rmdir /s "./app/Talk2VoxHAUT-Sketch/dist"
rmdir /s "./app/Talk2VoxHAUT/app/build"
rmdir /s "./app/Talk2VoxHAUT/app/src/main/assets"
mkdir "./app/Talk2VoxHAUT/app/src/main/assets"
pause
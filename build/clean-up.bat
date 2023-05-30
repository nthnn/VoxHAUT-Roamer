@echo off
cls
cd ../src
rmdir /s "./app/Talk2JogRat-Sketch/.cache"
rmdir /s "./app/Talk2JogRat-Sketch/dist"
rmdir /s "./app/Talk2JogRat/app/build"
rmdir /s "./app/Talk2JogRat/app/src/main/assets"
mkdir "./app/Talk2JogRat/app/src/main/assets"
pause
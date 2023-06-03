@echo off

rmdir debug /s /q
rmdir release /s /q
rmdir .vs /s /q
rmdir CMakeFiles /s /q

for /f "delims=" %%a in ('dir /ad /b /s bin') do rmdir /s /q "%%a" 

for /f "delims=" %%a in ('dir /ad /b /s obj') do rmdir /s /q "%%a" 

for /f "delims=" %%a in ('dir /ad /b /s debug') do rmdir /s /q "%%a" 

for /f "delims=" %%a in ('dir /ad /b /s release') do rmdir /s /q "%%a" 

for /f "delims=" %%a in ('dir /ad /b /s .vs') do rmdir /s /q "%%a" 

for /f "delims=" %%a in ('dir /ad /b /s CMakeFiles') do rmdir /s /q "%%a" 

del /F /S /Q  *.user
del /F /S /Q /A:H  *.cache
del /F /S /Q  CMakeCache.txt
del /F /S /Q  cmake_install.cmake
del /F /S /Q  Makefile
pause

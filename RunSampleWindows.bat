echo off
set PATH=C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin;%PATH%
rem echo %PATH%
rem cd "C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin"

cd %HOMEPATH%
set GO111MODULE=off
go get github.com/PDFTron/pdftron-go
xcopy /E /I go\src\github.com\PDFTron\pdftron-go\src_win go\src
xcopy /E /I go\src\github.com\PDFTron\pdftron-go\Samples go\src\pdftron\Samples
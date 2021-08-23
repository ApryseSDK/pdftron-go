@echo  off
set PATH=C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin;%PATH%
rem echo %PATH%
rem cd "C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin"

cd %HOMEPATH%
echo Set GO111MODULE OFF
set GO111MODULE=off

echo Get PDFTron-go from Github
go get github.com/PDFTron/pdftron-go

echo Copy PDFTrongo to src
xcopy /E /I go\src\github.com\PDFTron\pdftron-go\src_win go\src
xcopy /E /I go\src\github.com\PDFTron\pdftron-go\Samples go\src\pdftron\Samples

cd %HOMEPATH%\go\src\pdftron\Samples\AddImageTest\GO
echo Running AddImageTest Sample. This may take a few minutes to run...
RunTest.bat
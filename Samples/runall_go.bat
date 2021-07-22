@echo off
if not exist .\bin\ (
  md .\bin\ >nul
)
if not exist .\bin\PDFNetC.dll (
	copy ..\PDFNetC\Lib\PDFNetC.dll .\bin\PDFNetC.dll >nul
)

if not exist .\bin\pdftron.dll (
	copy ..\PDFNetC\Lib\pdftron.dll .\bin\pdftron.dll >nul
)

for /D %%s in (*) do (
    if exist %%s\GO\RunTest.bat (
        cd %%s\GO
        echo %%s starting...
        call RunTest.bat
        cd ..\..
        echo %%s finished.
        pause
    )
)

echo Build and run all tests finished.

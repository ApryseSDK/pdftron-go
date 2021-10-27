<div align="center">
  
  
  <h1>PDFTron GO</h1>
  
  <p>
    
  </p>

  <h3>
    <a href="https://www.pdftron.com/documentation/go/">Website</a>
  </h3>

</div>

<hr/>

# Supported platforms: Linux , Mac, Windows <br/>

<strong>Environments and versions:</strong> <br/>
- Minimum RAM of 2GB in Linux or 4GB in Mac/Windows
- <strong>Go </strong>1.15 <br/> Note: Ubuntu Linux 14.0.x can only use Go 1.15, as Go 1.16 or higher is no longer supported in that platform.
- <strong>Git</strong><br/>

For Windows, you will need <strong>mingw-64</strong>: <br/>
https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/8.1.0/<br/>
Click on MinGW-W64-install.exe under MinGW-W64 Online Installer and make sure to choose x86_64 architecture during installation. <br/>


# Running PDFTronGo from Linux

Run RunSampleLinux.sh from $HOME or <br/>
1. cd $HOME
2. export GO111MODULE=off
3. go get github.com/PDFTron/pdftron-go
4. cp -r go/src/github.com/PDFTron/pdftron-go/src_linux/pdftron/ go/src/
5. cp -r go/src/github.com/PDFTron/pdftron-go/Samples/ go/src/pdftron/

To execute the sample code, you can try the following: <br/>
1. cd $HOME/go/src/pdftron/Samples/AddImageTest/GO
2. ./RunTest.sh 


# Running PDFTronGo from Mac

Run RunSampleMac.sh from $HOME or <br/>
1. cd $HOME
2. export GO111MODULE=off
3. go get github.com/PDFTron/pdftron-go
4. cp -R go/src/github.com/PDFTron/pdftron-go/src_mac/pdftron/ go/src/pdftron/
5. cp -R go/src/github.com/PDFTron/pdftron-go/Samples/ go/src/pdftron/Samples/
6. install_name_tool -id "@rpath/libpdftron.dylib" $HOME/go/src/pdftron/PDFNetC/Lib/libpdftron.dylib

To execute the sample code, you can try the following: <br/>
1. cd $HOME/go/src/pdftron/Samples/AddImageTest/GO
2. ./RunTest.sh 


# Running PDFTronGo from Windows 

Run RunSampleWindows.bat from %HOMEPATH% or <br/>
1. Run mingw-w64.bat from "C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0" to open command prompt
2. cd %HOMEPATH%
3. set GO111MODULE=off 
4. go get github.com/PDFTron/pdftron-go
5. xcopy /E /I go\src\github.com\PDFTron\pdftron-go\src_win go\src
6. xcopy /E /I go\src\github.com\PDFTron\pdftron-go\Samples go\src\pdftron\Samples

To execute the sample code, you can try the following: <br/>
1. cd %HOMEPATH%\go\src\pdftron\Samples\AddImageTest\GO  
2. RunTest.bat

<hr/>

Output file will be in $HOME/go/src/pdftron/Samples/TestFiles/Output

Bin file will be in $HOME/go/src/pdftron/Samples/bin

<hr/>


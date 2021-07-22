<div align="center">
  
  
  <h1>PDFTron GO</h1>
  
  <p>
    
  </p>

  <h3>
    <a href="https://www.pdftron.com">Website</a>
  </h3>

</div>

<hr/>

# Supported platforms: Linux , Mac, Windows <br/>

<strong>Environments and versions:</strong> <br/>
- <strong>Go </strong>1.15 <br/>
- <strong>Git</strong><br/>

For Windows, you will need <strong>mingw-64</strong>: <br/>
http://mingw-w64.org/doku.php/download/mingw-builds <br/>
Make sure to choose x86_64 architecture during installation. <br/>


# Running PDFTronGo from Linux

1. cd $HOME/go 
2. go get github.com/PDFTron/pdftron-go
3. cp src/github.com/PDFTron/pdftron-go/src_linux/pdftron/ src/
4. cp src/github.com/PDFTron/pdftron-go/Samples/ src/pdftron/
5. cd $HOME/go/src/pdftron/Samples/AddImageTest/GO
6. ./RunTest.sh 


# Running PDFTronGo from Mac

1. cd $HOME/go 
2. export GO111MODULE=off
2. go get github.com/PDFTron/pdftron-go
3. cp src/github.com/PDFTron/pdftron-go/src_mac/pdftron/ src/
4. cp src/github.com/PDFTron/pdftron-go/Samples/ src/pdftron/
5. install_name_tool -id "@rpath/libpdftron.dylib" $HOME/go/src/pdftron/PDFNetC/Lib/libpdftron.dylib
6. cd $HOME/go/src/pdftron/Samples/AddImageTest/GO
7. ./RunTest.sh 


# Running PDFTronGo from Windows 

1. Run mingw-w64.bat from "C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0" to open command prompt
2. cd %HOMEPATH%
3. go get github.com/PDFTron/pdftron-go
4. xcopy /E /I go\src\github.com\PDFTron\pdftron-go\src_win go\src
4. xcopy /E /I go\src\github.com\PDFTron\pdftron-go\Samples go\src\pdftron\Samples
5. cd %HOMEPATH%\go\src\pdftron\Samples\AddImageTest\GO and call RunTest.bat

<hr/>

Output file will be in $HOME/go/src/pdftron/Samples/TestFiles/Output

Bin file will be in $HOME/go/src/pdftron/Samples/bin

<hr/>


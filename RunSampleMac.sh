#!/bin/sh

DIR="%HOME/go"
if [ -d "$DIR" ]; then
	# Take action if $DIR exists. #
	cd $HOME
  else 
    cd $HOME
	mkdir go
fi

export GO111MODULE=off

echo Get PDFTron-go from GIT

go get github.com/PDFTron/pdftron-go

echo Copying PDFTron-go to go/src

unzip go/src/github.com/PDFTron/pdtron-go/src_mac/pdftron/PDFNetC/Lib/libPDFNetC.zip -d go/src/pdftron/PDFNetC/Lib/
cp -R go/src/github.com/PDFTron/pdftron-go/src_mac/pdftron/ go/src/pdftron/
cp -R go/src/github.com/PDFTron/pdftron-go/Samples/ go/src/pdftron/Samples/

install_name_tool -id "@rpath/libpdftron.dylib" $HOME/go/src/pdftron/PDFNetC/Lib/libpdftron.dylib

# Go to sample directory and run AddImageTest Samples/
cd $HOME/go/src/pdftron/Samples/AddImageTest/GO
chmod +x RunTest.sh
echo -n "Running AddImageTest Sample. This may take a few minutes..."
./RunTest.sh

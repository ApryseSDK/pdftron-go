#!/bin/sh

DIR="%HOME/go"
if [ -d "$DIR" ]; then
	# Take action if $DIR exists. #
	cd $HOME/go
  else 
    cd $HOME
	mkdir go
	cd $HOME/go
fi

export GO111MODULE=off

echo Get PDFTron-go from GIT

go get github.com/PDFTron/pdftron-go

echo Copying PDFTron-go to go/src

cp src/github.com/PDFTron/pdftron-go/src_mac/pdftron/ src/
cp src/github.com/PDFTron/pdftron-go/Samples/ src/pdftron/

install_name_tool -id "@rpath/libpdftron.dylib" $HOME/go/src/pdftron/PDFNetC/Lib/libpdftron.dylib

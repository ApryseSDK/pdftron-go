#!/bin/sh

cd $HOME/go
export GO111MODULE=off

echo Get PDFTron-go from GIT

go get github.com/PDFTron/pdftron-go

echo Copying PDFTron-go to go/src

cp src/github.com/PDFTron/pdftron-go/src_mac/pdftron/ src/
cp src/github.com/PDFTron/pdftron-go/Samples/ src/pdftron/

install_name_tool -id "@rpath/libpdftron.dylib" $HOME/go/src/pdftron/PDFNetC/Lib/libpdftron.dylib

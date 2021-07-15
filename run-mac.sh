#!/bin/sh

cd $HOME/go
export GO111MODULE=off
go get github.com/PDFTron/pdftron-go
mv src/github.com/PDFTron/pdftron-go/src_mac/pdftron/ src/
install_name_tool -id "@rpath/libpdftron.dylib" $HOME/go/src/pdftron/PDFNetC/Lib/libpdftron.dylib

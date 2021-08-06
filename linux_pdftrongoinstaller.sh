#!/bin/sh

cd $HOME

echo Getting PDFTron_go from GIT
go get github.com/PDFTron/pdftron-go

echo Copying PDFTron_go to GO/src
cp src/github.com/PDFTron/pdftron-go/src_linux/pdftron/ src/
cp src/github.com/PDFTron/pdftron-go/Samples/ src/pdftron/

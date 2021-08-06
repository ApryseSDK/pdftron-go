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

echo Getting PDFTron_go from GIT
go get github.com/PDFTron/pdftron-go

echo Copying PDFTron_go to GO/src
cp src/github.com/PDFTron/pdftron-go/src_linux/pdftron/ src/
cp src/github.com/PDFTron/pdftron-go/Samples/ src/pdftron/

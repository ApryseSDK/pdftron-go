#!/bin/sh


DIR="%HOME/go"
if [ -d "$DIR" ]; then
	# Take action if $DIR exists. #
	cd $HOME
  else 
    cd $HOME
	mkdir go
fi

echo Getting PDFTron_go from GIT
go get github.com/PDFTron/pdftron-go

echo Copying PDFTron_go to GO/src
cp go/src/github.com/PDFTron/pdftron-go/src_linux/pdftron/ go/src/
cp go/src/github.com/PDFTron/pdftron-go/Samples/ go/src/pdftron/

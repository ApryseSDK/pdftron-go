#!/bin/sh

cd $HOME/go
mv src/github.com/PDFTron/pdftron-go/src_mac/pdftron/ src/
install_name_tool -id "@rpath/libpdftron.dylib" $HOME/go/src/pdftron/PDFNetC/Lib/libpdftron.dylib

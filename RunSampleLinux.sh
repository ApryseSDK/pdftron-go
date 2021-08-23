#!/bin/sh


#Check the size of System RAM
RAM=$(free -h | grep Mem: | awk '{print $2}')
GOVER=$(go version)
echo "Minimum RAM required is 4GB"
echo "Your RAM is: " $RAM
echo "\n"

#Check the version of Go
echo "Go version requirement is GO 1.15.x and up"
echo "For Ubuntu 14.0.x, only Go version 1.15 would work, as Go 1.16 and up is no longer compatible with the OS"
echo "Your GO is" $GOVER

echo "\n"

echo -n "Do you want to continue? (y/n)? "
read answer


if [ "$answer" != "${answer#[Yy]}" ] ;then
    continue
else
    exit
fi

#Create go folder if it doesnt exist
DIR="%HOME/go"
if [ -d "$DIR" ]; then
	# Take action if $DIR exists. #
	cd $HOME
  else 
    cd $HOME
	mkdir go
fi

# Turn off GO111MODULE for Go 1.16 or higher
export GO111MODULE=off

# Download from Git
echo Getting PDFTron_go from GIT
go get github.com/PDFTron/pdftron-go

# Copy to src folder
echo "Copying PDFTron_go to GO/src"
cp -r go/src/github.com/PDFTron/pdftron-go/src_linux/pdftron/ go/src/
cp -r go/src/github.com/PDFTron/pdftron-go/Samples/ go/src/pdftron/

# Go to sample directory and run AddImageTest Samples/
cd $HOME/go/src/pdftron/Samples/AddImageTest/GO
chmod +x RunTest.sh
echo -n "Running AddImageTest Sample. This may take a few minutes..."
./RunTest.sh

#!/bin/sh

echo "Copying binaries..."
#cp build/namas_main /run/user/1000/gvfs/smb-share\:server\=rpi\,share\=data/
cp build/namas_main /run/user/1000/gvfs/smb-share:server=debian,share=data


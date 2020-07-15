#!/bin/sh

echo "Copying binaries..."
#cp build/namas_main /run/user/1000/gvfs/smb-share\:server\=rpi\,share\=data/
#cp build/namas_main /run/user/1000/gvfs/smb-share:server=rpi,share=data
#cp build/formStyle.css /run/user/1000/gvfs/smb-share:server=rpi,share=data
#cp build/namas_main /media/pi_data/

#cp build/namas_main /run/user/1000/gvfs/smb-share\:server\=debian\,share\=data/ 
#cp build/formStyle.css /run/user/1000/gvfs/smb-share\:server\=debian\,share\=data/ 
scp build/namas_main pi@192.168.1.245:/home/pi/samba/namas_main

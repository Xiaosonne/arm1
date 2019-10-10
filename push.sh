ftp -i -n 192.168.1.241 << EOF
lcd bin
bin
cd /home
put arm1
bye
EOF
echo "COPY SUCCESSFUL"
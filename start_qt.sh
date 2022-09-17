#!/bin/bash

echo "123456" | sudo -S dpkg -i /home/dt/eBUS_SDK_Ubuntu-18.04-x86_64-6.2.8-5877.deb
sleep 6
echo "123456" | sudo -S chmod 777 /dev/ttyS0
sleep 20
cd /home/dt/tobacco_huaian/aaaaa/2022.8.21/2022.8.20/tobacco_v1_0
./tobacco_v1_0 > /home/dt/tobacco_huaian/aaaaa/2022.8.21/2022.8.20/tobacco_v1_0/123.txt

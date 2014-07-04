#!/bin/env bash
cd /opt/firmware/bin
./oam_database >./database.log 2>database.err &
echo $! > osp.pid

echo 0xFFFFFFFF > /proc/sys/kernel/shmmax
echo 64 > /proc/sys/vm/nr_hugepages
sync
echo 1 > /proc/sys/vm/drop_caches
echo 2 > /proc/sys/vm/drop_caches
echo 3 > /proc/sys/vm/drop_caches

cd /opt/firmware/lib/modules
rmmod rapidio.ko
rmmod interrupt.ko
rmmod sys_cpuclock.ko
insmod sys_cpuclock.ko
insmod interrupt.ko
insmod rapidio.ko mod_version=0x41

cd $OLDPWD

./ospd -t main -d -f /opt/firmware/lib/osp/libospmain.so >./ospmain.log 2>ospmain.err &
echo $! >> osp.pid


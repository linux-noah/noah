#!/bin/sh

echo "Run me in root user to avoid warning!"

curl -O http://idylls.jp/noah-blob/arch.tar.lzma
mkdir arch
tar xvf arch.tar.lzma -C arch --strip-components=1

#
# Modify Arch Linux Userspace to do away with VFS
#
ln -s /dev/null arch/dev/null

chmod u+w arch/proc
mkdir arch/proc/self/
echo "none / hfsplus" > arch/proc/self/mounts

rm arch/etc/mtab
ln -s ../proc/self/mounts arch/etc/mtab

rm arch/etc/resolv.conf
ln -s /etc/resolv.conf arch/etc/resolv.conf

rm -rf arch/tmp
ln -s /tmp arch/tmp

rm arch/etc/hostname

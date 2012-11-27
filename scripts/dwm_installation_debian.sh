#!/bin/bash
# Copyright bedis9 <at> gmail <dot> com

cd /usr/src
rm -rf dwm-6.0
apt-get source dwm

cd dwm-6.0

wget http://dwm.suckless.org/patches/dwm-6.0-systray.diff
patch -p1 < dwm-6.0-systray.diff

wget http://dwm.suckless.org/patches/dwm-6.0-pertag.diff
patch -p1 < dwm-6.0-pertag.diff

wget http://dwm.suckless.org/patches/dwm-azertykey.diff
patch -p1 < dwm-azertykey.diff

wget http://dwm.suckless.org/patches/dwm-6.0-focusonclick.diff
patch -p1 < dwm-6.0-focusonclick.diff

wget https://raw.github.com/bedis/dwm/master/patches/dwm-6.0-autostartscript.diff
patch -p1 < dwm-6.0-autostartscript.diff

mv config.h config.h.orig
wget https://raw.github.com/bedis/dwm/master/config/config.h

make


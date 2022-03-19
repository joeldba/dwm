#!/bin/bash
#
# a simple dmenu session script 
#
###

DMENU='dmenu -i -p picom'
choice=$(echo -e "enable\ndisable" | $DMENU | cut -f 1)

case "$choice" in
 "enable") picom --experimental-backends  ;;
 "disable") pkill picom  ;;
esac

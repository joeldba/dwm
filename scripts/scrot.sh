#!/bin/bash
#
# a simple dmenu session script 
#
###

DMENU='dmenu -i -p scrot'
choice=$(echo -e "  desktop (3s delay)\n  selection\n  active window" | $DMENU | cut -f 1)

case "$choice" in
 "  desktop (3s delay)") scrot -d 3 -c  ;;
 "  selection") scrot -s  ;;
 "  active window") scrot -u  ;;
esac

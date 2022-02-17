#!/bin/bash
#
# a simple dmenu session script 
#
###

DMENU='dmenu -i -p dunstctl'
choice=$(echo -e "  pause notifications\n  unpause notifications" | $DMENU | cut -f 1)

case "$choice" in
 "  pause notifications") dunstctl set-paused true  ;;
 "  unpause notifications") dunstctl set-paused false  ;;
esac

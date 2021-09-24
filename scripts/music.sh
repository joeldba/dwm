#!/bin/bash
#
# a simple dmenu session script 
#
###

DMENU='dmenu -i -p music'
choice=$(echo -e "  song list\n  play\n  pause\n  stop\n  next song\n  prev song\n  toggle random\n  toggle single\n  mute\n  vol 35\n  vol 50\n  vol 100" | $DMENU | cut -f 1)

case "$choice" in
 "  song list") $HOME/.config/dwm/scripts/mpdmenu.sh -p ;; 
 "  play") mpc play  ;;
 "  pause") mpc pause  ;;
 "  stop") mpc stop  ;;
 "  next song") mpc next  ;;
 "  prev song") mpc prev ;;
 "  toggle random") mpc random ;;
 "  toggle single") mpc single ;;
 "  mute") mpc vol 0 ;;
 "  vol 35") mpc vol 20 ;;
 "  vol 50") mpc vol 50 ;;
 "  vol 100") mpc vol 100 ;;
esac

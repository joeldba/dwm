#!/bin/bash
#
# a simple dmenu session script 
#
###

DMENU='dmenu -i -p config'
choice=$(echo -e "dwm\nst\ndmenu\nslock\ndwmblocks\nXdefaults\nzshrc\ndunstrc\npicom" | $DMENU | cut -f 1)

case "$choice" in
 "dwm") st -e vim $HOME/.config/dwm/config.h  ;;
 "st") st -e vim $HOME/.config/st/config.h  ;;
 "dmenu") st -e vim $HOME/.config/dmenu/config.h  ;;
 "slock") st -e vim $HOME/.config/slock/config.h  ;;
 "dwmblocks") st -e vim $HOME/.config/dwmblocks/blocks.h  ;;
 "Xdefaults") st -e vim $HOME/.Xdefaults  ;;
 "zshrc") st -e vim $HOME/.zshrc  ;;
 "dunstrc") st -e vim $HOME/.config/dunst/dunstrc  ;;
 "picom") st -e vim $HOME/.config/picom/picom.conf  ;;
esac

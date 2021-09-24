#!/bin/bash
#
# a simple dmenu session script 
#
###

DMENU='dmenu -i -p power'
choice=$(echo -e "  lock\n  logout\n  shutdown\n  reboot" | $DMENU | cut -f 1)

case "$choice" in
 "  lock") slock  ;;
 "  logout") killall Xorg  ;;
 "  shutdown") doas /sbin/poweroff  ;;
 "  reboot") doas /sbin/reboot  ;;
esac

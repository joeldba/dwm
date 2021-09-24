#!/bin/bash
#
# a simple dmenu session script 
#
###

DMENU='dmenu -i -p websites'
choice=$(echo -e "  youtube\n  twitter\n  twitch\n  reddit\n  github\n  wikipedia\n  arch wiki\n  gentoo wiki\n  zugaina" | $DMENU | cut -f 1)

case "$choice" in
 "  youtube") firefox https://www.youtube.com/  ;;
 "  twitter") firefox https://www.twitter.com/ ;;
 "  twitch") firefox https://www.twitch.tv/ ;;
 "  reddit") firefox https://www.reddit.com/  ;;
 "  github") firefox https://www.github.com/ ;;
 "  wikipedia") firefox https://www.wikipedia.org/ ;;
 "  arch wiki") firefox https://wiki.archlinux.org/  ;;
 "  gentoo wiki") firefox https://wiki.gentoo.org/wiki/Main_Page  ;;
 "  zugaina") firefox https://gpo.zugaina.org/ ;;
esac

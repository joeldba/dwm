#!/bin/bash
#
# a simple dmenu session script 
#
###

DMENU='dmenu -i -p favs'
choice=$(echo -e "  firefox\n  discord\n  steam\n  minecraft\n  gzdoom\n  openarena\n  quakespasm\n  quake3\n  ecwolf\n  supertuxkart\n  eduke32\n  ncmpcpp\n  vim\n  libreoffice\n  gimp\n  audacity\n  kdenlive\n  obs-studio\n  virtualbox" | $DMENU | cut -f 1)

case "$choice" in
 "  firefox") firefox;;
 "  discord") discord;;
 "  steam") steam;;
 "  minecraft") minecraft-launcher;;
 "  gzdoom") gzdoom;;
 "  openarena") openarena;;
 "  quakespasm") quakespasm ;;
 "  quake3") quake3 ;;
 "  ecwolf") ecwolf;;
 "  supertuxkart") supertuxkart;;
 "  eduke32") eduke32;;
 "  ncmpcpp") st -e ncmpcpp;; 
 "  vim") st -e vim;;
 "  libreoffice") libreoffice;;
 "  gimp") gimp;;
 "  audacity") audacity;;
 "  kdenlive") kdenlive;;
 "  obs-studio") obs;;
 "  virtualbox") virtualbox;;
esac

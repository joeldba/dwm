#!/bin/sh

xmenu <<EOF | sh &
Applications
	IMG:/home/rwt/.config/xmenu/icons/web.png		Firefox		firefox
	IMG:/home/rwt/.config/xmenu/icons/discord.png		Discord	        discord	
	IMG:/home/rwt/.config/xmenu/icons/steam.png		Steam	        steam
	IMG:/home/rwt/.config/xmenu/icons/gimp.png		GIMP		gimp
	IMG:/home/rwt/.config/xmenu/icons/audacity.png		Audacity	audacity
	IMG:/home/rwt/.config/xmenu/icons/obs.png		OBS		obs	
	IMG:/home/rwt/.config/xmenu/icons/kdenlive.png		Kdenlive	kdenlive
	IMG:/home/rwt/.config/xmenu/icons/virtualbox.png	Virtualbox 	virtualbox
	IMG:/home/rwt/.config/xmenu/icons/libreoffice.png	LibreOffice	libreoffice
	IMG:/home/rwt/.config/xmenu/icons/ncmpcpp.png		Ncmpcpp		st -e ncmpcpp
	IMG:/home/rwt/.config/xmenu/icons/vim.png		Vim		st -e vim

Open terminal		st

Lock			slock
Shutdown		doas poweroff
Reboot			doas reboot
EOF

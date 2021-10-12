#!/bin/sh

xmenu <<EOF | sh &
Applications
	IMG:$HOME/.config/xmenu/icons/web.png		Firefox		firefox
	IMG:$HOME/.config/xmenu/icons/discord.png	Discord	        discord	
	IMG:$HOME/.config/xmenu/icons/steam.png		Steam	        steam
	IMG:$HOME/.config/xmenu/icons/gimp.png		GIMP		gimp
	IMG:$HOME/.config/xmenu/icons/audacity.png	Audacity	audacity
	IMG:$HOME/.config/xmenu/icons/obs.png		OBS		obs	
	IMG:$HOME/.config/xmenu/icons/kdenlive.png	Kdenlive	kdenlive
	IMG:$HOME/.config/xmenu/icons/virtualbox.png	Virtualbox 	virtualbox
	IMG:$HOME/.config/xmenu/icons/libreoffice.png	LibreOffice	libreoffice
	IMG:$HOME/.config/xmenu/icons/ncmpcpp.png	Ncmpcpp		st -e ncmpcpp
	IMG:$HOME/.config/xmenu/icons/vim.png		Vim		st -e vim
Change wallpaper...	nitrogen

Open terminal...
	st	st
	alacritty	alacritty
	xterm		xterm
Open tabbed terminal	tabbed -c -r 2 st -w ''

Lock			slock
Shutdown		doas poweroff
Reboot			doas reboot
EOF

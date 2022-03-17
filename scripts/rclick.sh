#!/bin/sh

xmenu <<EOF | sh &
Applications
	Accessories	
		IMG:$HOME/.config/xmenu/icons/vim.png		Vim		st -e vim
		IMG:$HOME/.config/xmenu/icons/ranger.png	Ranger		st -e ranger
	Audio + Video	
		IMG:$HOME/.config/xmenu/icons/audacity.png	Audacity	audacity
		IMG:$HOME/.config/xmenu/icons/obs.png		OBS		obs	
		IMG:$HOME/.config/xmenu/icons/kdenlive.png	Kdenlive	kdenlive
		IMG:$HOME/.config/xmenu/icons/virtualbox.png	Virtualbox 	virtualbox
		IMG:$HOME/.config/xmenu/icons/ncmpcpp.png	Ncmpcpp		st -e ncmpcpp
	Games
		IMG:$HOME/.config/xmenu/icons/doom.png		GZDoom			gzdoom
		IMG:$HOME/.config/xmenu/icons/quake.png		Quake			quakespasm
		IMG:$HOME/.config/xmenu/icons/quake2.png	Quake 2			yamagi-quake2
		IMG:$HOME/.config/xmenu/icons/quake3.png	Quake 3			quake3	
		IMG:$HOME/.config/xmenu/icons/duke3d.png	Duke Nukem 3D		eduke32
		IMG:$HOME/.config/xmenu/icons/stk.png		SuperTuxKart		supertuxkart
		IMG:$HOME/.config/xmenu/icons/openarena.png	OpenArena		openarena
		IMG:$HOME/.config/xmenu/icons/steam.png		Steam	        steam
	Graphics	
		IMG:$HOME/.config/xmenu/icons/gimp.png		GIMP		gimp
		IMG:$HOME/.config/xmenu/icons/scrot.png		Scrot		scrot -s
	Internet	
		IMG:$HOME/.config/xmenu/icons/web.png		Firefox		firefox
		IMG:$HOME/.config/xmenu/icons/discord.png	Discord	        discord	
	Office
		IMG:$HOME/.config/xmenu/icons/libreoffice.png	LibreOffice Writer	libreoffice --writer
		IMG:$HOME/.config/xmenu/icons/libreoffice.png	LibreOffice Calc	libreoffice --calc
		IMG:$HOME/.config/xmenu/icons/libreoffice.png	LibreOffice Draw	libreoffice --draw
		IMG:$HOME/.config/xmenu/icons/libreoffice.png	LibreOffice Impress	libreoffice --impress
	Settings
		Appearance Settings
			GTK + Icon Settings	lxappearance
			Qt Settings		kvantummanager
		Volume Mixer	st -e pulsemixer
Change wallpaper...	nitrogen

Open terminal...
	st	st
	st (tabbed)	tabbed -c -r 2 st -w ''
	alacritty	alacritty
	urxvt		urxvt
	xterm		xterm
Kill window...		xkill

dwm
	Manual		st -e man dwm
	Edit config 	st -e vim $HOME/.config/dwm/config.h
	Quit 		killall dwm

Lock			slock
Shutdown		sudo poweroff
Reboot			sudo reboot
EOF

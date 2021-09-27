# About dwm
dwm is an extremely fast, small, and dynamic window manager for X.

# Prerequisites:
To build dwm, you will need:
* libx11
* libxft
* libxinerama
* libxcb

For the best possible experience with this build of dwm, you will need the following
* terminus-font
* ttf-font-awesome
* My builds of [st](https://github.com/joeldba/st), [dmenu](https://github.com/joeldba/dmenu), [slock](https://github.com/joeldba/slock), and [dwmblocks](https://github.com/joeldba/dwmblocks)
* My [dotfiles](https://github.com/joeldba/dotfiles)
* picom-tryone
* conky
* mpd + mpc
* scrot

# How do I install it?
To install dwm, run these commands:

* `git clone https://github.com/joeldba/dwm ~/.config/dwm`
* `cd ~/.config/dwm`
* `sudo make clean install`

If using xinit, put `exec dwm` in your .xinitrc and dwm will launch when `startx` is run.

# Extra tidbits
For the script bindings, you will need to replace "/home/rwt" with your own user path in order for the scripts to launch properly.
You may also need to make the scripts themselves executable by running:
`chmod +x ~/.config/dwm/scripts/*.sh`

# What features are there?
Even though the suckless devs had minimalism in mind when making dwm, I've decided to clog it up with a whole bunch of patches, some functional and some for aesthetics. Here's a list of them:
* vanitygaps + layouts
  * Adds gaps inbetween windows, the value of which can be changed in config.h. (default value is 20px for all dimensions) Also comes with a bunch of cool layouts, like spiral, dwindle, bstack, centeredmaster, etc. 
* swallow
  * Any window created by st (or any other terminal specified in config.h) will overlap the entirety of the terminal window, to reduce on-screen clutter. Very useful for viewing images with sxiv, and videos with mpv.
* hide-vacant-tags
  * The bar only shows tags with clients on them, a la i3.
* alternativetags
  * Allows you to temporarily show numbers instead of icons for each tag by pressing Mod+Ctrl+0.
* center
  * Centers newly-created floating windows.
* scratchpad
  * Allows you to show/hide a small, floating terminal window for quick typing or running commands.
* restartsig
  * Adds the ability to restart dwm, by pressing Mod+Shift+R. Making changes is much more of a breeze, as you don't have to completely restart X11 after rebuilding dwm.
* coolautostart
  * Adds a section in config.h where you can define programs/commands that are to be launched when dwm starts.
* actualfullscreen
  * Allows you to make a window entirely fullscreen by pressing Mod+Shift+M.
* movestack
  * Adds the ability to move windows through the master & stack using Mod+Shift+J or K.
* cfacts
  * Allows you to grow/shrink windows within master/stack horizontally using Mod+Shift+H or L
* barpadding
  * Creates a gap around the bar, purely for cosmetic purposes.
* [dwm-border-bar](https://codemadness.org/paste/dwm-border-bar.patch)
  * Creates a purely cosmetic border around the bar. 
* colorbar
  * Enables setting colors for each individual element of the bar.
* statuscolors
  * A patch that enables colors for each status module. This interfaces with my build of dwmblocks. 
* [modified rainbowtags](https://pastebin.com/MpYmWZyp)
  * Each individual tag has a different color. The stock rainbowtags patch on suckless.org only colorized selected tags, whereas this modified version colorizes all of them regardless of selection status. 

# What are the keybindings?
While this information can be gathered from `config.h` I've gone the extra mile and made a table that outlines most of the keybindings for you. The default modkey is `Super`, or the Windows key, as specified in `config.h`. 
However, if you wish to use the Alt key instead, go to the key definitions section and change the MODKEY value from Mod4Mask to Mod1Mask. Be warned however that the Alt key can conflict with keybindings for some programs.
|Action|Key combo|
|:---:|:---:|
|Spawn a terminal|Mod+Enter|
|Close window|Mod+C|
|Open dmenu prompt|Mod+p|
|Open favorite programs menu (configurable via scripts/favorites.sh|Mod+Shift+P|
|Open mpd control menu|Mod+Ctrl+m|
|Open favorite websites menu (configurable via scripts/webfavs.sh)|Mod+Ctrl+w|
|Open config file selection menu (configurable via scripts/config.sh)|Mod+Ctrl+v|
|Open screenshot/scrot menu|Mod+Ctrl+s|
|Open power options menu|Mod+Ctrl+x|
|Move focus right|Mod+k|
|Move focus left|Mod+j|
|Move window right|Mod+Shift+K|
|Move window left|Mod+Shift+J|
|Switch between tags|Mod+1 thru 9 (0 shows all windows on all tags)|
|Go to last tag|Mod+Tab|
|Move focused window between tags|Mod+Shift+1 thru 9 (0 will show focused window on all taga)|
|Show another tag|Mod+Ctrl+1 thru 9|
|Show all windows on all tags|Mod+0|
|Show focused window on all tags|Mod+Shift+0|
|Increase master size|Mod+l|
|Decrease master size|Mod+h|
|Expand window|Mod+Shift+H|
|Shrink window|Mod+Shift+L|
|Make slave master|Mod+Ctrl+Enter|
|Increase amt of masters|Mod+i|
|Decrease amt of masters|Mod+d|
|Toggle float on focused window|Mod+Shift+Space|
|Resize window|Mod+Mouse2|
|Drag window|Mod+Mouse1|
|Toggle bar on/off|Mod+b|
|Default/tall tile layout|Mod+t|
|Horizontal tile layout|Mod+Shift+T|
|Spiral layout|Mod+y|
|Dwindle layout|Mod+Shift+Y
|Centered master layout|Mod+u|
|Centered floating master layout|Mod+Shift+U|
|Grid layout|Mod+g|
|Nrowgrid layout|Mod+Shift+G|
|Monocle layout|Mod+m|
|Floating layout|Mod+f|
|Toggle fullscreen mode for focused window|Mod+Shift+M|
|Enable compositor|Mod+e|
|Disable compositor|Mod+Shift+E|
|Show/hide scratchpad|Mod+s|
|Restart dwm|Mod+Shift+R|
|Quit dwm|Mod+Shift+Q|


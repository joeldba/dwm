# About dwm
dwm is an extremely fast, small, and dynamic window manager for the X11 windowing system. It can manage windows in various tiling and floating/overlapping layouts. 

By default, dwm uses a tiling master/stack layout to manage windows; newly-opened windows are theoretically supposed to be the most important to you, and are thus placed in the master area- whereas older, less important windows are gradually moved deeper into the stack area. 

dwm is configured by directly editing its source code and recompiling- which keeps it simple and secure. The stock build of dwm from suckless.org is relatively minimal, and additional functionality can be implemented by the user via patches.

# Prerequisites:
To build this version of dwm, you will need:
* libx11
* libxft
* libxinerama
* libxcb
* libxrender
* libxrandr
* imlib2

For the best possible experience with this build of dwm, you will need the following
* terminus-font
* ttf-font-awesome
* My builds of [st](https://github.com/joeldba/st), [dmenu](https://github.com/joeldba/dmenu), [slock](https://github.com/joeldba/slock), [dwmblocks](https://github.com/joeldba/dwmblocks), [xmenu](https://github.com/joeldba/xmenu), and [tabbed](https://github.com/joeldba/tabbed)
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
For any keybindings that are used to launch dmenu/xmenu scripts, you will need to replace "/home/rwt" with your own user path in order for the scripts to launch properly. I would use $HOME or '~' but unfortunately there's no way to get those working under dwm as far as I know.
You may also need to make the scripts themselves executable by running:
`chmod +x ~/.config/dwm/scripts/*.sh`

# What features are there?
Even though the suckless devs had minimalism in mind when making dwm, I've decided to clog it up with a whole bunch of patches, some functional and some for aesthetics. Here's a list of them:
* vanitygaps + layouts
  * Adds gaps inbetween windows, the value of which can be changed in config.h. (default value is 15px for all dimensions) Also comes with a bunch of cool layouts, like spiral, dwindle, bstack, centeredmaster, etc. 
* swallow
  * Any window created by st (or any other terminal specified in config.h) will overlap the entirety of the terminal window, to reduce on-screen clutter. Very useful for viewing images with sxiv, and videos with mpv.
* hide-vacant-tags
  * The bar only shows tags with clients on them, a la i3.
* alternativetags
  * Allows you to temporarily show numbers instead of icons for each tag by pressing Mod+Ctrl+0.
* center
  * Centers newly-created floating windows.
* scratchpad
  * Allows you to show/hide a small, floating terminal window for quick typing or running commands, by pressing Mod+grave (or tilde key).
* sticky
  * The currently focused window can be shown on all workspaces by pressing Mod+s.
* hideborder
  * The border of the currently focused window can be hidden by pressing Mod+Shift+B.
* focusonclick
  * When using the mouse, windows must be clicked before they can be focused.
* layoutmenu
  * Using xmenu, a menu of available layouts can be brought up by left-clicking on the layout indicator icon in the bar. 
* cyclelayouts
  * Allows cycling between layouts by pressing Mod + Tab or Mod + Shift + Tab.
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
* killunsel
  * Gives the ability to kill all unfocused windows with Mod+Shift+C.
* stickyindicator
  * Provides an indicator in the bar that shows when a window is sticky.
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
* winicon
  * Shows an icon next to the window title in the bar, when available.

Additional features include various dmenu run prompts, including ones for taking screenshots via scrot, controlling mpd, power options, and favorite programs. All of the scripts used to launch these dmenu prompts are in the `scripts` folder and can be edited with relative ease. 

There is also an Openbox-like menu you can open by right-clicking on the desktop (This requires xmenu to be installed). This desktop right-click menu can be configured by editing the `rclick.sh` file in the `scripts` folder.

# What are the keybindings?
While this information can be gathered from `config.h` I've gone the extra mile and made a table that outlines most of the keybindings for you. 

The default modkey is `Super`, or the Windows key, as specified in `config.h`. However, if you wish to use the Alt key instead, go to the `/* key definitions */` section and change the `MODKEY` value from Mod4Mask to Mod1Mask. Be warned however that the Alt key can conflict with keybindings for some programs.

I've also included keybindings for my build of tabbed which can be found below the dwm bindings.
|Action|Key combo|
|:---:|:---:|
|Spawn terminal|Mod+Enter|
|Spawn tabbed terminal|Mod+Shift+Enter|
|Close window|Mod+C|
|Open dmenu prompt|Mod+p|
|Open favorite programs menu (configurable via scripts/favorites.sh|Mod+Shift+P|
|Open mpd control menu|Mod+Ctrl+m|
|Open favorite websites menu (configurable via scripts/webfavs.sh)|Mod+Ctrl+w|
|Open config file selection menu (configurable via scripts/config.sh)|Mod+Ctrl+v|
|Open screenshot/scrot menu|PrintScr|
|Open power options menu|Mod+Ctrl+x|
|Open dunstctl menu|Mod+Ctrl+z|
|Move focus right|Mod+k|
|Move focus left|Mod+j|
|Move window right|Mod+Shift+K|
|Move window left|Mod+Shift+J|
|Switch between tags|Mod+1 thru 9 (0 shows all windows on all tags)|
|Go to last tag|Mod+Tab|
|Move focused window between tags|Mod+Shift+1 thru 9 (0 will show focused window on all taga)|
|Show another tag|Mod+Ctrl+1 thru 9|
|Show all windows on all tags|Mod+0|
|Make window sticky|Mod+s|
|Increase master size|Mod+l|
|Decrease master size|Mod+h|
|Expand window|Mod+Shift+H|
|Shrink window|Mod+Shift+L|
|Move focused window to master area|Mod+Space|
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
|Cycle layout forward|Mod+Tab|
|Cycle layout backward|Mod+Shift+Tab|
|Enable compositor|Mod+e|
|Disable compositor|Mod+Shift+E|
|Show/hide scratchpad|Mod+s|
|Restart dwm|Mod+Shift+R|
|Quit dwm|Mod+Shift+Q|

Tabbed bindings

|Action|Key combo|
|:---:|:---:|
|Open tab|Ctrl+Shift+Enter|
|Close focused tab|Ctrl+q|
|Shift between tabs|Ctrl+Shift+H/L|
|Move focused tab|Ctrl+Shift+J/K]
|Go to tab|Ctrl+1-9|

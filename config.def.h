/* See LICENSE file for copyright and license details. */

/* general Settings */
/* window settings */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 15;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */

/* bar settings */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 28;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int vertpad            = 15;       /* vertical padding of bar */
static const int sidepad            = 15;       /* horizontal padding of bar */
#define ICONSIZE 14  				/* icon size */
#define ICONSPACING 8 				/* space between icon and title */

/* font settings */
static const char *fonts[]          = { "Terminus:size=8", 
					"FontAwesome5Free:style=Solid:size=8:antialias:true", 
					"FontAwesome5Free:style=Regular:size=8:antialias:true", 
					"FontAwesome5Brands:size=12:antialias:true" };
static const char dmenufont[]       = "Terminus:size=8";

/* gaps settings */
static const unsigned int gappih    = 15;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 15;       /* vert inner gap between windows */
static const unsigned int gappoh    = 15;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 15;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */

/* tag appearance settings */
static const unsigned int ulinepad	= 2;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 2;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

/* colors */
/* background colors */
static const char base0[]      	    = "#00010a";
static const char base1[]      	    = "#0f111a";
static const char base2[]      	    = "#272931";

/* foreground colors */
static const char fg1[]       	    = "#3b4252";
static const char fg2[]             = "#b48ead";
static const char fg3[]             = "#81a1c1";
static const char fg4[]             = "#e5e9f0";
static const char col_borderbar[]   = "#0f111a";

/* other colors (used in statusbar) */
static const char red[]       	    = "#ff4151";
static const char green[]           = "#a3be8c";
static const char yellow[]          = "#ebcb8b";
static const char blue[]       	    = "#81a1c1";

/* color schemes */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] 	  = { fg3,    base1,    base1 },
	[SchemeSel]  	  = { fg4,    base1,    base2 },
	[SchemeRed]       = { red,    base2,    "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeGreen]     = { green,  base2,    "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeYellow]    = { yellow, base2,    "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeBlue]      = { blue,   base2,    "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeStatus]    = { fg4,    base2,    "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeLayout]	  = { blue,  base1,	"#000000"  }, // Layout indicator {text,background,not used but cannot be empty}
        [SchemeInfoSel]   = { fg4,    base1,    "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
        [SchemeInfoNorm]  = { fg4,    base1,    "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* application autostart */
static const char *const autostart[] = {
	"xrdb", "/home/rwt/.Xdefaults", NULL,
	"/home/rwt/.scripts/randomwall/randomwall.sh", NULL,
	"conky", NULL,
	"dunst", NULL,
	"dwmblocks", NULL,
	"picom", "--experimental-backends", NULL,
	NULL /* terminate */
};

/* tagging */
/* tag chars */
static const char *tags[] = { "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  " };
static const char *tagsalt[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const int momentaryalttags = 1; /* 1 means alttags will show only when key is held down*/

/* tag colors */
static const char *tagsel[][2][2] = {
	/*      normal                      selected    */
	/*  fg          bg              fg          bg  */
	{ { "#a3be8c", base1 }, { "#a3be8c", "#272931" } },
	{ { "#ebcb8b", base1 }, { "#ebcb8b", "#272931" } },
	{ { "#8fbcbb", base1 }, { "#8fbcbb", "#272931" } },
	{ { "#88c0d0", base1 }, { "#88c0d0", "#272931" } },
	{ { "#81a1c1", base1 }, { "#81a1c1", "#272931" } },
	{ { "#e5e9f0", base1 }, { "#e5e9f0", "#272931" } },
	{ { "#a3be8c", base1 }, { "#a3be8c", "#272931" } },
	{ { "#ebcb8b", base1 }, { "#ebcb8b", "#272931" } },
	{ { "#b48ead", base1 }, { "#b48ead", "#272931" } },
};

/* window rules */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class              instance  title           tags mask  iscentered  isfloating  isterminal  noswallow  monitor */
	{ "st-256color",        NULL,     NULL,         0, 	   1,         0,          1,           0,        -1 },
	{ "XTerm",        	NULL,     NULL,         0, 	   1,         0,          1,           0,        -1 },
	{ "Alacritty",        	NULL,     NULL,         0, 	   1,         0,          1,           0,        -1 },
	{ "URxvt",        	NULL,     NULL,         0, 	   1,         0,          1,           0,        -1 },
	{ "tabbed",        	NULL,     NULL,         0, 	   1,         0,          1,           0,        -1 },
	{ "Conky",              NULL,     NULL,        	0, 	   0,         1,          0,           1,        -1 },
	{ "firefox",            NULL,     NULL,        	1, 	   0,         0,          0,           0,        -1 },
	{ "discord",            NULL,     NULL,        	1 << 1,    0,         0,          0,           0,        -1 },
	{ "Steam",              NULL,     NULL,        	1 << 3,    0,         0,          0,           0,        -1 },
	{ "Gimp",               NULL,     NULL,        	1 << 4,    0,         0,          0,           0,        -1 },
	{ "Audacity",           NULL,     NULL,        	1 << 5,    0,         0,          0,           0,        -1 },
	{ "kdenlive",           NULL,     NULL,        	1 << 6,    0,         0,          0,           0,        -1 },
	{ "obs",                NULL,     NULL,        	1 << 6,    0,         0,          0,           0,        -1 },
	{ "VirtualBox Manager",	NULL,     NULL,        	1 << 7,    0,         0,          0,           0,        -1 },
	{ NULL,               NULL,     "Event Tester", 0,         0, 	      0,          0,           1,        -1 }, /* xev */
};

/* layout settings */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ " []= ",    tile },    /* first entry is default */
	{ " ><> ",    NULL },    /* no layout function means floating behavior */
 	{ " [M] ",    monocle },
	{ " [@] ",    spiral },
	{ " [\\] ",   dwindle },
	{ " TTT ",    bstack },
	{ " |M| ",    centeredmaster },
	{ " >M> ",    centeredfloatingmaster },
	{ " HHH ",    grid },
	{ " ### ",    nrowgrid },
	{ " --- ",    horizgrid },
	{ " H[] ",    deck },
	{ " === ",    bstackhoriz },
	{ " ::: ",    gaplessgrid },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* command definitions */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, NULL }; /* run prompt */
static const char *termcmd[]  = { "st", NULL }; /* terminal */
static const char *tabtermcmd[]  = { "tabbed", "-r", "2", "st", "-w", "''", NULL }; /* terminal */
static const char *layoutmenu_cmd = "/home/rwt/.config/dwm/scripts/layoutmenu.sh"; /* layout menu */
static const char *rclickcmd[] = { "/home/rwt/.config/dwm/scripts/rclick.sh", NULL }; /* right-click program menu */
static const char scratchpadname[] = "scratchpad"; /* name of the scratchpad */
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "80x24", NULL }; /* scratchpad */
static const char *pwrscript[] = { "/home/rwt/.config/dwm/scripts/power.sh", NULL }; /* power options menu */
static const char *scrotscript[] = { "/home/rwt/.config/dwm/scripts/scrot.sh", NULL }; /* screenshot-taking menu */
static const char *musicscript[] = { "/home/rwt/.config/dwm/scripts/music.sh", NULL }; /* rudimentary mpd control menu */
static const char *favscript[] = { "/home/rwt/.config/dwm/scripts/favorites.sh", NULL }; /* favorite programs menu */
static const char *compon[]  = { "picom", "--experimental-backends", NULL }; /* picom */
static const char *compoff[] = { "pkill", "picom", NULL }; /* kill picom */
static const char *cfgscript[] = { "/home/rwt/.config/dwm/scripts/config.sh", NULL }; /* config file selection menu */
static const char *webscript[] = { "/home/rwt/.config/dwm/scripts/webfavs.sh", NULL }; /* favorite webpages menu */
#include "movestack.c"

/* key bindings */
static Key keys[] = {
	/* START_KEYS */ 
	/* modifier                     key        function        argument */
	/* program/command bindings */	
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ControlMask,		XK_x,	   spawn,	   {.v = pwrscript } },	
	{ 0,				XK_Print,  spawn,	   {.v = scrotscript } },
	{ MODKEY|ControlMask,		XK_m,      spawn,	   {.v = musicscript } },
	{ MODKEY|ControlMask,		XK_p,      spawn,	   {.v = favscript } },
	{ MODKEY|ControlMask,		XK_v,      spawn,	   {.v = cfgscript } },
	{ MODKEY|ControlMask,		XK_w,      spawn,	   {.v = webscript } },
	{ MODKEY,			XK_e,      spawn,	   {.v = compon } },
	{ MODKEY|ShiftMask,		XK_e,      spawn,	   {.v = compoff } },
	{ MODKEY,	                XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,	        XK_Return, spawn,          {.v = tabtermcmd } },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },

	/* window management */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_b,      hideborder,     {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,           		XK_space,  zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefloating, {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY|ShiftMask,             XK_m,      togglefullscr,  {0} },
	{ MODKEY,             		XK_c,      killclient,     {0} },

	/* gaps management */	
	{ MODKEY,              		XK_equal,  incrigaps,      {.i = +5 } },
	{ MODKEY,    			XK_minus,  incrigaps,      {.i = -5 } },
	{ MODKEY|ShiftMask,     	XK_equal,  incrogaps,      {.i = +5 } },
	{ MODKEY|ShiftMask,    		XK_minus,  incrogaps,      {.i = -5 } },
	{ MODKEY|ControlMask|ShiftMask, XK_equal,  defaultgaps,    {0} },	
	{ MODKEY|ControlMask|ShiftMask, XK_minus,  togglegaps,     {0} },

	/* layout switching */
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,		XK_t,	   setlayout,	   {.v = &layouts[5]} },
	{ MODKEY,			XK_y,	   setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,		XK_y,	   setlayout,	   {.v = &layouts[4]} },
	{ MODKEY,			XK_g,	   setlayout,	   {.v = &layouts[8]} },
	{ MODKEY|ShiftMask,		XK_g,	   setlayout,	   {.v = &layouts[9]} },	
	{ MODKEY,			XK_u,	   setlayout,	   {.v = &layouts[6]} },
	{ MODKEY|ShiftMask,		XK_u,	   setlayout,      {.v = &layouts[7]} },	
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	/* tagging */	
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY|ControlMask,           XK_0,      togglealttag,   {0} },	
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

	/* monitor switching */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	/* quitting/restarting */
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} },
	{ MODKEY|ShiftMask, 		XK_q,      quit,           {0} }, 
	/* END_KEYS */
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        layoutmenu,     {0} },	
	{ ClkRootWin,           0,              Button3,        spawn,          {.v = rclickcmd } },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


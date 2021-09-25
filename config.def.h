/* See LICENSE file for copyright and license details. */

/* general Settings */
/* window settings */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 20;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */

/* bar settings */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 28;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int vertpad            = 15;       /* vertical padding of bar */
static const int sidepad            = 15;       /* horizontal padding of bar */

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
static const unsigned int ulinepad	= 4;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 2;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

/* colors */
/* bg colors */
static const char base0[]      	    = "#00010a";
static const char base1[]      	    = "#0f111a";
static const char base2[]      	    = "#272931";

/* fg colors */
static const char fg1[]       	    = "#3b4252";
static const char fg2[]             = "#b48ead";
static const char fg3[]             = "#81a1c1";
static const char fg4[]             = "#e5e9f0";
static const char col_borderbar[]   = "#0f111a";

/* other colors */
static const char red[]       	    = "#ff4151";
static const char green[]           = "#a3bebc";
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
	[SchemeStatus]    = { fg2,    base2,    "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]   = { fg4,    base2,    "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
        [SchemeTagsNorm]  = { fg3,    base1,    "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
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
static const char *tags[] = { "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  ", "  " };

static const char *tagsel[][2] = {
	{ "#ff4151", "#272931" },
	{ "#a3bebc", "#272931" },
	{ "#ebcb8b", "#272931" },
	{ "#81a1c1", "#272931" },
	{ "#b48ead", "#272931" },
	{ "#e5e9f0", "#272931" },
	{ "#ebcb8b", "#272931" },
	{ "#a3bebc", "#272931" },
	{ "#ff4151", "#272931" },
};

/* window rules */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class              instance  title           tags mask  iscentered  isfloating  isterminal  noswallow  monitor */
	{ "st-256color",      NULL,     NULL,           0, 	   1,         0,          1,           0,        -1 },
	{ "Conky",            NULL,     NULL,        	0, 	   0,         1,          0,           1,        -1 },
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
	{ "  tile",       tile },    /* first entry is default */
 	{ "  monocle",    monocle },
	{ "  spiral",     spiral },
	{ "  dwindle",    dwindle },
	{ "  deck",       deck },
	{ "  bstack",     bstack },
	{ "  bshoriz",    bstackhoriz },
	{ "  grid",       grid },
	{ "  nrgrid",     nrowgrid },
	{ "  hgrid",      horizgrid },
	{ "  ggrid",      gaplessgrid },
	{ "  cmaster",    centeredmaster },
	{ "  cfmaster",   centeredfloatingmaster },
	{ "  float",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* command definitions */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "80x24", NULL };
static const char *pwrscript[] = { "/home/rwt/.config/dwm/scripts/power.sh", NULL };
static const char *scrotscript[] = { "/home/rwt/.config/dwm/scripts/scrot.sh", NULL };
static const char *musicscript[] = { "/home/rwt/.config/dwm/scripts/music.sh", NULL };
static const char *favscript[] = { "/home/rwt/.config/dwm/scripts/favorites.sh", NULL };
static const char *compon[]  = { "picom", "--experimental-backends", NULL };
static const char *compoff[] = { "pkill", "picom", NULL };
static const char *cfgscript[] = { "/home/rwt/.config/dwm/scripts/config.sh", NULL };
static const char *webscript[] = { "/home/rwt/.config/dwm/scripts/webfavs.sh", NULL };
#include "movestack.c"

/* key bindings */
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_s,  	   togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
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
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[13]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,		XK_t,	   setlayout,	   {.v = &layouts[5]} },
	{ MODKEY,			XK_y,	   setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,		XK_y,	   setlayout,	   {.v = &layouts[3]} },
	{ MODKEY,			XK_g,	   setlayout,	   {.v = &layouts[7]} },
	{ MODKEY|ShiftMask,		XK_g,	   setlayout,	   {.v = &layouts[8]} },	
	{ MODKEY,			XK_u,	   setlayout,	   {.v = &layouts[11]} },
	{ MODKEY|ShiftMask,		XK_u,	   setlayout,      {.v = &layouts[12]} },	
	{ MODKEY,              		XK_equal,  incrigaps,      {.i = +5 } },
	{ MODKEY,    			XK_minus,  incrigaps,      {.i = -5 } },
	{ MODKEY|ShiftMask,     	XK_equal,  incrogaps,      {.i = +5 } },
	{ MODKEY|ShiftMask,    		XK_minus,  incrogaps,      {.i = -5 } },
	{ MODKEY|ControlMask|ShiftMask, XK_equal,  defaultgaps,    {0} },	
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,		XK_x,	   spawn,	   {.v = pwrscript } },	
	{ MODKEY|ShiftMask,		XK_s,      spawn,	   {.v = scrotscript } },
	{ MODKEY|ShiftMask,		XK_m,      spawn,	   {.v = musicscript } },
	{ MODKEY|ShiftMask,		XK_p,      spawn,	   {.v = favscript } },
	{ MODKEY|ShiftMask,		XK_v,      spawn,	   {.v = cfgscript } },
	{ MODKEY|ShiftMask,		XK_w,      spawn,	   {.v = webscript } },
	{ MODKEY,			XK_e,      spawn,	   {.v = compon } },
	{ MODKEY|ShiftMask,		XK_e,      spawn,	   {.v = compoff } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} },
	{ MODKEY|ShiftMask, 		XK_q,      quit,           {0} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


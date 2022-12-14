/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 16;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 16;       /* vert inner gap between windows */
static const unsigned int gappoh    = 16;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 16;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int vertpad			= 16;		/* vertical padding of bar */
static const int sidepad			= 16;		/* horizontal padding of bar */
static const int horizpadbar		= 0;		/* horizontal padding of statusbar */
static const int vertpadbar			= 12;		/* vertical padding for statusbar */
static const Bool viewontag			= True;		/* Switch view on tag switch */
static const char *fonts[]          = { 
		"JetBrains Mono:style=Bold:size=13", 
		"Font Awesome 6 Brands:size=12",
		"Font Awesome 6 Free:style=Solid:size=12",
		"Font Awesome v4 Compatibility:size=12",
 	};
static const char dmenufont[]       = "JetBrains Mono:style=Bold:size=16";

#include "/home/tim/.config/colorscheme/colors.h"

enum { SchemeNorm, SchemeCol1, SchemeCol2, SchemeCol3, SchemeCol4,
       SchemeCol5, SchemeCol6, SchemeCol7, SchemeSel }; /* color schemes */

static const char *colors[][3]      = {
	/*                fg         	bg         		border   */
	[SchemeNorm]  = { inactive_fg,	inactive_bg, 	inactive_border },
	[SchemeCol1]  = { col1,      	inactive_bg, 	inactive_border },
	[SchemeCol2]  = { col2,      	inactive_bg, 	inactive_border },
	[SchemeCol3]  = { col3,      	inactive_bg, 	inactive_border },
	[SchemeCol4]  = { col4,      	inactive_bg, 	inactive_border },
	[SchemeCol5]  = { col5,      	inactive_bg, 	inactive_border },
	[SchemeCol6]  = { col6,      	inactive_bg, 	inactive_border },
	[SchemeCol7]  = { col7,      	inactive_bg, 	inactive_border },
	[SchemeSel]   = { active_fg, 	active_bg,  	active_border  	},
};

/* tagging */
static const char *tags[] = { "???", "???", "???", "???", "???", "???", "???", "???", "???", "???" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      		instance    title				tags mask		switchtotag		iscentered		isfloating		monitor 	scratchkey */
	{ "Gimp",     		NULL,   	NULL,       		0,     	       	0,				0,				1,           	-1,			0 },
	{ "firefox",  		NULL,   	NULL,       		1 << 4,       	1,				0,				0,           	-1,			0 },
	{ "Chromium",  		NULL,   	NULL,       		1 << 4,       	1,				0,				0,           	-1,			0 },
	{ "discord",  		NULL,   	NULL,       		1 << 2,       	1,				1,				0,           	2,			0 },
	{ "lunarclient",	NULL,   	NULL,   			1 << 3,    		1,				1,				1,           	0,			0 },
	{ "lunarclient",	NULL,   	"Launcher Update",  1 << 3,    		1,				1,				1,           	0,			0 },
	{ "MultiMC5",  		NULL,   	NULL,       		1 << 3,      	1,				1,				1,           	0,			0 },
	{ "Steam",  		NULL,		NULL,       		1 << 3,         1,				0,				0,           	-1,			0 },
	{ "KeePassXC",  	NULL,   	NULL,       		0,     			0,				1,				1,           	-1,			0 },
	{ "Signal",  		NULL,  	 	NULL,       		1 << 7,        	1,				0,				0,           	1,			0 },
	{ "localtube",  	NULL,  	 	NULL,       		0,        	    0,				0,				0,           	-1,			0 },
	{ "Yad",  		    NULL,  	 	NULL,       		0,        	    0,				0,				1,           	0,			0 },
	{ "scrcpy",	      	NULL,		NULL, 	            0,	    	    0,				0,				1,	 			0,			0 },
	{ "obs",	      	NULL,		NULL, 	            1 << 9,	        0,				0,				0,	 		    2,			0 },
	{ "Gcolor3",	    NULL,		NULL, 	            0,	    	    0,				1,				1,	 			0,			0 },
	{ "Thunar", 	    NULL,		NULL, 	            0,	    	    0,				1,				1,	 			0,			0 },
	{ "mpv",	        NULL,		NULL, 	            0,	    	    0,				1,				1,	 			0,			0 },
	{ "bitcoin-qt",     NULL,		NULL, 	            0,	    	    0,				1,				1,	 			-1,			0 },
	{ NULL,	      		NULL,		"Picture in picture", 	0,	    	0,				0,				1,	 			0,			0 },
	{ NULL,	      		NULL,		"File Operation Progress",  0,	    0,				1,				1,	 			0,			0 },
	{ NULL,       		NULL,   	"scratchpad",   	0,            	0,				1,				1,           	-1,       	's' },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "???",      tile },    /* first entry is default */
	{ "???",      NULL },    /* no layout function means floating behavior */
	{ "[M]",    monocle },
	{ "[@]",    spiral },
	{ "[\\]",   dwindle },
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

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", inactive_bg, "-nf", inactive_fg, "-sb", active_border, "-sf", active_fg, NULL };
static const char hplist[] = "codium,vscodium,chromium,gimp,thunderbird,signal-desktop,discord,obs,lunarclient,multimc,spt-init,keepassxc-sync,freetube,idea,localtube";
static const char *dmenucmd[] = { "dmenu_run", "-hp", hplist, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *appbarcmd[]  = { "eww", "open", "appbar", NULL };

#include "selfrestart.c"
#include <X11/XF86keysym.h>

/* First arg only serves to match against key in rules */
static const char *scratchpadcmd[] = {"s", "st", "-t", "scratchpad", "-g", "110x32", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_v,      spawn,          {.v = appbarcmd } },
	{ 0,                            XF86XK_AudioMute,spawn,    SHCMD("amixer set Master toggle && sigdwmblocks 6") },
	{ 0,                            XF86XK_AudioRaiseVolume,spawn,SHCMD("/home/tim/.local/bin/dwmb/sb-music/set-volume.sh +5% && sigdwmblocks 9") },
	{ 0,                            XF86XK_AudioLowerVolume,spawn,SHCMD("/home/tim/.local/bin/dwmb/sb-music/set-volume.sh -5% && sigdwmblocks 9") },
	//{ 0,                            XF86XK_AudioRaiseVolume,spawn,SHCMD("sptvolume=$(spt playback -f %v) && spt playback --volume \"$(((sptvolume += 5) > 100 ? 100 : (sptvolume < 0 ? 0 : sptvolume)))\"") },
	//{ 0,                            XF86XK_AudioLowerVolume,spawn,SHCMD("sptvolume=$(spt playback -f %v) && spt playback --volume \"$(((sptvolume -= 5) > 100 ? 100 : (sptvolume < 0 ? 0 : sptvolume)))\"") },
	{ 0,                            XF86XK_AudioPrev,spawn,    SHCMD("spt playback -p") },
	{ 0,                            XF86XK_AudioNext,spawn,    SHCMD("spt playback -n") },
	{ 0,                            XF86XK_AudioPlay,spawn,    SHCMD("spt playback -t") },
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY,                       XK_e,      incrgaps,       {.i = -1 } },
	{ MODKEY,                       XK_g,      togglegaps,     {0} },
	{ MODKEY|ShiftMask,             XK_g,      defaultgaps,    {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
    { MODKEY|ShiftMask,		        XK_s,	   spawn,	       SHCMD("maim -s -u | xclip -selection clipboard -t image/png -i") },
    { MODKEY,		                XK_c,	   spawn,	       SHCMD("gcolor3 | tr -d '\n' | xclip -selection clipboard") },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_a,      togglealwaysontop, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
    TAGKEYS(                        XK_0,                      9)
	{ MODKEY|ShiftMask,             XK_o,      self_restart,   {0} },
	// { MODKEY|ShiftMask,				XK_o,	   quit,		   {1} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_Escape, spawn,          SHCMD("byebye") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} }, // scroll up
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} }, // scroll down
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} }, // shift click
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

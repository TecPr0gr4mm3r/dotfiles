/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gap pixel between windows */
static const unsigned int snap      = 5;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */

static const char *fonts[]          = { "monospace:size=10" };
static const char col_gray1[]       = "#000000"; /* Non-activated bar background */
static const char col_gray2[]       = "#000000"; /* Non-activated window border */
static const char col_gray3[]       = "#C0C0C0"; /* Non-activated bar background */
static const char col_gray4[]       = "#C0C0C0"; /* activated bar background */
static const char col_cyan[]        = "#4d4b4b"; /* activated window border */
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6","7", "8", "9" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     iscentered     isfloating   monitor */
	{ "firefox",  NULL,       NULL,     	1 << 1,       0,             0,           -1 },
	{ "Brave-browser",  NULL,       NULL,     	1 << 1,       0,             0,           -1 },

	{ "Filezilla",		NULL,		NULL,	0,	-1,	-1,		-1 },
	{ "MEGAsync",		NULL,		NULL,	0,	-1,	-1,		-1 },
	{ "CenterTerminal",		NULL,		NULL,	0,	-1,	-1,		-1 },
	{ "Gimp",		NULL,		NULL,		1 <<  2,	0,	0,		-1 },
	{ "Olive",	NULL,		NULL,	1 <<  3,	0,	0,		-1 },
	{ "QBitorrent",		NULL,		NULL,	1 <<  5,	0,	0,		-1 },
	{ "Subl3",  NULL,       NULL,      		1 << 2,       0,             0,           -1 },
	{ "kdenlive",	NULL,		NULL,	1 <<  3,	0,		-1 },
	{ "REAPER",	NULL,		NULL,	1 <<  7,	0,		-1 },
/*	{ "Pcmanfm",	NULL,		NULL,	1 <<  3,	0,		0 }, */
/*	{ "mpv",	NULL,		NULL,	1 <<  4,	0,		0 }, */
	{ "TelegramDesktop",	NULL,		NULL,	1 <<  6,	0,		0 },
};

/* layout(s) */
/* static const float mfact     = 0.70;  factor of master area size [0.05..0.95] */
static const float mfact     = 0.51;  /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "t",      tile },    /* first entry is default */
	{ "f",      NULL },    /* no layout function means floating behavior */
	{ "m",      monocle },
	{ "g",      gaplessgrid },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} },
static const char *dmenu[] = { "dmenu_run", "-i", "-l", "4", NULL};
static const char *pcmanfm[] = {"pcmanfm",NULL};
static const char *telegramapp[] = {"telegram-desktop"};

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,			XK_d,	   	spawn, {.v = dmenu } },
	{ MODKEY,		XK_Return, 	spawn, SHCMD("st")},
	{ ShiftMask,		XK_q, 	spawn, SHCMD("pkill mpv;pkill sxiv")},
	{ MODKEY|ShiftMask,		XK_Return, 	spawn, SHCMD("st -c CenterTerminal") },
	{ MODKEY|ShiftMask,		XK_n,	   	spawn,	SHCMD("symbols") },
	{ MODKEY|ShiftMask,		XK_r,	   	spawn,	SHCMD("killdwm") },
	{ MODKEY|ShiftMask,		XK_w,	   	spawn,	SHCMD("words") },
	{ MODKEY,			XK_y,	  	spawn,	SHCMD("yt") },
	{ ShiftMask,  XK_v,		spawn,	{.v = pcmanfm } },
	{ ShiftMask, 					XK_t, spawn, {.v =telegramapp}},

	{ ShiftMask,			XK_d,		spawn,	SHCMD("amixer sset Master 5%- ; pkill -RTMIN+10 dwmblocks") },
	{ ShiftMask,			XK_m,		spawn,	SHCMD("amixer sset Master toggle ; pkill -RTMIN+10 dwmblocks") },
	{ ShiftMask,			XK_u,		spawn,	SHCMD("amixer sset Master 5%+ ; pkill -RTMIN+10 dwmblocks") },
	{ ShiftMask,			XK_l,		spawn,	SHCMD("emojis") },
	{ ShiftMask,			XK_w,		spawn,	SHCMD("wp") },

	{ ShiftMask,			XK_p,		spawn,	SHCMD("audacious --play") },

	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_k,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = -1 } },

	{ MODKEY,                       XK_comma,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_period,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_r, 	   zoom,           {0} },
    { MODKEY,             XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,				XK_q,	   spawn,  SHCMD("xdotool getwindowfocus windowki") },
	{ MODKEY|ShiftMask,				XK_s,	   spawn,  SHCMD("class") },
	{ MODKEY|ShiftMask,				XK_c,	   spawn,  SHCMD("xbacklight -dec 5")},
	{ MODKEY|ShiftMask,				XK_x,	   spawn,  SHCMD("xbacklight -inc 5")},
	{ MODKEY|ShiftMask,		XK_e,	  	spawn,	SHCMD("dmn_power") },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },

	{ MODKEY,            			XK_f,  togglefloating, {0} },
	{ MODKEY, 			            XK_c,  setcentered, {0} },
	{ MODKEY,                 	  	XK_t,  setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,                    XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,                    XK_t,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,                    XK_g,      setlayout,      {.v = &layouts[3]} },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

/* See LICENSE file for copyright and license details. */

/* autostart script path */
static const char autostartscript[] = "/home/bassmann/.config/dwm/autostart.sh";

/* appearance */
static const char font[]            = "-*-terminus-medium-r-*-*-12-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#444444";
static const char normbgcolor[]     = "#222222";
static const char normfgcolor[]     = "#bbbbbb";
static const char selbordercolor[]  = "#ffffff";
static const char selbgcolor[]      = "#005577";
static const char selfgcolor[]      = "#eeeeee";
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const unsigned int gappx     = 0;        /* gap pixel between windows */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const Bool showsystray       = True;     /* False means no systray */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */
static const Bool clicktofocus      = True;     /* Change focus only by clicking */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Dia",      NULL,       NULL,       0,            True,        -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       False,       -1 },
	{ "Gimp",     NULL,       NULL,       0,            True,        -1 },
};

/* layout(s) */
static const float mfact      = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
//	{ "[]=",      tile },    /* first entry is default */
//	{ "><>",      NULL },    /* no layout function means floating behavior */
//	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define WINDOWKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
#define MYXTERM "/home/bassmann/bin/myxterm"
//"x-terminal-emulator",
static const char *browsercmd[]  = { "chrome", NULL };
static const char *dmenucmd[]    = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *gvimcmd[]     = { "gvim", NULL };
static const char *sndctrlcmd[]  = { MYXTERM, "alsamixer", NULL };
static const char *termcmd[]     = { MYXTERM, NULL };
static const char *muacmd[]      = { MYXTERM, "mutt", NULL };
static const char *irccmd[]      = { MYXTERM, "irssi", NULL };
static const char *screensavercmd[] = { "/usr/bin/xscreensaver-command", "-lock", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_z,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_e,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_f,      spawn,          {.v = browsercmd } },
	{ MODKEY,                       XK_g,      spawn,          {.v = gvimcmd } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_i,      spawn,          {.v = irccmd } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ WINDOWKEY,                    XK_l,      spawn,          {.v = screensavercmd } },
	{ MODKEY,                       XK_m,      spawn,          {.v = muacmd } },
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_s,      swapfocus,      {0} },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = sndctrlcmd } },
	{ MODKEY,                       XK_x,      spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_agrave, view,           {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_agrave, tag,            {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_ampersand,              0)
	TAGKEYS(                        XK_eacute,                 1)
	TAGKEYS(                        XK_quotedbl,               2)
	TAGKEYS(                        XK_apostrophe,             3)
	TAGKEYS(                        XK_parenleft,              4)
	TAGKEYS(                        XK_minus,                  5)
	TAGKEYS(                        XK_egrave,                 6)
	TAGKEYS(                        XK_underscore,             7)
	TAGKEYS(                        XK_ccedilla,               8)
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


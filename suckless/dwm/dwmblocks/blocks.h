//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"m", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},
	{"v", "vol", 40, 10},
	{"d","date +'📆%b %d (%a)|🕓%I:%M%p'", 40, 0 },
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = '|';

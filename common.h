#ifndef COMMON_H
#define COMMON_H

#define POINTSIZE 4
#define MATH_PI 3.14159265359

struct point
{
	short int x;
	short int y;
};

struct dwindsize
{
	int x1, y1, x2, y2;
};

struct text
{
	char **textstr;
	int strnum;
};

enum STATUSBAR {
	MMENU,
	DWINDOW,
	SWINDOW
};

enum PROGRAMSTATUS {
	LOADING_SCREEN,
	MAINMENU,
	HELP,
	ABOUT,
	STARTMENU
};

#endif // COMMON_H
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
	char str1[40];
};

enum STATUSBAR {
	MMENU,
	DWINDOW,
	SWINDOW,
	RANDDESKWINDOW,
	FILEDESKWINDOW,
	INPUTWINDOW,
	FILECHOOSEWINDOW,
	DELETEWINDOW
};

enum PROGRAMSTATUS {
	LOADING_SCREEN,
	MAINMENU,
	HELP,
	ABOUT,
	STARTMENU,
	STDDESK,
	RANDCMENU,
	FILECMENU
};

#endif // COMMON_H
#ifndef COMMON_H
#define COMMON_H

#define POINTSIZE 4
#define MATH_PI 3.14159265359

struct point
{
	short int x;
	short int y;
};

enum PROGRAMSTATUS {
	LOADING_SCREEN,
	MAINMENU
};

#endif // COMMON_H
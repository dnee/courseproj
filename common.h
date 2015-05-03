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

enum ANGLESTATUS
{
	PO, PT, VO, VT, LO, LT, NO, NT, PPV, PPN, LPV, LPN
};

#endif // COMMON_H
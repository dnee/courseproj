#include <stdlib.h>
#include <ctime>
#include "pgraph.h"

extern "C"
{
#include "pdata.h"
#include "plogic.h"
#include "pfile.h"
#include "common.h"
}


int main()
{
	initiategraph();
	srand(time(NULL));
	setcolor(9);
	short int pointsnum = 0;
	//struct point *points = generatepoints(pointsnum);
	//int x = putpoints("5.txt", points, pointsnum);
	//printf("%d\n", x);
	struct point *points = getpoints("100.txt", &pointsnum);
	drawpoints(points, pointsnum);
	//drawpoly(points, pointsnum);
	pointsnum = findpoints(points, pointsnum);
	setcolor(10);
	drawpoly(points, pointsnum);
	getch();
	//enum PROGRAMSTATUS status = MAINMENU;
	//while (1)
	//{
	//	switch (status)
	//	{
	//	case LOADING_SCREEN:
	//		loadingscr();
	//		status = MAINMENU;
	//		getch();
	//		break;
	//	case MAINMENU:
	//		cleardevice();
	//		drawmainmenu();
	//		getch();
	//		exit(0);
	//		break;
	//	default:
	//		break;
	//	}
	//}
	//return 0;
}
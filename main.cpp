#include <stdlib.h>
#include <ctime>
#include "pgraph.h"

extern "C"
{
#include <math.h>
#include "pdata.h"
#include "plogic.h"
#include "pfile.h"
#include "common.h"
}


int main()
{
	initiategraph();
	srand(time(NULL));
	short int pnum;
	struct point *points = getpoints("yolo.txt", &pnum);
	setcolor(4);
	//drawpoly(points, pnum);
	setcolor(8);
	pnum = findpoints(points, pnum);
	drawpoly(points, pnum);
	setcolor(13);
	drawfence(points, pnum, 10);
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
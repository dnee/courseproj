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
	//putpixel(100, 100, 13);
	//arc(100, 100, 0, 10, 20);
	//setcolor(9);
	//line(100, 100, 600, 100);
	//line(600, 100, 600, 500);
	//line(100, 100, 100, 500);
	//line(100, 500, 600, 500);
	short int pointsnum, fp = 3;
	//struct point *points = generatepoints(pointsnum);
	//int x = putpoints("5.txt", points, pointsnum);
	//printf("%d\n", x);
	struct point points[3] = { { 200, 200 }, { 100, 150 }, { 100, 250 } };
	drawpoly(points, fp);
	//fp = findpoints(points, pointsnum);
	setcolor(10);
	//drawpoly(points, fp);
	setcolor(13);
	//test(points, fp);
	//drawpoly(points, fp);
	drawfence(points, fp, 10);
	//drawpoly(points, pointsnum);
	//drawpoly(points, pointsnum);
	//pointsnum = findpoints(points, pointsnum);
	//setcolor(10);
	//drawpoly(points, pointsnum);
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
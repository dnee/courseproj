#include "pdata.h"

struct point *generatepoints(const short int pointsnum)
{
	short int half = pointsnum / 2, i;
	short int dx = 500 / half * 2, dy = 200 / half * 2, cx = 100, cy = 300;
	struct point *points = (struct point *)malloc(pointsnum * POINTSIZE);
	if (points == NULL)
		exit(1);
	for (i = 0; i < half; i++)
	{
		points[i].x = cx;
		points[i].y = cy;
		if (i % 2 == 0)
			cx += dx;
		else
			cy -= dy;
	}
	cy += 200;
	for (; i < 2* half; i++)
	{
		points[i].x = cx;
		points[i].y = cy;
		if (i % 2 == 0)
			cx -= dx;
		else
			cy += dy;
	}
	//for (; i < 2 * quatter; i++)
	//{
	//	points[i].x = cx;
	//	points[i].y = cy;
	//	if (i % 2 == 0)
	//		cx += dx;
	//	else
	//		cy += dy;
	//}
	//for (; i < 3 * quatter; i++)
	//{
	//	points[i].x = cx;
	//	points[i].y = cy;
	//	if (i % 2 == 0)
	//		cx -= dx;
	//	else
	//		cy += dy;
	//}
	//for (; i < 4 * quatter; i++)
	//	{
	//		points[i].x = cx;
	//		points[i].y = cy;
	//		if (i % 2 == 0)
	//			cx -= dx;
	//		else
	//			cy -= dy;
	//	}


	//for (int i = 0; i < pointsnum; i++)
	//{
	//	points[i].x = rand() % 500 + 100;
	//	points[i].y = rand() % 300 + 100;
	//	while (1)
	//	{
	//		containpoint = 0;
	//		for (int j = 0; j < i && !containpoint; j++)
	//			if (points[j].x == points[i].x && points[j].y == points[i].y)
	//				containpoint = 1;
	//		if (containpoint)
	//		{
	//			points[i].x = rand() % 500 + 100;
	//			points[i].y = rand() % 400 + 100;
	//		}
	//		else
	//			break;
	//	}
	//}
	return points;
}
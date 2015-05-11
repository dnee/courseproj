#include "pgraph.h"

void initiategraph()
{
	initwindow(800, 600, "Zabor");
}

void drawcentermask()
{
	setlinestyle(0, 0, 1);
	setfillstyle(1, 1);
	line(400, 0, 400, 600);
	line(0, 300, 800, 300);
}

void drawfence(const struct point *points, const short int pointsnum, const short int radius)
{
	struct point prev = points[pointsnum - 1], current, next;
	int dx1, dy1, dx2, dy2, bchange;
	float angle1, angle2;
	for (int i = 0; i < pointsnum; i++)
	{
		bchange = 1;
		dx1 = 0; dy1 = 0;
		dx2 = 0; dy2 = 0;
		current = points[i];
		if (i == pointsnum - 1)
			next = points[0];
		else
			next = points[i+1];
		angle1 = findangle(prev, current);
		angle2 = findangle(current, next);
		finddelta(&dx1, &dy1, angle1, radius);
		finddelta(&dx2, &dy2, angle2, radius);
		line(prev.x + dx1, prev.y + dy1, current.x + dx1, current.y + dy1);
		if ((angle1 > 315.0f || angle1 <= 45.0f) && (angle2 > 315.0f || angle2 <= 45.0f))
			bchange = 0;
		else if ((angle1 > 45.0f && angle1 <= 135.0f) && (angle2 > 45.0f && angle2 <= 135.0f))
			bchange = 0;
		else if ((angle1 > 135.0f && angle1 <= 225.0f) && (angle2 > 135.0f && angle2 <= 225.0f))
			bchange = 0;
		else if ((angle1 > 225.0f && angle1 <= 315.0f) && (angle2 > 225.0f && angle2 <= 315.0f))
			bchange = 0;
		if (bchange)
		{
			struct point temp;
			temp.x = current.x + dx1; temp.y = current.y + dy1;
			int sta = (int)findangle(current, temp);
			temp.x = current.x + dx2; temp.y = current.y + dy2;
			int ena = (int)findangle(current, temp);;
			arc(current.x, current.y, sta, ena, radius);
		}
		prev = current;
	}
}

void drawpoly(const struct point *points, const short int pointsnum)
{
	int *poly = (int *)malloc((pointsnum * 2 + 2) * sizeof(int));
	if (poly == NULL)
		exit(1);
	*poly = points[pointsnum - 1].x;
	*(poly + 1) = points[pointsnum - 1].y;
	for (int i = 0; i < pointsnum; i++)
	{
		*(poly + 2 + i * 2) = points[i].x;
		*(poly + 3 + i * 2) = points[i].y;
	}
	drawpoly(pointsnum + 1, poly);
	free(poly);
}

void drawpoints(const struct point *points, const short int pointsnum)
{
	for (int i = 0; i < pointsnum; i++)
		putpixel(points[i].x, points[i].y, 9);
}


void drawmainmenu(int param)
{
	drawcentermask();
	setfillstyle(1, 14);
	bar(75, 100, 100, 150);
	bar(75, 200, 100, 250);
	bar(75, 300, 100, 350);
	bar(75, 400, 100, 450);
	setfillstyle(1, 6);
	bar(100, 100, 250, 150);
	bar(100, 200, 250, 250);
	bar(100, 300, 250, 350);
	bar(100, 400, 250, 450);
	//line(175, 0, 175, 600);//середина кнопки
	outtextxy(117, 113, "START");
	outtextxy(130, 213, "HELP");
	outtextxy(113, 313, "ABOUT");
	outtextxy(130, 413, "EXIT");
	setfillstyle(1, 4);
	bar(75, 100 + 100 * param, 100, 150 + 100 * param);
}

char getkey()
{
	char ch1, ch2;
	ch1 = getch();
	if (ch1 == 0)
	{
		ch2 = getch();
		return ch2;
	}
	else
		return ch1;
}

void drawloadingscr()
{
	drawcentermask();
	int poly[6];
	int i = 0, j = 0;
	setfillstyle(1, 14);
	bar(30, 30, 176, 82); //¬нешн€€ рамка "ZABOR"
	bar(0, 44, 30, 50); // ¬ерхн€€ палка
	bar(0, 62, 30, 68); // Ќижн€€ палка
	setfillstyle(1, 6);
	//setbkcolor(6); //замена черного фона
	bar(40, 40, 166, 72); //¬нутрен€€ рамка "ZABOR"
	outtextxy(41, 45, "ZABOR");
	//setbkcolor(0); //черный фон
	outtextxy(330, 190, "Loading...");
	setlinestyle(0, 0, 1);
	setcolor(6);
	//while (i < 640) {
	//	line(i, 240, i, 250);
	//	delay(rand() % 2);
	//	if (i < 620 && i > 150)
	//		for (; j < i - rand() % 150; j++)
	//			line(j, 340, j, 350);
	//	else if (i > 150)
	//		for (; j <= i; j++)
	//			line(j, 340, j, 350);
	//	i++;
	//}
	//setcolor(14);
	//poly[0] = 15;
	//poly[1] = 230;
	//poly[2] = 40;
	//poly[3] = 200;
	//poly[4] = 65;
	//poly[5] = 230;
	//fillpoly(3, poly);
	//for (i = 0; i < 8; i++)
	//{
	//	if (i > 4)
	//		delay(200);
	//	delay(150 + rand() % 80 - 40);
	//	bar(15 + i * 80, 230, 65 + i * 80, 380);
	//	fillpoly(3, poly);
	//	for (j = 0; j < 6; j++)
	//		if (j % 2 == 0)
	//			poly[j] += 80;
	//}
}
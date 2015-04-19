#include "pgraph.h"

void initiategraph()
{
	initwindow(800, 600, "Zabor");
}

void testgr()
{
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(0, HORIZ_DIR, 0);
	outtextxy(100, 100, "test");
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


void drawmainmenu()
{
	bar(350, 150, 450, 175);
	bar(350, 250, 450, 275);
	bar(350, 350, 450, 375);
}

void loadingscr()
{
	int poly[6];
	int i = 0, j = 0;
	setfillstyle(1, 6);
	bar(30, 30, 145, 80);
	bar(0, 40, 30, 46);
	bar(0, 63, 30, 69);
	setfillstyle(1, 14);
	bar(40, 40, 135, 70);
	settextstyle(0, HORIZ_DIR, 2);
	outtextxy(48, 48, "ZABOR");
	outtextxy(245, 120, "Loading...");
	setlinestyle(0, 0, 1);
	setcolor(6);
	while (i < 640) {
		line(i, 240, i, 250);
		delay(rand() % 2);
		if (i < 620 && i > 150)
			for (; j < i - rand() % 150; j++)
				line(j, 340, j, 350);
		else if (i > 150)
			for (; j <= i; j++)
				line(j, 340, j, 350);
		i++;
	}
	setcolor(14);
	poly[0] = 15;
	poly[1] = 230;
	poly[2] = 40;
	poly[3] = 200;
	poly[4] = 65;
	poly[5] = 230;
	fillpoly(3, poly);
	for (i = 0; i < 8; i++)
	{
		if (i > 4)
			delay(200);
		delay(150 + rand() % 80 - 40);
		bar(15 + i * 80, 230, 65 + i * 80, 380);
		fillpoly(3, poly);
		for (j = 0; j < 6; j++)
			if (j % 2 == 0)
				poly[j] += 80;
	}
}
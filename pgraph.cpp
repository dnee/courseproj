#include "pgraph.h"

void initiategraph()
{
	initwindow(800, 600, "Zabor");
}

void drawfence(const struct point *points, const short int pointsnum, const short int radius)
{
	struct point base = points[pointsnum - 1], prev = points[pointsnum - 1], current = points[0], next;
	float angle;
	if (points == NULL)
		exit(1);
	for (int i = 0; i < pointsnum; i += 2)
	{
		current = points[i];
		if (i == pointsnum - 1)
			next = points[0];
		else
			next = points[i+1];
		char t = findangle(prev, current, next, &angle);
		float dx, dy;
		findcoords(&dx, &dy, prev, current, radius, 0);
		switch (t)
		{
		case 0:
			line(prev.x, prev.y + radius, current.x, current.x + radius);
			line(current.x + (int)dx2, current.y - (int)dy2, next.x + (int)dx2, next.y - (int)dy2);
			//arc(current.x, current.y, 270 + (180 - angle) / 2, 270 + (180 - angle) / 2 + angle, radius);
			printf("PO angle= %f\n", angle);
			break;
		case 1:
			break;
		case 2:
			line(prev.x, prev.y - radius, current.x, current.y - radius);
			line(current.x, current.y - radius, next.x, next.y - radius);
			//arc(current.x, current.y, (180 - angle) / 2, (180 - angle) / 2 + angle, radius);
			printf("VO angle= %f", angle);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			line(prev.x - radius, prev.y, current.x - radius, current.y);
			break;
		case 6:
			//line(prev.x - (int)dx1, prev.y/* - (int)dy1*/, current.x - (int)dx1, current.y/* - (int)dy1*/);
			//line(current.x + (int)dx2, current.y /*+ (int)dy2*/, next.x + (int)dx2, next.y /*+ (int)dy2*/);
			//printf("NO angle= %f", angle);
			break;
		case 7:
			line(prev.x, prev.y + radius, current.x, current.y + radius);
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		}
		prev = next;
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
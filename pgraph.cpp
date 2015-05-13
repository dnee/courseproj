#include "pgraph.h"

void initiategraph()
{
	initwindow(800, 600, "Zabor");
}

void drawcentermask()
{
	setlinestyle(0, 0, 1);
	setfillstyle(1, 1);
	line(395, 0, 395, 590);
	line(0, 295, 790, 295);
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
	setfillstyle(1, 14);
	bar(75, 100, 100, 150);
	bar(75, 200, 100, 250);
	bar(75, 300, 100, 350);
	bar(75, 400, 100, 450);
	bar(250, 100, 275, 150);
	bar(250, 200, 275, 250);
	bar(250, 300, 275, 350);
	bar(250, 400, 275, 450);
	setfillstyle(1, 6);
	bar(100, 100, 250, 150);
	bar(100, 200, 250, 250);
	bar(100, 300, 250, 350);
	bar(100, 400, 250, 450);
	setbkcolor(6);
	outtextxy(117, 113, "START");
	outtextxy(130, 213, "HELP");
	outtextxy(113, 313, "ABOUT");
	outtextxy(130, 413, "EXIT");
	setbkcolor(0);
	setfillstyle(1, 4);
	bar(75, 100 + 100 * param, 100, 150 + 100 * param);
	bar(250, 100 + 100 * param, 275, 150 + 100 * param);
	setfillstyle(1, 14);
	if (param != 0)
	{
		bar(75, 100 + 100 * (param - 1), 100, 150 + 100 * (param - 1));
		bar(250, 100 + 100 * (param - 1), 275, 150 + 100 * (param - 1));
	}
	if (param != 3)
	{
		bar(75, 100 + 100 * (param + 1), 100, 150 + 100 * (param + 1));
		bar(250, 100 + 100 * (param + 1), 275, 150 + 100 * (param + 1));
	}
}

void drawloadingscr()
{
	int poly[6];
	int i = 0, j = 0;
	setfillstyle(1, 14);
	bar(30, 30, 176, 82); //Âíåøíÿÿ ðàìêà "ZABOR"
	bar(0, 44, 30, 50); // Âåðõíÿÿ ïàëêà
	bar(0, 62, 30, 68); // Íèæíÿÿ ïàëêà
	setfillstyle(1, 6);
	bar(40, 40, 166, 72); //Âíóòðåíÿÿ ðàìêà "ZABOR"
	setbkcolor(6);
	outtextxy(41, 45, "ZABOR");
	setbkcolor(0);
	outtextxy(330, 190, "Loading...");
	setlinestyle(0, 0, 1);
	int pflineoffset = 0;
	int pslineoffset = 0;
	for (int i = 1; i < 5; i++)
	{
		int flineoffset;
		int slineoffset;
		if (i != 4)
		{
			flineoffset = rand() % (260 * i) + pflineoffset + 1;
			slineoffset = rand() % (260 * i) + pslineoffset + 1;
		}
		else
		{
			flineoffset = 790;
			slineoffset = 790;
		}
		for (int j = pflineoffset; j < flineoffset; j += 2)
		{
			bar(j, 330, j + 2, 340);
			if (j % 5 == 0)
				delay(1);
		}
		for (int j = pslineoffset; j < slineoffset; j += 2)
		{
			bar(j, 430, j + 2, 440);
			if (j % 5 == 0)
				delay(1);
		}
		pflineoffset = flineoffset;
		pslineoffset = slineoffset;
	}
	setcolor(14);
	setfillstyle(1, 14);
	poly[0] = 10;
	poly[1] = 315;
	poly[2] = 35;
	poly[3] = 285;
	poly[4] = 60;
	poly[5] = 315;
	for (i = 0; i < 10; i++)
	{
		if (i > 4)
			delay(200);
		delay(150 + rand() % 80 - 40);
		bar(10 + i * 80, 315, 60 + i * 80, 465);
		fillpoly(3, poly);
		for (j = 0; j < 6; j++)
			if (j % 2 == 0)
				poly[j] += 80;
	}
	setcolor(15);
	setfillstyle(1, 0);
	bar(330, 190, 630, 214);
	outtextxy(200, 190, "Press any key to continue...");
}

void drawdiagwindow(struct text ctext)
{
	setfillstyle(1, 14);
	bar(0, 0, 30, 590);
	bar(0, 0, 790, 30);
	bar(760, 0, 790, 590);
	bar(0, 560, 790, 590);
	setfillstyle(1, 6);
	bar(30, 30, 760, 560);
	setbkcolor(6);
	for (int i = 0; i < ctext.strnum; i++)
		outtextxy(30, 30 + i * 24, ctext.textstr[i]);
	setbkcolor(0);
}

void drawstatusbar(enum STATUSBAR status)
{
	setfillstyle(1, 6);
	bar(0, 566, 800, 590);
	setbkcolor(6);
	settextstyle(4, HORIZ_DIR, 2);
	switch (status)	
	{
	case MMENU:
		outtextxy(0, 566, "ÂÛÁÎÐ \"Enter\",ÏÅÐÅÊËÞ×ÅÍÈÅ \"ÂÂÅÐÕ/ÂÍÈÇ\"");
		break;
	case DWINDOW:
		outtextxy(0, 566, "ÂÛÕÎÄ \"ESC\"");
		break;
	default:
		break;
	}
	settextstyle(4, HORIZ_DIR, 3);
	setbkcolor(0);
}
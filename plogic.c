#include "plogic.h"

short int findpoints(struct point *points, const short int pointsnum)
{
	short int fpindex = 0;
	for (int i = 1; i < pointsnum; i++)
		if (points[fpindex].y < points[i].y)
			fpindex = i;
		else if (points[fpindex].y == points[i].y && points[fpindex].x > points[i].x)
			fpindex = i;
	swappoints(points, fpindex, pointsnum - 1);
	struct point base = points[pointsnum - 1];
	struct point current = base;
	short int k = 0, counter = 0;
	long int tres;
	while (1)
	{
		k = counter;
		for (int i = k + 1; i < pointsnum; i++)
		{
			tres = turn(current, points[k], points[i]);
			if (tres > 0)
				k = i;
			else if (tres == 0)
				if (checklength(current, points[k], points[i]))
					k = i;
		}
		current = points[k];
		swappoints(points, counter, k);
		counter++;
		if (current.x == base.x && current.y == base.y)
			break;
	}
	return counter;
}

float findangle(const struct point P, const struct point C)
{
	float angle;
	struct point PC = { C.x - P.x, C.y - P.y }, PO = { 1, 0 };
	float modPC = sqrtf(powf(PC.x, 2.0f) + powf(PC.y, 2.0f));
	float modPO = sqrtf(powf(PO.x, 2.0f) + powf(PO.y, 2.0f));
	angle = (PC.x * PO.x + PC.y * PO.y) / (modPC * modPO);
	angle = acosf(angle);
	angle = angle * 180 / MATH_PI;
	if (C.y == P.y)
		if (P.x > C.x)
			angle = 180;
		else
			angle = 0;
	else if (C.y > P.y)
		angle = 360 - angle;
	return angle;
}

void finddelta(int *dx, int *dy, const float angle, const short int radius)
{
	if (angle > 315.0f || angle <= 45.0f)
		*dy = radius;
	else if (angle > 45.0f && angle <= 135.0f)
		*dx = radius;
	else if (angle > 135.0f && angle <= 225.0f)
		*dy = -radius;
	else if (angle > 225.0f && angle <= 315.0f)
		*dx = -radius;
}

short int checklength(const struct point current, const struct point a, const struct point b)
{
	float f1, f2;
	f1 = sqrtf(powf(a.x - current.x, 2.0f) + powf(a.y - current.y, 2.0f));
	f2 = sqrtf(powf(b.x - current.x, 2.0f) + powf(b.y - current.y, 2.0f));
	return (f2 > f1) ? 1 : 0;
}

long int turn(const struct point a, const struct point b, const struct point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void swappoints(struct point *points, short int a, short int b)
{
	struct point tpoint = points[b];
	points[b] = points[a];
	points[a] = tpoint;
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

struct point *genpoints(const short int number)
{
	struct point *points = (struct point *)malloc(number * POINTSIZE);
	if (points == NULL)
		exit(1);
	if (number == 3)
	{
		points[0].x = rand() % 260 + 70;
		points[0].y = rand() % 213 + 70;
		points[1].x = rand() % 260 + 330;
		points[1].y = rand() % 213 + 70;
		if (rand() % 2 == 0)
			points[2].x = rand() % 260 + 330;
		else
			points[2].x = rand() % 260 + 70;
		points[2].y = rand() % 213 + 283;
		return points;
	}
	else
	{
		int n1 = number / 4, n2 = number / 4, n3 = number / 4, n4 = number / 4, i;
		switch (number % 4)
		{
		case 1:
			n1++;
			break;
		case 2:
			n1++; n2++;
			break;
		case 3:
			n1++; n2++; n3++;
			break;
		default:
			break;
		}
		int dx, dy, cx,cy;
		if (n1 % 2 == 0)
			dy = n1 / 2;
		else
			dy = n1 / 2 + 1;
		dx = n1 / 2;
		if (dx == 0 || dx == 1)
		{
			dy = -50;
			dx = 50;
		}
		else
		{
			dx = 245 / dx;
			dy = -(200 / dy);
		}
		cx = 70;
		cy = 283;
		for (i = 0; i < n1; i++)
		{
			if (i % 2 == 0)
				cy += dy;
			else
				cx += dx;
			points[i].x = cx;
			points[i].y = cy;
		}
		cx = 330;
		cy = 70;
		dy = -dy;
		for (; i < n2 + n1; i++)
		{
			if (i % 2 == 0)
				cx += dx;
			else
				cy += dy;
			points[i].x = cx;
			points[i].y = cy;
		}
		cx = 590;
		cy = 283;
		dx = -dx;
		for (; i < n3 + n2 + n1; i++)
		{
			if (i % 2 == 0)
				cy += dy;
			else
				cx += dx;
			points[i].x = cx;
			points[i].y = cy;
		}
		cx = 330;
		cy = 496;
		dy = -dy;
		for (; i < n4 + n3 + n2 + n1; i++)
		{
			if (i % 2 == 0)
				cx += dx;
			else
				cy += dy;
			points[i].x = cx;
			points[i].y = cy;
		}
		return points;
	}
}
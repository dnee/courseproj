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

void findcoords(float *dx, float *dy, const struct point P, const struct point C, const short int radius, const int by)
{
	float A = P.y - C.y, B = C.x - P.x, C1 = P.x * C.y - C.x * P.y;
	if (by)
	{
		*dy = (-A*P.x - C1 + B*radius) / B;
		*dx = (-B*(*dy) - C1 + B*radius) / A;
		*dy = P.y - *dy;
		*dx = P.x - *dx;
	}
	else
	{
		*dx = (-B*P.y - C1 + A*radius) / A;
		*dy = (-A*(*dx) - C1 + A*radius) / B;
		*dy = P.y - *dy;
		*dx = P.x - *dx;
	}
}

char findangle(const struct point P, const struct point C, const struct point N, float *angle)
{
	enum ANGLESTATUS status;
	struct point CP = { P.x - C.x, P.y - C.y }, CN = { N.x - C.x, N.y - C.y };
	float modCP = sqrtf(powf(CP.x, 2.0f) + powf(CP.y, 2.0f));
	float modCN = sqrtf(powf(CN.x, 2.0f) + powf(CN.y, 2.0f));
	*angle = (CP.x * CN.x + CP.y * CN.y) / (modCP * modCN);
	*angle = acosf(*angle);
	*angle = *angle * 180 / MATH_PI;
	if (*angle <= 90)
	{
		if (C.y == P.y && C.x == N.x)
			if (C.x > P.x)
				return 9;
			else
				return 10;
		else if (C.y == N.y && C.x == P.x)
			if (C.x > N.x)
				return 8;
			else
				return 11;
		else if (C.x > P.x && C.x > N.x)
			return 0;
		else if (C.y < P.y && C.y < N.y)
			return 2;
		else if (C.x < P.x && C.x < N.x)
			return 4;
		else if (C.y > P.y && C.y > N.y)
			return 6;
	}
	else
	{
		if (C.y <= P.y && C.y > N.y)
			return 1;
		else if (C.y <= P.y && C.y < N.y)
			return 3;
		else if (C.y > P.y && C.y < N.y)
			return 5;
		else if (C.y > P.y && C.y > N.y)
			return 7;
	}
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
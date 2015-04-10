#include "plogic.h"

short int findpoints(struct point *points, const short int length)
{
	struct point base = points[length - 1];
	struct point current = base;
	short int k = 0, counter = 0, tres;
	while (1)
	{
		k = counter;
		for (int i = k + 1; i < length; i++)
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

short int checklength(const struct point current, const struct point a, const struct point b)
{
	float f1, f2;
	f1 = sqrtf(powf(a.x - current.x, 2.0f) + powf(a.y - current.y, 2.0f));
	f2 = sqrtf(powf(b.x - current.x, 2.0f) + powf(b.y - current.y, 2.0f));
	return (f2 > f1) ? 1 : 0;
}

short int turn(const struct point a, const struct point b, const struct point c)
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

short int findfpindex(struct point *points, const short int length)
{
	short int fpindex = 0;
	for (int i = 1; i < length; i++)
		if (points[fpindex].y < points[i].y)
			fpindex = i;
		else if (points[fpindex].y == points[i].y && points[fpindex].x > points[i].x)
			fpindex = i;
	return fpindex;
}

void swappoints(struct point *points, short int a, short int b)
{
	struct point tpoint = points[b];
	points[b] = points[a];
	points[a] = tpoint;
}
#include "pdata.h"

int *getpolypoints(const struct point *points, const short int pointsnum)
{
	int *polypoints = (int *)malloc((pointsnum * 2 + 1) * sizeof(int));
	if (polypoints == NULL)
		exit(1);

}

struct point *generatepoints(const short int pointsnum)
{
	char containpoint;
	struct point *points = (struct point *)malloc(pointsnum * POINTSIZE);
	if (points == NULL)
		exit(1);
	for (int i = 0; i < pointsnum; i++)
	{
		points[i].x = rand() % 500 + 100;
		points[i].y = rand() % 300 + 100;
		while (1)
		{
			containpoint = 0;
			for (int j = 0; j < i && !containpoint; j++)
				if (points[j].x == points[i].x && points[j].y == points[i].y)
					containpoint = 1;
			if (containpoint)
			{
				points[i].x = rand() % 500 + 100;
				points[i].y = rand() % 400 + 100;
			}
			else
				break;
		}
	}
	return points;
}
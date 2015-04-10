#ifndef PLOGIC_H
#define PLOGIC_H
#include <math.h>

short int findfpindex(struct point *points, const short int length);
void swappoints(struct point *points, short int a, short int b);
short int turn(const struct point a, const struct point b, const struct point c);
short int checklength(const struct point current, const struct point a, const struct point b);
short int findpoints(struct point *points, const short int length);

struct point
{
	short x;
	short y;
};

#endif // PLOGIC_H
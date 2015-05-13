#ifndef PLOGIC_H
#define PLOGIC_H

#include <math.h>
#include <stdlib.h>
#include "common.h"

void swappoints(struct point *points, short int a, short int b);
long int turn(const struct point a, const struct point b, const struct point c);
short int checklength(const struct point current, const struct point a, const struct point b);
short int findpoints(struct point *points, const short int pointsnum);
float findangle(const struct point P, const struct point C);
void finddelta(int *dx, int *dy,const float angle, const short int radius);
char getkey();

#endif // PLOGIC_H
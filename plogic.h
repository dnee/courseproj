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
float findangle3(const struct point P, const struct point C, const struct point N);
//void findcoords(float *dx, float *dy, const struct point P, const struct point C, const short int radius, const int by);

#endif // PLOGIC_H
#ifndef PGRAPH_H
#define PGRAPH_H

#include "graphics.h"
#include "common.h"

extern "C"
{
#include "plogic.h"
}

void initiategraph();
void loadingscr();
void drawmainmenu();
void drawarc(const float angle, const float angle1, const float angle2, const struct point C, const short int radius);
void drawwall(const float angle, const struct point P, const struct point C, const short int radius);
void drawpoly(const struct point *points, const short int pointsnum);
void drawpoints(const struct point *points, const short int pointsnum);
void drawfence(const struct point *points, const short int pointsnum, const short int radius);

#endif // PGRAPH_H
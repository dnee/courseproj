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
void drawpoly(const struct point *points, const short int pointsnum);
void drawpoints(const struct point *points, const short int pointsnum);
void drawfence(const struct point *points, const short int pointsnum, const short int radius);

#endif // PGRAPH_H
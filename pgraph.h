#ifndef PGRAPH_H
#define PGRAPH_H

#include "graphics.h"
#include "common.h"

extern "C"
{
#include "plogic.h"
}

void initiategraph();
void drawloadingscr();
void drawmainmenu(int param);
void drawcentermask();
void drawpoly(const struct point *points, const short int pointsnum);
void drawpoints(const struct point *points, const short int pointsnum);
void drawfence(const struct point *points, const short int pointsnum, const short int radius);
char getkey();

#endif // PGRAPH_H
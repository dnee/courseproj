#ifndef PGRAPH_H
#define PGRAPH_H

#include "graphics.h"
#include "common.h"

void initiategraph();
void loadingscr();
void drawmainmenu();
void testgr();
void drawpoly(const struct point *points, const short int pointsnum);
void drawpoints(const struct point *points, const short int pointsnum);

#endif // PGRAPH_H
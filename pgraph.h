#ifndef PGRAPH_H
#define PGRAPH_H

#include "graphics.h"

extern "C"
{
#include "plogic.h"
#include "common.h"
}

void initiategraph();
void drawloadingscr();
void drawmainmenu(int param);
void drawcentermask();
void drawpoly(const struct point *points, const short int pointsnum);
void drawpoints(const struct point *points, const short int pointsnum);
void drawfence(const struct point *points, const short int pointsnum, const short int radius);
void drawdiagwindow(struct text ctext, struct dwindsize size);
void drawstatusbar(enum STATUSBAR status);
void drawstartmenu(int param);

#endif // PGRAPH_H
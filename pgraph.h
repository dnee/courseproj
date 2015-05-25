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
void drawmainmenu(const int param);
void drawpoly(const struct point *points, const short int pointsnum);
void drawpoints(const struct point *points, const short int pointsnum);
void drawfence(const struct point *points, const short int pointsnum, const short int radius);
void drawdiagwindow(struct text ctext, struct dwindsize size);
void drawstatusbar(enum STATUSBAR status);
void drawstartmenu(const int param);
void drawdesk();
void drawfilemenuframe(const int curpos, const char bcolor);
struct point *drawmode(short int *pointsnum);
void drawpoint(const struct point dpoint, const char bisold);

#endif // PGRAPH_H
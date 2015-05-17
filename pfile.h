#ifndef PFILE_H
#define PFILE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "common.h"

struct point *getpoints(const char *filename, short int *pointsnum);
int putpoints(const char *filename, const struct point *points, const short int pointsnum);
struct text gettext(const char *path);
void deltextstr(const int delitem, const struct text deltext, const char *filename);
void addtextstr(const char *filename, const char *item);

#endif // PFILE_H
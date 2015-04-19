#ifndef PDATA_H
#define PDATA_H

#include <stdlib.h>
#include "common.h"

int *getpolypoints(const struct point *points, const short int pointsnum);
struct point *generatepoints(const short int pointsnum);

#endif // PDATA_H
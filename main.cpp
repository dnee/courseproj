#include "pgraph.h"

extern "C"
{
#include "plogic.h"
#include "pfile.h"
#include "common.h"
}

int main()
{
	short int numpoints;
	struct point *points = getpoints("yolo.txt", &numpoints);
	numpoints = findpoints(points, numpoints);
	return 0;
}
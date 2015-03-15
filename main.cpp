#include "graphics.h"
extern "C"
{
#include "pfile.h"
#include "pdata.h"
}

int main()
{
	int *numobj = (int *)malloc(sizeof(int));
	char *path = "yolo.txt";
	FILE *file = openfile(path, "r");
	char *rawdata = readdata(file, path);
	closefile(file, path);
	short int **data = decodedata(rawdata, numobj);
	initwindow(1024, 768, "Course proj");
	moveto(data[0][0], data[0][1]);
	for (int i = 1; i < *numobj; i++)
		lineto(data[i][0], data[i][1]);
	getch();
	return 0;
}
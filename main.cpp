#include "pgraph.h"
extern "C"
{
#include "plogic.h"
//#include "pfile.h"
//#include "pdata.h"
}

int main()
{
	
	//bootscreen();
	initwindow(1024, 768);
	short int length = 12;
	struct point lolo[12] = { 3, 4, 5, 2, 6, 4, 7, 2, 7, 3, 7, 6, 9, 2, 9, 3, 9, 4, 11, 2, 11, 6, 13, 4 };
	int polycounts[26] = { 30, 40, 50, 20, 70, 20, 70, 30, 90, 30, 90, 20, 110, 20, 130, 40, 110, 60, 90, 40, 70, 60, 60, 40, 30, 40 };
	drawpoly(13, polycounts);
	getch();
	int x = findfpindex(lolo, 12);
	swappoints(lolo, x, length - 1);
	int z = findpoints(lolo, 12);
	int sodoge[26];
	sodoge[0] = lolo[z - 1].x;
	sodoge[1] = lolo[z - 1].y;
	int k = 2;
	for (int i = 0; i < z; i++)
		for (int j = 0; j < 2; j++)
		{
			if (j == 0)
				sodoge[k] = lolo[i].x;
			if (j == 1)
				sodoge[k] = lolo[i].y;
			k++;
		}
	for (int i = 0; i < z * 2 + 2; i++)
		if (i % 2 == 0)
			sodoge[i] = sodoge[i] * 10 + 0;
		else
			sodoge[i] = sodoge[i] * 10;
	setcolor(4);
	drawpoly(z+1, sodoge);
	//int *numobj = (int *)malloc(sizeof(int));
	//char *path = "yolo.txt";
	//FILE *file = openfile(path, "r");
	//char *rawdata = readdata(file, path);
	//closefile(file, path);
	//short int **data = decodedata(rawdata, numobj);
	//moveto(data[0][0], data[0][1]);
	//for (int i = 1; i < *numobj; i++)
	//	lineto(data[i][0], data[i][1]);
	getch();
	return 0;
}
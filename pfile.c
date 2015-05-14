#include "pfile.h"

struct point *getpoints(const char *filename, short int *pointsnum)
{
	FILE *cfile = fopen(filename, "r");
	if (cfile == NULL)
		exit(1);
	char tch, bytesnum[7];
	int counter;
	for (counter = 0; (tch = fgetc(cfile)) != 'b' && counter < 7; counter++)
		bytesnum[counter] = tch;
	if (counter > 6)
		exit(1);
	*(bytesnum + counter) = 0;
	int bytestoread = atoi(bytesnum);
	char *data = (char *)malloc((bytestoread + 1) * sizeof(char));
	if (data == NULL)
		exit(1);
	if (bytestoread != fread(data, sizeof(char), bytestoread, cfile))
	{
		fclose(cfile);
		exit(1);
	}
	fclose(cfile);
	*(data + bytestoread) = 0;
	char *sloc;
	if ((sloc = strchr(data, 's')) == NULL)
		exit(1);
	int offset = sloc - data + 1;
	if (offset > 6)
		exit(1);
	int objectstoread = atoi(data);
	if (objectstoread < 3 || objectstoread > 10000)
		exit(1);
	struct point *points = (struct point *)malloc(objectstoread * POINTSIZE);
	if (points == NULL)
		exit(1);
	for (int i = 0; i < objectstoread; i++)
	{
		points[i].x = atoi(data + offset);
		offset = strchr(data + offset, 'x') - data + 1;
		points[i].y = atoi(data + offset);
		offset = strchr(data + offset, 'y') - data + 1;
	}
	free(data);
	*pointsnum = objectstoread;
	return points;
}

int putpoints(const char *filename, const struct point *points, const short int pointsnum)
{
	char tempbuf[11];
	int bytesnum = 0;
	sprintf(tempbuf, "%ds", pointsnum);
	bytesnum += strlen(tempbuf);
	for (int i = 0; i < pointsnum; i++)
	{
		sprintf(tempbuf, "%dx%dy", points[i].x, points[i].y);
		bytesnum += strlen(tempbuf);
	}
	if (bytesnum > 999999)
		exit(1);
	int count, num = bytesnum;
	for (count = 0; num / 10 != 0 || num % 10 != 0; count++)
		num /= 10;
	char *data = (char *)malloc((bytesnum + count + 2) * sizeof(char));
	if (data == NULL)
		exit(1);
	sprintf(data, "%db", bytesnum);
	sprintf(tempbuf, "%ds", pointsnum);
	strcat(data, tempbuf);
	for (int i = 0; i < pointsnum; i++)
	{
		sprintf(tempbuf, "%dx%dy", points[i].x, points[i].y);
		strcat(data, tempbuf);
	}
	int bytestowrite = strlen(data);
	FILE *cfile = fopen(filename, "w");
	if (cfile == NULL)
		exit(1);
	if (bytestowrite != fwrite(data, sizeof(char), bytestowrite, cfile))
	{
		fclose(cfile);
		exit(1);
	}
	fclose(cfile);
	free(data);
	return bytestowrite;
}

struct text gettext(const char *path)
{
	struct text ctext;
	FILE *cfile = fopen(path, "r");
	if (cfile == NULL)
		exit(1);
	int counter = 0;
	char buffer[40];
	while (!feof(cfile))
	{
		fgets(buffer, 40, cfile);
		counter++;
	}
	ctext.strnum = counter;
	rewind(cfile);
	char **outstr = (char **)malloc(counter * sizeof(char *));
	for (int i = 0; i < counter; i++)
		outstr[i] = (char *)malloc(40 * sizeof(char));
	counter = 0;
	while (!feof(cfile))
	{
		if (fgets(outstr[counter], 40, cfile) == NULL)
			*outstr[counter] = 0;
		counter++;
	}
	fclose(cfile);
	ctext.textstr = outstr;
	return ctext;
}
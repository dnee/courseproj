#include "pdata.h"

short **decodedata(char *data, int *numobjects)
{
	int offset, pos, objectsnum;
	offset = strchr(data, 's') - data + 1;
	objectsnum = parsenum(data, "s");
	if (objectsnum > 10000 || objectsnum < 1)
	{
		printf("Too many objects.\n");
		exit(1);
	}
	short int **datarr = (short int**)malloc(objectsnum * sizeof(short int*));
	for (int i = 0; i < objectsnum; i++)
		datarr[i] = (short int *)malloc(2 * sizeof(short int));
	for (int i = 0; i < objectsnum; i++)
	{
		pos = strchr((data + offset), 'x') - data + 1;
		datarr[i][0] = parsenum((data + offset), "x");
		offset = pos;
		pos = strchr((data + offset), 'y') - data + 1;
		datarr[i][1] = parsenum((data + offset), "y");
		offset = pos;
	}
	*numobjects = objectsnum;
	free(data);
	return datarr;
}

char *encodedata(short int **data, const int *numobjects)
{
	char buffer[6];
	int num, count, offset;
	num = *numobjects;
	for (count = 0; num != 0; count++)
		num /= 10;
	offset = count + 1;
	for (int i = 0; i < *numobjects; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			num = data[i][j];
			for (count = 0; num != 0; count++)
				num /= 10;
			offset += count;
		}
		offset += 2;
	}
	char *outdata = (char *)malloc((offset + 1)*sizeof(char));
	numtostr(*numobjects, &buffer);
	strcpy(outdata, &buffer);
	strcat(outdata, "s");
	for (int i = 0; i < *numobjects; i++)
	{
		numtostr(data[i][0], &buffer);
		strcat(outdata, &buffer);
		strcat(outdata, "x");
		numtostr(data[i][1], &buffer);
		strcat(outdata, &buffer);
		strcat(outdata, "y");
	}
	return outdata;
}

short int parsenum(char *data, const char *ch)
{
	char *pch;
	short int parsednum;
	if (strchr(data, *ch) != NULL && (strchr(data, *ch) - data) < 6)
	{
		pch = strtok(data, ch);
		if (pch == NULL)
		{
			printf("Corrupted data.\n");
			exit(1);
		}
		parsednum = strtonum(pch);
	}
	else
	{
		printf("Corrupted data.\n");
		exit(1);
	}
	return parsednum;
}
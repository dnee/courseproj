#include "pfile.h"

FILE *openfile(const char *path, const char *mode)
{
	FILE *file;
	if ((file = fopen(path, mode)) == NULL)
	{
		printf("Can not open file: %s\n", path);
		exit(1);
	}
	return file;
}

void closefile(FILE *file, const char *path)
{
	if ((fclose(file)) != 0)
	{
		printf("Can not close file: %s\n", path);
		exit(1);
	}
}

int writedata(const char *data, FILE *file, const char *path)
{
	int byteswrite = 0, count, bytes, num;
	num = bytes = strlen(data);
	if (bytes > 999992)
	{
		printf("Data overflow.\n");
		closefile(file, path);
		exit(1);
	}
	for (count = 0; num / 10 != 0 || num % 10 != 0; count++)
		num /= 10;
	char *out = (char *)malloc((count + bytes + 2) * sizeof(char));
	num = bytes + count + 1;
	numtostr(num, out);
	strcat(out, "b");
	strcat(out, data);
	byteswrite = fwrite(out, sizeof(char), strlen(out), file);
	if (ferror(file))
	{
		printf("Can not writing to file: %s", path);
		closefile(file, path);
		exit(1);
	}
	free(out);
	return byteswrite;
}

char *readdata(FILE *file, const char *path)
{
	int bytenum = 0, count, bytesread;
	char tch, numbytesarr[8];
	for (count = 0; (tch = fgetc(file)) != 'b' && count < 7; count++)
	{
		if (!isdigit(tch))
		{
			printf("Corrupted data.\n");
			closefile(file, path);
			exit(1);
		}
		if (ferror(file))
		{
			printf("Can not reading from file: %s\n", path);
			closefile(file, path);
			exit(1);
		}
		numbytesarr[count] = tch;
	}
	if (count > 6)
	{
		printf("Corrupted data.\n");
		closefile(file, path);
		exit(1);
	}
	numbytesarr[count] = '\0';
	bytenum = strtonum(&numbytesarr);
	char *out = (char *)malloc((bytenum - count) * sizeof(char));
	bytesread = fread(out, sizeof(char), strlen(out), file);
	if (bytesread != (bytenum - count - 1))
	{
		printf("Corrupted data.\n");
		closefile(file, path);
		free(out);
		exit(1);
	}
	if (ferror(file))
	{
		printf("Can not reading from file: %s\n", path);
		closefile(file, path);
		exit(1);
	}
	*(out + (bytenum - count - 1)) = '\0';
	return out;
}
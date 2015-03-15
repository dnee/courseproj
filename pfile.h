#ifndef PFILE_H
#define PFILE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "common.h"

FILE *openfile(const char *path, const char *mode);
int writedata(const char *data, FILE *file, const char *path);
char *readdata(FILE *file, const char *path);
void closefile(FILE *file, const char *path);

#endif // PFILE_H
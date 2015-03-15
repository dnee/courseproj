#ifndef COMMON_H
#define COMMON_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int chtonum(const char ch);
char numtoch(const int num);
void numtostr(const int num, char *str);
int strtonum(const char *str);

#endif // COMMON_H
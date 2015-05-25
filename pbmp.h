#ifndef PBMP_H
#define PBMP_H

#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

// Заголовок Bmp
#pragma pack(push)
#pragma pack(1)
typedef struct
{
	unsigned char   b1, b2;
	unsigned long   bfSize;
	unsigned short  bfReserved1;
	unsigned short  bfReserved2;
	unsigned long   bfOffBits;
} BmpHeader;
#pragma pack(pop)

// Основная часть Bmp
typedef struct
{
	unsigned long   biSize;
	unsigned long   biWidth;
	unsigned long   biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount;
	unsigned short biCompression;
	unsigned short biSizeImage;
	unsigned long  biXPelsPerMeter;
	unsigned long  biYPelsPerMeter;
	unsigned short biClrUsed;
	unsigned short biClrImportant;
} BmpImageInfo;

typedef struct {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RGB;

void MergeBytes(RGB *pixel, unsigned char *p, int bytes);
void Code(FILE *BmpImage);
void drawbmpt(const char bismainmenu);

#endif // PBMP_H
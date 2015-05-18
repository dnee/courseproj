#include "pbmp.h"

void Code(FILE *BmpImage) // основная функция всей проги, считывает и рисует саму картинку
{
	BmpHeader bmpheader;
	BmpImageInfo bmpimageinfo;
	int pad;
	RGB *pixels;
	int size;
	int bytes2read;
	unsigned char tmp[5];
	pad = sizeof(BmpHeader);
	if (fread(&bmpheader, pad, 1, BmpImage) != 1){
		exit(-1);
	}
	if (fread(&bmpimageinfo, sizeof(BmpImageInfo), 1, BmpImage) != 1){

		exit(-1);
	}
	bmpimageinfo.biSizeImage = bmpimageinfo.biXPelsPerMeter;
	bmpimageinfo.biXPelsPerMeter = bmpimageinfo.biYPelsPerMeter;
	bmpimageinfo.biYPelsPerMeter = bmpimageinfo.biClrUsed;
	bmpimageinfo.biClrUsed = 0;
	size = bmpimageinfo.biHeight * bmpimageinfo.biWidth;

	if ((pixels = (RGB *)malloc(size * sizeof(RGB))) == NULL){
		printf("Malloc error\n");
	}

	for (int i = 0; i<size; i++) {
		pixels[i].r = 0;
		pixels[i].g = 0;
		pixels[i].b = 0;
	}
	fseek(BmpImage, bmpheader.bfOffBits, 0);
	bytes2read = bmpimageinfo.biBitCount / 8;
	int x = bmpimageinfo.biWidth, y = 0, i = 0, j = 0;
	if (size > 0){
		for (int i = 0; i<size; i++)
		{
			fread(tmp, 1, bytes2read, BmpImage);
			MergeBytes(&(pixels[i]), tmp, bytes2read);
		}
	}
	for (i = size; i>0;) // собственно, сам цикл рисования. Ничего тут не трогать.
	{
		for (j = 0; j<bmpimageinfo.biWidth; j++)
		{
			if ((pixels[i].r == 255) && (pixels[i].b == 0) && (pixels[i].g == 0)) { putpixel(x, y, 4); }
			else if ((pixels[i].r == 0) && (pixels[i].b == 0) && (pixels[i].g == 255)) { putpixel(x, y, 10); }
			else if ((pixels[i].r == 0) && (pixels[i].b == 0) && (pixels[i].g == 0)) { putpixel(x, y, 0); }
			else if ((pixels[i].r == 255) && (pixels[i].b == 255) && (pixels[i].g == 255)) { putpixel(x, y, 15); }
			else if ((pixels[i].r == 128) && (pixels[i].b == 128) && (pixels[i].g == 0)) { putpixel(x, y, 5); }
			else if ((pixels[i].r == 128) && (pixels[i].b == 128) && (pixels[i].g == 128)) { putpixel(x, y, 8); }
			else if ((pixels[i].r == 192) && (pixels[i].b == 192) && (pixels[i].g == 192)) { putpixel(x, y, 7); }
			else if ((pixels[i].r == 0) && (pixels[i].b == 128) && (pixels[i].g == 0)) { putpixel(x, y, 1); }
			else if ((pixels[i].r == 0) && (pixels[i].b == 128) && (pixels[i].g == 128)) { putpixel(x, y, 9); }
			else if ((pixels[i].r == 128) && (pixels[i].b == 0) && (pixels[i].g == 0)) { putpixel(x, y, 4); }
			else if ((pixels[i].r == 128) && (pixels[i].b == 0) && (pixels[i].g == 128)) { putpixel(x, y, 10); }
			//else if ((pixels[i].r == 128) && (pixels[i].b == 0) && (pixels[i].g == 128)) { putpixel(x, y, 14); }
			else if ((pixels[i].r == 0) && (pixels[i].b == 255) && (pixels[i].g == 255)) { putpixel(x, y, 11); }
			else if ((pixels[i].r == 0) && (pixels[i].b == 0) && (pixels[i].g == 128)) { putpixel(x, y, 2); }
			else { putpixel(x, y, 7); }
			x -= 1;
			i--;
		}
		x = bmpimageinfo.biWidth;
		y += 1;
	}
}

void MergeBytes(RGB *pixel, unsigned char *p, int bytes) // функция заполнения палитры
{
	if (bytes == 4) {
		pixel->r = p[2];
		pixel->g = p[1];
		pixel->b = p[0];
	}
	else if (bytes == 3) {
		pixel->r = p[2];
		pixel->g = p[1];
		pixel->b = p[0];
	}
	else if (bytes == 2) {
		pixel->r = (p[1] & 0x7c) << 1;
		pixel->g = ((p[1] & 0x03) << 6) | ((p[0] & 0xe0) >> 2);
		pixel->b = (p[0] & 0x1f) << 3;
	}
}

void drawbmpt(const char bismainmenu)
{
	FILE *bmpfile;
	if (bismainmenu)
		bmpfile = fopen("test.bmp", "rb");
	else
		bmpfile = fopen("logo.bmp", "rb");
	setactivepage(2);
	cleardevice();
	Code(bmpfile);
	fclose(bmpfile);
}
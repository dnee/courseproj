#include "common.h"

int chtonum(const char ch)
{
	int num;
	switch (ch)
	{
	case '0': num = 0;
		break;
	case '1': num = 1;
		break;
	case '2': num = 2;
		break;
	case '3': num = 3;
		break;
	case '4': num = 4;
		break;
	case '5': num = 5;
		break;
	case '6': num = 6;
		break;
	case '7': num = 7;
		break;
	case '8': num = 8;
		break;
	case '9': num = 9;
		break;
	default: num = 0;
	}
	return num;
}

char numtoch(const int num)
{
	char ch;
	switch (num)
	{
	case 0: ch = '0';
		break;
	case 1: ch = '1';
		break;
	case 2: ch = '2';
		break;
	case 3: ch = '3';
		break;
	case 4: ch = '4';
		break;
	case 5: ch = '5';
		break;
	case 6: ch = '6';
		break;
	case 7: ch = '7';
		break;
	case 8: ch = '8';
		break;
	case 9: ch = '9';
		break;
	default: ch = '0';
	}
	return ch;
}

void numtostr(const int num, char *str)
{
	int dcount, tnum;
	tnum = num;
	if (tnum > 999999)
	{
		printf("Corrupted data.\n");
		exit(1);
	}
	for (dcount = 0; tnum != 0; dcount++)
		tnum /= 10;
	tnum = num;
	char *out = (char *)malloc((dcount + 1) * sizeof(char));
	for (int i = dcount - 1; i >= 0; i--)
	{
		*(out + i) = numtoch(tnum % 10);
		tnum /= 10;
	}
	*(out + dcount) = '\0';
	strcpy(str, out);
	free(out);
}

int strtonum(const char *str)
{
	int digit, result = 0;
	char tch;
	int digits = strlen(str);
	if (digits > 6)
	{
		printf("Corrupted data.\n");
		exit(1);
	}
	if (*str == '0')
	{
		printf("Corrupted data.\n");
		exit(1);
	}
	for (int i = digits - 1; i >= 0; i--)
	{
		tch = *(str + i);
		if (!isdigit(tch))
		{
			printf("Corrupted data.\n");
			exit(1);
		}
		digit = chtonum(tch);
		result += digit * pow(10.0, digits - (i + 1));
	}
	return result;
}
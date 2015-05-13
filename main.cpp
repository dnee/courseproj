#include <stdlib.h>
#include <ctime>
#include "pgraph.h"

extern "C"
{
#include <math.h>
#include "pdata.h"
#include "plogic.h"
#include "pfile.h"
#include "common.h"
}

int main()
{
	struct text abouttext = getabout(1), helptext = getabout(0);
	int param = 0;
	char key = 0;
	srand(time(NULL));
	initiategraph();
	settextstyle(4, HORIZ_DIR, 3);
	enum PROGRAMSTATUS status = LOADING_SCREEN;
	while (1)
	{
		switch (status)
		{
		case LOADING_SCREEN:
			drawloadingscr();
			status = MAINMENU;
			key = getch();
			break;
		case MAINMENU:
			cleardevice();
			drawmainmenu(param);
			drawstatusbar(MMENU);
			while (1)
			{
				if (status != MAINMENU)
					break;
				if (kbhit())
				{
					key = getkey();
					if (key == 80)
					{
						param++;
						if (param == 4)
							param = 0;
						drawmainmenu(param);
					}
					if (key == 72)
					{
						param--;
						if (param == -1)
							param = 3;
						drawmainmenu(param);
					}
					if (key == 13)
						switch (param)
					{
						case 0: exit(0);
							break;
						case 1: status = HELP;
							break;
						case 2: status = ABOUT;
							break;
						case 3: exit(0);
							break;
						default:
							break;
					}
				}
				delay(50);
			}
			break;
		case ABOUT:
			drawdiagwindow(abouttext);
			drawstatusbar(DWINDOW);
			while (1)
			{
				if (status != ABOUT)
					break;
				if (kbhit())
				{
					key = getkey();
					if (key == 27)
						status = MAINMENU;
				}
				delay(100);
			}
			break;
		case HELP:
			drawdiagwindow(helptext);
			drawstatusbar(DWINDOW);
			while (1)
			{
				if (status != HELP)
					break;
				if (kbhit())
				{
					key = getkey();
					if (key == 27)
						status = MAINMENU;
				}
				delay(100);
			}
			break;
		default:
			break;
		}
	}
	return 0;
}
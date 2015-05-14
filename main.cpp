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
	struct text abouttext = gettext("about.txt1"), helptext = gettext("help.txt1");
	struct text randbut = gettext("randbut.txt1"), filebut = gettext("filebut.txt1");
	struct text drawbut = gettext("drawbut.txt1");
	struct dwindsize hasize = { 20, 20, 770, 546 }, smenusize = { 90, 150, 690, 500 };
	int param = 0, param1 = 0;
	char key = 0;
	srand(time(NULL));
	initiategraph();
	settextstyle(4, HORIZ_DIR, 3);
	enum PROGRAMSTATUS status = STARTMENU;
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
						case 0: status = STARTMENU;
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
			drawdiagwindow(abouttext, hasize);
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
			drawdiagwindow(helptext, hasize);
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
		case STARTMENU:
			cleardevice();
			setfillstyle(1, 7);
			bar(0, 0, 790, 566);
			drawstartmenu(param1);
			drawdiagwindow(randbut, smenusize);
			drawstatusbar(SWINDOW);
			while (1)
			{
				if (status != STARTMENU)
					break;
				if (kbhit())
				{
					key = getkey();
					if (key == 77)
					{
						param1++;
						if (param1 == 3)
							param1 = 0;
						drawstartmenu(param1);
					}
					if (key == 75)
					{
						param1--;
						if (param1 == -1)
							param1 = 2;
						drawstartmenu(param1);
					}
					switch (param1)
					{
					case 0:
						drawdiagwindow(randbut, smenusize);
						break;
					case 1:
						drawdiagwindow(filebut, smenusize);
						break;
					case 2:
						drawdiagwindow(drawbut, smenusize);
						break;
					default:
						break;
					}
					if (key == 13)
						switch (param1)
					{
						case 0: status = STARTMENU;
							break;
						case 1: status = HELP;
							break;
						case 2: status = ABOUT;
							break;
						default:
							break;
					}
					if (key == 27)
						status = MAINMENU;
				}
				delay(50);
			}
			break;
		default:
			break;
		}
	}
	return 0;
}
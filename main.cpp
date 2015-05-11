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
	initiategraph();
	srand(time(NULL));
	settextstyle(4, HORIZ_DIR, 3);
	int param = 0;
	char key = 0;
	enum PROGRAMSTATUS status = MAINMENU;
	while (1)
	{
		switch (status)
		{
		case LOADING_SCREEN:
			drawloadingscr();
			status = MAINMENU;
			getch();
			break;
		case MAINMENU:
			cleardevice();
			drawmainmenu(param);
			while (1)
			{
				if (kbhit())
				{
					key = getkey();
					if (key == 80)
					{
						param++;
						if (param == 4)
							param = 0;
						delay(150);
						cleardevice();
						drawmainmenu(param);
					}
				}
			}
			break;
		default:
			break;
		}
	}
	return 0;
}
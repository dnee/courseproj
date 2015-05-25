#include <ctime>
#include "pgraph.h"
#include "pbmp.h"

extern "C"
{
#include "plogic.h"
#include "pfile.h"
#include "common.h"
}


int main()
{
	struct text abouttext = gettext("about.txt1"), helptext = gettext("help.txt1");
	struct text randbut = gettext("randbut.txt1"), filebut = gettext("filebut.txt1");
	struct text drawbut = gettext("drawbut.txt1"), inputxt = { NULL, 1, "" };
	struct text randtxt = { NULL, 1, "Введите количество углов" }, randtxt1 = { NULL, 1, "Введите радиус" };
	struct text filetext = { NULL, 1, "Выберите файл" }, filelisttxt = gettext("filelist.txt1");
	struct text deletetext = { NULL, 1, "Вы хотите удалить файл?" }, createtext = {NULL,1,"Сохранить файл"};
	struct dwindsize hasize = { 20, 20, 770, 546 }, smenusize = { 90, 150, 690, 500 };
	struct dwindsize randtitlesize { 175, 195, 615, 245 }, randinputsize = { 275, 345, 515, 395 };
	struct dwindsize filetitlesize = { 262, 20, 527, 70 }, fileitemsize = { 30, 120, 240, 170 };
	struct dwindsize deletewindsize = { 175, 195, 615, 245 }, createwindsize = { 175, 195, 615, 245 };
	int param = 0, param1 = 0;
	short int numobjects = 0, minpathobj = 0, radius = 0;
	char key = 0, brandstage = 0, inputbuf[11], bfilestage = 0, bstddesktype = 0, curpos = 0, bexitfileloop = 0;
	struct point *objects = NULL, *minpath = NULL;
	void *mainmenubmp = NULL, *logobmp = NULL;
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
			break;
		case MAINMENU:
			if (mainmenubmp == NULL)
			{
				drawbmpt(1);
				unsigned int mainmenubmpsize = imagesize(0, 0, 800, 600);
				mainmenubmp = malloc(mainmenubmpsize);
				getimage(0, 0, 800, 600, mainmenubmp);
				key = getch();
				setactivepage(0);
				putimage(0, 0, mainmenubmp, 0);
			}
			else
				putimage(0, 0, mainmenubmp, 0);
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
			if (logobmp == NULL)
			{
				drawbmpt(0);
				unsigned int logobmpsize = imagesize(0, 0, 340, 255);
				logobmp = malloc(logobmpsize);
				getimage(0, 0, 340, 255, logobmp);
				setactivepage(0);
				putimage(225, 281, logobmp, 0);
			}
			else
				putimage(225, 281, logobmp, 0);
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
			setfillstyle(1, 7);
			bar(0, 0, 790, 566);
			drawstartmenu(param1);
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
						case 0: status = RANDCMENU;
							break;
						case 1: status = FILECMENU;
							break;
						case 2: status = DRAW;
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
		case STDDESK:
			setfillstyle(1, 7);
			bar(0, 0, 790, 566);
			switch (bstddesktype)
			{
			case 0:
				drawstatusbar(RANDDESKWINDOW);
				break;
			case 1:
				drawstatusbar(FILEDESKWINDOW);
				break;
			default:
				break;
			}			
			drawdesk();
			drawpoly(objects, numobjects);
			minpath = (struct point *)malloc(numobjects * POINTSIZE);
			if (minpath == NULL)
				exit(1);
			memcpy(minpath, objects, numobjects * POINTSIZE);
			minpathobj = findpoints(minpath, numobjects);
			while (1)
			{
				if (status != STDDESK)
					break;
				if (kbhit())
				{
					key = getkey();
					if (key == 27)
					{
						status = STARTMENU;
						free(objects);
						free(minpath);
					}
					if (key == 32)
						drawfence(minpath, minpathobj, radius);
					if (key == 60 && bstddesktype == 0)
					{
						setvisualpage(1);
						setactivepage(1);
						setfillstyle(1, 7);
						bar(0, 0, 790, 566);
						drawstatusbar(INPUTWINDOW);
						drawdiagwindow(createtext, createwindsize);
						drawdiagwindow(inputxt, randinputsize);
						while (1)
						{
							if (kbhit())
							{
								key = getkey();
								if (isalnum(key) && strlen(inputxt.str1) < 6)
								{
									sprintf(inputbuf, "%c", key);
									strcat(inputxt.str1, inputbuf);
								}
								if (key == 8)
									if (strlen(inputxt.str1) != 0)
										inputxt.str1[strlen(inputxt.str1) - 1] = 0;
								if (key == 13)
								{
									inputbuf[0] = 0;
									strcat(inputbuf, inputxt.str1);
									strcat(inputbuf, ".txt");
									inputxt.str1[0] = 0;
									putpoints(inputbuf, objects, numobjects);
									addtextstr("filelist.txt1", inputbuf);
									free(objects);
									free(minpath);
									status = STARTMENU;
									setactivepage(0);
									setvisualpage(0);
									break;
								}
								if (key == 27)
								{
									inputxt.str1[0] = 0;
									setactivepage(0);
									setvisualpage(0);
									break;
								}
								drawdiagwindow(inputxt, randinputsize);
							}
							delay(100);
						}
					}

				}
				delay(100);
			}
			break;
		case RANDCMENU:
			setfillstyle(1, 7);
			bar(0, 0, 790, 566);
			drawstatusbar(INPUTWINDOW);
			drawdiagwindow(randtxt, randtitlesize);
			drawdiagwindow(inputxt, randinputsize);
			while (1)
			{
				if (status != RANDCMENU)
					break;
				if (kbhit())
				{
					key = getkey();
					if (isdigit(key))
					{
						sprintf(inputbuf, "%c", key);
						strcat(inputxt.str1, inputbuf);
					}
					if (key == 8)
						if (strlen(inputxt.str1) != 0)
							inputxt.str1[strlen(inputxt.str1) - 1] = 0;
					if (key == 13)
						if (!brandstage)
						{
							brandstage = 1;
							numobjects = atoi(inputxt.str1);
							inputxt.str1[0] = 0;
						}
						else
						{
							bstddesktype = 0;
							brandstage = 0;
							radius = atoi(inputxt.str1);
							inputxt.str1[0] = 0;
							status = STDDESK;
							objects = genpoints(numobjects);
							break;
						}
					if (key == 27)
						if (brandstage)
						{
							brandstage = 0;
							inputxt.str1[0] = 0;
						}
						else
						{
							status = STARTMENU;
							inputxt.str1[0] = 0;
						}
					switch (brandstage)
					{
					case 0:
						drawdiagwindow(randtxt, randtitlesize);
						drawdiagwindow(inputxt, randinputsize);
						break;
					case 1:
						drawdiagwindow(randtxt1, randtitlesize);
						drawdiagwindow(inputxt, randinputsize);
						break;
					default:
						break;
					}
				}
				delay(100);
			}
			break;
		case FILECMENU:
			filelisttxt = gettext("filelist.txt1");
			setfillstyle(1, 7);
			bar(0, 0, 790, 566);
			drawstatusbar(FILECHOOSEWINDOW);
			drawdiagwindow(filetext, filetitlesize);
			for (int i = 0; i < filelisttxt.strnum; i++)
			{
				struct dwindsize tempsize = fileitemsize;
				struct text temptext = { NULL, 1, "" };
				short int length = strchr(filelisttxt.textstr[i], '.') - filelisttxt.textstr[i];
				strncpy(temptext.str1, filelisttxt.textstr[i], length);
				temptext.str1[length] = 0;
				tempsize.y1 = fileitemsize.y1 + (i % 4) * 115;
				tempsize.y2 = fileitemsize.y2 + (i % 4) * 115;
				tempsize.x1 = fileitemsize.x1 + 260 * (i / 4);
				tempsize.x2 = fileitemsize.x2 + 260 * (i / 4);
				drawdiagwindow(temptext, tempsize);
			}
			drawfilemenuframe(curpos, 1);
			while (1)
			{
				if (status != FILECMENU)
					break;
				if (kbhit())
				{
					key = getkey();
					if (key == 72)
						if (curpos % 4 != 0)
						{
							drawfilemenuframe(curpos, 0);
							curpos--;
							drawfilemenuframe(curpos, 1);
						}
					if (key == 80 && (curpos + 1) < filelisttxt.strnum)
						if (curpos % 4 != 3)
						{
							drawfilemenuframe(curpos, 0);
							curpos++;
							drawfilemenuframe(curpos, 1);
						}
					if (key == 75)
						if (curpos > 3)
						{
							drawfilemenuframe(curpos, 0);
							curpos -= 4;
							drawfilemenuframe(curpos, 1);
						}
					if (key == 77)
						if (curpos < 8 && (curpos + 4) < filelisttxt.strnum)
						{
							drawfilemenuframe(curpos, 0);
							curpos += 4;
							drawfilemenuframe(curpos, 1);
						}
					if (key == 13)
					{
						setfillstyle(1, 7);
						bar(0, 0, 790, 566);
						drawstatusbar(INPUTWINDOW);
						drawdiagwindow(randtxt1, randtitlesize);
						drawdiagwindow(inputxt, randinputsize);
							while (1)
							{
								if (kbhit())
								{
									key = getkey();
									if (isdigit(key))
									{
										sprintf(inputbuf, "%c", key);
										strcat(inputxt.str1, inputbuf);
									}
									if (key == 8)
										if (strlen(inputxt.str1) != 0)
											inputxt.str1[strlen(inputxt.str1) - 1] = 0;
									if (key == 13)
									{
										radius = atoi(inputxt.str1);
										bstddesktype = 1;
										inputxt.str1[0] = 0;
										objects = getpoints(filelisttxt.textstr[curpos], &numobjects);
										status = STDDESK;
										break;
									}
									if (key == 27)
									{
										inputxt.str1[0] = 0;
										bexitfileloop = 1;
										break;
									}
									drawdiagwindow(inputxt, randinputsize);
								}
								delay(100);
							}
					}
					if (key == 83)
					{
						setfillstyle(1, 7);
						bar(0, 0, 790, 566);
						drawstatusbar(DELETEWINDOW);
						drawdiagwindow(deletetext, deletewindsize);
						struct text temptext = { NULL, 1, "" };
						short int length = strchr(filelisttxt.textstr[curpos], '.') - filelisttxt.textstr[curpos];
						strncpy(temptext.str1, filelisttxt.textstr[curpos], length);
						temptext.str1[length] = 0;
						drawdiagwindow(temptext, randinputsize);
						while (1)
						{
							if (kbhit())
							{
								key = getkey();
								if (key == 13)
								{
									if (curpos != 0)
										deltextstr(curpos, filelisttxt, "filelist.txt1");
									if (curpos == filelisttxt.strnum - 1 && curpos != 0)
										curpos--;
									bexitfileloop = 1;
									break;
								}
								if (key == 27)
								{
									bexitfileloop = 1;
									break;
								}
							}
							delay(100);
						}
					}
					if (bexitfileloop)
					{
						bexitfileloop = 0;
						break;
					}
					if (key == 27)
						status = STARTMENU;
				}
				delay(50);
			}
			break;
		case DRAW:
			objects = drawmode(&numobjects);
			if (objects == NULL)
				status = STARTMENU;
			else
			{
				setfillstyle(1, 7);
				bar(0, 0, 790, 566);
				drawstatusbar(INPUTWINDOW);
				drawdiagwindow(randtxt1, randtitlesize);
				drawdiagwindow(inputxt, randinputsize);
				while (1)
				{
					if (status != DRAW)
						break;
					if (kbhit())
					{
						key = getkey();
						if (isdigit(key))
						{
							sprintf(inputbuf, "%c", key);
							strcat(inputxt.str1, inputbuf);
						}
						if (key == 8)
							if (strlen(inputxt.str1) != 0)
								inputxt.str1[strlen(inputxt.str1) - 1] = 0;
						if (key == 13)
						{
							bstddesktype = 0;
							radius = atoi(inputxt.str1);
							inputxt.str1[0] = 0;
							status = STDDESK;
						}
						if (key == 27)
						{
							free(objects);
							numobjects = 0;
							inputxt.str1[0] = 0;
							status = STARTMENU;
						}
						drawdiagwindow(inputxt, randinputsize);
					}
					delay(100);
				}
			}
			break;
		default:
			break;
		}
	}
	return 0;
}
#include"founction.h"

void game_face(int level, int step_num, int restep_num);
void pause();
void lastlevel();
void passlevel(int step_num);

char gameloop(int level)
{
	mciSendString(TEXT("open Boxmove.wav alias Boxmove"), NULL, 0, NULL);

	PIMAGE pimg_wall = newimage();
	PIMAGE pimg_land = newimage();
	PIMAGE pimg_BoxYellow = newimage();
	PIMAGE pimg_BoxRed = newimage();
	PIMAGE pimg_aim = newimage();
	PIMAGE pimg_ManUP1 = newimage();
	PIMAGE pimg_ManUP2 = newimage();
	PIMAGE pimg_ManDOWN1 = newimage();
	PIMAGE pimg_ManDOWN2 = newimage();
	PIMAGE pimg_ManRIGHT1 = newimage();
	PIMAGE pimg_ManRIGHT2 = newimage();
	PIMAGE pimg_ManLEFT1 = newimage();
	PIMAGE pimg_ManLEFT2 = newimage();
	PIMAGE pimg_black = newimage();

	getimage(pimg_wall, "data\\Picture\\wall.jpg", 0, 0);
	getimage(pimg_land, "data\\Picture\\land.jpg", 0, 0);
	getimage(pimg_BoxYellow, "data\\Picture\\BoxYellow.jpg", 0, 0);
	getimage(pimg_BoxRed, "data\\Picture\\BoxRed.jpg", 0, 0);
	getimage(pimg_aim, "data\\Picture\\aim.jpg", 0, 0);
	getimage(pimg_ManUP1, "data\\Picture\\ManUP1.jpg", 0, 0);
	getimage(pimg_ManUP2, "data\\Picture\\ManUP2.jpg", 0, 0);
	getimage(pimg_ManDOWN1, "data\\Picture\\ManDOWN1.jpg", 0, 0);
	getimage(pimg_ManDOWN2, "data\\Picture\\ManDOWN2.jpg", 0, 0);
	getimage(pimg_ManRIGHT1, "data\\Picture\\ManRIGHT1.jpg", 0, 0);
	getimage(pimg_ManRIGHT2, "data\\Picture\\ManRIGHT2.jpg", 0, 0);
	getimage(pimg_ManLEFT1, "data\\Picture\\ManLEFT1.jpg", 0, 0);
	getimage(pimg_ManLEFT2, "data\\Picture\\ManLEFT2.jpg", 0, 0);
	getimage(pimg_black, "data\\Picture\\black.jpg", 0, 0);

	//定义及初始化地图
	char map[maps_num][50][50] = {
		{
			"|========|",
			"|==###===|",
			"|==#X#===|",
			"|==# ####|",
			"|###O OX#|",
			"|#X O@###|",
			"|####O#==|",
			"|===#X#==|",
			"|===###==|",
			"||=======|"
		},//第1关
		{
			"|=========|",
			"|#####====|",
			"|#@  #====|",
			"|# OO#=###|",
			"|# O #=#X#|",
			"|### ###X#|",
			"|=##    X#|",
			"|=#   #  #|",
			"|=#   ####|",
			"|=#####===|",
			"||========|"
		},//第2关
		{
			"|==========|",
			"|=#######==|",
			"|=#     ###|",
			"|##O###   #|",
			"|# @ O  O #|",
			"|# XX# O ##|",
			"|##XX#   #=|",
			"|=########=|",
			"||=========|"
		},//第3关
		{
			"|======|",
			"|=####=|",
			"|##  #=|",
			"|#@O #=|",
			"|##O ##|",
			"|## O #|",
			"|#XO  #|",
			"|#XXQX#|",
			"|######|",
			"||=====|"
		},//第4关
		{
			"|========|",
			"|=#####==|",
			"|=# @###=|",
			"|=# O  #=|",
			"|### # ##|",
			"|#X# #  #|",
			"|#XO  # #|",
			"|#X   O #|",
			"|########|",
			"||=======|"
		},//第5关
		{
			"|=============|",
			"|===#######===|",
			"|####     #===|",
			"|#   X### #===|",
			"|# # #    ##==|",
			"|# # O O#X #==|",
			"|# #  Q  # #==|",
			"|# X#O O # #==|",
			"|##    # # ###|",
			"|=# ###X    @#|",
			"|=#     ##   #|",
			"|=############|",
			"||============|"
		},//第6关
		{
			"|==========|",
			"|===#######|",
			"|==##  # @#|",
			"|==#   #O #|",
			"|==#O  O  #|",
			"|==# O##  #|",
			"|### O # ##|",
			"|#XXXXX  #=|",
			"|#########=|",
			"||=========|"
		},//第7关
		{
			"|==========|",
			"|===######=|",
			"|=###    #=|",
			"|##X O## ##|",
			"|#XXO O @ #|",
			"|#XX O O ##|",
			"|######  #=|",
			"|=====####=|",
			"||=========|"
		},//第8关
		{
			"|===========|",
			"|=#########=|",
			"|=#  ##   #=|",
			"|=#   O   #=|",
			"|=#O ### O#=|",
			"|=# #XXX# #=|",
			"|## #XXX# ##|",
			"|# O  O  O #|",
			"|#     #  @#|",
			"|###########|",
			"||==========|"
		},//第9关
		{
			"|========|",
			"|==######|",
			"|==#    #|",
			"|###OOO #|",
			"|#@ OXX #|",
			"|# OXXX##|",
			"|####  #=|",
			"|===####=|",
			"||=======|"
		},//第10关
		{
			"|============|",
			"|=####==#####|",
			"|##  #==#   #|",
			"|# O ####O  #|",
			"|#  OXXXX O #|",
			"|##    # @ ##|",
			"|=##########=|",
			"||===========|"
		},//第11关
		{
			"|========|",
			"|==#####=|",
			"|###  @#=|",
			"|#  OX ##|",
			"|#  XOX #|",
			"|### QO #|",
			"|==#   ##|",
			"|==######|",
			"||=======|"
		},//第12关
		{
			"|========|",
			"|==####==|",
			"|==#XX#==|",
			"|=## X##=|",
			"|=#  OX#=|",
			"|## O  ##|",
			"|#  #OO #|",
			"|#  @   #|",
			"|########|",
			"||=======|"
		},//第13关
		{
			"|========|",
			"|########|",
			"|#  #   #|",
			"|# OXXO #|",
			"|#@OXQ ##|",
			"|# OXXO #|",
			"|#  #   #|",
			"|########|",
			"||=======|"
		},//第14关
		{
			"|========|",
			"|=######=|",
			"|##    ##|",
			"|# O OO #|",
			"|#XXXXXX#|",
			"|# OO O #|",
			"|### @###|",
			"|==####==|",
			"||=======|"
		},//第15关
		{
			"|==========|",
			"|==########|",
			"|==#    ###|",
			"|==# O    #|",
			"|### O ## #|",
			"|#XXX O   #|",
			"|#XXXO#O ##|",
			"|#### # O #|",
			"|===#   @ #|",
			"|===#######|",
			"||=========|"
		},//第16关
		{
			"|=========|",
			"|######===|",
			"|#    #===|",
			"|# OOO##==|",
			"|#  #XX###|",
			"|##  XXO #|",
			"|=#  @   #|",
			"|=########|",
			"||========|"
		},//第17关
		{
			"|==========|",
			"|==########|",
			"|==#   #X #|",
			"|=##  OXXX#|",
			"|=#  O #QX#|",
			"|## ##O# ##|",
			"|#   O  O #|",
			"|#   #    #|",
			"|#######@ #|",
			"|======####|",
			"||=========|"
		},//第18关
		{
			"|==========|",
			"|=#######==|",
			"|=#XXXX #==|",
			"|###XXXO###|",
			"|#  O#O O #|",
			"|# OO  #O #|",
			"|#    #   #|",
			"|#### @ ###|",
			"|===#####==|",
			"||=========|"
		},//第19关
		{
			"|=======|",
			"|#######|",
			"|#XXOXX#|",
			"|#XX#XX#|",
			"|# OOO #|",
			"|#  O  #|",
			"|# OOO #|",
			"|#  #@ #|",
			"|#######|",
			"||======|"
		},//第20关
		{
			"|===========|",
			"|===######==|",
			"|===# XXX#==|",
			"|####XXXX#==|",
			"|#  ###O ###|",
			"|# O O  OO #|",
			"|#@ O O    #|",
			"|#   ###   #|",
			"|#####=#####|",
			"||==========|"
		},//第21关
		{
			"|=========|",
			"|########=|",
			"|#      #=|",
			"|# #OO  #=|",
			"|# XXX# #=|",
			"|##XXXO ##|",
			"|=# ## O #|",
			"|=#O  O  #|",
			"|=#  #  @#|",
			"|=########|",
			"||========|"
		},//第22关
		{
			"|==========|",
			"|==#####===|",
			"|###   ####|",
			"|#   O  O #|",
			"|# O @O   #|",
			"|###OO#####|",
			"|==#  XX#==|",
			"|==#XXXX#==|",
			"|==######==|",
			"||=========|"
		},//第23关
		{
			"|==============|",
			"|######===#####|",
			"|#    ###=#  X#|",
			"|#  O O #=#XXX#|",
			"|# #  O ###  X#|",
			"|#  OOO   O @X#|",
			"|###  O  O#  X#|",
			"|==#  O#O #XXX#|",
			"|==##     #  X#|",
			"|===###########|",
			"||=============|"
		},//第24关
		{
			"|===========|",
			"|=====######|",
			"|=#####X   #|",
			"|=#  #XX## #|",
			"|=#  OXX   #|",
			"|=#  # X# ##|",
			"|### ##O#  #|",
			"|# O    OO #|",
			"|# #O#  #  #|",
			"|#@  #######|",
			"|#####======|",
			"||==========|"
		},//第25关
		{
			"|=============|",
			"|=#########===|",
			"|=#   ##  ####|",
			"|=# O        #|",
			"|=##O### ##  #|",
			"|=#  ## Q # ##|",
			"|=# OXXXXXX #=|",
			"|## ### X # #=|",
			"|#     O###O#=|",
			"|#   #    O@#=|",
			"|#####O# ####=|",
			"|====#   #====|",
			"|====#####====|",
			"||============|"
		},//第26关
		{
			"|===============|",
			"|======#########|",
			"|======#       #|",
			"|======# # # # #|",
			"|======#  O O# #|",
			"|#######   O   #|",
			"|#XX#  ## O O# #|",
			"|#XX   ## O O  #|",
			"|#XX#  ## ######|",
			"|#XX# # O O #===|",
			"|#XX     O  #===|",
			"|#  ###@  ###===|",
			"|####=#####=====|",
			"||==============|"
		},//第27关
		{
			"|================|",
			"|====####========|",
			"|#####  #========|",
			"|#  O O #=#######|",
			"|#   O  #=#QXQXQ#|",
			"|## O O ###XQXQX#|",
			"|=#O O  #  QXQXQ#|",
			"|=#@O O    XQXQX#|",
			"|=#O O  #  QXQXQ#|",
			"|## O O ###XQXQX#|",
			"|#   O  #=#QXQXQ#|",
			"|#  O O #=#######|",
			"|#####  #========|",
			"|====####========|",
			"||===============|"
		},//第28关
		{
			"|=========|",
			"|########=|",
			"|#XXXXXX#=|",
			"|#  O # ##|",
			"|# O # O #|",
			"|##O O O #|",
			"|=#  @   #|",
			"|=########|",
			"||========|"
		},//第29关
		{
			"|============|",
			"|==##########|",
			"|###    X@  #|",
			"|#   ##O##  #|",
			"|#   Q X X ##|",
			"|## O##O## #=|",
			"|=#    X   #=|",
			"|=##########=|",
			"||===========|"
		},//第30关
		{
			"|=========|",
			"|===######|",
			"|####X  @#|",
			"|#  OOO  #|",
			"|#X##X##X#|",
			"|#   O   #|",
			"|#  OX# ##|",
			"|####   #=|",
			"|===#####=|",
			"||========|"
		},//第31关
		{
			"|========|",
			"|=######=|",
			"|=#X XX#=|",
			"|=#X OX#=|",
			"|###  O##|",
			"|# O  O #|",
			"|# #O## #|",
			"|#   @  #|",
			"|########|",
			"||=======|"
		},//第32关
		{
			"|==============|",
			"|====######====|",
			"|==###    ###==|",
			"|==#   #O   ###|",
			"|==#   O   OO #|",
			"|==# OO #O    #|",
			"|==##   O   O #|",
			"|###### #O#####|",
			"|#XX@ #O  #====|",
			"|#X#XX  O##====|",
			"|#XXXXO# #=====|",
			"|#XXXX   #=====|",
			"|#########=====|",
			"||=============|"
		},//第33关
		{
			"|===============|",
			"|###############|",
			"|#      #      #|",
			"|# O #O # O##O #|",
			"|# #  O #      #|",
			"|#   ##O#O##OO #|",
			"|# # # XXX #   #|",
			"|# O  X # XO   #|",
			"|# O#@OXXX# #  #|",
			"|#    X # X  O #|",
			"|# ##XO###OX # #|",
			"|# # OXXXXX ## #|",
			"|#             #|",
			"|###############|",
			"||==============|"
		},//第34关
		{
			"|==========|",
			"|#########=|",
			"|#   ##  #=|",
			"|# # O O #=|",
			"|#  QX#  #=|",
			"|## #X@X##=|",
			"|##O###Q###|",
			"|#        #|",
			"|#   ## # #|",
			"|######   #|",
			"|=====#####|",
			"||=========|"
		}//第35关
	};


	//变量申明
	//i,t 循环计数器, x 纵坐标, y 横坐标, pass 通关判断条件
	//restep_num 记录每局撤销次数,step_num 记录本局总步数,wide 地图宽度
	int i, t, x, y, pass, restep_num, step_num, wide, high, count;
	//(ch 游戏过程中读取键盘信息, option暂停过程中读取键盘信息及游戏结束返还值,last_step 记录上一步数据)
	char ch, option, last_step;
	//申明两数组，记录终点坐标
	int X_num[50] = { 0 }, Y_num[50] = { 0 }, xnum, ynum;
	//lstep 记录是否撤销过,x_box 记录上一次推箱子前箱的纵坐标子,y_box 记录上一次推箱子前箱的横坐标子, rerestep_num 记录上一次推箱子前所走的步数
	int lstep, x_box, y_box, rerestep_num;

	//初始化变量
	high = wide = step_num = restep_num = pass = 0;
	ch = option = last_step = NULL;
	xnum = ynum = 0;
	lstep = count = 0;

	//初始化起始位置
	for (i = 0; i < 20; i++)
	{
		for (t = 0; map[level][i][t] != '\0'; t++)
			if (map[level][i][t] == '@')
			{
				x = i;
				y = t;
				i = 99;
				break;
			}
	}

	//寻找终点坐标
	for (i = 2; i < 20; i++)
	{
		for (t = 2; map[level][i][t] != '\0'; t++)
		{
			if (map[level][i][t] == 'X' || map[level][i][t] == 'Q')
			{
				X_num[xnum] = i;
				Y_num[ynum] = t;
				xnum++;
				ynum++;
			}
			if (map[level][i][1] == '|')
			{
				i = 99;
				break;
			}
		}
	}
	//计算地图高度
	for (high = 0; high < 20; high++)
		if (map[level][high][0] != '|')
			break;
	high = (13 - high) / 2;

	//计算地图宽度
	wide = (16 - strlen(map[level][0])) / 2;

	//打印地图
	game_face(level, step_num, restep_num);
	for (i = 1; i <= 17; i++)
	{
		for (t = 0; t < strlen(map[level][0]); t++)
		{
			if (map[level][i][t] == '|' || map[level][i][t] == '=')
				putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_black);
			if (map[level][i][t] == ' ')
				putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_land);
			if (map[level][i][t] == 'O')
				putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_BoxYellow);
			if (map[level][i][t] == 'Q')
				putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_BoxRed);
			if (map[level][i][t] == '#')
				putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_wall);
			if (map[level][i][t] == 'X')
				putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_aim);
			if (map[level][i][t] == '@')
				if (ch == 'd' || ch == 'D')
				{
					if (count % 5 > 0)
						putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManRIGHT1);
					else
						putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManRIGHT2);
				}
				else if (ch == 'a' || ch == 'A')
				{
					if (count % 5 > 0)
						putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManLEFT1);
					else
						putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManLEFT2);
				}
				else if (ch == 'w' || ch == 'W')
				{
					if (count % 5 > 0)
						putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManUP1);
					else
						putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManUP2);
				}
				else
				{
					if (count % 5 > 0)
						putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManDOWN1);
					else
						putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManDOWN2);
				}
		}
		if (map[level][i][1] == '|')
			break;
	}


	//游戏主程序
	for (; is_run(); delay_fps(60))
	{
		fflush(stdin);
		Sleep(100);
		// todo: 逻辑更新
		if (kbhit())
		{
			ch = getch();
			ch = tolower(ch);

			switch (ch)
			{
				//向下移动
			case 's':
				if (map[level][x + 1][y] == ' ' || map[level][x + 1][y] == 'X')
				{
					map[level][x][y] = ' ';
					x++;
					map[level][x][y] = '@';
					step_num++;
				}
				else if ((map[level][x + 1][y] == 'O' || map[level][x + 1][y] == 'Q') && map[level][x + 2][y] != 'O' && map[level][x + 2][y] != 'Q' && map[level][x + 2][y] != '#')
				{
					map[level][x][y] = ' ';
					x++;
					map[level][x][y] = '@';
					map[level][x + 1][y] = 'O';
					lstep = 1;
					x_box = x;
					y_box = y;
					rerestep_num = step_num;
					step_num++;
					last_step = ch;//存储上一步信息

					mciSendString(TEXT("seek Boxmove to 0"), NULL, 0, NULL);
					mciSendString(TEXT("play Boxmove"), NULL, 0, NULL);
				}
				break;
				//向上移动
			case 'w':
				if (map[level][x - 1][y] == ' ' || map[level][x - 1][y] == 'X')
				{
					map[level][x][y] = ' ';
					x--;
					map[level][x][y] = '@';
					step_num++;
				}
				else if ((map[level][x - 1][y] == 'O' || map[level][x - 1][y] == 'Q') && map[level][x - 2][y] != 'O' && map[level][x - 2][y] != 'Q' && map[level][x - 2][y] != '#')
				{
					map[level][x][y] = ' ';
					x--;
					map[level][x][y] = '@';
					map[level][x - 1][y] = 'O';
					lstep = 1;
					x_box = x;
					y_box = y;
					rerestep_num = step_num;
					step_num++;
					last_step = ch;//存储上一步信息

					mciSendString(TEXT("seek Boxmove to 0"), NULL, 0, NULL);
					mciSendString(TEXT("play Boxmove"), NULL, 0, NULL);
				}
				break;
				//向左移动
			case 'a':
				if (map[level][x][y - 1] == ' ' || map[level][x][y - 1] == 'X')
				{
					map[level][x][y] = ' ';
					y--;
					map[level][x][y] = '@';
					step_num++;
				}
				else if ((map[level][x][y - 1] == 'O' || map[level][x][y - 1] == 'Q') && map[level][x][y - 2] != 'O' && map[level][x][y - 2] != 'Q' && map[level][x][y - 2] != '#')
				{
					map[level][x][y] = ' ';
					y--;
					map[level][x][y] = '@';
					map[level][x][y - 1] = 'O';
					lstep = 1;
					x_box = x;
					y_box = y;
					rerestep_num = step_num;
					step_num++;
					last_step = ch;//存储上一步信息

					mciSendString(TEXT("seek Boxmove to 0"), NULL, 0, NULL);
					mciSendString(TEXT("play Boxmove"), NULL, 0, NULL);
				}
				break;
				//向右移动
			case 'd':
				if (map[level][x][y + 1] == ' ' || map[level][x][y + 1] == 'X')
				{
					map[level][x][y] = ' ';
					y++;
					map[level][x][y] = '@';
					step_num++;
				}
				else if ((map[level][x][y + 1] == 'O' || map[level][x][y + 1] == 'Q') && map[level][x][y + 2] != 'O' && map[level][x][y + 2] != 'Q'&&map[level][x][y + 2] != '#')
				{
					map[level][x][y] = ' ';
					y++;
					map[level][x][y] = '@';
					map[level][x][y + 1] = 'O';
					lstep = 1;
					x_box = x;
					y_box = y;
					rerestep_num = step_num;
					step_num++;
					last_step = ch;//存储上一步信息

					mciSendString(TEXT("seek Boxmove to 0"), NULL, 0, NULL);
					mciSendString(TEXT("play Boxmove"), NULL, 0, NULL);
				}
				break;

			case 27://暂停界面
				pause();
				while (ch != 'r')
				{
					ch = getch();
					if (ch == 'x' || ch == 'q' || ch == 'n' || ch == 'm' || ch == 'X' || ch == 'Q' || ch == 'N' || ch == 'M')
					{
						option = ch;
						ch = 27;
						break;
					}
				}
				break;

			case 'q'://重玩
				option = ch;
				break;
			}
		}

		//撤销一步
		if (lstep == 1 && ch == 'b'&&restep_num < 3)
		{
			switch (last_step)
			{
				//返还向下移动
			case 's':
				map[level][x][y] = ' ';
				map[level][x_box + 1][y_box] = ' ';
				map[level][x_box][y_box] = 'O';
				x_box--;
				x = x_box;
				y = y_box;
				map[level][x][y] = '@';
				step_num = rerestep_num;
				restep_num++;
				lstep = 0;
				break;
				//返还向上移动
			case 'w':
				map[level][x][y] = ' ';
				map[level][x_box - 1][y_box] = ' ';
				map[level][x_box][y_box] = 'O';
				x_box++;
				x = x_box;
				y = y_box;
				map[level][x][y] = '@';
				step_num = rerestep_num;
				restep_num++;
				lstep = 0;
				break;
				//返还向左移动
			case 'a':
				map[level][x][y] = ' ';
				map[level][x_box][y_box - 1] = ' ';
				map[level][x_box][y_box] = 'O';
				y_box++;
				x = x_box;
				y = y_box;
				map[level][x][y] = '@';
				step_num = rerestep_num;
				restep_num++;
				lstep = 0;
				break;
				//返还向右移动
			case 'd':
				map[level][x][y] = ' ';
				map[level][x_box][y_box + 1] = ' ';
				map[level][x_box][y_box] = 'O';
				y_box--;
				x = x_box;
				y = y_box;
				map[level][x][y] = '@';
				step_num = rerestep_num;
				restep_num++;
				lstep = 0;
				break;
			}
		}

		//if (lstep = 1)
		//	last_step = ch;//存储上一步信息

		//还原终点标记
		for (i = 0; X_num[i] != 0; i++)
		{
			if (map[level][X_num[i]][Y_num[i]] == ' ')
				map[level][X_num[i]][Y_num[i]] = 'X';
			if (map[level][X_num[i]][Y_num[i]] == 'O')
				map[level][X_num[i]][Y_num[i]] = 'Q';
		}



		//中途退出或重玩
		if (ch == 27 || ch == 'q')
		{
			pass = 0;
			break;
		}

		count++;
		if (count == 99)
			count = 0;

		// todo: 图形更新
		// 清屏
		cleardevice();
		//打印地图
		game_face(level, step_num, restep_num);
		for (i = 1; i <= 17; i++)
		{
			for (t = 0; t < strlen(map[level][0]); t++)
			{
				if (map[level][i][t] == '|' || map[level][i][t] == '=')
					putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_black);
				if (map[level][i][t] == ' ')
					putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_land);
				if (map[level][i][t] == 'O')
					putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_BoxYellow);
				if (map[level][i][t] == 'Q')
					putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_BoxRed);
				if (map[level][i][t] == '#')
					putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_wall);
				if (map[level][i][t] == 'X')
					putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_aim);
				if (map[level][i][t] == '@')
					if (ch == 'd' || ch == 'D')
					{
						if (count % 5 > 0)
							putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManRIGHT1);
						else
							putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManRIGHT2);
					}
					else if (ch == 'a' || ch == 'A')
					{
						if (count % 5 > 0)
							putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManLEFT1);
						else
							putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManLEFT2);
					}
					else if (ch == 'w' || ch == 'W')
					{
						if (count % 5 > 0)
							putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManUP1);
						else
							putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManUP2);
					}
					else
					{
						if (count % 5 > 0)
							putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManDOWN1);
						else
							putimage(50 + t * 40 + wide * 40, 20 + i * 40 + high * 40, pimg_ManDOWN2);
					}
			}
			if (map[level][i][1] == '|')
				break;
		}

		//通关条件判定
		for (i = 0; X_num[i] != 0; i++)
		{
			if (map[level][X_num[i]][Y_num[i]] == 'Q')
				pass++;
		}
		if (pass == xnum)
		{
			pass = 1;
			ch = 27;
			Sleep(1000);
			break;
		}
		else
			pass = 0;
	}

	//判断能否继续下一关
	cleardevice();
	if (option != NULL)
	{
		if (option == 'n')
		{
			if (level == maps_num - 1)
			{
				lastlevel();
				option = 'p';
				Sleep(1500);
				system("cls");
			}
		}

		delimage(pimg_wall);
		delimage(pimg_land);
		delimage(pimg_BoxYellow);
		delimage(pimg_BoxRed);
		delimage(pimg_aim);
		delimage(pimg_ManUP1);
		delimage(pimg_ManUP2);
		delimage(pimg_ManDOWN1);
		delimage(pimg_ManDOWN2);
		delimage(pimg_ManRIGHT1);
		delimage(pimg_ManRIGHT2);
		delimage(pimg_ManLEFT1);
		delimage(pimg_ManLEFT2);
		delimage(pimg_black);
		return option;
	}

	//通关界面
	if (pass == 1)
	{
		passlevel(step_num);
	}
	while (pass == 1)
	{
		option = getch();
		if (option == 27)
			option = 'm';
		if (option == 'n' || option == 'N')
		{
			if (level == maps_num - 1)
			{
				lastlevel();
				option = 'p';
				Sleep(1500);
				cleardevice();
			}
		}
		if (option == 'x' || option == 'q' || option == 'n' || option == 'p' || option == 'm' || option == 'X' || option == 'Q' || option == 'N' || option == 'P' || option == 'M')
		{
			cleardevice();

			delimage(pimg_wall);
			delimage(pimg_land);
			delimage(pimg_BoxYellow);
			delimage(pimg_BoxRed);
			delimage(pimg_aim);
			delimage(pimg_ManUP1);
			delimage(pimg_ManUP2);
			delimage(pimg_ManDOWN1);
			delimage(pimg_ManDOWN2);
			delimage(pimg_ManRIGHT1);
			delimage(pimg_ManRIGHT2);
			delimage(pimg_ManLEFT1);
			delimage(pimg_ManLEFT2);
			delimage(pimg_black);
			return option;
		}
	}

	delimage(pimg_wall);
	delimage(pimg_land);
	delimage(pimg_BoxYellow);
	delimage(pimg_BoxRed);
	delimage(pimg_aim);
	delimage(pimg_ManUP1);
	delimage(pimg_ManUP2);
	delimage(pimg_ManDOWN1);
	delimage(pimg_ManDOWN2);
	delimage(pimg_ManRIGHT1);
	delimage(pimg_ManRIGHT2);
	delimage(pimg_ManLEFT1);
	delimage(pimg_ManLEFT2);
	delimage(pimg_black);
	return option;
}

void game_face(int level, int step_num, int restep_num)
{
	cleardevice();

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(750, 0, 755, 700);

	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	setfont(48, 0, "楷体");
	setbkmode(TRANSPARENT);
	char str[20];
	sprintf(str, "第%d关", level + 1);
	outtextxy(800, 100, str);
	setfont(24, 0, "楷体");
	sprintf(str, "步数：%d", step_num);
	outtextxy(780, 250, str);

	sprintf(str, "剩余撤销次数：%d", 3 - restep_num);
	outtextxy(780, 300, str);

	outtextxy(780, 350, "重玩本关(Q)");
	outtextxy(780, 400, "撤销(B)");
	outtextxy(780, 450, "菜单(M)");
}

void pause()
{
	cleardevice();

	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	setfont(48, 0, "楷体");
	setbkmode(TRANSPARENT);
	outtextxy(400, 200, "继续(R)");

	setfont(40, 0, "楷体");
	outtextxy(140, 300, "选关(X)");
	outtextxy(320, 300, "重玩(Q)");
	outtextxy(480, 300, "下一关(N)");
	outtextxy(700, 300, "菜单(M)");
}

void lastlevel()
{
	cleardevice();

	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	setfont(48, 0, "楷体");
	setbkmode(TRANSPARENT);
	outtextxy(280, 250, "这已经是最后一关了！");
}

void passlevel(int step_num)
{
	cleardevice();

	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));
	setfont(60, 0, "楷体");
	setbkmode(TRANSPARENT);
	outtextxy(420, 150, "过关！");

	setfont(40, 0, "楷体");
	char str[20];
	sprintf(str, "本关总计步数:%d", step_num);
	outtextxy(350, 250, str);

	setfont(40, 0, "楷体");
	outtextxy(140, 350, "选关(X)");
	outtextxy(320, 350, "重玩(Q)");
	outtextxy(480, 350, "下一关(N)");
	outtextxy(700, 350, "菜单(M)");
}
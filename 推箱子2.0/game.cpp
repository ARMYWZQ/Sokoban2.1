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

	//���弰��ʼ����ͼ
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
		},//��1��
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
		},//��2��
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
		},//��3��
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
		},//��4��
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
		},//��5��
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
		},//��6��
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
		},//��7��
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
		},//��8��
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
		},//��9��
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
		},//��10��
		{
			"|============|",
			"|=####==#####|",
			"|##  #==#   #|",
			"|# O ####O  #|",
			"|#  OXXXX O #|",
			"|##    # @ ##|",
			"|=##########=|",
			"||===========|"
		},//��11��
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
		},//��12��
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
		},//��13��
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
		},//��14��
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
		},//��15��
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
		},//��16��
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
		},//��17��
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
		},//��18��
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
		},//��19��
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
		},//��20��
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
		},//��21��
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
		},//��22��
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
		},//��23��
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
		},//��24��
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
		},//��25��
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
		},//��26��
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
		},//��27��
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
		},//��28��
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
		},//��29��
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
		},//��30��
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
		},//��31��
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
		},//��32��
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
		},//��33��
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
		},//��34��
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
		}//��35��
	};


	//��������
	//i,t ѭ��������, x ������, y ������, pass ͨ���ж�����
	//restep_num ��¼ÿ�ֳ�������,step_num ��¼�����ܲ���,wide ��ͼ���
	int i, t, x, y, pass, restep_num, step_num, wide, high, count;
	//(ch ��Ϸ�����ж�ȡ������Ϣ, option��ͣ�����ж�ȡ������Ϣ����Ϸ��������ֵ,last_step ��¼��һ������)
	char ch, option, last_step;
	//���������飬��¼�յ�����
	int X_num[50] = { 0 }, Y_num[50] = { 0 }, xnum, ynum;
	//lstep ��¼�Ƿ�����,x_box ��¼��һ��������ǰ�����������,y_box ��¼��һ��������ǰ��ĺ�������, rerestep_num ��¼��һ��������ǰ���ߵĲ���
	int lstep, x_box, y_box, rerestep_num;

	//��ʼ������
	high = wide = step_num = restep_num = pass = 0;
	ch = option = last_step = NULL;
	xnum = ynum = 0;
	lstep = count = 0;

	//��ʼ����ʼλ��
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

	//Ѱ���յ�����
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
	//�����ͼ�߶�
	for (high = 0; high < 20; high++)
		if (map[level][high][0] != '|')
			break;
	high = (13 - high) / 2;

	//�����ͼ���
	wide = (16 - strlen(map[level][0])) / 2;

	//��ӡ��ͼ
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


	//��Ϸ������
	for (; is_run(); delay_fps(60))
	{
		fflush(stdin);
		Sleep(100);
		// todo: �߼�����
		if (kbhit())
		{
			ch = getch();
			ch = tolower(ch);

			switch (ch)
			{
				//�����ƶ�
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
					last_step = ch;//�洢��һ����Ϣ

					mciSendString(TEXT("seek Boxmove to 0"), NULL, 0, NULL);
					mciSendString(TEXT("play Boxmove"), NULL, 0, NULL);
				}
				break;
				//�����ƶ�
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
					last_step = ch;//�洢��һ����Ϣ

					mciSendString(TEXT("seek Boxmove to 0"), NULL, 0, NULL);
					mciSendString(TEXT("play Boxmove"), NULL, 0, NULL);
				}
				break;
				//�����ƶ�
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
					last_step = ch;//�洢��һ����Ϣ

					mciSendString(TEXT("seek Boxmove to 0"), NULL, 0, NULL);
					mciSendString(TEXT("play Boxmove"), NULL, 0, NULL);
				}
				break;
				//�����ƶ�
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
					last_step = ch;//�洢��һ����Ϣ

					mciSendString(TEXT("seek Boxmove to 0"), NULL, 0, NULL);
					mciSendString(TEXT("play Boxmove"), NULL, 0, NULL);
				}
				break;

			case 27://��ͣ����
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

			case 'q'://����
				option = ch;
				break;
			}
		}

		//����һ��
		if (lstep == 1 && ch == 'b'&&restep_num < 3)
		{
			switch (last_step)
			{
				//���������ƶ�
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
				//���������ƶ�
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
				//���������ƶ�
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
				//���������ƶ�
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
		//	last_step = ch;//�洢��һ����Ϣ

		//��ԭ�յ���
		for (i = 0; X_num[i] != 0; i++)
		{
			if (map[level][X_num[i]][Y_num[i]] == ' ')
				map[level][X_num[i]][Y_num[i]] = 'X';
			if (map[level][X_num[i]][Y_num[i]] == 'O')
				map[level][X_num[i]][Y_num[i]] = 'Q';
		}



		//��;�˳�������
		if (ch == 27 || ch == 'q')
		{
			pass = 0;
			break;
		}

		count++;
		if (count == 99)
			count = 0;

		// todo: ͼ�θ���
		// ����
		cleardevice();
		//��ӡ��ͼ
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

		//ͨ�������ж�
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

	//�ж��ܷ������һ��
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

	//ͨ�ؽ���
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
	setfont(48, 0, "����");
	setbkmode(TRANSPARENT);
	char str[20];
	sprintf(str, "��%d��", level + 1);
	outtextxy(800, 100, str);
	setfont(24, 0, "����");
	sprintf(str, "������%d", step_num);
	outtextxy(780, 250, str);

	sprintf(str, "ʣ�೷��������%d", 3 - restep_num);
	outtextxy(780, 300, str);

	outtextxy(780, 350, "���汾��(Q)");
	outtextxy(780, 400, "����(B)");
	outtextxy(780, 450, "�˵�(M)");
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
	setfont(48, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(400, 200, "����(R)");

	setfont(40, 0, "����");
	outtextxy(140, 300, "ѡ��(X)");
	outtextxy(320, 300, "����(Q)");
	outtextxy(480, 300, "��һ��(N)");
	outtextxy(700, 300, "�˵�(M)");
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
	setfont(48, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(280, 250, "���Ѿ������һ���ˣ�");
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
	setfont(60, 0, "����");
	setbkmode(TRANSPARENT);
	outtextxy(420, 150, "���أ�");

	setfont(40, 0, "����");
	char str[20];
	sprintf(str, "�����ܼƲ���:%d", step_num);
	outtextxy(350, 250, str);

	setfont(40, 0, "����");
	outtextxy(140, 350, "ѡ��(X)");
	outtextxy(320, 350, "����(Q)");
	outtextxy(480, 350, "��һ��(N)");
	outtextxy(700, 350, "�˵�(M)");
}
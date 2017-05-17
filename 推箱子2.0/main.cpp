//==========================
//程序名称：推箱子2.0
//制作人：杨新瑞
//创建时间：2017.1.30 9:52
//上次修改时间：2017.2.11 20:59
//总制作天数：3
//==========================
#include"head.h"

//窗口尺寸
#define Win_L 1000
#define Win_H 600

int main(void)
{
	

	int level, level_option, i;
	char option, ch;

	level = 0;
	option = 'M';
	ch = NULL;

	ege::setinitmode(ege::INIT_ANIMATION);
	// 图形初始化
	ege::initgraph(Win_L, Win_H);
	// 随机数初始化，如果需要使用随机数的话
	ege::randomize();
	// 程序主循环
	//主程序
	while (is_run())
	{
		//主菜单1
		main_interface1();
		while (is_run())
		{
			option = getch();
			if (option == 's' || option == 'S' || option == 27)
				break;
		}
		while (is_run())
		{
			if (option == 's' || option == 'S')//打印主菜单2
			{
				main_interface2();
				while (1)
				{
					option = getch();
					if (option == 'a' || option == 'A' || option == 'x' || option == 'X' || option == 'r' || option == 'R')
						break;
				}
			}
			if (option == 'n' || option == 'N')//进入下一关
			{
				system("cls");
				level++;
				option = mainloop(level);//进入游戏
			}
			if (option == 'q' || option == 'Q')//重玩本关
			{
				system("cls");
				option = mainloop(level);//进入游戏
			}
			if (option == 'a' || option == 'A')//从头开始
			{
				system("cls");
				level = 0;
				option = mainloop(level);//进入游戏
			}
			if (option == 'x' || option == 'X')//选关
			{
				level_option = 1;
				while (1)
				{
					xuanguan(level_option);
					ch = NULL;
					ch = getch();

					if ((ch == 'w' || ch == 'W') && level_option < maps_num)
						level_option++;
					if ((ch == 's' || ch == 'S') && level_option > 1)
						level_option--;
					if (ch == 13)
					{
						option = 'q';
						level = level_option - 1;
						break;
					}
					if (ch == 'r' || ch == 'R')
					{
						option = 's';
						break;
					}
				}
			}
			if (option == 'p' || option == 'P')//通关重置数据
			{
				option = 'm';
				level = 0;
				break;
			}
			if (option == 'm' || option == 'M' || option == 'r' || option == 'R')//主菜单1选择
			{
				break;
			}
			if (option == 27)//退出程序
				break;
		}
		if (option == 27)//退出程序
			break;
	}

	jieyu();
	Sleep(2000);

	// 关闭绘图设备
	ege::closegraph();
	return 0;
}

void main_interface1()
{
	PIMAGE pimg_logo = newimage();
	getimage(pimg_logo, "logo.jpg", 0, 0);

	//清屏
	cleardevice();
	
	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	//文字背景色（注意setbkcolor函数也会同时改变文字背景色）
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	setbkmode(TRANSPARENT);
	putimage(280, 50, pimg_logo);
	setfont(48, 0, "楷体");
	outtextxy(400, 300, "开始(S)");
	outtextxy(380, 400, "退出(ESC)");

	delimage(pimg_logo);
}

void main_interface2()
{
	PIMAGE pimg_logo = newimage();
	getimage(pimg_logo, "logo.jpg", 0, 0);
	//清屏
	cleardevice();

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	//文字背景色（注意setbkcolor函数也会同时改变文字背景色）
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	//设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
	setfont(80, 0, "楷体");

	//要使用特殊格式化字符请用outtextrect
	//设置文字背景填充方式为透明，默认为OPAQUE不透明
	setbkmode(TRANSPARENT);
	putimage(280, 50, pimg_logo);
	
	setfont(48, 0, "楷体");
	outtextxy(360, 300, "从头开始(A)");
	outtextxy(400, 350, "选关(X)");
	outtextxy(400, 400, "返回(R)");

	delimage(pimg_logo);
}

void jieyu()
{
	//清屏
	cleardevice();

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	//文字背景色（注意setbkcolor函数也会同时改变文字背景色）
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	//设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
	//如果高度为12，即相当于小五号字，或者9磅字，实际的换算就自己完成吧
	setfont(48, 0, "楷体");

	//写文字，注意：outtextxy不支持\t \n这类格式化用的特殊字符，这类字符会被忽略
	//要使用特殊格式化字符请用outtextrect
	//设置文字背景填充方式为透明，默认为OPAQUE不透明
	setbkmode(TRANSPARENT);
	outtextxy(330, 200, "南宫大仙 出品");
	outtextxy(370, 280, "逆虹 测试");
}

void xuanguan(int level)
{
	//清屏
	cleardevice();

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	//文字背景色（注意setbkcolor函数也会同时改变文字背景色）
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	//设置字体，第一个参数是字体的高度（像素），第二个参数是字体的宽度，第二个参数如果为0，就使用默认比例值
	//如果高度为12，即相当于小五号字，或者9磅字，实际的换算就自己完成吧
	setfont(48, 0, "楷体");

	//写文字，注意：outtextxy不支持\t \n这类格式化用的特殊字符，这类字符会被忽略
	//要使用特殊格式化字符请用outtextrect
	//设置文字背景填充方式为透明，默认为OPAQUE不透明
	setbkmode(TRANSPARENT);
	outtextxy(340, 200, "按W，S键选关");
	char str[20];
	sprintf(str, "关卡:%d", level);
	outtextxy(400, 300, str);
	outtextxy(400, 400, "返回(R)");
}
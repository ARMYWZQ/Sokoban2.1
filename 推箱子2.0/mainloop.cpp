#include"founction.h"

void mainloop()
{
	int level, level_option;
	char option, ch;

	level = 0;
	option = 'M';
	ch = NULL;

	//������
	while (is_run())
	{
		//���˵�1
		main_interface1();
		while (is_run())
		{
			option = getch();
			if (option == 's' || option == 'S' || option == 27)
				break;
		}
		while (is_run())
		{
			if (option == 's' || option == 'S')//��ӡ���˵�2
			{
				main_interface2();
				while (1)
				{
					option = getch();
					if (option == 'a' || option == 'A' || option == 'x' || option == 'X' || option == 'r' || option == 'R')
						break;
				}
			}
			if (option == 'n' || option == 'N')//������һ��
			{
				system("cls");
				level++;
				option = gameloop(level);//������Ϸ
			}
			if (option == 'q' || option == 'Q')//���汾��
			{
				system("cls");
				option = gameloop(level);//������Ϸ
			}
			if (option == 'a' || option == 'A')//��ͷ��ʼ
			{
				system("cls");
				level = 0;
				option = gameloop(level);//������Ϸ
			}
			if (option == 'x' || option == 'X')//ѡ��
			{
				level_option = 1;
				while (is_run())
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
			if (option == 'p' || option == 'P')//ͨ����������
			{
				option = 'm';
				level = 0;
				break;
			}
			if (option == 'm' || option == 'M' || option == 'r' || option == 'R')//���˵�1ѡ��
			{
				break;
			}
			if (option == 27)//�˳�����
				break;
		}
		if (option == 27)//�˳�����
			break;
	}

	jieyu();
	Sleep(2000);
}

void main_interface1()
{
	PIMAGE pimg_logo = newimage();
	getimage(pimg_logo, "data\\Picture\\logo.jpg", 0, 0);

	//����
	cleardevice();

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	//���ֱ���ɫ��ע��setbkcolor����Ҳ��ͬʱ�ı����ֱ���ɫ��
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	setbkmode(TRANSPARENT);
	putimage(280, 50, pimg_logo);
	setfont(48, 0, "����");
	outtextxy(400, 300, "��ʼ(S)");
	outtextxy(380, 400, "�˳�(ESC)");

	delimage(pimg_logo);
}

void main_interface2()
{
	PIMAGE pimg_logo = newimage();
	getimage(pimg_logo, "data\\Picture\\logo.jpg", 0, 0);
	//����
	cleardevice();

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	//���ֱ���ɫ��ע��setbkcolor����Ҳ��ͬʱ�ı����ֱ���ɫ��
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	//�������壬��һ������������ĸ߶ȣ����أ����ڶ�������������Ŀ�ȣ��ڶ����������Ϊ0����ʹ��Ĭ�ϱ���ֵ
	setfont(80, 0, "����");

	//Ҫʹ�������ʽ���ַ�����outtextrect
	//�������ֱ�����䷽ʽΪ͸����Ĭ��ΪOPAQUE��͸��
	setbkmode(TRANSPARENT);
	putimage(280, 50, pimg_logo);

	setfont(48, 0, "����");
	outtextxy(360, 300, "��ͷ��ʼ(A)");
	outtextxy(400, 350, "ѡ��(X)");
	outtextxy(400, 400, "����(R)");

	delimage(pimg_logo);
}

void jieyu()
{
	//����
	cleardevice();

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	//���ֱ���ɫ��ע��setbkcolor����Ҳ��ͬʱ�ı����ֱ���ɫ��
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	//�������壬��һ������������ĸ߶ȣ����أ����ڶ�������������Ŀ�ȣ��ڶ����������Ϊ0����ʹ��Ĭ�ϱ���ֵ
	//����߶�Ϊ12�����൱��С����֣�����9���֣�ʵ�ʵĻ�����Լ���ɰ�
	setfont(200, 0, "����");

	//д���֣�ע�⣺outtextxy��֧��\t \n�����ʽ���õ������ַ��������ַ��ᱻ����
	//Ҫʹ�������ʽ���ַ�����outtextrect
	//�������ֱ�����䷽ʽΪ͸����Ĭ��ΪOPAQUE��͸��
	setbkmode(TRANSPARENT);
	outtextxy(330, 200, "SIRI");
}

void xuanguan(int level)
{
	//����
	cleardevice();

	setcolor(EGERGB(0x40, 0xE0, 0xD0));
	setfillcolor(WHITE);
	bar(0, 595, 1000, 600);
	bar(0, 0, 5, 600);
	bar(995, 0, 1000, 600);

	//���ֱ���ɫ��ע��setbkcolor����Ҳ��ͬʱ�ı����ֱ���ɫ��
	setfontbkcolor(EGERGB(0x80, 0x00, 0x80));

	//�������壬��һ������������ĸ߶ȣ����أ����ڶ�������������Ŀ�ȣ��ڶ����������Ϊ0����ʹ��Ĭ�ϱ���ֵ
	//����߶�Ϊ12�����൱��С����֣�����9���֣�ʵ�ʵĻ�����Լ���ɰ�
	setfont(48, 0, "����");

	//д���֣�ע�⣺outtextxy��֧��\t \n�����ʽ���õ������ַ��������ַ��ᱻ����
	//Ҫʹ�������ʽ���ַ�����outtextrect
	//�������ֱ�����䷽ʽΪ͸����Ĭ��ΪOPAQUE��͸��
	setbkmode(TRANSPARENT);
	outtextxy(340, 200, "��W��S��ѡ��");
	char str[20];
	sprintf(str, "�ؿ�:%d", level);
	outtextxy(400, 300, str);
	outtextxy(400, 400, "����(R)");
}
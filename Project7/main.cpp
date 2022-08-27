#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<winsock.h>
#include<mysql.h>//需调用winsock所以先引用winsock
#include <graphics.h>
#include <conio.h>
#include<time.h>
#include <fstream>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
//#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "MSIMG32.LIB")

//
//struct game_data_head
//{
//	int data_index;
//};
//
//struct game_save
//{
//	int second;
//
//	time_t clock;
//};
int count = 0;
char arr1[64];
char arr2[64];
char arr3[64];
char del[64];
void settextheight(int px)
{
	LOGFONT font;

	gettextstyle(&font);

	font.lfHeight = px;

	settextstyle(&font);
}

//std::vector<game_save> saves;

void menu_ui()
{
	settextheight(70);

	settextcolor(RGB(30, 30, 30));

	setbkcolor(RGB(244, 245, 249));

	cleardevice();

	outtextxy(30, 50, "PPT设计与演讲大赛");

	setfillcolor(RGB(93, 103, 251));

	solidrectangle(110, 180, 110 + 330, 40 + 180);
	//solidrectangle(110, 250, 330 + 110, 40 + 250);
	solidrectangle(162, 500, 217 + 163, 40 + 500);
	//solidrectangle(163, 343, 217 + 163, 40 + 343);
	settextcolor(RGB(251, 251, 251));

	settextheight(40);

	outtextxy(130, 180, "勇攀高峰");
	outtextxy(300, 180, "展示自我");
	outtextxy(200, 500, "开始抽奖");
	settextheight(23);

	//wchar_t* text = new wchar_t[1024];

	settextcolor(RGB(30, 30, 30));
}

void init_game()
{
	initgraph(540, 660);

	SetWindowText(GetHWnd(), "      抽奖游戏");

	// Read game save
	//std::ifstream game_dat("./game.dat");

	//game_data_head head;
	//game_save	   save;

	//game_dat.read((char*)&head, sizeof(&head));

	//for (int count = 0; count < head.data_index; ++count)
	//{
	//	//game_dat.read((char*)&save, sizeof(&save));

	//	saves.push_back(save);
	//}

	//game_dat.close();

	//std::sort(saves.begin(), saves.end(), [](game_save r, game_save l) -> bool { return r.second < l.second; });

	LOGFONT font;

	gettextstyle(&font);

	font.lfQuality = PROOF_QUALITY;

	_tcscpy_s(font.lfFaceName, "微软雅黑");

	setbkmode(TRANSPARENT);

	settextstyle(&font);

	menu_ui();
}

void free_game()
{
	closegraph();
}

// Every number's button
//struct map_button
//{
//	int x;
//	int y;
//};

//map_button button[5][5];
//
//COLORREF   button_color[5][5] = { { RGB(245, 248, 251) } };

//time_t start_time;


void draw_map(bool show_number = true)
{

	setfillcolor(RGB(93, 103, 251));

	settextheight(28);

	solidrectangle(183, 599, 183 + 175, 599 + 40);

	settextcolor(RGB(251, 251, 251));

	outtextxy(230, 603, "  抽奖");
}

void test2() {
	cleardevice();
	ExMessage message;
	BeginBatchDraw();

	settextheight(19);

	settextcolor(RGB(30, 30, 30));
	fillrectangle(100, 100, 450, 150);
	fillrectangle(100, 200, 450, 250);
	fillrectangle(100, 300, 450, 350);
	settextcolor(RGB(251, 251, 251));
	settextheight(28);
	outtextxy(170, 120, arr1);
	outtextxy(170, 220, arr2);
	outtextxy(170, 320, arr3);
	FlushBatchDraw();
}

void test1() {
	cleardevice();
	ExMessage message;
	BeginBatchDraw();

	settextheight(19);

	settextcolor(RGB(30, 30, 30));
	fillrectangle(100, 100, 450, 150);
	fillrectangle(100, 200, 450, 250);
	solidrectangle(183, 599, 183 + 175, 599 + 40);
	settextcolor(RGB(251, 251, 251));
	settextheight(28);
	outtextxy(230, 603, "  抽奖");
	outtextxy(170, 120, arr1);
	outtextxy(170, 220, arr2);
	FlushBatchDraw();
	while (true)
	{
		getmessage(&message);

		if (message.message == WM_LBUTTONDOWN)
		{
			if (message.x >= 183 && message.y >= 599 &&
				message.x <= 185 + 175 && message.y <= 599 + 40)
			{
				test2();
				break;
			}
		}
	}
}

void test() {
	int ret = 0;
	MYSQL* mysql = mysql_init(0);//初始化mysql的执行环境
	mysql_real_connect(mysql, "127.0.0.1", "root", "071411", "Lucky", 0, 0, 0);
	mysql_query(mysql, "set names gbk");



	ret = rand() % 300;
	sprintf(arr1, "select * from sheet where serial_number=%d",ret);
	sprintf(del, "delete from number where serial_number=%d", ret);
	mysql_query(mysql,arr1);
	MYSQL_RES* result = mysql_store_result(mysql);
	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	sprintf_s(arr1,"第%d次抽奖的号码为%s",count++,row[1]);
	mysql_query(mysql, del);


	ret = rand() % 300;
	sprintf(arr2, "select * from sheet where serial_number=%d", ret);
	sprintf(del, "delete from number where serial_number=%d", ret);
	mysql_query(mysql, arr2);
	result = mysql_store_result(mysql);
	row = mysql_fetch_row(result);
	sprintf_s(arr2, "第%d次抽奖的号码为%s", count++, row[1]);
	mysql_query(mysql, del);

	ret = rand() % 300;
	sprintf(arr3, "select * from sheet where serial_number=%d", ret);
	sprintf(del, "delete from number where serial_number=%d", ret);
	mysql_query(mysql, arr3);
	result = mysql_store_result(mysql);
	row = mysql_fetch_row(result);
	sprintf_s(arr3, "第%d次抽奖的号码为%s", count++, row[1]);
	mysql_query(mysql, del);


	mysql_free_result(result);
	cleardevice();
	ExMessage message;
	BeginBatchDraw();

	settextheight(19);

	settextcolor(RGB(30, 30, 30));
	fillrectangle(100, 100, 450, 150);
	settextcolor(RGB(251, 251, 251));
	solidrectangle(183, 599, 183 + 175, 599 + 40);
	settextheight(28);
	outtextxy(170, 120,arr1);
	outtextxy(230, 603, "  抽奖");
	FlushBatchDraw();
	mysql_close(mysql);//关闭数据库连接，程序最后必须关闭链接否者mysql服务器会有卡死的可能性
	printf("关闭数据库成功\n");

	while (true)
	{
		getmessage(&message);

		if (message.message == WM_LBUTTONDOWN)
		{
			if (message.x >= 183 && message.y >= 599 &&
				message.x <= 185 + 175 && message.y <= 599 + 40)
			{
				test1();
				break;
			}
		}
	}

}


void start_game()
{
	cleardevice();


	draw_map(false);

	int last_number = 0;
	ExMessage message;
	BeginBatchDraw();

	settextheight(19);

	settextcolor(RGB(30, 30, 30));

	outtextxy(208, 569, "点击抽奖按钮开始");

	FlushBatchDraw();
	while (true)
	{
		getmessage(&message);

		if (message.message == WM_LBUTTONDOWN)
		{
			if (message.x >= 183 && message.y >= 599 &&
				message.x <= 185+175 && message.y <= 599+40)
			{//183, 599, 183 + 175, 599 + 40
				count++;
				test();
				break;
			}
		}
	}
}

int main()
{
	mciSendString("open 1.mp3 alias bkmusic", NULL, 0, NULL);
	mciSendString("play bkmusic repeat", NULL, 0, NULL);     //循环播放音乐
	memset(arr1, 0x00, sizeof(arr1));
	memset(arr2, 0x00, sizeof(arr2));
	memset(arr3, 0x00, sizeof(arr3));
	memset(del, 0x00, sizeof(del));
	srand(time(NULL));
	init_game();

	ExMessage message;

	while (true)
	{
		getmessage(&message);

		if (message.message == WM_LBUTTONDOWN)
		{//162, 500, 217 + 163, 40 + 500
			if (message.x >= 162 && message.y >= 500 &&
				message.x <= 217 + 163 && message.y <= 500 + 40)
			{
				start_game();
				break;
			}
		}
	}

	_getch();

	free_game();
 system("pause");
	return 0;
}
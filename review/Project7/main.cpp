//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream> 
//#include <algorithm> 
//#include <stdio.h> 
//#include <string.h> 
//#include <stdlib.h> 
//using namespace std;
//
//char pp[2][3] = { "A1","A2" };
//int ppsl[10];
//char pz[6][3] = { "B1","B2","B3","B4","B5","B6" };
//int pzsl[10];
//char dl[2][5] = { "汽油","柴油" };
//int dlsl[10];
//char qd[2][5] = { "二驱","四驱" };
//int qdsl[10];
//char ys[11][5] = { "黑色","白色","蓝色","棕色","金色","R","S","红色","黄色","银色","灰色" };
//int yssl[11];
//
//int z[1000]; int zl;
//int y[1000]; int yl;
//int x[1000]; int xl;
//int w[1000]; int wl;
//int v[1000]; int vl;
//struct A1
//{
//	int pz[6];
//	int dl[2];
//	int qd[2];
//	int ys[9];
//};
//struct A2
//{
//	int pz[6];
//	int dl[2];
//	int qd[2];
//	int ys[9];
//};
//A1 a1; A2 a2;
//int hcz[4];
//void hcsf(int b)
//{
//	int n, x, q, e, r, c;
//	q = 70; e = 70; r = 70;//第一、三、四组 70 辆 
//	n = b / 70;//求出有几组满编（70 辆）的组 
//	x = b % (n * 70); //求出余数 X 
//	if (x < 50)//如果余数 x 小于最低组数 50 
//	{
//		q = 70 - (50 - x);//将第一组的黑车调动到第二组 
//		if (x < 50)//如果第一组调配 20 辆还不够的话 
//		{
//			c = 50 - x; //需要调剂的数量 
//			if (c < 20)
//			{
//				q = q - c;//第一组减去调动的车数 
//				x = x + c;//第二组获得第一组调配的 车数 
//			}
//			else
//			{
//				q = q - 20;
//				x = x + 20;
//				c = 50 - x;
//				if (c < 20)
//				{
//					e = e - c;//第三组减去调动的车数 
//					x = x + c;
//				}
//				else
//				{
//					e = e - 20;
//					x = x + 20;
//					c = 50 - x;// 
//					if (c < 20)
//					{
//						r = r - c;//第四组减去调动的车数 
//						x = x + c;
//					}
//					else
//					{
//						printf("数据错误\n");
//					}
//				}
//			}
//		}
//	}
//	if (x >= 50)//如果余数 x 大于最低要求的 50 辆 
//	{
//		hcz[0] = q; hcz[1] = x; hcz[2] = e; hcz[3] = r;
//	}
//}
//int sum(int* p, int i)
//{
//	int s = 0;
//	while (i--)
//		s += p[i];
//	return s;
//}
//int main(int argc, char* argv[])
//{
//	int twt;
//	printf("请输入需要连续分析的天数（文件创建在 D 盘）\n（要连续分析 7 天的数据则输入 7）\n");
//	scanf_s("%d", &twt);
//	FILE* fp;
//	fp = fopen("D:\\schedule.xls", "a+");//创建表到 D 盘的 EXCEL 
//	setbuf(stdin, NULL);
//	for (int q = 1; q <= twt; q++)
//	{
//		int zab, zbb, zaw, zbw;
//		zl = 0;
//		int ab, bb, aw, bw;
//		printf("A1 型号的数据:\n");
//		printf("输入各配置数量的和（输入 B1、B2、B3、B4、B5、B6 的和，若无则输入 0）:\n"); for (int i = 0; i < 6; i++)scanf_s(" % d", &a1.pz[i]);
//		printf("输入各动力数量的和(输入汽油、柴油车数量的和，若无则输入0) :\n"); for (int i = 0; i < 2; i++)scanf_s(" % d", &a1.dl[i]);
//		printf(" 输 入 各 驱 动 数 量 的 和 （ 输 入 二 驱 、 四 驱 数 量 ） :\n"); for (int
//			i = 0; i < 2; i++)scanf_s("%d", &a1.qd[i]);
//		printf("输入各颜色数量的和（输入黑色、白色、蓝色、棕色、金色、R 类车（红色黄色之和）、\nS 类车（银色灰色之和）、红色、黄色、银色、灰色） : \n"); for (int
//			i = 0; i < 11; i++)scanf_s("%d", &a1.ys[i]);
//		zab = ab = sum(a1.ys, 7) / 2;
//		zaw = aw = sum(a1.ys, 7) - ab;
//		printf("A2:");
//		printf("输入各配置数量的和（输入 B1、B2、B3、B4、B5、B6 的和，若无则输入 0）:\n"); for (int i = 0; i < 6; i++)scanf_s(" % d", &a2.pz[i]);
//		printf("输入各动力数量的和(输入汽油、柴油车数量的和，若无则输入0) :\n"); for (int i = 0; i < 2; i++)scanf_s(" % d", &a2.dl[i]);
//		printf(" 输 入 各 驱 动 数 量 的 和 （ 输 入 二 驱 、 四 驱 数 量 ） :\n"); for (int
//			i = 0; i < 2; i++)scanf_s("%d", &a2.qd[i]);
//		printf("输入各颜色数量的和（输入黑色、白色、蓝色、棕色、金色、R 类车（红色黄色之和）、\nS 类车（银色灰色之和）、红色、黄色、银色、灰色） : \n"); for (int
//			i = 0; i < 11; i++)scanf_s("%d", &a2.ys[i]);
//		zbb = bb = sum(a2.ys, 7) / 2;
//		zbw = bw = sum(a2.ys, 7) - bb;
//		hcsf(a1.ys[0] + a2.ys[0]);//黑车分组 
//		for (int i = 0; i < hcz[0]; i++)//第一次黑车 
//			z[zl++] = 0;
//		a1.ys[0] -= hcz[0];
//		ab -= hcz[0];
//		for (; a1.ys[2] != 0;)//蓝、白车 
//		{
//			if (zl % 2 == 0)
//			{
//				z[zl++] = 2; ab--; a1.ys[2]--;
//				if (ab == 0)break;
//				z[zl++] = 1; ab--; a1.ys[1]--;
//				if (ab == 0)break;
//			}
//			else
//			{
//				z[zl++] = 1; ab--; a1.ys[1]--;
//				if (ab == 0)break;
//				z[zl++] = 2; ab--; a1.ys[2]--;
//				if (ab == 0)break;
//			}
//		}
//		/***********白天的 A1*********************************/
//		int a1hcsl;
//		if (a2.ys[0] >= bb)
//		{
//			a1hcsl = hcz[1] - bb;
//		}
//		else
//		{
//			a1hcsl = hcz[1] - a2.ys[0];
//		}
//		for (; a1.ys[5] != 0 && a1.ys[4] != 0 && ab != a1hcsl;)//R、金车 
//		{
//			if (zl % 2 == 0)
//			{
//				z[zl++] = 5; ab--; a1.ys[5]--;
//				if (ab == a1hcsl)break;
//				z[zl++] = 4; ab--; a1.ys[4]--;
//				if (ab == a1hcsl)break;
//			}
//			else
//			{
//				z[zl++] = 4; ab--; a1.ys[4]--;
//				if (ab == a1hcsl)break;
//				z[zl++] = 5; ab--; a1.ys[5]--;
//				if (ab == a1hcsl)break;
//			}
//		}
//
//		if (a1.ys[4] == 0)
//		{
//			for (; a1.ys[5] != 0 && a1.ys[6] != 0 && ab > a1hcsl;)//R、S 车 
//			{
//				if (zl % 2 == 0)
//				{
//					z[zl++] = 5; ab--; a1.ys[5]--;
//					if (ab == a1hcsl)break;
//					z[zl++] = 6; ab--; a1.ys[6]--;
//					if (ab == a1hcsl)break;
//				}
//				else
//				{
//					z[zl++] = 6; ab--; a1.ys[6]--;
//					if (ab == a1hcsl)break;
//					z[zl++] = 5; ab--; a1.ys[5]--;
//					if (ab == a1hcsl)break;
//				}
//			}
//			if (a1.ys[6] == 0)
//			{
//				for (; a1.ys[5] != 0 && a1.ys[3] != 0 && ab > a1hcsl;)//R、棕车 
//				{
//					if (zl % 2 == 0)
//					{
//						z[zl++] = 5; ab--; a1.ys[5]--;
//						if (ab == a1hcsl)break;
//						z[zl++] = 3; ab--; a1.ys[3]--;
//						if (ab == a1hcsl)break;
//					}
//					else
//					{
//						z[zl++] = 3; ab--; a1.ys[3]--;
//						if (ab == a1hcsl)break;
//						z[zl++] = 5; ab--; a1.ys[5]--;
//						if (ab == a1hcsl)break;
//					}
//				}
//			}
//		}
//		else if (a1.ys[5] == 0)
//		{
//			for (; a1.ys[4] != 0 && a1.ys[6] != 0 && ab > a1hcsl;)//金、S 车 
//			{
//				if (zl % 2 == 0)
//				{
//					z[zl++] = 4; ab--; a1.ys[4]--;
//					if (ab == a1hcsl)break;
//					z[zl++] = 6; ab--; a1.ys[6]--;
//					if (ab == a1hcsl)break;
//				}
//				else
//				{
//					z[zl++] = 6; ab--; a1.ys[6]--;
//					if (ab == a1hcsl)break;
//					z[zl++] = 4; ab--; a1.ys[4]--;
//					if (ab == a1hcsl)break;
//				}
//			}
//			if (a1.ys[6] == 0)
//			{
//				for (; a1.ys[4] != 0 && a1.ys[3] != 0 && ab > a1hcsl;)//金、棕车 
//				{
//					if (zl % 2 == 0)
//					{
//						z[zl++] = 4; ab--; a1.ys[4]--;
//						if (ab == a1hcsl)break;
//						z[zl++] = 3; ab--; a1.ys[3]--;
//						if (ab == a1hcsl)break;
//					}
//					else
//					{
//						z[zl++] = 3; ab--; a1.ys[3]--;
//						if (ab == a1hcsl)break;
//						z[zl++] = 4; ab--; a1.ys[4]--;
//						if (ab == a1hcsl)break;
//					}
//				}
//			}
//		}
//		for (; a1.ys[6] != 0 && ab != a1hcsl; a1.ys[6]--, ab--)//S 车 
//			z[zl++] = 6;
//		for (; a1.ys[1] != 0 && a1.ys[3] != 0 && ab != a1hcsl;)
//		{
//			z[zl++] = 1; ab--; a1.ys[1]--;
//			if (ab == a1hcsl)break;
//			z[zl++] = 3; ab--; a1.ys[3]--;
//			if (ab == a1hcsl)break;
//		}
//		if (a1.ys[1] == 0)
//		{
//			for (; ab != a1hcsl && a1.ys[3] != 0; ab--, a1.ys[3]--)
//				z[zl++] = 3;
//		}
//		else if (a1.ys[3] == 0)
//		{
//			for (; ab != a1hcsl && a1.ys[1] != 0; ab--, a1.ys[1]--)
//				z[zl++] = 1;
//		}
//
//		/**********************************************************************
//	   *************/
//
//		a1.ys[0] -= ab;
//		for (; ab > 0; ab--)
//		{
//			z[zl++] = 0;
//		}
//		if (a2.ys[0] >= bb)
//		{
//			a2.ys[0] -= bb;
//			for (; bb != 0; bb--)
//				z[zl++] = 0;
//		}
//		else
//		{
//			bb -= a2.ys[0];
//			for (; a2.ys[0] != 0; a2.ys[0]--)
//				z[zl++] = 0;
//			for (; a2.ys[2] != 0;)//蓝、白车 
//			{
//				if (zl % 2 == 0)
//				{
//					z[zl++] = 2; bb--; a2.ys[2]--;
//					if (bb == 0)break;
//					z[zl++] = 1; bb--; a2.ys[1]--;
//					if (bb == 0)break;
//				}
//				else
//				{
//					z[zl++] = 1; ab--; a2.ys[1]--;
//					if (bb == 0)break;
//					z[zl++] = 2; ab--; a2.ys[2]--;
//					if (bb == 0)break;
//				}
//			}
//			/****************** 白天的
//		   A2********************************************************/
//			for (; a2.ys[5] != 0 && a2.ys[4] != 0 && bb != 0;)//R 金 
//			{
//				if (zl % 2 == 0)
//				{
//					z[zl++] = 5; bb--; a2.ys[5]--;
//					if (bb == 0)break;
//					z[zl++] = 4; bb--; a2.ys[4]--;
//					if (bb == 0)break;
//				}
//				else
//				{
//					z[zl++] = 4; bb--; a2.ys[4]--;
//					if (bb == 0)break;
//					z[zl++] = 5; bb--; a2.ys[5]--;
//					if (bb == 0)break;
//				}
//			}
//
//			if (a2.ys[4] == 0)
//			{
//				for (; a2.ys[5] != 0 && a2.ys[6] != 0 && bb != 0;)//R S 
//				{
//					if (zl % 2 == 0)
//					{
//						z[zl++] = 5; bb--; a2.ys[5]--;
//						if (bb == 0)break;
//						z[zl++] = 6; bb--; a2.ys[6]--;
//						if (bb == 0)break;
//					}
//					else
//					{
//						z[zl++] = 6; bb--; a2.ys[6]--;
//						if (bb == 0)break;
//						z[zl++] = 5; bb--; a2.ys[5]--;
//						if (bb == 0)break;
//					}
//				}
//				if (a2.ys[6] == 0)
//				{
//					for (; a2.ys[5] != 0 && a2.ys[3] != 0 && bb != 0;)//R 棕 
//					{
//						if (zl % 2 == 0)
//						{
//							z[zl++] = 5; bb--; a2.ys[5]--;
//							if (bb == 0)break;
//							z[zl++] = 3; bb--; a2.ys[3]--;
//							if (bb == 0)break;
//						}
//						else
//						{
//							z[zl++] = 3; bb--; a2.ys[3]--;
//							if (bb == 0)break;
//							z[zl++] = 5; bb--; a2.ys[5]--;
//							if (bb == 0)break;
//						}
//					}
//				}
//			}
//			else if (a2.ys[5] == 0)
//			{
//				for (; a2.ys[4] != 0 && a2.ys[6] != 0 && bb != 0;)//金 S 
//				{
//					if (zl % 2 == 0)
//					{
//						z[zl++] = 4; bb--; a2.ys[4]--;
//						if (bb == 0)break;
//						z[zl++] = 6; bb--; a2.ys[6]--;
//						if (bb == 0)break;
//					}
//					else
//					{
//						z[zl++] = 6; bb--; a2.ys[6]--;
//						if (bb == 0)break;
//						z[zl++] = 4; bb--; a2.ys[4]--;
//						if (bb == 0)break;
//					}
//				}
//				if (a2.ys[6] == 0)
//				{
//					for (; a2.ys[4] != 0 && a2.ys[3] != 0 && bb != 0;)//金 棕 
//					{
//						if (zl % 2 == 0)
//						{
//							z[zl++] = 4; bb--; a2.ys[4]--;
//							if (bb == 0)break;
//							z[zl++] = 3; bb--; a2.ys[3]--;
//							if (bb == 0)break;
//						}
//						else
//						{
//							z[zl++] = 3; bb--; a2.ys[3]--;
//							if (bb == 0)break;
//							z[zl++] = 4; bb--; a2.ys[4]--;
//							if (bb == 0)break;
//						}
//					}
//				}
//			}
//			for (; a2.ys[6] != 0 && bb != 0; a2.ys[6]--, bb--)//S 
//				z[zl++] = 6;
//			for (; a2.ys[1] != 0 && a2.ys[3] != 0 && bb != 0;)
//			{
//				z[zl++] = 1; bb--; a2.ys[1]--;
//				if (bb == 0)break;
//				z[zl++] = 3; bb--; a2.ys[3]--;
//				if (bb == 0)break;
//			}
//			if (a2.ys[1] == 0)
//			{
//				for (; bb != 0 && a2.ys[3] != 0; bb--, a2.ys[3]--)
//					z[zl++] = 3;
//			}
//			else if (a2.ys[3] == 0)
//			{
//				for (; bb != 0 && a2.ys[1] != 0; bb--, a2.ys[1]--)
//					z[zl++] = 1;
//			}
//
//			/**********************************************************************
//			*****************************************/
//		}
//
//		/******晚上******/
//		for (int i = 0; i < hcz[2]; i++)
//			z[zl++] = 0;
//		a1.ys[0] -= hcz[2];
//		aw -= hcz[2];
//		for (; a1.ys[2] != 0;)
//		{
//			if (zl % 2 == 0)
//			{
//				z[zl++] = 2; aw--; a1.ys[2]--;
//				if (aw == 0)break;
//				z[zl++] = 1; aw--; a1.ys[1]--;
//				if (aw == 0)break;
//			}
//			else
//			{
//				z[zl++] = 1; aw--; a1.ys[1]--;
//				if (aw == 0)break;
//				z[zl++] = 2; aw--; a1.ys[2]--;
//				if (aw == 0)break;
//			}
//		}
//		/*******************晚上的 A1***********************************/
//		a1hcsl;
//		if (a2.ys[0] >= bw)
//		{
//			a1hcsl = hcz[3] - bw;
//		}
//		else
//		{
//			a1hcsl = hcz[3] - a2.ys[0];
//		}
//		for (; a1.ys[5] != 0 && a1.ys[4] != 0 && aw > a1hcsl;)//R 金 
//		{
//			if (zl % 2 == 0)
//			{
//				z[zl++] = 5; aw--; a1.ys[5]--;
//				if (aw == a1hcsl)break;
//				z[zl++] = 4; aw--; a1.ys[4]--;
//				if (aw == a1hcsl)break;
//			}
//			else
//			{
//				z[zl++] = 4; aw--; a1.ys[4]--;
//				if (aw == a1hcsl)break;
//				z[zl++] = 5; aw--; a1.ys[5]--;
//				if (aw == a1hcsl)break;
//			}
//		}
//
//		if (a1.ys[4] == 0)
//		{
//			for (; a1.ys[5] != 0 && a1.ys[6] != 0 && aw > a1hcsl;)//R S 
//			{
//				if (zl % 2 == 0)
//				{
//					z[zl++] = 5; aw--; a1.ys[5]--;
//					if (aw == a1hcsl)break;
//					z[zl++] = 6; aw--; a1.ys[6]--;
//					if (aw == a1hcsl)break;
//				}
//				else
//				{
//					z[zl++] = 6; aw--; a1.ys[6]--;
//					if (aw == a1hcsl)break;
//					z[zl++] = 5; aw--; a1.ys[5]--;
//					if (aw == a1hcsl)break;
//				}
//			}
//			if (a1.ys[6] == 0)
//			{
//				for (; a1.ys[5] != 0 && a1.ys[3] != 0 && aw > a1hcsl;)//R 棕 
//				{
//					if (zl % 2 == 0)
//					{
//						z[zl++] = 5; aw--; a1.ys[5]--;
//						if (aw == a1hcsl)break;
//						z[zl++] = 3; aw--; a1.ys[3]--;
//						if (aw == a1hcsl)break;
//					}
//					else
//					{
//						z[zl++] = 3; aw--; a1.ys[3]--;
//						if (aw == a1hcsl)break;
//						z[zl++] = 5; aw--; a1.ys[5]--;
//						if (aw == a1hcsl)break;
//					}
//				}
//			}
//		}
//		else if (a1.ys[5] == 0)
//		{
//			for (; a1.ys[4] != 0 && a1.ys[6] != 0 && aw > a1hcsl;)//金 S 
//			{
//				if (zl % 2 == 0)
//				{
//					z[zl++] = 4; aw--; a1.ys[4]--;
//					if (aw == a1hcsl)break;
//					z[zl++] = 6; aw--; a1.ys[6]--;
//					if (aw == a1hcsl)break;
//				}
//				else
//				{
//					z[zl++] = 6; aw--; a1.ys[6]--;
//					if (aw == a1hcsl)break;
//					z[zl++] = 4; aw--; a1.ys[4]--;
//					if (aw == a1hcsl)break;
//				}
//			}
//			if (a1.ys[6] == 0)
//			{
//				for (; a1.ys[4] != 0 && a1.ys[3] != 0 && aw > a1hcsl;)//金 棕 
//				{
//					if (zl % 2 == 0)
//					{
//						z[zl++] = 4; aw--; a1.ys[4]--;
//						if (aw == a1hcsl)break;
//						z[zl++] = 3; aw--; a1.ys[3]--;
//						if (aw == a1hcsl)break;
//					}
//					else
//					{
//						z[zl++] = 3; aw--; a1.ys[3]--;
//						if (aw == a1hcsl)break;
//						z[zl++] = 4; aw--; a1.ys[4]--;
//						if (aw == a1hcsl)break;
//					}
//				}
//			}
//		}
//		for (; a1.ys[6] != 0 && aw != a1hcsl; a1.ys[6]--, aw--)//S 
//			z[zl++] = 6;
//		for (; a1.ys[1] != 0 && a1.ys[3] != 0 && aw != a1hcsl;)
//		{
//			z[zl++] = 1; aw--; a1.ys[1]--;
//			if (aw == a1hcsl)break;
//			z[zl++] = 3; aw--; a1.ys[3]--;
//			if (aw == a1hcsl)break;
//		}
//		if (a1.ys[1] == 0)
//		{
//			for (; aw != a1hcsl && a1.ys[3] != 0; aw--, a1.ys[3]--)
//				z[zl++] = 3;
//		}
//		else if (a1.ys[3] == 0)
//		{
//			for (; aw != a1hcsl && a1.ys[1] != 0; aw--, a1.ys[1]--)
//				z[zl++] = 1;
//		}
//
//		/**********************************************************************
//	   *************/
//
//		a1.ys[0] -= aw;
//		for (; aw > 0; aw--)
//		{
//			z[zl++] = 0;
//		}
//		if (a2.ys[0] >= bw)
//		{
//			a2.ys[0] -= bw;
//			for (; bb != 0; bw--)
//				z[zl++] = 0;
//		}
//		else
//		{
//			bw -= a2.ys[0];
//			for (; a2.ys[0] != 0; a2.ys[0]--)
//				z[zl++] = 0;
//			for (; a2.ys[2] != 0;)//蓝、白车 
//			{
//				if (zl % 2 == 0)
//				{
//					z[zl++] = 2; bw--; a2.ys[2]--;
//					if (bw == 0)break;
//					z[zl++] = 1; bw--; a2.ys[1]--;
//					if (bw == 0)break;
//				}
//				else
//				{
//					z[zl++] = 1; bw--; a2.ys[1]--;
//					if (bw == 0)break;
//					z[zl++] = 2; bw--; a2.ys[2]--;
//					if (bw == 0)break;
//				}
//			}
//			/****************************** 晚上的
//		   A2***************************************/
//			for (; a2.ys[5] != 0 && a2.ys[4] != 0 && bw != 0;)//R 金 
//			{
//				if (zl % 2 == 0)
//				{
//					z[zl++] = 5; bw--; a2.ys[5]--;
//					if (bw == 0)break;
//					z[zl++] = 4; bw--; a2.ys[4]--;
//					if (bw == 0)break;
//				}
//				else
//				{
//					z[zl++] = 4; bw--; a2.ys[4]--;
//					if (bw == 0)break;
//					z[zl++] = 5; bw--; a2.ys[5]--;
//					if (bw == 0)break;
//				}
//			}
//
//			if (a2.ys[4] == 0)
//			{
//				for (; a2.ys[5] != 0 && a2.ys[6] != 0 && bw != 0;)//R S 
//				{
//					if (zl % 2 == 0)
//					{
//						z[zl++] = 5; bw--; a2.ys[5]--;
//						if (bw == 0)break;
//						z[zl++] = 6; bw--; a2.ys[6]--;
//						if (bw == 0)break;
//					}
//					else
//					{
//						z[zl++] = 6; bw--; a2.ys[6]--;
//						if (bw == 0)break;
//						z[zl++] = 5; bw--; a2.ys[5]--;
//						if (bw == 0)break;
//					}
//				}
//				if (a2.ys[6] == 0)
//				{
//					for (; a2.ys[5] != 0 && a2.ys[3] != 0 && bw != 0;)//R 棕 
//					{
//						if (zl % 2 == 0)
//						{
//							z[zl++] = 5; bw--; a2.ys[5]--;
//							if (bw == 0)break;
//							z[zl++] = 3; bw--; a2.ys[3]--;
//							if (bw == 0)break;
//						}
//						else
//						{
//							z[zl++] = 3; bw--; a2.ys[3]--;
//							if (bw == 0)break;
//							z[zl++] = 5; bw--; a2.ys[5]--;
//							if (bw == 0)break;
//						}
//					}
//				}
//			}
//			else if (a2.ys[5] == 0)
//			{
//				for (; a2.ys[4] != 0 && a2.ys[6] != 0 && bw != 0;)//金 S 
//				{
//					if (zl % 2 == 0)
//					{
//						z[zl++] = 4; bw--; a2.ys[4]--;
//						if (bw == 0)break;
//						z[zl++] = 6; bw--; a2.ys[6]--;
//						if (bw == 0)break;
//					}
//					else
//					{
//						z[zl++] = 6; bw--; a2.ys[6]--;
//						if (bw == 0)break;
//						z[zl++] = 4; bw--; a2.ys[4]--;
//						if (bw == 0)break;
//					}
//				}
//				if (a2.ys[6] == 0)
//				{
//					for (; a2.ys[4] != 0 && a2.ys[3] != 0 && bw != 0;)//金 棕 
//					{
//						if (zl % 2 == 0)
//						{
//							z[zl++] = 4; bw--; a2.ys[4]--;
//							if (bw == 0)break;
//							z[zl++] = 3; bw--; a2.ys[3]--;
//							if (bw == 0)break;
//						}
//						else
//						{
//							z[zl++] = 3; bw--; a2.ys[3]--;
//							if (bw == 0)break;
//							z[zl++] = 4; bw--; a2.ys[4]--;
//							if (bw == 0)break;
//						}
//					}
//				}
//			}
//			for (; a2.ys[6] != 0 && bw != 0; a2.ys[6]--, bw--)//S 
//				z[zl++] = 6;
//			for (; a2.ys[1] != 0 && a2.ys[3] != 0 && bw != 0;)
//			{
//				z[zl++] = 1; bw--; a2.ys[1]--;
//				if (bw == 0)break;
//				z[zl++] = 3; bw--; a2.ys[3]--;
//				if (bw == 0)break;
//			}
//			if (a2.ys[1] == 0)
//			{
//				for (; bw != 0 && a2.ys[3] != 0; bw--, a2.ys[3]--)
//					z[zl++] = 3;
//			}
//			else if (a2.ys[3] == 0)
//			{
//				for (; bw != 0 && a2.ys[1] != 0; bw--, a2.ys[1]--)
//					z[zl++] = 1;
//			}
//
//			/**********************************************************************
//		   *****************************************/
//		}
//		/****************/
//
//		yl = 0;
//		ab = sum(a1.qd, 2) / 2; bb = sum(a2.qd, 2) / 2;
//		aw = sum(a1.qd, 2) - ab; bw = sum(a2.qd, 2) - bb;
//		int ajg = (ab * 2 / (a1.qd[1] == 0 ? 1 : a1.qd[1])) - 2;
//		if (ajg < 5)ajg = (ab * 4 / (a1.qd[1] == 0 ? 1 : a1.qd[1])) - 2;
//		int bjg = (bb * 2 / (a2.qd[1] == 0 ? 1 : a2.qd[1])) - 2;
//		if (bjg < 5)bjg = (bb * 4 / (a2.qd[1] == 0 ? 1 : a2.qd[1])) - 2;
//		while (ab != 0)
//		{
//			for (int i = 0; i < 2 && ab != 0 && a1.qd[1] != 0; i++)
//				a1.qd[1]--, ab--, y[yl++] = 1;
//			for (int i = 0; i < ajg && ab != 0 && a1.qd[0] != 0; i++)
//				a1.qd[0]--, ab--, y[yl++] = 0;
//		}
//		while (bb != 0)
//		{
//			for (int i = 0; i < 2 && bb != 0 && a2.qd[1] != 0; i++)
//				a2.qd[1]--, bb--, y[yl++] = 1;
//			for (int i = 0; i < bjg && bb != 0 && a2.qd[0] != 0; i++)
//				a2.qd[0]--, bb--, y[yl++] = 0;
//		}
//		while (aw != 0)
//		{
//			for (int i = 0; i < 2 && aw != 0 && a1.qd[1] != 0; i++)
//				a1.qd[1]--, aw--, y[yl++] = 1;
//			for (int i = 0; i < ajg && aw != 0 && a1.qd[0] != 0; i++)
//				a1.qd[0]--, aw--, y[yl++] = 0;
//		}
//		while (bw != 0)
//		{
//			for (int i = 0; i < 2 && bw != 0 && a2.qd[1] != 0; i++)
//				a2.qd[1]--, bw--, y[yl++] = 1;
//			for (int i = 0; i < bjg && bw != 0 && a2.qd[0] != 0; i++)
//				a2.qd[0]--, bw--, y[yl++] = 0;
//		}
//
//
//		xl = 0;
//		ab = sum(a1.dl, 2) / 2; bb = sum(a2.dl, 2) / 2;
//		aw = sum(a1.dl, 2) - ab; bw = sum(a2.dl, 2) - bb;
//		ajg = (ab * 2 / (a1.dl[1] == 0 ? 1 : a1.dl[1])) - 2;
//		if (ajg < 5)ajg = (ab * 4 / (a1.dl[1] == 0 ? 1 : a1.dl[1])) - 2;
//		bjg = (bb * 2 / (a2.dl[1] == 0 ? 1 : a2.dl[1])) - 2;
//		if (bjg < 5)bjg = (bb * 4 / (a2.dl[1] == 0 ? 1 : a2.dl[1])) - 2;
//		while (ab != 0)
//		{
//			for (int i = 0; i < 2 && ab != 0 && a1.dl[1] != 0; i++)
//				a1.dl[1]--, ab--, x[xl++] = 1;
//			for (int i = 0; i < ajg && ab != 0 && a1.dl[0] != 0; i++)
//				a1.dl[0]--, ab--, x[xl++] = 0;
//		}
//		while (bb != 0)
//		{
//			for (int i = 0; i < 2 && bb != 0 && a2.dl[1] != 0; i++)
//				a2.dl[1]--, bb--, x[xl++] = 1;
//			for (int i = 0; i < bjg && bb != 0 && a2.dl[0] != 0; i++)
//				a2.dl[0]--, bb--, x[xl++] = 0;
//		}
//		while (aw != 0)
//		{
//			for (int i = 0; i < 2 && aw != 0 && a1.dl[1] != 0; i++)
//				a1.qd[1]--, aw--, x[xl++] = 1;
//			for (int i = 0; i < ajg && aw != 0 && a1.dl[0] != 0; i++)
//				a1.qd[0]--, aw--, x[xl++] = 0;
//		}
//		while (bw != 0)
//		{
//			for (int i = 0; i < 2 && bw != 0 && a2.dl[1] != 0; i++)
//				a2.dl[1]--, bw--, x[xl++] = 1;
//			for (int i = 0; i < bjg && bw != 0 && a2.dl[0] != 0; i++)
//				a2.dl[0]--, bw--, x[xl++] = 0;
//		}
//
//		ab = sum(a1.pz, 6) / 2; bb = sum(a2.pz, 6) / 2;
//		aw = sum(a1.pz, 6) - ab; bw = sum(a2.pz, 6) - bb;
//		wl = 0;
//		for (int i = 0; i < 6 && ab != 0; i++)
//		{
//			for (; a1.pz[i] != 0 && ab != 0; a1.pz[i]--, ab--)
//				w[wl++] = i;
//		}
//		for (int i = 0; i < 6 && bb != 0; i++)
//		{
//			for (; a2.pz[i] != 0 && bb != 0; a2.pz[i]--, bb--)
//				w[wl++] = i;
//		}
//		for (int i = 0; i < 6 && aw != 0; i++)
//		{
//			for (; a1.pz[i] != 0 && aw != 0; a1.pz[i]--, aw--)
//				w[wl++] = i;
//		}
//		for (int i = 0; i < 6 && bw != 0; i++)
//		{
//			for (; a2.pz[i] != 0 && bw != 0; a2.pz[i]--, bw--)
//				w[wl++] = i;
//		}
//
//		ab = zab; bb = zbb;
//		aw = zaw; bw = zbw;
//		vl = 0;
//		while (ab--)v[vl++] = 0;
//		while (bb--)v[vl++] = 1;
//		while (aw--)v[vl++] = 0;
//		while (bw--)v[vl++] = 1;
//
//		ab = zab; bb = zbb;
//		aw = zaw; bw = zbw;
//		int i = 0;
//		for (; ab != 0; i++, ab--)
//		{
//			if (z[i] == 5)
//			{
//				if (a1.ys[7] != 0)
//					z[i] = 7, a1.ys[7]--;
//				else if (a1.ys[8] != 0)
//					z[i] = 8, a1.ys[8]--;
//			}
//			if (z[i] == 6)
//			{
//				if (a1.ys[9] != 0)
//					z[i] = 9, a1.ys[9]--;
//				else if (a1.ys[10] != 0)
//					z[i] = 10, a1.ys[10]--;
//			}
//
//		}
//		for (; bb != 0; i++, bb--)
//		{
//			if (z[i] == 5)
//			{
//				if (a2.ys[7] != 0)
//					z[i] = 7, a2.ys[7]--;
//				else if (a2.ys[8] != 0)
//					z[i] = 8, a2.ys[8]--;
//			}
//			if (z[i] == 6)
//			{
//				if (a2.ys[9] != 0)
//					z[i] = 9, a2.ys[9]--;
//				else if (a2.ys[10] != 0)
//					z[i] = 10, a2.ys[10]--;
//			}
//		}
//		for (; aw != 0; i++, aw--)
//		{
//			if (z[i] == 5)
//			{
//				if (a1.ys[7] != 0)
//					z[i] = 7, a1.ys[7]--;
//				else if (a1.ys[8] != 0)
//					z[i] = 8, a1.ys[8]--;
//			}
//			if (z[i] == 6)
//			{
//				if (a1.ys[9] != 0)
//					z[i] = 9, a1.ys[9]--;
//				else if (a1.ys[10] != 0)
//					z[i] = 10, a1.ys[10]--;
//			}
//		}
//		for (; bw != 0; i++, bw--)
//		{
//			if (z[i] == 5)
//			{
//				if (a2.ys[7] != 0)
//					z[i] = 7, a2.ys[7]--;
//				else if (a2.ys[8] != 0)
//					z[i] = 8, a2.ys[8]--;
//			}
//			if (z[i] == 6)
//			{
//				if (a2.ys[9] != 0)
//					z[i] = 9, a2.ys[9]--;
//				else if (a2.ys[10] != 0)
//					z[i] = 10, a2.ys[10]--;
//			}
//		}
//		fprintf_s(fp, "分析的第%d 日的装配顺序表\n", q);//给每天的数据命名 
//		fprintf_s(fp, "品牌\t 配置\t 动力\t 驱动\t 颜色\t 喷涂线\n");
//		for (int i = 0; i < zl; i++)
//		{
//			fprintf_s(fp, "%s\t%s\t%s\t%s\t%s\tC%d\n", pp[v[i]], pz[w[i]], dl[x[i]], qd[y[i]], ys[z[i]], i % 2 + 1);
//			//cout<<<<","<<<<","<<<<","<<<<","<<<<endl; 
//		}
//	}
//	fclose(fp);
//	return 0;
//}

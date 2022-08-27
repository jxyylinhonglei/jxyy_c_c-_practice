#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int big , medium , small,i = 0;
	scanf("%d%d%d", &big, &medium, &small);
	printf("初始化停车场：大车位%d个，中车位%d个，小车位%d个。\n", big, medium, small);
	do
	{
		printf("请输入需要停入的车尺寸：");
		scanf("%d", &i);
		if (i == 1 && big != 0)
		{
			big--;
			printf(" true\n");
		}
		else if (i == 2 && medium != 0)
		{
			medium--;
			printf(" true\n");
		}
		else if (i == 3 && small != 0)
		{
			small--;
			printf(" ture\n");
		}
		else
		{
			printf("false\n");
		}
	} while (1);
	return 0;
}
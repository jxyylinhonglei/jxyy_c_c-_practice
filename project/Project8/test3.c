#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int main()
{
	int big , medium , small,i = 0;
	scanf("%d%d%d", &big, &medium, &small);
	printf("��ʼ��ͣ��������λ%d�����г�λ%d����С��λ%d����\n", big, medium, small);
	do
	{
		printf("��������Ҫͣ��ĳ��ߴ磺");
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
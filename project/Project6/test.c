#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
void check_capacity(struct con* ps)
{
	if ((ps->capacity) == (ps->site))
	{
		ps->capacity += 1;
		struct con* pf = (struct con*)realloc(ps->arr, sizeof(int) * (ps->capacity));
		if (pf != ps->arr)
		{
			ps->arr = pf;
		}
	}
}
struct con
{
	int site;//输入了几天的股票的价格
	int capacity;//数组的容量
	int* arr;
};
int main()
{
	int i, j, ret, tmp = 0;
	struct con* ps = (struct con*)malloc(sizeof(struct con));
	ps->arr = (int*)malloc(sizeof(int));
	ps->site = 0;
	ps->capacity = 1;
	while (scanf("%d", ps->arr[i]))
	{
		ps->site++;
		check_capacity(ps);
		i++;
	}
	printf("请输入要购买第几天的股票\n");
	scanf("%d", &j);
	ret = ps->arr[j - 1];
	tmp = ret;
	for (i = j; i < ps->site; i++)
	{
		if (tmp < ps->arr[i])
		{
			tmp = ps->arr[i];
		}
	}
	if (ret == tmp)
	{
		printf("0");
	}
	else
	{
		printf("%d", tmp - ret);
	}
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
typedef struct lis
{
	char book_name[10];//书名
	int book_number;//编号
}book;
typedef struct list
{
	int element;//书的数量
	book* base;
}booklist;
void add_list(booklist* ps)//添加书
{
	scanf("%s", ps->base[ps->element].book_name);
	scanf("%d",&(ps->base[ps->element].book_number));
	ps->element++;
}
void delete(booklist* ps)
{
	int i = 0;
	printf("请选择要删除的书的编号》\n");
	scanf("%d", &i);
	if (i<0 || i>ps->element)
	{
		printf("输入错误\n");
		return;
	}
	else
	{
		while (i<ps->element)
		{
			ps->base[i-1] = ps->base[i];
			i++;
	   }
		ps->element--;
	}
}
void search(booklist* ps)
{
	int i;
	for (i = 0; i < ps->element; i++)
	{

	}
}
void insert(booklist* ps)
{
	int i = 0;
	int a = ps->element;
	booklist a = { "zhangsan",13 };
	printf("输入插入的位置\n");
	if (i<0 || i>ps->element+1)
	{
		printf("输入错误\n");
	}
	else
	{
		for(i=i;i<=ps->element;i++)
		{
			ps->base[a] = ps->base[a-1];
		}
	}
}
void inilist(booklist* ps)//初始化表
{
	ps->element = 0;
	ps->base = (book*)malloc(sizeof(book) * 10);
}
int main()
{
	booklist s = { 0 };
	inilist(&s);
	return 0;
}
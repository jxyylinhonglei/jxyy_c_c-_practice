#include<stdio.h>
#include<stdlib.h>
typedef struct lis
{
	char book_name[10];//����
	int book_number;//���
}book;
typedef struct list
{
	int element;//�������
	book* base;
}booklist;
void add_list(booklist* ps)//�����
{
	scanf("%s", ps->base[ps->element].book_name);
	scanf("%d",&(ps->base[ps->element].book_number));
	ps->element++;
}
void delete(booklist* ps)
{
	int i = 0;
	printf("��ѡ��Ҫɾ������ı�š�\n");
	scanf("%d", &i);
	if (i<0 || i>ps->element)
	{
		printf("�������\n");
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
	printf("��������λ��\n");
	if (i<0 || i>ps->element+1)
	{
		printf("�������\n");
	}
	else
	{
		for(i=i;i<=ps->element;i++)
		{
			ps->base[a] = ps->base[a-1];
		}
	}
}
void inilist(booklist* ps)//��ʼ����
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
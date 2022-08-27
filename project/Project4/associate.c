#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
void meun()//打印菜单
{
	printf("**********************************************\n");
	printf("**1.add*********************2.dele************\n");
	printf("**3.search***********4.modify*****************\n");
	printf("**5.show*************0.exit*******************\n");
}

struct Contact//姓名性别年龄电话号码
{
	char name[20];
	char sex[5];
	int age;
	char tele[12];
};
struct con
{
	int site;
	int capacity;
	struct Contact* arr;
};
enum contact
{
	EXIT,
	ADD,
	DELE,
	SEARCH,
	MODIFY,
	SHOW,
	SAVE,
};
void check_capacity(struct con* ps)
{
	if (ps->site==ps->capacity)
	{
		ps->capacity += 2;
		struct Contact* pa=(struct Contact*)realloc(ps->arr, sizeof(struct Contact) *(ps->capacity));
		if (ps != NULL)
		{
			ps->arr = pa;
			printf("扩容成功\n");
		}
	}
}
void add_contact(struct con* ps)
{
	    check_capacity(ps);
		printf("请输入姓名：>");
		scanf("%s",ps->arr[ps->site].name);
		printf("请输入性别：>");
		scanf("%s", ps->arr[ps->site].sex);
		printf("请输入年龄：>");
		scanf("%d",&(ps->arr[ps->site].age));
		printf("请输入电话号码：>");
		scanf("%s", ps->arr[ps->site].tele);
		printf("输入成功\n");
		ps->site++;
}
void show_contact(struct con* ps)
{
	printf("姓名\t性别\t年龄\t电话号码\n");
	int i = 0;
	for (i = 0; i < ps->site;i++)
	{
		printf("%s\t%s\t%d\t%s\n", ps->arr[i].name, ps->arr[i].sex, ps->arr[i].age, ps->arr[i].tele);
	}
}
void dele_contact(struct con* ps)
{
	printf("请输入要删除联系人的名字>");
	char dele_name[20] = { 0 };
	int i = 0;
	int a = 0;
	scanf("%s", dele_name);
	for (i = 0; i < ps->site; i++)
	{
		int ret = strcmp(dele_name,ps->arr[i].name);
		if (ret == 0)
		{
			int j = 0;
			for (j = i; j <ps->site-1 ; j++)
			{
				ps->arr[j] = ps->arr[j + 1];
			}
			ps->site--;
			a++;
			printf("删除成功\n");
			break;
		}
	}
	if (a == 0)
	{
		printf("没有该联系人\n");
	}
}
void search_contact(struct con* ps)
{
	printf("请输入要查找的联系人名字>");
	int i = 0;
	int ret = 0;
	char search_name[20] = { 0 };
	scanf("%s", search_name);
	for (i = 0; i <ps->site ; i++)
	{
		int ret=strcmp(ps->arr[i].name, search_name);
		if (ret == 0)
		{
			printf("找到了\n");
			printf("姓名\t性别\t年龄\t电话号码\n");
		    printf("%s\t%s\t%d\t%s\n", ps->arr[i].name, ps->arr[i].sex, ps->arr[i].age, ps->arr[i].tele);
			break;
		}
	}
}
void modify_contact(struct con* ps)
{
	printf("请输入要修改人的名字>");
	char modify_name[20] = { 0 };
	int i = 0;
	scanf("%s", modify_name);
	for (i = 0; i <ps->site ; i++)
	{
		int ret = strcmp(modify_name, ps->arr[i].name);
		if (ret == 0)
		{
			printf("请输入姓名：>");
			scanf("%s", ps->arr[i].name);
			printf("请输入性别：>");
			scanf("%s", ps->arr[i].sex);
			printf("请输入年龄：>");
			scanf("%d", &(ps->arr[i].age));
			printf("请输入电话号码：>");
			scanf("%s", ps->arr[i].tele);
			printf("修改成功\n");
			break;
		}
	}
}
void save_contact(struct con* ps)
{
	int i = 0;
	FILE* pf = fopen("test.txt", "wb");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	for (i = 0; i < ps->site; i++)
	{
		fwrite(&(ps->arr[i]), sizeof(struct Contact), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}
void Load_contact(struct con* ps)
{
	struct Contact tmp = { 0 };
	FILE* pf = fopen("test.txt", "rb");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(struct Contact), 1, pf))
	{
		check_capacity(ps);
		ps->arr[ps->site] = tmp;
		printf("正在输入\n");
		ps->site++;
	}
	fclose(pf);
	pf = NULL;
}
int main()
{
	int input = 0;
	struct con* ps = (struct con*)malloc(sizeof(struct con));
	ps->site = 0;
	ps->capacity = 2;
	ps->arr =(struct Contact*)malloc(2*sizeof(struct Contact));
	memset(ps->arr,'0',sizeof(ps->arr));//给结构体数组初始化
	Load_contact(ps);
	do
	{ 
		meun();
		scanf_s("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("退出\n");
			break;
		case ADD:
			add_contact(ps);//添加联系人信息
			break;
		case DELE:
			dele_contact(ps);//删除联系人信息
			break;
		case SEARCH:
			search_contact(ps);//查找联系人信息
			break;
		case MODIFY:
			modify_contact(ps);//修改联系人信息
			break;
		case SHOW:
			show_contact(ps);//显示所有联系人的信息
			break;
		case SAVE:
			save_contact(ps);
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
void meun()//��ӡ�˵�
{
	printf("**********************************************\n");
	printf("**1.add*********************2.dele************\n");
	printf("**3.search***********4.modify*****************\n");
	printf("**5.show*************0.exit*******************\n");
}

struct Contact//�����Ա�����绰����
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
			printf("���ݳɹ�\n");
		}
	}
}
void add_contact(struct con* ps)
{
	    check_capacity(ps);
		printf("������������>");
		scanf("%s",ps->arr[ps->site].name);
		printf("�������Ա�>");
		scanf("%s", ps->arr[ps->site].sex);
		printf("���������䣺>");
		scanf("%d",&(ps->arr[ps->site].age));
		printf("������绰���룺>");
		scanf("%s", ps->arr[ps->site].tele);
		printf("����ɹ�\n");
		ps->site++;
}
void show_contact(struct con* ps)
{
	printf("����\t�Ա�\t����\t�绰����\n");
	int i = 0;
	for (i = 0; i < ps->site;i++)
	{
		printf("%s\t%s\t%d\t%s\n", ps->arr[i].name, ps->arr[i].sex, ps->arr[i].age, ps->arr[i].tele);
	}
}
void dele_contact(struct con* ps)
{
	printf("������Ҫɾ����ϵ�˵�����>");
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
			printf("ɾ���ɹ�\n");
			break;
		}
	}
	if (a == 0)
	{
		printf("û�и���ϵ��\n");
	}
}
void search_contact(struct con* ps)
{
	printf("������Ҫ���ҵ���ϵ������>");
	int i = 0;
	int ret = 0;
	char search_name[20] = { 0 };
	scanf("%s", search_name);
	for (i = 0; i <ps->site ; i++)
	{
		int ret=strcmp(ps->arr[i].name, search_name);
		if (ret == 0)
		{
			printf("�ҵ���\n");
			printf("����\t�Ա�\t����\t�绰����\n");
		    printf("%s\t%s\t%d\t%s\n", ps->arr[i].name, ps->arr[i].sex, ps->arr[i].age, ps->arr[i].tele);
			break;
		}
	}
}
void modify_contact(struct con* ps)
{
	printf("������Ҫ�޸��˵�����>");
	char modify_name[20] = { 0 };
	int i = 0;
	scanf("%s", modify_name);
	for (i = 0; i <ps->site ; i++)
	{
		int ret = strcmp(modify_name, ps->arr[i].name);
		if (ret == 0)
		{
			printf("������������>");
			scanf("%s", ps->arr[i].name);
			printf("�������Ա�>");
			scanf("%s", ps->arr[i].sex);
			printf("���������䣺>");
			scanf("%d", &(ps->arr[i].age));
			printf("������绰���룺>");
			scanf("%s", ps->arr[i].tele);
			printf("�޸ĳɹ�\n");
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
		printf("��������\n");
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
	memset(ps->arr,'0',sizeof(ps->arr));//���ṹ�������ʼ��
	Load_contact(ps);
	do
	{ 
		meun();
		scanf_s("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("�˳�\n");
			break;
		case ADD:
			add_contact(ps);//�����ϵ����Ϣ
			break;
		case DELE:
			dele_contact(ps);//ɾ����ϵ����Ϣ
			break;
		case SEARCH:
			search_contact(ps);//������ϵ����Ϣ
			break;
		case MODIFY:
			modify_contact(ps);//�޸���ϵ����Ϣ
			break;
		case SHOW:
			show_contact(ps);//��ʾ������ϵ�˵���Ϣ
			break;
		case SAVE:
			save_contact(ps);
			break;
		default:
			printf("�������\n");
			break;
		}
	} while (input);
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}
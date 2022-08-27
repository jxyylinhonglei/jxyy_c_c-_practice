#include"contact.h"
void my_memset(struct contact* ps)
{
	memset(ps, '0', sizeof(ps));
}
void check_capacity(struct con* ps)
{
	if (ps->capacity == ps->site)
	{
		ps->capacity += 2;
		struct contact* pf=(struct contact*)realloc(ps->add,sizeof(struct contact)*ps->capacity);
		printf("���ݳɹ�\n");
		if (pf != ps->add)
		{
			ps->add = pf;
		}
	}
}
void add_contact(struct con* ps)//�����Ա�����סַ�绰����
{
	check_capacity(ps);
	printf("����������>");
	scanf("%s", ps->add[ps->site].name);
	printf("�������Ա�>");
	scanf("%s", ps->add[ps->site].sex);
	printf("����������>");
	scanf("%d", &(ps->add[ps->site].age));
	printf("������סַ>");
	scanf("%s", ps->add[ps->site].addr);
	printf("������绰����>");
	scanf("%s", ps->add[ps->site].tele);
	printf("����ɹ�\n");
	ps->site++;
}
void show_contact(struct con* ps)//�����Ա�����סַ�绰����
{
	int i = 0;
	printf("����\t\t�Ա�\t\t����\t\tסַ\t\t�绰����\n");
	for (i = 0; i <ps->site; i++)
	{
		printf("%s\t\t%s\t\t%d\t\t%s\t\t%s\n",ps->add[i].name,ps->add[i].sex,ps->add[i].age,ps->add[i].addr,ps->add[i].tele);
	}
}
void dele_contact(struct con* ps)
{
	int i,j ,ret= 0;
	char dele_name[10] = { 0 };
	printf("������Ҫɾ����ϵ�˵����֡�");
	scanf("%s", dele_name);
	for (i = 0; i < ps->site; i++)
	{
		ret = strcmp(dele_name, ps->add[i].name);
		if (ret == 0)
		{
			for (j = i; j < ps->site-1; j++)
			{
				ps->add[j] = ps->add[j + 1];
			}
			ps->site--;
			printf("ɾ�����\n");
			printf("����\t\t�Ա�\t\t����\t\tסַ\t\t�绰����\n");
			for (i = 0; i < ps->site; i++)
			{
				printf("%s\t\t%s\t\t%d\t\t%s\t\t%s\n", ps->add[i].name, ps->add[i].sex, ps->add[i].age, ps->add[i].addr, ps->add[i].tele);
			}
			break;
		}

	}
	if (ret != 0)
	{
		printf("û�и���ϵ��\n");
	}
}
void search_contact(struct con* ps)
{
	int i,ret = 0;
	char search_name[10] = { 0 };
	printf("������Ҫ������ϵ�˵�������");
	scanf("%s",search_name);
	for (i = 0; i < ps->site; i++)
	{
		ret = strcmp(search_name, ps->add[i].name);
		if (ret == 0)
		{
			printf("�ҵ���\n");
			printf("����\t\t�Ա�\t\t����\t\tסַ\t\t�绰����\n");
			printf("%s\t\t%s\t\t%d\t\t%s\t\t%s\n", ps->add[i].name, ps->add[i].sex, ps->add[i].age, ps->add[i].addr, ps->add[i].tele);
			break;
		}
	}
}
void modify_contact(struct con* ps)
{
	int i, ret = 0;
	char modify_name[10] = { 0 };
	printf("������Ҫ�޸���ϵ�˵�������");
	scanf("%s", modify_name);
	for (i = 0; i < ps->site; i++)
	{
		ret = strcmp(modify_name, ps->add[i].name);
		if (ret == 0)
		{
			printf("����������>");
			scanf("%s", ps->add[i].name);
			printf("�������Ա�>");
			scanf("%s", ps->add[i].sex);
			printf("����������>");
			scanf("%d", &(ps->add[i].age));
			printf("������סַ>");
			scanf("%s", ps->add[i].addr);
			printf("������绰����>");
			scanf("%s", ps->add[i].tele);
			printf("�ɹ��޸�\n");
			break;
		}
	}
	if (ret != 0)
	{
		printf("û�и���ϵ��\n");
	}
}
void save_contact(struct con* ps)
{
	int i = 0;
	struct contact tmp = { 0 };
	FILE* pf = fopen("Դtest.txt", "wb");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	else
	{
		for (i = 0; i < ps->site; i++)
		{
			tmp = ps->add[i];
			fwrite(&tmp,sizeof(struct contact),1,pf);
		/*	ps->site--;*/
			printf("������\n");
		}
		fclose(pf);
		pf = NULL;
		printf("�ѱ���\n");
	}
}
void read_contact(struct con* ps)
{
	struct contact tmp = { 0 };
	FILE* pf = fopen("Դtest.txt", "rb" );
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	else
	{
		while (fread(&tmp, sizeof(struct contact), 1, pf))
		{
			check_capacity(ps);
			ps->add[ps->site] = tmp;
			ps->site++;
			printf("��������\n");
		}
		fclose(pf);
		pf = NULL;
	}
}
//int cmp_by(const void* e1, const void* e2)
//{
//	return strcmp(((struct contact*)e1)->name, ((struct contact*)e2)->name);
//}
//void swap(char* buft1, char* buft2,int wight)
//{
//	int i = 0;
//	for (i = 0; i < wight; i++)
//	{
//		char tmp = *buft1;
//		*buft1 = *buft2;
//		*buft2 = tmp;
//		buft1++;
//		buft2++;
//	}
//}
//void sort_bubble(void* e1,int sz,int wight,int (*cmp)(void* buft1,void* buft2))
//{
//	int i, j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)e1+j*wight,(char*)e1+(j+1)*wight)>0)
//			{
//				swap((char*)e1 + j * wight, (char*)e1 + (j + 1) * wight,wight);
//			}
//		}
//	}
//}
//void sort(struct con* ps)
//{
//	int sz = sizeof(ps->add) / sizeof(ps->add[0]);
//	sort_bubble(ps->add, sz, sizeof(ps->add[0]), cmp_by);
//	show_contact(ps);
//}
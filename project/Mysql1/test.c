#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<winsock.h>
#include<mysql.h>//�����winsock����������winsock
int main()
{
	int i = 0;//ѭ����
	int j = 0;
	char sql[200] = { 0 };
	char arr[200] = { 0 };
	MYSQL* mysql = mysql_init(0);//��ʼ��mysql��ִ�л���
	if (!mysql_real_connect(mysql, "127.0.0.1", "root","071411","yggl", 0, 0, 0))//ָ������IP��ַ���û��������룬���ݿ������˿ڣ�ȫ��0����Ĭ�϶˿ڣ�
	{//����ʧ�ܷ���false
		printf("���ӳ���%s", mysql_error(mysql));//��ӡ�������ݿ�ʧ�ܵ�ԭ��
		goto exit;
	}
	if (mysql_query(mysql,"set names gbk"))//�����������Ĳ��룬set names gbk�Ǳ�mysql֧�ֵ����
	{
		printf("�趨����ʧ�ܣ�%s",mysql_error(mysql));
		goto exit;
	}
	//������
	/*if (mysql_query(mysql, "create table diyitian (No float not null, ���� nvarchar(255) not null, ����SN nvarchar(255) not null, �����վ nvarchar(255) not null, �����վ�� nvarchar(255) not null, �賵��׮�� nvarchar(255) not null, �賵ʱ�� nvarchar(255) not null, �黹��վ nvarchar(255) not null,������վ�� nvarchar(255) not null, ������׮�� nvarchar(255) not null, ����ʱ�� nvarchar(255) not null, �ó�ʱ�� nvarchar(255) not null, �ó���ʽ nvarchar(255) not null, ������ nvarchar(255) not null, �賵��SN nvarchar(255) not null) "))
	{
		printf("�����ˣ�%s", mysql_error(mysql));
	}*/
	//if (mysql_query(mysql, " insert into Course values('C02','��ѧӢ��',3,'')"));//��������  ������ɹ�������
	//{
	//	printf("����ɹ�\n");
	//}
	//if (mysql_query(mysql, "insert into Course values('C03','�����Ӧ�ü���',3,' ')"));//��������  ������ɹ�������
	//{
	//	printf("����ɹ�\n");
	//}
	//if (mysql_query(mysql, "insert into Course values('C04','���ݿ⼼��',2,'C03,c01')"));//��������  ������ɹ�������
	//{
	//	printf("����ɹ�\n");
	//}
	//if (mysql_query(mysql, "insert into Course  values('C05','�˹�����',2,'C04,c01,c03')"));//��������  ������ɹ�������
	//{
	//	printf("����ɹ�\n");
	//}
	//for (i = 31; i < 36; i++)
	//{//sprintf("������"��������printfһ���������ǽ�����Ķ������뵽������
	//	sprintf(sql, "insert into person(id, passwd) values('%d','%d')", i, i);
	//	if (!mysql_query(mysql, sql))//�����ȥ�ɹ����ؼ�
	//	{
	//		printf("lllll");
	//	}
	//	else
	//		goto exit;
	//}
	//printf("���ӳɹ����Ҳ���ɹ�\n");
    //�ӱ�������ɾ��
	/*for (i = 1; i < 5; i++)
	{
		sprintf(sql,"delete from Course where credit=%d", i);
		if (!mysql_query(mysql, sql))
		{
			printf("ɾ���ɹ�\n");
		}
		else
			printf("%s", mysql_error(mysql));
	}*/
	//sprintf(sql, "update person set id=25 where id=22");
	//if (!mysql_query(mysql, sql))
	//{
	//	printf("hahah\n");
	//}
	//else
	//	printf("%s", mysql_error(mysql));
	//if (mysql_query(mysql, "select * from Course"))
	//{
	//	printf("������%s\n", mysql_error(mysql));//�����ݿ�ִ�в�ѯ���
	//}
	///*while (i)
	//{
	//	
	//	i--;
	//	if (!mysql_query(mysql,"insert into Course  values('C05','�˹�����',2,'C04,c01,c03')"))
	//     {
	//	    printf("hahah\n");
	//     }
	//     else
	//	     printf("%s", mysql_error(mysql));
	//}*/
	/*if (!mysql_query(mysql, "select * from employ"))
	{
		printf("��ѯ�ɹ�\n");
	}*/
	////���߽�����������Ǵ����vs�У��ŵ�ʹ�÷��� ȱ�� ռ�ڴ档�ʺ�С�����
	//MYSQL_RES* result = mysql_store_result(mysql);//��ȡ��ѯ����������ݷ����ڴ��У����ڴ��еĶ�����Ҫ�ֶ��ͷ�
	//MYSQL_ROW row;
	//////ֻҪ�����ݾ�һֱִ��,mysql_fetch_row�����ƶ����һ����һ�е�����mysql_row����
	//while (row = mysql_fetch_row(result))//��ȡһ�У��������û�оͷŻ�0
	//{
	//	char* Employees = row[0];//ȡ�������ַ������͵�
	//	char* name = row[1];
	//	char* education = row[2];
	//	char* birthday = row[3];
	//	char* sex = row[4];
	//	char* workyear = row[5];
	//	char* address = row[6];
	//	char* phonenumber = row[7];
	//	char* departmentID = row[8];
	//	printf("%d: Employees=%s,name=%s,education=%s,birthday=%s,sex=%s,workyear=%s,address=%s,phonenumber=%s,departmentID=%s,\n",i,row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8]);
	//	i++;
	//}

	for (i = 1; i < 12; i++)
	{
		for (j = 1; j <= 31; j++)
		{
			sprintf(sql,"select sum(`����`) from suoyou where `ˮ����`='64397����' group by and `�ɼ�ʱ��` like '____/%d/%d %'", i, j);
			if (!mysql_query(mysql, sql))
			{
				printf("��ѯ�ɹ�\n");
			}
			printf("%d %d", i, j);
			MYSQL_RES* result = mysql_store_result(mysql);//��ȡ��ѯ����������ݷ����ڴ��У����ڴ��еĶ�����Ҫ�ֶ��ͷ�
			MYSQL_ROW row;
			while (row = mysql_fetch_row(result))//��ȡһ�У��������û�оͷŻ�0
			{
				char* Employees = row[0];//ȡ�������ַ������͵�
				printf("%s", row[0]);
			}
			mysql_free_result(result);//�ͷű����ڴ��ѯ���
		}
	}
	//mysql_free_result(result);//�ͷű����ڴ��ѯ���
exit:
	mysql_close(mysql);//�ر����ݿ����ӣ�����������ر����ӷ���mysql���������п����Ŀ�����
	printf("�ر����ݿ�ɹ�\n");
	return 0;
}
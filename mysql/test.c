#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<winsock.h>
#include<mysql.h>//�����winsock����������winsock
int main() {
	MYSQL* mysql = mysql_init(0);//��ʼ��mysql��ִ�л���
	mysql_real_connect(mysql, "127.0.0.1", "root", "071411", "Lucky", 0, 0, 0);
	mysql_query(mysql, "set names gbk");
	//mysql_query(mysql, "insert into Course values('C01','�ߵ���ѧ',3,' ')");
	//mysql_query(mysql, "create table course(cno char(8) primary key not null,cn char(20) not null,credit int not null,cpno char(14))");
/*	mysql_query(mysql, "select * from Course")*/;
	mysql_query(mysql, "create table sheet(number int primary key not null,serial_number int not null)");
	int i = 0;
	char arr[64];
	memset(arr,0x00,sizeof(arr));
	for (i = 0; i < 300;i++) {
		sprintf(arr,"insert into sheet values(%d,%d)",i,i+1);
		mysql_query(mysql,arr);
	}
	mysql_query(mysql, "select * from sheet");
	MYSQL_RES* result = mysql_store_result(mysql);
	MYSQL_ROW row;
	while (row = mysql_fetch_row(result))//��ȡһ�У��������û�оͷŻ�0
	{
			char* cno = row[0];//ȡ�������ַ������͵�
			char* cn = row[1];
			printf("number=%s,data=%s\n",row[0],row[1]);
	}
	mysql_free_result(result);
	mysql_close(mysql);//�ر����ݿ����ӣ�����������ر����ӷ���mysql���������п����Ŀ�����
	printf("�ر����ݿ�ɹ�\n");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<winsock.h>
#include<mysql.h>//需调用winsock所以先引用winsock
int main() {
	MYSQL* mysql = mysql_init(0);//初始化mysql的执行环境
	mysql_real_connect(mysql, "127.0.0.1", "root", "071411", "Lucky", 0, 0, 0);
	mysql_query(mysql, "set names gbk");
	//mysql_query(mysql, "insert into Course values('C01','高等数学',3,' ')");
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
	while (row = mysql_fetch_row(result))//获取一行，如果这行没有就放回0
	{
			char* cno = row[0];//取出来是字符串类型的
			char* cn = row[1];
			printf("number=%s,data=%s\n",row[0],row[1]);
	}
	mysql_free_result(result);
	mysql_close(mysql);//关闭数据库连接，程序最后必须关闭链接否者mysql服务器会有卡死的可能性
	printf("关闭数据库成功\n");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<winsock.h>
#include<mysql.h>//需调用winsock所以先引用winsock
int main()
{
	int i = 0;//循环用
	int j = 0;
	char sql[200] = { 0 };
	char arr[200] = { 0 };
	MYSQL* mysql = mysql_init(0);//初始化mysql的执行环境
	if (!mysql_real_connect(mysql, "127.0.0.1", "root","071411","yggl", 0, 0, 0))//指针名，IP地址，用户名，密码，数据库名，端口（全是0代表默认端口）
	{//链接失败返回false
		printf("链接出错：%s", mysql_error(mysql));//打印链接数据库失败的原因
		goto exit;
	}
	if (mysql_query(mysql,"set names gbk"))//设置允许中文插入，set names gbk是被mysql支持的语句
	{
		printf("设定编码失败：%s",mysql_error(mysql));
		goto exit;
	}
	//创建表
	/*if (mysql_query(mysql, "create table diyitian (No float not null, 车号 nvarchar(255) not null, 车号SN nvarchar(255) not null, 借出车站 nvarchar(255) not null, 借出车站号 nvarchar(255) not null, 借车锁桩号 nvarchar(255) not null, 借车时刻 nvarchar(255) not null, 归还车站 nvarchar(255) not null,还车车站号 nvarchar(255) not null, 还车锁桩号 nvarchar(255) not null, 还车时刻 nvarchar(255) not null, 用车时间 nvarchar(255) not null, 用车方式 nvarchar(255) not null, 卡类型 nvarchar(255) not null, 借车卡SN nvarchar(255) not null) "))
	{
		printf("出错了，%s", mysql_error(mysql));
	}*/
	//if (mysql_query(mysql, " insert into Course values('C02','大学英语',3,'')"));//插入内容  ，插入成功返回真
	//{
	//	printf("插入成功\n");
	//}
	//if (mysql_query(mysql, "insert into Course values('C03','计算机应用技术',3,' ')"));//插入内容  ，插入成功返回真
	//{
	//	printf("插入成功\n");
	//}
	//if (mysql_query(mysql, "insert into Course values('C04','数据库技术',2,'C03,c01')"));//插入内容  ，插入成功返回真
	//{
	//	printf("插入成功\n");
	//}
	//if (mysql_query(mysql, "insert into Course  values('C05','人工智能',2,'C04,c01,c03')"));//插入内容  ，插入成功返回真
	//{
	//	printf("插入成功\n");
	//}
	//for (i = 31; i < 36; i++)
	//{//sprintf("数组名"，后面与printf一样）作用是将后面的东西插入到数组中
	//	sprintf(sql, "insert into person(id, passwd) values('%d','%d')", i, i);
	//	if (!mysql_query(mysql, sql))//插入进去成功返回假
	//	{
	//		printf("lllll");
	//	}
	//	else
	//		goto exit;
	//}
	//printf("链接成功并且插入成功\n");
    //从表中批量删除
	/*for (i = 1; i < 5; i++)
	{
		sprintf(sql,"delete from Course where credit=%d", i);
		if (!mysql_query(mysql, sql))
		{
			printf("删除成功\n");
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
	//	printf("出错了%s\n", mysql_error(mysql));//在数据库执行查询语句
	//}
	///*while (i)
	//{
	//	
	//	i--;
	//	if (!mysql_query(mysql,"insert into Course  values('C05','人工智能',2,'C04,c01,c03')"))
	//     {
	//	    printf("hahah\n");
	//     }
	//     else
	//	     printf("%s", mysql_error(mysql));
	//}*/
	/*if (!mysql_query(mysql, "select * from employ"))
	{
		printf("查询成功\n");
	}*/
	////离线结果集（数据是存放在vs中）优点使用方便 缺点 占内存。适合小结果集
	//MYSQL_RES* result = mysql_store_result(mysql);//获取查询结果，把数据放入内存中，在内存中的堆区需要手动释放
	//MYSQL_ROW row;
	//////只要有数据就一直执行,mysql_fetch_row向下移动并且获得这一行的数据mysql_row对象
	//while (row = mysql_fetch_row(result))//获取一行，如果这行没有就放回0
	//{
	//	char* Employees = row[0];//取出来是字符串类型的
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
			sprintf(sql,"select sum(`用量`) from suoyou where `水表名`='64397副表' group by and `采集时间` like '____/%d/%d %'", i, j);
			if (!mysql_query(mysql, sql))
			{
				printf("查询成功\n");
			}
			printf("%d %d", i, j);
			MYSQL_RES* result = mysql_store_result(mysql);//获取查询结果，把数据放入内存中，在内存中的堆区需要手动释放
			MYSQL_ROW row;
			while (row = mysql_fetch_row(result))//获取一行，如果这行没有就放回0
			{
				char* Employees = row[0];//取出来是字符串类型的
				printf("%s", row[0]);
			}
			mysql_free_result(result);//释放本地内存查询结果
		}
	}
	//mysql_free_result(result);//释放本地内存查询结果
exit:
	mysql_close(mysql);//关闭数据库连接，程序最后必须关闭链接否者mysql服务器会有卡死的可能性
	printf("关闭数据库成功\n");
	return 0;
}
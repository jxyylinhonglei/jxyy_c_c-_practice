#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>   
//#include<errno.h>
//#include <string.h>   
//#include <windows.h>   
//#include <sql.h>   
//#include <sqlext.h>   
//#include <sqltypes.h>   
//#include <odbcss.h>   
//
//SQLHENV henv;
//SQLHDBC hdbc;
//SQLHSTMT hstmt;
//SQLRETURN retcode;
/////*
////    cpp文件功能说明：
////    1.数据库操作中的添加，修改，删除，主要体现在SQL语句上
////    2.采用直接执行方式和参数预编译执行方式两种
////*/
//int main() {
//    retcode = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
//    retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
//    retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
//    //
//    //
//    retcode = SQLConnect(hdbc, (SQLCHAR*)"mytest", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"071411", SQL_NTS);
//
//    if (!(retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO))
//    {
//        printf("链接失败\n");
//        printf("%s", strerror(errno));
//        return -1;
//    }
//    else
//    {
//        printf("lainjiechenggong\n");
//    }
//    retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
//    SQLCHAR sql1[] = "use 2013";
//    SQLCHAR sql2[] = "select * from diyitian1";
//    retcode = SQLExecDirect(hstmt, sql1, SQL_NTS);
//    retcode = SQLExecDirect(hstmt, sql2, SQL_NTS);
//
//    SQLDisconnect(hdbc);
//    SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
//    SQLFreeHandle(SQL_HANDLE_DBC, henv);
//    return 0;
//}
//    //char a[200] = "bbb";
//    //char b[200] = "200";
//    //SQLINTEGER   p;
//    //RETCODE retcode;
//    //UCHAR    szDSN[SQL_MAX_DSN_LENGTH + 1] = "csql",
//    //    szUID[MAXNAME] = "sa",
//    //    szAuthStr[MAXNAME] = "pass";
//    ////SQL语句
//    //    //直接SQL语句
//    //UCHAR    sql[37] = "insert into test values('aaa','100')";
//    ////预编译SQL语句
//    //UCHAR    pre_sql[29] = "insert into test values(?,?)";
//    ////1.连接数据源
//    //    // 分配ODBC 环境句柄
//    //retcode = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
//    //// 告诉ODBC这是一个3.0标准的应用程序  
//    //retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
//    //// 分配连接句柄并建立连接
//    //retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc1);
//    //retcode = SQLConnect(hdbc1, szDSN, (SWORD)strlen(szDSN), szUID, (SWORD)strlen(szUID), szAuthStr, (SWORD)strlen(szAuthStr));
//    ////判断连接是否成功
//    //if ((retcode != SQL_SUCCESS) && (retcode != SQL_SUCCESS_WITH_INFO)) {
//    //    printf("连接失败!\n");
//    //}
//    //else {
//    //    //2.创建并执行一条或多条SQL语句
//    //    /*
//    //    1.分配一个语句句柄(statement handle)
//    //    2.创建SQL语句
//    //    3.执行语句
//    //    4.销毁语句
//    //    */
//    //    retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc1, &hstmt1);
//    //    //第一种方式
//    //    //直接执行
//    //    //添加操作
//    //    //SQLExecDirect (hstmt1,sql,37);
//
//    //    //第二种方式
//    //    //绑定参数方式
//
//    //    p = SQL_NTS;
//    //    //1预编译
//    //    SQLPrepare(hstmt1, pre_sql, 29); //第三个参数与数组大小相同，而不是数据库列相同
//    //    //2绑定参数值
//    //    SQLBindParameter(hstmt1, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a, 0, &p);
//    //    SQLBindParameter(hstmt1, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &b, 0, &p);
//    //    //3 执行
//    //    SQLExecute(hstmt1);
//
//    //    printf("操作成功!");
//    //    //释放语句句柄
//    //    SQLCloseCursor(hstmt1);
//    //    SQLFreeHandle(SQL_HANDLE_STMT, hstmt1);
//
//    //}
//    ////3.断开数据源
//    ///*
//    // 1.断开与数据源的连接.
//    // 2.释放连接句柄.
//    // 3.释放环境句柄(如果不再需要在这个环境中作更多连接)
//    //*/
//    //SQLDisconnect(hdbc1);
//    //SQLFreeHandle(SQL_HANDLE_DBC, hdbc1);
//    //SQLFreeHandle(SQL_HANDLE_ENV, henv);
//    //system("pause");
//    //return(0);
//}




//int main()
//{
//
//
//	void sqlConnect();
//	sqlConnect();
//	getchar();
//	return 0;
//}
//void sqlConnect()
//{
//	SQLHENV henv;
//	SQLHDBC hdbc;
//	SQLHSTMT hstmt;
//	SQLRETURN retcode;
//	UCHAR sql1[79] = "select No from Student where Name='jim'";
//
//	retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
//	if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
//	{
//
//		retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
//		if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
//		{
//
//			retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
//			if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
//			{
//
//				retcode = SQLConnect(hdbc, (SQLCHAR*)"LocalServer", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"123456", SQL_NTS);
//				if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO)
//				{
//
//					retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
//					if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS)
//					{
//
//						//绑定参数方式
//						char a[20] = "Jim";
//						SQLINTEGER p = SQL_NTS;
//						//1.预编译
//						SQLPrepare(hstmt, sql1, 79);//第三个参数与数组大小相同，而不是数据库列相同
//						//2.绑定参数值
//						SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a, 0, &p);
//						SQLExecute(hstmt);
//						printf("connection is OK\n");
//						//SQLExecDirect(hstmt,sql1,79);
//						char list[5];
//						SQLBindCol(hstmt, 1, SQL_C_CHAR, list, 5, 0);
//						SQLFetch(hstmt);
//						printf("%s\n", list);
//					}
//					SQLDisconnect(hdbc);
//				}
//				SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
//			}
//		}
//	}
//}

//#include <stdio.h>   
//
//#include <string.h>   
//#include <windows.h>   
//#include <sql.h>   
//#include <sqlext.h>   
//#include <sqltypes.h>   
//#include <odbcss.h>   
//
//SQLHENV henv = SQL_NULL_HENV;
//SQLHDBC hdbc1 = SQL_NULL_HDBC;
//SQLHSTMT hstmt1 = SQL_NULL_HSTMT;
//
///*
//    cpp文件功能说明：
//    1.数据库操作中的添加，修改，删除，主要体现在SQL语句上
//    2.采用直接执行方式和参数预编译执行方式两种
//*/
//int main() {
//    char a[200] = "bbb";
//    char b[200] = "200";
//    SQLINTEGER   p;
//    RETCODE retcode;
//    UCHAR    szDSN[SQL_MAX_DSN_LENGTH + 1] = "2013",
//        szUID[MAXNAME] = "as",
//        szAuthStr[MAXNAME] = "071411";
//    //SQL语句
//        //直接SQL语句
//    UCHAR    sql[37] = "insert into test values('aaa','100')";
//    //预编译SQL语句
//    UCHAR    pre_sql[29] = "insert into test values(?,?)";
//    //1.连接数据源
//        // 分配ODBC 环境句柄
//    retcode = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
//    // 告诉ODBC这是一个3.0标准的应用程序  
//    retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
//    // 分配连接句柄并建立连接
//    retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc1);
//    retcode = SQLConnect(hdbc1, szDSN, (SWORD)strlen(szDSN), szUID, (SWORD)strlen(szUID), szAuthStr, (SWORD)strlen(szAuthStr));
//    //判断连接是否成功
//    if ((retcode != SQL_SUCCESS) && (retcode != SQL_SUCCESS_WITH_INFO)) {
//        printf("连接失败!\n");
//    }
//    else {
//        //2.创建并执行一条或多条SQL语句
//        /*
//        1.分配一个语句句柄(statement handle)
//        2.创建SQL语句
//        3.执行语句
//        4.销毁语句
//        */
//        retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc1, &hstmt1);
//        //第一种方式
//        //直接执行
//        //添加操作
//        //SQLExecDirect (hstmt1,sql,37);
//
//        //第二种方式
//        //绑定参数方式
//
//        p = SQL_NTS;
//        //1预编译
//        SQLPrepare(hstmt1, pre_sql, 29); //第三个参数与数组大小相同，而不是数据库列相同
//        //2绑定参数值
//        SQLBindParameter(hstmt1, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a, 0, &p);
//        SQLBindParameter(hstmt1, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &b, 0, &p);
//        //3 执行
//        SQLExecute(hstmt1);
//
//        printf("操作成功!");
//        //释放语句句柄
//        SQLCloseCursor(hstmt1);
//        SQLFreeHandle(SQL_HANDLE_STMT, hstmt1);
//
//    }
//    //3.断开数据源
//    /*
//     1.断开与数据源的连接.
//     2.释放连接句柄.
//     3.释放环境句柄(如果不再需要在这个环境中作更多连接)
//    */
//    SQLDisconnect(hdbc1);
//    SQLFreeHandle(SQL_HANDLE_DBC, hdbc1);
//    SQLFreeHandle(SQL_HANDLE_ENV, henv);
//    system("pause");
//    return(0);
//}


#include<stdio.h>

#include<windows.h>

#include<sql.h>

#include<sqlext.h>

#include<sqltypes.h>

int main()

{

	SQLRETURN ret;

	SQLHENV henv;

	SQLHDBC hdbc;

	SQLHSTMT hstmt;

	ret = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);//申请环境句柄

	ret = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);

	ret = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);//申请数据库连接句柄

	ret = SQLConnect(hdbc, (SQLCHAR*)"mytest", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"071411", SQL_NTS);

	/*data_test为配置的ODBC数据源名称，这里根据自己的配置进行修改*/

	if (!(ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO))

	{

		printf("连接数据库失败!\n");

		return -1;

	}

	ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

	/*执行sql语句*/

	/*SQLCHAR sql1[] = "use stu_info";

	SQLCHAR sql2[] = "select * from student";

	ret = SQLExecDirect(hstmt, sql1, SQL_NTS);

	ret = SQLExecDirect(hstmt, sql2, SQL_NTS);*/

	//if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)

	//{

	//	SQLCHAR str1[50], str2[50], str3[50], str4[50], str5[50], str6[50];

	//	SQLINTEGER len_str1, len_str2, len_str3, len_str4, len_str5, len_str6;

	//	while (SQLFetch(hstmt) != SQL_NO_DATA)

	//	{

	//		SQLGetData(hstmt, 1, SQL_C_CHAR, str1, 50, &len_str1); //获取第一列数据

	//		SQLGetData(hstmt, 2, SQL_C_CHAR, str2, 50, &len_str2);

	//		SQLGetData(hstmt, 3, SQL_C_CHAR, str3, 50, &len_str3);

	//		SQLGetData(hstmt, 4, SQL_C_CHAR, str4, 50, &len_str4);

	//		SQLGetData(hstmt, 5, SQL_C_CHAR, str5, 50, &len_str5);

	//		SQLGetData(hstmt, 6, SQL_C_CHAR, str6, 50, &len_str6);

	//		printf("%s\t%s\t%s\t%s\t%s\t%s\n", str1, str2, str3, str4, str5, str6);

	//	}

	//}

	SQLFreeHandle(SQL_HANDLE_DBC, hdbc);//释放连接句柄

	SQLFreeHandle(SQL_HANDLE_ENV, henv);//释放环境句柄

	return 0;

}
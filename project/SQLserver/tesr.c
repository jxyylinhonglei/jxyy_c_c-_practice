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
////    cpp�ļ�����˵����
////    1.���ݿ�����е���ӣ��޸ģ�ɾ������Ҫ������SQL�����
////    2.����ֱ��ִ�з�ʽ�Ͳ���Ԥ����ִ�з�ʽ����
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
//        printf("����ʧ��\n");
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
//    ////SQL���
//    //    //ֱ��SQL���
//    //UCHAR    sql[37] = "insert into test values('aaa','100')";
//    ////Ԥ����SQL���
//    //UCHAR    pre_sql[29] = "insert into test values(?,?)";
//    ////1.��������Դ
//    //    // ����ODBC �������
//    //retcode = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
//    //// ����ODBC����һ��3.0��׼��Ӧ�ó���  
//    //retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
//    //// �������Ӿ������������
//    //retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc1);
//    //retcode = SQLConnect(hdbc1, szDSN, (SWORD)strlen(szDSN), szUID, (SWORD)strlen(szUID), szAuthStr, (SWORD)strlen(szAuthStr));
//    ////�ж������Ƿ�ɹ�
//    //if ((retcode != SQL_SUCCESS) && (retcode != SQL_SUCCESS_WITH_INFO)) {
//    //    printf("����ʧ��!\n");
//    //}
//    //else {
//    //    //2.������ִ��һ�������SQL���
//    //    /*
//    //    1.����һ�������(statement handle)
//    //    2.����SQL���
//    //    3.ִ�����
//    //    4.�������
//    //    */
//    //    retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc1, &hstmt1);
//    //    //��һ�ַ�ʽ
//    //    //ֱ��ִ��
//    //    //��Ӳ���
//    //    //SQLExecDirect (hstmt1,sql,37);
//
//    //    //�ڶ��ַ�ʽ
//    //    //�󶨲�����ʽ
//
//    //    p = SQL_NTS;
//    //    //1Ԥ����
//    //    SQLPrepare(hstmt1, pre_sql, 29); //�����������������С��ͬ�����������ݿ�����ͬ
//    //    //2�󶨲���ֵ
//    //    SQLBindParameter(hstmt1, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a, 0, &p);
//    //    SQLBindParameter(hstmt1, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &b, 0, &p);
//    //    //3 ִ��
//    //    SQLExecute(hstmt1);
//
//    //    printf("�����ɹ�!");
//    //    //�ͷ������
//    //    SQLCloseCursor(hstmt1);
//    //    SQLFreeHandle(SQL_HANDLE_STMT, hstmt1);
//
//    //}
//    ////3.�Ͽ�����Դ
//    ///*
//    // 1.�Ͽ�������Դ������.
//    // 2.�ͷ����Ӿ��.
//    // 3.�ͷŻ������(���������Ҫ���������������������)
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
//						//�󶨲�����ʽ
//						char a[20] = "Jim";
//						SQLINTEGER p = SQL_NTS;
//						//1.Ԥ����
//						SQLPrepare(hstmt, sql1, 79);//�����������������С��ͬ�����������ݿ�����ͬ
//						//2.�󶨲���ֵ
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
//    cpp�ļ�����˵����
//    1.���ݿ�����е���ӣ��޸ģ�ɾ������Ҫ������SQL�����
//    2.����ֱ��ִ�з�ʽ�Ͳ���Ԥ����ִ�з�ʽ����
//*/
//int main() {
//    char a[200] = "bbb";
//    char b[200] = "200";
//    SQLINTEGER   p;
//    RETCODE retcode;
//    UCHAR    szDSN[SQL_MAX_DSN_LENGTH + 1] = "2013",
//        szUID[MAXNAME] = "as",
//        szAuthStr[MAXNAME] = "071411";
//    //SQL���
//        //ֱ��SQL���
//    UCHAR    sql[37] = "insert into test values('aaa','100')";
//    //Ԥ����SQL���
//    UCHAR    pre_sql[29] = "insert into test values(?,?)";
//    //1.��������Դ
//        // ����ODBC �������
//    retcode = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);
//    // ����ODBC����һ��3.0��׼��Ӧ�ó���  
//    retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
//    // �������Ӿ������������
//    retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc1);
//    retcode = SQLConnect(hdbc1, szDSN, (SWORD)strlen(szDSN), szUID, (SWORD)strlen(szUID), szAuthStr, (SWORD)strlen(szAuthStr));
//    //�ж������Ƿ�ɹ�
//    if ((retcode != SQL_SUCCESS) && (retcode != SQL_SUCCESS_WITH_INFO)) {
//        printf("����ʧ��!\n");
//    }
//    else {
//        //2.������ִ��һ�������SQL���
//        /*
//        1.����һ�������(statement handle)
//        2.����SQL���
//        3.ִ�����
//        4.�������
//        */
//        retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc1, &hstmt1);
//        //��һ�ַ�ʽ
//        //ֱ��ִ��
//        //��Ӳ���
//        //SQLExecDirect (hstmt1,sql,37);
//
//        //�ڶ��ַ�ʽ
//        //�󶨲�����ʽ
//
//        p = SQL_NTS;
//        //1Ԥ����
//        SQLPrepare(hstmt1, pre_sql, 29); //�����������������С��ͬ�����������ݿ�����ͬ
//        //2�󶨲���ֵ
//        SQLBindParameter(hstmt1, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &a, 0, &p);
//        SQLBindParameter(hstmt1, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 200, 0, &b, 0, &p);
//        //3 ִ��
//        SQLExecute(hstmt1);
//
//        printf("�����ɹ�!");
//        //�ͷ������
//        SQLCloseCursor(hstmt1);
//        SQLFreeHandle(SQL_HANDLE_STMT, hstmt1);
//
//    }
//    //3.�Ͽ�����Դ
//    /*
//     1.�Ͽ�������Դ������.
//     2.�ͷ����Ӿ��.
//     3.�ͷŻ������(���������Ҫ���������������������)
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

	ret = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);//���뻷�����

	ret = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);

	ret = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);//�������ݿ����Ӿ��

	ret = SQLConnect(hdbc, (SQLCHAR*)"mytest", SQL_NTS, (SQLCHAR*)"sa", SQL_NTS, (SQLCHAR*)"071411", SQL_NTS);

	/*data_testΪ���õ�ODBC����Դ���ƣ���������Լ������ý����޸�*/

	if (!(ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO))

	{

		printf("�������ݿ�ʧ��!\n");

		return -1;

	}

	ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

	/*ִ��sql���*/

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

	//		SQLGetData(hstmt, 1, SQL_C_CHAR, str1, 50, &len_str1); //��ȡ��һ������

	//		SQLGetData(hstmt, 2, SQL_C_CHAR, str2, 50, &len_str2);

	//		SQLGetData(hstmt, 3, SQL_C_CHAR, str3, 50, &len_str3);

	//		SQLGetData(hstmt, 4, SQL_C_CHAR, str4, 50, &len_str4);

	//		SQLGetData(hstmt, 5, SQL_C_CHAR, str5, 50, &len_str5);

	//		SQLGetData(hstmt, 6, SQL_C_CHAR, str6, 50, &len_str6);

	//		printf("%s\t%s\t%s\t%s\t%s\t%s\n", str1, str2, str3, str4, str5, str6);

	//	}

	//}

	SQLFreeHandle(SQL_HANDLE_DBC, hdbc);//�ͷ����Ӿ��

	SQLFreeHandle(SQL_HANDLE_ENV, henv);//�ͷŻ������

	return 0;

}
#include"manager.h"
Work_manage::Work_manage()
{
}
void Work_manage::menu()
{
	cout << "*******************************" << endl;
	cout << "*******欢迎使用职工管理系统****" << endl;
	cout << "**********0.退出管理程序*******" << endl;
	cout << "**********1.添加员工信息*******" << endl;
	cout << "**********2.显示员工信息*******" << endl;
	cout << "**********3.删除离职员工*******" << endl;
	cout << "**********4.修改员工信息*******" << endl;
	cout << "**********5.查找员工信息*******" << endl;
	cout << "**********6.按照编号排序*******" << endl;
	cout << "**********7.清空所有文档*******" << endl;
	cout << endl;
}
Work_manage::~Work_manage()
{

}
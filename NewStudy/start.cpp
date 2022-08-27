#include<iostream>//引入标准输入输出流
#include"complex.h"
using namespace std;//使用标准命名空间
int a = 100;
namespace TEST {//命名空间可以解决命名冲突，可以存放变量，函数，结构体，类等。并且命名空间声明在全局作用域下
	int a = 200;
	struct animal {
		char name[10]="wngcai1";
		void func1(){
			cout << "animal::func1" << endl;
		}
	};
	namespace AAA {//命名空间可以嵌套
		void func1() {
			cout << "animal:AAA:::func1" << endl;
		}
	}
}
namespace TEST {//命名空间是开放的可以随时添加成员
	int b = 10;
}
//namespace std {
//	int bb = 100;
//}
int bb = 200;
namespace  {//命名空间可以是匿名的
	int m_a = 111;//相当于是 static int m_a=111;
}
namespace name {
	void name11() {
		cout <<"我是name的函数" << endl;
	}
}
void test1(){
	using name::name11;//using的声明	
	name11();
}
void test2() {
	using namespace name;//using 编译
	name11();
}
//gettest(w,h) {
//
//}
int main11() {
	//const int aa = 10;//对于const变量取地址，编译器会进行分配临时空间地址，p指向的是临时空间地址
	//int* p = (int*)&aa;
	//*p = 20;
	//cout << p << "  " << &a << endl;
	//cout <<aa <<endl;
	
	//test2();
	//int a = 10;
	//int b = 20;
	//*(a > b ? &a : &b) = 100;
	//printf("11 b=%d\n", b);
	//const int len = 10;
	//int arr[len];
	//cout <<"  hello world	" << endl;//end作用是刷新缓冲区，并且换行
	//cout <<::a<< endl;//::是代表作用域，::前面什么都不加代表全局作用域
	//cout<<TEST::a<<endl;
	//TEST::animal tmp;
	//tmp.func1();
	//TEST::AAA::func1();
	//int bb = 200;//当使用命名空间，与变量名冲突时，优先使用局部变量
	//cout << bb << endl;
	//cout<<m_a<<endl;
	//namespace label = name;//命名空间可以取别名
	//label::name11();

	//const complex<int> a;//代表变量a是不能改变的,并且只能调用complex中const函数
	////a.real();
	//a.imag();
	return 0;
}
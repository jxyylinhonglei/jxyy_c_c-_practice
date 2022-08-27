#include<iostream>
using namespace std;
//class A {
//public:
//	virtual void func1() {
//		cout << "test虚函数" << endl;
//	}
//};
//class B :public A {
//public:
//	virtual void func1() {
//		cout << "test1虚函数" << endl;
//	}
//};
//int main() {
//	/*
//		动态绑定必须通过指针
//	*/
//	B b;
//	b.func1();
//	A a=(A)b;
//	a.func1();
//	A* aa=new B;
//	aa->func1();
//	return 0;
//}
class Document {
public:
	void openFile() {
		serial();
	}
	virtual void serial() {
		
	}
};
class File:public Document {
public:
	virtual void serial() {// openFile(Document* this)中this->serial();
		cout << "在File类中调用的" << endl;
	}
};
//const 修饰成员函数，表示不修改类属性
//const 修饰对象，这个对象只能调用const修饰的函数
//当成员函数有const与没有const修饰的版本同时存在时，const修饰的对象调用const修饰的成员函数，非const修饰的对象调用非const成员函数
class Const_member {
public:
	Const_member() {
		cout << "默认构造函数" << endl;
	}
	Const_member(double tt):a(tt) {
		cout << "赋值构造函数" << endl;
	}
	~Const_member() {
		cout << "默认析构函数" << endl;
	}
	void test() const {
		cout << "Const_member的const修饰的test方法" << endl;
	}
	void test() {
		cout << "Const_member的非const修饰的test方法" << endl;
	}
	operator int(){//转换函数是不用写返回类型的
		return (int)a;
	}
	double a = 1.11;
	/*
		重载new与free操作符
	*/
	static void*  operator new(size_t a) {
		Const_member*p=(Const_member*)malloc(a);
		cout << "tamade" << endl;
		cout << "nishiyigedashibi1" << endl;
		return p;
	}
	static void operator delete(void* ps,size_t a) {
		cout << "nishiyigedashibi1" << endl;
		free(ps);
	}
};
int global = 100;
int main_aaa() {
	Const_member* ps = new Const_member(0.999);
	delete ps;
	//Const_member a1;
	//a1.test();
	//cout<<int(a1)<<endl;
	//const Const_member a2;
	//a2.test();

	//int global = 20;
	//cout<<::global<<endl;//::变量是调用全局变量

	//Document* ps=new File;
	//ps->openFile();
	return 0;
}
//new底层调用的是malloc。如果是new一个对象，那么会分配完内存后调用构造函数，delete释放这个对象会先调用对象的析构函数在回收空间。
// 
//
//
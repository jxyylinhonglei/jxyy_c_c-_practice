#include<iostream>
using namespace std;
//class A {
//public:
//	virtual void func1() {
//		cout << "test�麯��" << endl;
//	}
//};
//class B :public A {
//public:
//	virtual void func1() {
//		cout << "test1�麯��" << endl;
//	}
//};
//int main() {
//	/*
//		��̬�󶨱���ͨ��ָ��
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
	virtual void serial() {// openFile(Document* this)��this->serial();
		cout << "��File���е��õ�" << endl;
	}
};
//const ���γ�Ա��������ʾ���޸�������
//const ���ζ����������ֻ�ܵ���const���εĺ���
//����Ա������const��û��const���εİ汾ͬʱ����ʱ��const���εĶ������const���εĳ�Ա��������const���εĶ�����÷�const��Ա����
class Const_member {
public:
	Const_member() {
		cout << "Ĭ�Ϲ��캯��" << endl;
	}
	Const_member(double tt):a(tt) {
		cout << "��ֵ���캯��" << endl;
	}
	~Const_member() {
		cout << "Ĭ����������" << endl;
	}
	void test() const {
		cout << "Const_member��const���ε�test����" << endl;
	}
	void test() {
		cout << "Const_member�ķ�const���ε�test����" << endl;
	}
	operator int(){//ת�������ǲ���д�������͵�
		return (int)a;
	}
	double a = 1.11;
	/*
		����new��free������
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
	//cout<<::global<<endl;//::�����ǵ���ȫ�ֱ���

	//Document* ps=new File;
	//ps->openFile();
	return 0;
}
//new�ײ���õ���malloc�������newһ��������ô��������ڴ����ù��캯����delete�ͷ����������ȵ��ö�������������ڻ��տռ䡣
// 
//
//
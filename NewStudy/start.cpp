#include<iostream>//�����׼���������
#include"complex.h"
using namespace std;//ʹ�ñ�׼�����ռ�
int a = 100;
namespace TEST {//�����ռ���Խ��������ͻ�����Դ�ű������������ṹ�壬��ȡ����������ռ�������ȫ����������
	int a = 200;
	struct animal {
		char name[10]="wngcai1";
		void func1(){
			cout << "animal::func1" << endl;
		}
	};
	namespace AAA {//�����ռ����Ƕ��
		void func1() {
			cout << "animal:AAA:::func1" << endl;
		}
	}
}
namespace TEST {//�����ռ��ǿ��ŵĿ�����ʱ��ӳ�Ա
	int b = 10;
}
//namespace std {
//	int bb = 100;
//}
int bb = 200;
namespace  {//�����ռ������������
	int m_a = 111;//�൱���� static int m_a=111;
}
namespace name {
	void name11() {
		cout <<"����name�ĺ���" << endl;
	}
}
void test1(){
	using name::name11;//using������	
	name11();
}
void test2() {
	using namespace name;//using ����
	name11();
}
//gettest(w,h) {
//
//}
int main11() {
	//const int aa = 10;//����const����ȡ��ַ������������з�����ʱ�ռ��ַ��pָ�������ʱ�ռ��ַ
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
	//cout <<"  hello world	" << endl;//end������ˢ�»����������һ���
	//cout <<::a<< endl;//::�Ǵ���������::ǰ��ʲô�����Ӵ���ȫ��������
	//cout<<TEST::a<<endl;
	//TEST::animal tmp;
	//tmp.func1();
	//TEST::AAA::func1();
	//int bb = 200;//��ʹ�������ռ䣬���������ͻʱ������ʹ�þֲ�����
	//cout << bb << endl;
	//cout<<m_a<<endl;
	//namespace label = name;//�����ռ����ȡ����
	//label::name11();

	//const complex<int> a;//�������a�ǲ��ܸı��,����ֻ�ܵ���complex��const����
	////a.real();
	//a.imag();
	return 0;
}
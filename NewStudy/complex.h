#ifndef __COMPLEX__//��ֹͷ�ļ��ظ�����
#define __COMPLEX__
#include<string>
template<typename T>
#include<iostream>
class complex {
public://�����������أ����ݲ�����������λ������
	complex(T r = 0, T i = 0) :re(r), im(i) {//��ʼ���б�Ч�ʸ���

	}
	//complex() :re(0), im(0) {//�����������ֻ�ܶ�ѡ��һ()

	//}
	T real() const { return re; }//���������ܸı���������
	T imag() const { return im; }
	T func(complex& a)//��ͬclass�ĸ�object��Ϊfriend,������Ԫ��Ҫ����
	{
		return a.re;
	}
	~complex() {}
private:
	T re;
	T im;
	template<typename T>
	friend std::ostream& operator<<(std::ostream& out, complex& a);
};
template<typename T>
std::ostream& operator<<(std::ostream& out, const complex<T>& a) {
	return out << a.real();
}
//class A {// singleton ����ģʽ������������ڴ���ֻ����һ��
//public:
//	static A& getInstance();
//private:
//	A();
//	A(const A& rhs);
//};
//A& A::getInstance() {
//	static A a;
//	return a;
//}

//temp object��ʱ��������();�������ھ�����һ��
#endif

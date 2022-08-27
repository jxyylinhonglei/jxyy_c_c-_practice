#ifndef __COMPLEX__//防止头文件重复包含
#define __COMPLEX__
#include<string>
template<typename T>
#include<iostream>
class complex {
public://函数可以重载，根据参数的类型与位置区别
	complex(T r = 0, T i = 0) :re(r), im(i) {//初始化列表，效率更高

	}
	//complex() :re(0), im(0) {//这种与上面的只能二选择一()

	//}
	T real() const { return re; }//常函数不能改变数据内容
	T imag() const { return im; }
	T func(complex& a)//相同class的各object互为friend,并且友元需要声明
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
//class A {// singleton 单例模式，这个对象在内存中只存在一份
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

//temp object临时对象，类名();生命周期就在这一行
#endif

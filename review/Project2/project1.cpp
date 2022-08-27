#include<iostream>
using namespace std;
template<class T>//类模板
class share_ptr {//智能指针封装
public://const share_ptr* this
	share_ptr(T& a)  :px(&a){}
	T& operator*() {
		return *px;
	}
	T* operator->() {
		return (operator*());
	}
	T operator ()(const T& a,const T& b)const {
		return a + b;
	}
private:
	T* px;
};
class test {
public:
	test(int _tmp) :tmp(_tmp) {

	}
	int operator() (int a, int b) {
		return a + b;
	}
	~test() {}
private:
	int tmp;
};
class stone {
public:
	stone(int w=0,int h=0,int we=0) :_w(w),_h(h),_we(we){}
	bool operator> (const stone& tmp) const {
		return this->_w > tmp._w;
	}
private:
	int _w;
	int _h;
	int _we;
};
template<class T>//函数模板
inline const T& min_(const T& a,const T& b) {
	return a > b ? b : a;
}

////模板特化
//template<>
//struct hash<int> {
//	void operator()(int tmp) {
//		cout<<"hash<int> tmp="<<tmp << endl;
//	}
//};
//template<>
//struct hash<char> {
//	void operator()(char tmp) {
//		cout << "hash<char> tmp=" << tmp << endl;
//	}
//};
int main000() {
	//test t(10);
	//cout << t(10, 20) << endl;//仿函数
	//int a = 10;
	//share_ptr<int> str(a);
	//cout<<*str<<endl;

	//stone a(1,1,1), b(2,2,2), c;
	//c = min_(a,b);
	//hash<char>()('a');
	//hash<int>()(10);//创建临时对象类型()
	return 0;
}
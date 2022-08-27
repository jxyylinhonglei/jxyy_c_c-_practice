#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include"complex.h"
#include"myString.h"
#include<algorithm>
using namespace std;
#define a10 10
class Solution {
public://[[1,10],[8,9]]
	explicit Solution(int len) {//explicit防止隐式转换
		cout<<"len=" << len << endl;
	}
	Solution(const char* ps) {//explict防止隐式转换
		cout << "ps=" << ps << endl;
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		for (int i = 0; i < intervals.size();i++) {
			if (ans.size()!=0&&ans.back()[1]>=intervals[i][0]) {
				ans.back()[1] = max(ans.back()[1], intervals[i][1]);
			}
			else {
				ans.push_back(intervals[i]);
			}
		}
		return ans;
	}
};
int main0() {
	complex c1(2, 1);
	complex c2(4, 0);

	cout << c1 << endl;
	cout << c2 << endl;

	cout << c1 + c2 << endl;
	cout << c1 - c2 << endl;


	cout << (c1 += c2) << endl;

	cout << (c1 == c2) << endl;
	cout << (c1 != c2) << endl;

	cout << (c2 - 2) << endl;
	cout << (5 + c2) << endl;
	int a = 10;
	int& b = a;
	cout<<"&a="<<&a << endl;
	cout << "&b=" << &b << endl;
	cout <<sizeof(complex)<< endl;
	String s1("hello");
	String s2("world");

	String s3(s2);
	cout << s3 << endl;

	s3 = s1;
	cout << s3 << endl;
	cout << s2 << endl;
	cout << s1 << endl;
	cout << a10 << endl;//cout之所以能够打印出这么多的类型是因为，实现了很多<<重载
#undef a10

	return 0;
}
class test1 {
public:
	test1() {
		cout<<"test的构造函数" << endl;
	}
	virtual ~test1() {
		cout << "test的构造函数" << endl;
	}
};
class test22 :public test1 {
public:
	test22() {
		cout << "test2的构造函数" << endl;
	}
	~test22() {
		cout << "test2的构造函数" << endl;
	}
};
class Fraction {
public:
	explicit Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}//explicit可以防止隐式转换，explicit作用在构造函数上

	//operator double() const {//函数转换，由用户定义将一个类对象转换成其他类型
	//	return (double)(m_numerator / m_denominator);
	//}
	operator double() const {
		return (double)(m_numerator / m_denominator);
	}
	Fraction operator + (const Fraction& fac) const {
		return Fraction(this->m_numerator+fac.m_numerator,this->m_denominator*fac.m_denominator);
	}
private:
	int m_numerator;//分子
	int m_denominator;//分母
};
int main() {

/*	Fraction f(3, 5);
	Fraction f = 4 + f;*///编译器会先去寻找是否有operator+（double,Fraction）运算符重载，没有就会调用 operator double()类型转换函数		
	Fraction f(3, 5);
	//Fraction d =f+4;//会出现二义性，编译器可以把f转换为double类型进行相加然后调用构造函数。也可以进行将4转换为Fraction进行相加，然后调用摩尔嗯拷贝构造函数
	//test1* tmp=new test22;
	//delete tmp;
	//Solution solution;
	//vector<vector<int>> ans;
	//ans.push_back(vector<int>{1, 4});
	//ans.push_back(vector<int>{0, 0});
	//solution.merge(ans);
	
	//extern int jxyy;
	//jxyy = 200;
	//cout<<"jxyy=" << jxyy << endl;
	//extern void prin();
	//prin();

	//Solution s(10);
	//Solution s1("haha");
	//Solution s3 = 20;//当构造函数加上explicit是，隐式转换就失效了
	return 0;
}
//stack
//heap 操作系统提供一块全局内存空间
// new底层调用的是malloc，最后会调用构造函数
// delete会先调用析构函数，最后回收内存底层是free函数
// new出来一个数组，delete删除也一定要搭配上[],否则会造成内存泄露
// 
//
//常函数 ： 修饰成员函数中的 this指针，让指针指向的值不可以修改
 //常函数中或常对象 有些特殊属性依然想修改，加入关键字 mutable
 // mutable int tmp=10;
//编译器会实参推到		

//在成员函数前面加上virtual就是虚函数
//非虚函数意思是父类不希望子类重写函数
//虚函数意思是父类可以让子类重写函数
//纯虚函数意思是子类一定要重写函数
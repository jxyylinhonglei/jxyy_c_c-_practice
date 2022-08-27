#ifndef __MYSTRING__
#define __MYSTRING__
#define _CRT_SECURE_NO_WARNINGS
class String {
public:
	String(const char* spr);
	String(const String& str);
	String& operator = (const String& str);
	char* get_c_str() const { return m_data; }
	~String();
private:
	char* m_data;
};
#include<cstring>
inline String::String(const char* spr) {
	if (spr) {
		this->m_data = new char[strlen(spr)+1];
		strcpy(this->m_data,spr);
	}
	else {
		this->m_data = new char[1];
		this->m_data[0] = '\0';
	}
}
inline String::String(const String& str) {
	this->m_data = new char[strlen(str.get_c_str())+1];
	strcpy(this->m_data,str.get_c_str());
}
//赋值运算符重载
// 下面的当delete后，new对象出现内存不足抛出异常
//inline String& String::operator = (const String& str) {
//	if (this==&str){
//		return *this;
//	}
//	delete[] this->m_data;
//	this->m_data = new char[strlen(str.get_c_str()) + 1];
//	strcpy(this->m_data, str.get_c_str());
//	return *this;
//}
//方法改进
inline String& String::operator = (const String& str) {
	if (this != &str) {
		String tmp(str);
		char* pTmp = this->m_data;
		this->m_data = tmp.m_data;
		tmp.m_data = pTmp;
		/*
			使用一个临时变量，储存str的数据，然后数据与当前类数交换，当出去了if后就会调用临时变量的析构函数会销毁对象原先的字符串
		*/
	}
	return *this;
}
inline String::~String() {
	delete[] this->m_data;
}
#include<iostream>
using namespace std;
ostream& operator << (ostream& out, String& str) {
	out << str.get_c_str();
	return out;
}
#endif
//静态成员函数，没有this指针，只能处理静态数据
//成员函数在内存中只有一份，不同对象调用调用同一个成员函数，这个成员函数是根据this指针区分的
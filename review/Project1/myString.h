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
//��ֵ���������
// ����ĵ�delete��new��������ڴ治���׳��쳣
//inline String& String::operator = (const String& str) {
//	if (this==&str){
//		return *this;
//	}
//	delete[] this->m_data;
//	this->m_data = new char[strlen(str.get_c_str()) + 1];
//	strcpy(this->m_data, str.get_c_str());
//	return *this;
//}
//�����Ľ�
inline String& String::operator = (const String& str) {
	if (this != &str) {
		String tmp(str);
		char* pTmp = this->m_data;
		this->m_data = tmp.m_data;
		tmp.m_data = pTmp;
		/*
			ʹ��һ����ʱ����������str�����ݣ�Ȼ�������뵱ǰ��������������ȥ��if��ͻ������ʱ�������������������ٶ���ԭ�ȵ��ַ���
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
//��̬��Ա������û��thisָ�룬ֻ�ܴ���̬����
//��Ա�������ڴ���ֻ��һ�ݣ���ͬ������õ���ͬһ����Ա�����������Ա�����Ǹ���thisָ�����ֵ�
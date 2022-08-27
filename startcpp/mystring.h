#pragma once
#include<iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning( disable : 4996)
using namespace std;
class mystring
{
friend istream& operator>>(istream& cin, mystring& ps);
public:
	mystring();
	mystring(char* tmp);
	mystring::mystring(mystring& p1);
	char* m_print();
	void operator=(mystring& ps);
	char& operator[](int index);
	mystring operator+(mystring& pp);
	~mystring();
private:
	char* ps;
	int size;
};
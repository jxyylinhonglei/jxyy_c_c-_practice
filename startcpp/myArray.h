#pragma once
#include<iostream>
using namespace std;
#include<string>
class Array
{
public:
	Array();
	Array(int x);//设置容量
	Array(const Array& ps);//复制数组
	void pushBack(int x);//尾插
	void setData(int pos, int x);//任意插
	int gerData(int pos);//根据位置获取数据
	int getCapacity();//获取数组容量
	int getSize();//获取数组大小
	int& operator[](int index);
	~Array();
private:
	int* arr;
	int size;
	int capacity;
};
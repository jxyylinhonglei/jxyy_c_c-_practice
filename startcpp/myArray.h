#pragma once
#include<iostream>
using namespace std;
#include<string>
class Array
{
public:
	Array();
	Array(int x);//��������
	Array(const Array& ps);//��������
	void pushBack(int x);//β��
	void setData(int pos, int x);//�����
	int gerData(int pos);//����λ�û�ȡ����
	int getCapacity();//��ȡ��������
	int getSize();//��ȡ�����С
	int& operator[](int index);
	~Array();
private:
	int* arr;
	int size;
	int capacity;
};
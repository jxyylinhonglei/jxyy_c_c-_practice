#include"myArray.h"
Array::Array()
{
	this->capacity = 100;
	this->size = 0;
	this->arr = new int[this->capacity];
}
Array::Array(int x)//��������
{
	this->capacity = x;
	this->size = 0;
	this->arr = new int[this->capacity];
}
Array::Array(const Array& ps)//��������
{
	this->capacity = ps.capacity;
	this->size = 0;
	this->arr = new int[this->capacity];
	//for (int i=0;i<ps.size;i++)
	//{
	//	this->arr[i] = ps.arr[i];
	//}
}
void Array::pushBack(int x)//β��
{
	if (this->size >= this->capacity)
	{
		cout << "��������" << endl;
		return;
	}
	this->arr[this->size] =x;
	this->size++;
}
void Array::setData(int pos, int x)//�����
{
	for (int i=this->size;i>=pos;i--)
	{
		int tmp = this->arr[i];
		this->arr[i] = this->arr[i+1];
		this->arr[i + 1] = tmp;
	}
	this->arr[pos] = x;
	this->size++;
}
int Array::gerData(int pos)//����λ�û�ȡ����
{
	if (pos<=this->size&&pos>=0)
	{
		return this->arr[pos];
	}
	cout << "Խ��" << endl;
}
int Array::getCapacity()//��ȡ��������
{
	return this->capacity;
}
int Array::getSize()//��ȡ�����С
{
	return this->size;
}
int&  Array::operator[](int index)
{
	return this->arr[index];
}
Array::~Array()
{
	if (this != NULL)
	{
		delete[this->capacity] this->arr;
	}
}
#include"myArray.h"
Array::Array()
{
	this->capacity = 100;
	this->size = 0;
	this->arr = new int[this->capacity];
}
Array::Array(int x)//设置容量
{
	this->capacity = x;
	this->size = 0;
	this->arr = new int[this->capacity];
}
Array::Array(const Array& ps)//复制数组
{
	this->capacity = ps.capacity;
	this->size = 0;
	this->arr = new int[this->capacity];
	//for (int i=0;i<ps.size;i++)
	//{
	//	this->arr[i] = ps.arr[i];
	//}
}
void Array::pushBack(int x)//尾插
{
	if (this->size >= this->capacity)
	{
		cout << "容量不足" << endl;
		return;
	}
	this->arr[this->size] =x;
	this->size++;
}
void Array::setData(int pos, int x)//任意插
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
int Array::gerData(int pos)//根据位置获取数据
{
	if (pos<=this->size&&pos>=0)
	{
		return this->arr[pos];
	}
	cout << "越界" << endl;
}
int Array::getCapacity()//获取数组容量
{
	return this->capacity;
}
int Array::getSize()//获取数组大小
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
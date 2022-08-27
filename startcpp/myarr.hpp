#pragma once
template<class T>
class arraya
{
public:
	arraya(){}
	arraya(int _capacity)
	{
		this->capacity = _capacity;
		paddress = new T[this->capacity];
	}
	arraya(arraya& a)
	{
		this->capacity = a.capacity;
		this->size = a.size;
		paddress = new T[this->capacity];
		for (int i=0;i<this->size;i++)
		{
			this->paddress[i]=a.paddress[i];
		}
	}
	//ÖØÔØ=
	arraya& operator=(arraya& a)
	{
		if (this->paddress!=NULL)
		{
			delete[] paddress;
		}
		this->capacity = a.capacity;
		this->size = a.size;
		paddress = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			this->paddress[i] = a.paddress[i];
		}
		return *this;
	}
	//ÖØÔØ[]
	T& operator[](int index)
	{
		return this->paddress[index];
	}
	//Î²²å
	void pushback(int val)
	{
		if (this->size == this->capacity)
		{
			return;
		}
		this->paddress[this->size] = val;
		this->size++;
	}
	int getcapacity()
	{
		return this->capacity;
	}
	int getsize()
	{
		return this->size;
	}
	void print()
	{
		for (int i=0;i<size;i++)
		{
			cout<<this->paddress[i]<<" ";
		}
		cout << endl;
	}
	~arraya()
	{
		if (this->paddress != NULL)
		{
			delete[] paddress;
		}
	}
private:
	T* paddress;
	int capacity;
	int size;
};
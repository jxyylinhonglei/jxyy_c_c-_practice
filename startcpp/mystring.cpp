#include"mystring.h"
mystring::mystring()
{
	this->ps = NULL;
	this->size = 0;
}
mystring::mystring(char* tmp)
{
	this->ps=new char[strlen(tmp)+1];
	strcpy(this->ps,tmp);
	this->size = strlen(tmp)+1;
}
mystring::mystring(mystring& p1)
{
	this->ps = new char[strlen(p1.ps)+1];
	strcpy(this->ps,p1.ps);
	this->size = p1.size;
}
char* mystring::m_print()
{
	return this->ps;
}
istream& operator>>(istream& cin,mystring& ps)
{
	if (ps.ps != NULL)
	{
		delete[ps.size] ps.ps;
		ps.ps = NULL;
	}
	char buff[1024];
	cin >> buff;
	ps.ps = new char[strlen(buff) + 1];
	strcpy(ps.ps,buff);
	ps.size = strlen(ps.ps) + 1;
	return cin;
}
char& mystring::operator[](int index)
{
	return *(this->ps + index);
}
mystring mystring::operator+(mystring& pp)
{
	char* tt = new char[strlen(this->ps)+strlen(pp.ps)+1];
	strcat(tt,this->ps);
	cout << this->ps << endl;
	strcat(tt,pp.ps);
	cout << pp.ps << endl;
	mystring tmp(tt);
	cout << tmp.ps << endl;
	tmp.size = strlen(this->ps) + strlen(pp.ps) + 1;
	return tmp;
}
void mystring::operator=(mystring& ps)
{
	if (this->ps != NULL)
	{
		delete[this->size] this->ps;
	}
	this->ps = new char[strlen(ps.ps) + 1];
	strcpy(this->ps,ps.ps);
	this->size = strlen(this->ps) + 1;
}
mystring::~mystring()
{
	if (this->ps!=NULL)
	{
		delete [this->size] this->ps;
	}
}

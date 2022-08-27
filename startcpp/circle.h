#pragma once
#include<iostream>
using namespace std;
class Point
{
public:
	void setm_x(int x);
	void setm_y(int y);
	int getm_x();
	int getm_y();
private:
	int m_x;
	int m_y;
};
class Circle
{
public:
	void setm_r(int r);
	void setPoint(Point& tt);
	int getm_r();
	Point getPoint();
	void compare00(Point& aa);
private:
	int m_r;
	Point m_xy;
};


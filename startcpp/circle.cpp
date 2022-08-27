#include"circle.h"
void Point::setm_x(int x)
{
	m_x = x;
}
void Point::setm_y(int y)
{
	m_y = y;
}
int Point::getm_x()
{
	return m_x;
}
int Point::getm_y()
{
	return m_y;
}
void Circle::setm_r(int r)
{
	m_r = r;
}
void Circle::setPoint(Point& tt)
{
	m_xy = tt;
}
int Circle::getm_r()
{
	return m_r;
}
Point Circle::getPoint()
{
	return m_xy;
}
void Circle::compare00(Point& aa)
{
	int distance = (getPoint().getm_x() - aa.getm_x()) * (getPoint().getm_x() - aa.getm_x()) + (getPoint().getm_y() - aa.getm_y()) * (getPoint().getm_y() - aa.getm_y());
	if (distance ==getm_r() * getm_r())
	{
		cout << "点在圆上" << endl;
	}
	else if (distance < getm_r() *getm_r())
	{
		cout << "点在圆内" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;
	}
}
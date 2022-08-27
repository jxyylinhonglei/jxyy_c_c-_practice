#ifndef __MYCOMPLEX__
#define __MYCOMPLEX__
class complex;
complex& __doapl(complex* ths,const complex& r);
class complex {
public:
	complex(double r=0,double i=0):re(r),im(i) {}
	complex& operator += (const complex&);
	double real() const{ return re; }
	double imag() const{ return im; }
	double imag__(const complex& t) const { return t.re; }
private:
	int tmp, a;//不存在内存对齐
	double re, im;
	char s;
	friend complex& __doapl(complex*, const complex&);
};
inline complex& __doapl(complex* ths, const complex& r) {
	ths->im += r.im;
	ths->re += r.re;
	return *ths;
}
inline complex& complex::operator +=(const complex& r) {
	return __doapl(this,r);
}
inline double image(const complex& x) {
	return x.imag();
}
inline double real(const complex& x) {
	return x.real();
}
inline complex operator + (const complex & x, const complex & y) {
	return complex(real(x)+ real(y),image(y)+image(y));
}
inline complex operator + (const complex& x,double y) {
	return complex(real(x)+y, image(y));
}
inline complex operator + (double y, const complex& x) {
	return complex(real(x) + y, image(y));
}
inline complex operator - (const complex& x, const complex& y) {
	return complex(real(x)-real(y),
		image(x)-image(y));
}
inline complex operator - (double x, const complex& y) {
	return complex(real(y)-x,-image(y));
}
inline complex operator - (const complex& y, double x) {
	return complex(real(y) - x, -image(y));
}
inline bool operator == (const complex& x, const complex& y) {
	return real(x) == real(y) && image(x) == image(y);
}
inline bool operator == (const complex& x, double y) {
	return real(x) == y && image(x) == 0;
}
inline bool operator == (double x, const complex& y) {
	return x == real(y) && 0 == image(y);
}
inline bool operator != (const complex& x, const complex& y) {
	return real(x) != real(y) || image(x) != image(y);
}
inline bool operator != (const complex& x, double y) {
	return real(x) != y || image(x) != 0;
}
inline bool operator != (double x, const complex& y) {
	return x != real(y) || image(y)!=0;
}
#include<iostream>
std::ostream& operator << (std::ostream& out,const complex x) {
	return out << '(' << real(x) << ',' << image(x) << ')'<<'h';
}
#endif	//MYCOMPLEX
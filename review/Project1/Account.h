#ifndef __ACCOUNT__
#define __ACCOUNT__
class Account {
public:
	static double m_rate;
	static void set_rate(const double& x) { m_rate = x; }
};
double Account::m_rate = 10;
#endif//����static������ʽ������

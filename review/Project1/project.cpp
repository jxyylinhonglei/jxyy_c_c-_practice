#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include"complex.h"
#include"myString.h"
#include<algorithm>
using namespace std;
#define a10 10
class Solution {
public://[[1,10],[8,9]]
	explicit Solution(int len) {//explicit��ֹ��ʽת��
		cout<<"len=" << len << endl;
	}
	Solution(const char* ps) {//explict��ֹ��ʽת��
		cout << "ps=" << ps << endl;
	}
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		for (int i = 0; i < intervals.size();i++) {
			if (ans.size()!=0&&ans.back()[1]>=intervals[i][0]) {
				ans.back()[1] = max(ans.back()[1], intervals[i][1]);
			}
			else {
				ans.push_back(intervals[i]);
			}
		}
		return ans;
	}
};
int main0() {
	complex c1(2, 1);
	complex c2(4, 0);

	cout << c1 << endl;
	cout << c2 << endl;

	cout << c1 + c2 << endl;
	cout << c1 - c2 << endl;


	cout << (c1 += c2) << endl;

	cout << (c1 == c2) << endl;
	cout << (c1 != c2) << endl;

	cout << (c2 - 2) << endl;
	cout << (5 + c2) << endl;
	int a = 10;
	int& b = a;
	cout<<"&a="<<&a << endl;
	cout << "&b=" << &b << endl;
	cout <<sizeof(complex)<< endl;
	String s1("hello");
	String s2("world");

	String s3(s2);
	cout << s3 << endl;

	s3 = s1;
	cout << s3 << endl;
	cout << s2 << endl;
	cout << s1 << endl;
	cout << a10 << endl;//cout֮�����ܹ���ӡ����ô�����������Ϊ��ʵ���˺ܶ�<<����
#undef a10

	return 0;
}
class test1 {
public:
	test1() {
		cout<<"test�Ĺ��캯��" << endl;
	}
	virtual ~test1() {
		cout << "test�Ĺ��캯��" << endl;
	}
};
class test22 :public test1 {
public:
	test22() {
		cout << "test2�Ĺ��캯��" << endl;
	}
	~test22() {
		cout << "test2�Ĺ��캯��" << endl;
	}
};
class Fraction {
public:
	explicit Fraction(int num, int den = 1) : m_numerator(num), m_denominator(den) {}//explicit���Է�ֹ��ʽת����explicit�����ڹ��캯����

	//operator double() const {//����ת�������û����彫һ�������ת������������
	//	return (double)(m_numerator / m_denominator);
	//}
	operator double() const {
		return (double)(m_numerator / m_denominator);
	}
	Fraction operator + (const Fraction& fac) const {
		return Fraction(this->m_numerator+fac.m_numerator,this->m_denominator*fac.m_denominator);
	}
private:
	int m_numerator;//����
	int m_denominator;//��ĸ
};
int main() {

/*	Fraction f(3, 5);
	Fraction f = 4 + f;*///����������ȥѰ���Ƿ���operator+��double,Fraction����������أ�û�оͻ���� operator double()����ת������		
	Fraction f(3, 5);
	//Fraction d =f+4;//����ֶ����ԣ����������԰�fת��Ϊdouble���ͽ������Ȼ����ù��캯����Ҳ���Խ��н�4ת��ΪFraction������ӣ�Ȼ�����Ħ���ſ������캯��
	//test1* tmp=new test22;
	//delete tmp;
	//Solution solution;
	//vector<vector<int>> ans;
	//ans.push_back(vector<int>{1, 4});
	//ans.push_back(vector<int>{0, 0});
	//solution.merge(ans);
	
	//extern int jxyy;
	//jxyy = 200;
	//cout<<"jxyy=" << jxyy << endl;
	//extern void prin();
	//prin();

	//Solution s(10);
	//Solution s1("haha");
	//Solution s3 = 20;//�����캯������explicit�ǣ���ʽת����ʧЧ��
	return 0;
}
//stack
//heap ����ϵͳ�ṩһ��ȫ���ڴ�ռ�
// new�ײ���õ���malloc��������ù��캯��
// delete���ȵ��������������������ڴ�ײ���free����
// new����һ�����飬deleteɾ��Ҳһ��Ҫ������[],���������ڴ�й¶
// 
//
//������ �� ���γ�Ա�����е� thisָ�룬��ָ��ָ���ֵ�������޸�
 //�������л򳣶��� ��Щ����������Ȼ���޸ģ�����ؼ��� mutable
 // mutable int tmp=10;
//��������ʵ���Ƶ�		

//�ڳ�Ա����ǰ�����virtual�����麯��
//���麯����˼�Ǹ��಻ϣ��������д����
//�麯����˼�Ǹ��������������д����
//���麯����˼������һ��Ҫ��д����
#include<vector>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<map>
#include<array>
using namespace std;
void test() {
	vector<int> v(10,1);//������Ĭ��ֵ
	//cout << v.at(2) << endl;
	//cout << v.at(3) << endl;
	//cout << v.at(6) << endl;
	//v.resize(5);//���ô�С��
	v.resize(5);
	for (int i = 0; i < 5;i++) {
		//v.insert(v.begin()+i,i);//Ч�ʵ�	
		v.push_back(i);
	}

	//v.erase(v.begin()+7);
	////v.erase(v.begin(),v.end());//�ȼ���clear()
	//v.clear();
	vector<int> v1{9,2};
	v1.swap(v);//swap(v)//�ö�����v���н���
	vector<int>::iterator it = v.begin();
	while (it!=v.end()) {
		cout << *it <<"	";
		it++;
	}
	cout << endl;
}
/*
	string��ʹ��
*/
void test1() {
	string str="tamade123456789";
	str.replace(1,3,"o");
	cout << str << endl;
	str.append("666");
	cout << str << endl;
	cout << str.find("de") << endl;
	const char* c = str.c_str();
	cout << c << endl;
}
void test2() {
	multiset<int> set;
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 100000;i++) {
		set.insert(rand());
	}
	long end = clock();
	cout << "����������ʱ" << end - begin << endl;
	cout << "Ԫ�صĸ���Ϊ" << set.size() << "�������β" << set.max_size() << endl;
	cout << "10000�ĸ���Ϊ" << set.count(10000) << endl;
	//while (set.count(10000)) {
	//	auto ret = set.find(10000);
	//	set.erase(ret);
	//	cout << "10000�ĸ���Ϊ" << set.count(10000) << endl;
	//}
	while (set.count(10000)) {
		cout << "10000�ĸ���Ϊ" << set.count(10000) << endl;
		set.erase(10000);
	}
	cout << "10000�ĸ���Ϊ" << set.count(10000) << endl;//erase(Ԫ��)��ɾ��set�����е��ڵ�ֵ
}
void test10() {
	set<int> ss;
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 100000; i++) {
		ss.insert(rand());
	}
	long end = clock();
	cout << "����������ʱ" << end - begin << endl;
	cout << "Ԫ�صĸ���Ϊ" << ss.size() << "�������β" << ss.max_size() << endl;
	cout <<"1000�ĸ����ж��ٸ�"<< ss.count(1000) << endl;
	set<int>::iterator ret = ss.find(1000);
	while (ss.count(1000)) {
		//ss.erase(1000);//�汾һ
		auto ret = ss.find(1000);
		ss.erase(ret);
	}
	cout << "1000�ĸ����ж��ٸ�" << ss.count(1000) << endl;
}
void test11() {//unordered(
	unordered_set<int> ss;//�ײ�ʹ�ù�ϣ��洢
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 100000; i++) {
		ss.insert(rand());
	}
	long end = clock();
	cout << "����������ʱ" << end - begin << endl;
	cout << "Ԫ�صĸ���Ϊ" << ss.size() << "�������β" << ss.max_size() << endl;
	cout << "1000�ĸ����ж��ٸ�" << ss.count(1000) << endl;
	while (ss.count(1000)) {
		cout << "1000�ĸ����ж��ٸ�" << ss.count(1000) << endl;
		auto ret=ss.find(1000);
		ss.erase(ret);
	}
	cout << "1000�ĸ����ж��ٸ�" << ss.count(1000) << endl;
	unordered_set<int>().swap(ss);
	cout << "Ԫ�صĸ���Ϊ" << ss.size() << "�������β" << ss.max_size() << endl;
}
void test12() {
	unordered_multiset<int> ss;
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 100000; i++) {
		ss.insert(rand());
	}
	long end = clock();
	cout << "����������ʱ" << end - begin << endl;
	cout << "Ԫ�صĸ���Ϊ" << ss.size() << "�������β" << ss.max_size() << endl;
	cout << "1000�ĸ����ж��ٸ�" << ss.count(1000) << endl;
	while (ss.count(1000)) {
		cout << "1000�ĸ����ж��ٸ�" << ss.count(1000) << endl;
		auto ret = ss.find(1000);
		ss.erase(ret);
	}
	cout << "1000�ĸ����ж��ٸ�" << ss.count(1000) << endl;
}
void test13() {
	map<int, string> m;
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 100000; i++) {
		m.insert(pair<int,string>(rand(),string("tamade")));
	}
	long end = clock();
	cout << "����������ʱ" << end - begin << endl;
	cout << "Ԫ�صĸ���Ϊ" << m.size() << "�������β" << m.max_size() << endl;
	while (m.count(1000)) {
		map<int, string>::iterator ret = m.find(1000);
		cout << ret->first << "	" << ret->second << endl;
		m.erase(ret->first);
	}
}
void test14() {
	multimap<int, int> m;
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 100000;i++) {
		m.insert(pair<int,int>(rand(),i));
	}
	long end = clock();
	cout << "����������ʱ" << end - begin << endl;
	cout << "Ԫ�صĸ���Ϊ" << m.size() << "�������β" << m.max_size() << endl;
	while (m.count(666)) {
		auto ret=m.find(666);
		cout << ret->first << "	" << ret->second << "�ж��ٸ�" << m.count(666) << endl;
		m.erase(ret);
	}
	//while (m.count(666)) {
	//	auto ret = m.find(666);
	//	cout << ret->first << "	" << ret->second <<"�ж��ٸ�" << m.count(666) << endl;
	//	m.erase(666);
	//}
}
void test15() {
	unordered_multimap<int, int> m;
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 100000; i++) {
		m.insert(pair<int, int>(rand(), i));
	}
	long end = clock();
	cout << "����������ʱ" << end - begin << endl;
	cout << "Ԫ�صĸ���Ϊ" << m.size() << "�������β" << m.max_size() << endl;
	while (m.count(666)) {
		auto ret = m.find(666);
		cout << ret->first << "	" << ret->second << "�ж��ٸ�" << m.count(666) << endl;
		m.erase(ret);
	}
}
void test16() {
	unordered_map<int, int> m;
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 100000; i++) {
		m.insert(pair<int, int>(rand(), i));
	}
	long end = clock();
	cout << "����������ʱ" << end - begin << endl;
	cout << "Ԫ�صĸ���Ϊ" << m.size() << "�������β" << m.max_size() << endl;
	while (m.count(666)) {
		auto ret = m.find(666);
		cout << ret->first << "	" << ret->second << "�ж��ٸ�" << m.count(666) << endl;
		m.erase(ret);
	}
}
/*
	��ģ��ĸ���ƫ�ػ�
*/
template<class T,class TT=int>
class tmp {
public:
	void test() {
		cout << "class T,class TT=int��tmp" << sizeof(a) << endl;
	}
	TT a;
};
template<class TT>
class tmp<char,TT> {
public:
	void test() {
		cout << "int,class TT=int��tmp" <<sizeof(a)<< endl;
	}
	TT a;
};
/*
	��Χ��ƫ�ػ�
*/
template<class T>
class iter {
public:
	void test() {
		cout << "��һ��"<< endl;
	}
};
template<class T>
class iter<T*> {
public:
	void test() {
		cout << "�ڶ���" << endl;
	}
};
template<typename T>
class point {
public:
	T data;
};
class Solution {
public:
	void dfs(vector<string>& ans, string& ret, string& s, int number, int cur) {//�𰸣���ʱ�ַ������������ָ��ĸ�����λ��
		if (number==4) {
			if (cur==s.size()) {
				ans.push_back(ret);
			}
			return;
		}
		int sz = ret.size();
		for (int i = 0; i < 3;i++) {
			if (i==1&&ret.back()=='0') {
				break;
			}
			if (i==2&&(s[cur - 2] > '2'||s[cur-2]=='2'\
				&&s[cur-1]>'5'|| s[cur - 2] == '2' && \
				s[cur - 1] == '5'&&s[cur]>'5')) {//�������255�����
				break;
			}
			ret.push_back(s[cur++]);
			if (number!=3) {
				ret.push_back('.');
			}
			dfs(ans,ret,s,number+1,cur);
			if (number!=3) {
				ret.pop_back();
			}
		}
		ret.resize(sz);
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		string ret;
		dfs(ans, ret, s, 0, 0);
		return ans;
	}
	int minMaxGame(vector<int>& nums) {
		vector<int> temp1(nums);
		vector<int> temp2;
		int sz = nums.size();
		int k = 0;
		for (int i = 0; i < sz && sz != 1; i += 2) {
			if (k % 2==0) {
				temp2.push_back(min(temp1[i], temp1[i + 1]));
			}
			else {
				temp2.push_back(max(temp1[i], temp1[i + 1]));
			}
			k++;
			if (i == sz - 2) {
				i = -2;
				k = 0;
				sz = temp2.size();
				temp1.swap(temp2);
				temp2.clear();
			}
		}
		return temp1.back();
	}
};
int main0() {
	//unodered_set<string> tmp;//errorԭ���Ǳ�׼��û��ʵ��string����hash����
	set<string> tmp;


	//unordered_set<int> set;
	//srand(time(NULL));
	//for (int i = 0; i < 10000;i++) {
	//	set.insert(rand());
	//	cout << "Ԫ�صĸ���Ϊ" << set.size() << "����Ϊ" << set.bucket_count() << endl;
	//}



	//set<int> test;
	//srand(time(0));
	//for (int i = 0; i < 15;i++) {
	//	test.insert(rand());
	//}
	//set<int>::iterator itr = test.begin();
	//while (itr!=test.end()) {
	//	cout << *itr << "	";
	//	itr++;
	//}

	//vector<int> nums{ 1,3,5,2,4,8,2,2 };
	//Solution leetcode;
	//int ans=leetcode.minMaxGame(nums);
	//cout << ans << endl;

	//leetcode
	//string s=
	//	"66212274";
	//Solution leetcode;
	//vector<string> ans= leetcode.restoreIpAddresses(s);
	//vector<string>::iterator ite = ans.begin();
	//while (ite!=ans.end()) {
	//	cout << *ite << endl;
	//	ite++;
	//}

	//tmp<int> s;
	//s.test();

	//tmp<char,double> s1;
	//s1.test();

	//iter<int> i;
	//i.test();

	//iter<int*> i1;
	//i1.test();

	//test16();
	//ʹ�÷�����
	
	//allocator<int> alloc;//����������
	//int* p = alloc.allocate(2);
	//alloc.deallocate(p,2);
	return 0;
}
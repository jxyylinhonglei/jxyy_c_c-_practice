#include<vector>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<map>
#include<array>
using namespace std;
void test() {
	vector<int> v(10,1);//个数，默认值
	//cout << v.at(2) << endl;
	//cout << v.at(3) << endl;
	//cout << v.at(6) << endl;
	//v.resize(5);//重置大小，
	v.resize(5);
	for (int i = 0; i < 5;i++) {
		//v.insert(v.begin()+i,i);//效率低	
		v.push_back(i);
	}

	//v.erase(v.begin()+7);
	////v.erase(v.begin(),v.end());//等价于clear()
	//v.clear();
	vector<int> v1{9,2};
	v1.swap(v);//swap(v)//让对象与v进行交换
	vector<int>::iterator it = v.begin();
	while (it!=v.end()) {
		cout << *it <<"	";
		it++;
	}
	cout << endl;
}
/*
	string的使用
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
	cout << "插入数据用时" << end - begin << endl;
	cout << "元素的个数为" << set.size() << "最大容量尾" << set.max_size() << endl;
	cout << "10000的个数为" << set.count(10000) << endl;
	//while (set.count(10000)) {
	//	auto ret = set.find(10000);
	//	set.erase(ret);
	//	cout << "10000的个数为" << set.count(10000) << endl;
	//}
	while (set.count(10000)) {
		cout << "10000的个数为" << set.count(10000) << endl;
		set.erase(10000);
	}
	cout << "10000的个数为" << set.count(10000) << endl;//erase(元素)会删除set中所有等于的值
}
void test10() {
	set<int> ss;
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 100000; i++) {
		ss.insert(rand());
	}
	long end = clock();
	cout << "插入数据用时" << end - begin << endl;
	cout << "元素的个数为" << ss.size() << "最大容量尾" << ss.max_size() << endl;
	cout <<"1000的个数有多少个"<< ss.count(1000) << endl;
	set<int>::iterator ret = ss.find(1000);
	while (ss.count(1000)) {
		//ss.erase(1000);//版本一
		auto ret = ss.find(1000);
		ss.erase(ret);
	}
	cout << "1000的个数有多少个" << ss.count(1000) << endl;
}
void test11() {//unordered(
	unordered_set<int> ss;//底层使用哈希表存储
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 100000; i++) {
		ss.insert(rand());
	}
	long end = clock();
	cout << "插入数据用时" << end - begin << endl;
	cout << "元素的个数为" << ss.size() << "最大容量尾" << ss.max_size() << endl;
	cout << "1000的个数有多少个" << ss.count(1000) << endl;
	while (ss.count(1000)) {
		cout << "1000的个数有多少个" << ss.count(1000) << endl;
		auto ret=ss.find(1000);
		ss.erase(ret);
	}
	cout << "1000的个数有多少个" << ss.count(1000) << endl;
	unordered_set<int>().swap(ss);
	cout << "元素的个数为" << ss.size() << "最大容量尾" << ss.max_size() << endl;
}
void test12() {
	unordered_multiset<int> ss;
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 100000; i++) {
		ss.insert(rand());
	}
	long end = clock();
	cout << "插入数据用时" << end - begin << endl;
	cout << "元素的个数为" << ss.size() << "最大容量尾" << ss.max_size() << endl;
	cout << "1000的个数有多少个" << ss.count(1000) << endl;
	while (ss.count(1000)) {
		cout << "1000的个数有多少个" << ss.count(1000) << endl;
		auto ret = ss.find(1000);
		ss.erase(ret);
	}
	cout << "1000的个数有多少个" << ss.count(1000) << endl;
}
void test13() {
	map<int, string> m;
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 100000; i++) {
		m.insert(pair<int,string>(rand(),string("tamade")));
	}
	long end = clock();
	cout << "插入数据用时" << end - begin << endl;
	cout << "元素的个数为" << m.size() << "最大容量尾" << m.max_size() << endl;
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
	cout << "插入数据用时" << end - begin << endl;
	cout << "元素的个数为" << m.size() << "最大容量尾" << m.max_size() << endl;
	while (m.count(666)) {
		auto ret=m.find(666);
		cout << ret->first << "	" << ret->second << "有多少个" << m.count(666) << endl;
		m.erase(ret);
	}
	//while (m.count(666)) {
	//	auto ret = m.find(666);
	//	cout << ret->first << "	" << ret->second <<"有多少个" << m.count(666) << endl;
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
	cout << "插入数据用时" << end - begin << endl;
	cout << "元素的个数为" << m.size() << "最大容量尾" << m.max_size() << endl;
	while (m.count(666)) {
		auto ret = m.find(666);
		cout << ret->first << "	" << ret->second << "有多少个" << m.count(666) << endl;
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
	cout << "插入数据用时" << end - begin << endl;
	cout << "元素的个数为" << m.size() << "最大容量尾" << m.max_size() << endl;
	while (m.count(666)) {
		auto ret = m.find(666);
		cout << ret->first << "	" << ret->second << "有多少个" << m.count(666) << endl;
		m.erase(ret);
	}
}
/*
	类模板的个数偏特化
*/
template<class T,class TT=int>
class tmp {
public:
	void test() {
		cout << "class T,class TT=int的tmp" << sizeof(a) << endl;
	}
	TT a;
};
template<class TT>
class tmp<char,TT> {
public:
	void test() {
		cout << "int,class TT=int的tmp" <<sizeof(a)<< endl;
	}
	TT a;
};
/*
	范围的偏特化
*/
template<class T>
class iter {
public:
	void test() {
		cout << "第一个"<< endl;
	}
};
template<class T>
class iter<T*> {
public:
	void test() {
		cout << "第二个" << endl;
	}
};
template<typename T>
class point {
public:
	T data;
};
class Solution {
public:
	void dfs(vector<string>& ans, string& ret, string& s, int number, int cur) {//答案，临时字符串，主串，分割点的个数，位置
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
				s[cur - 1] == '5'&&s[cur]>'5')) {//处理大于255的情况
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
	//unodered_set<string> tmp;//error原因是标准库没有实现string类型hash函数
	set<string> tmp;


	//unordered_set<int> set;
	//srand(time(NULL));
	//for (int i = 0; i < 10000;i++) {
	//	set.insert(rand());
	//	cout << "元素的个数为" << set.size() << "容量为" << set.bucket_count() << endl;
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
	//使用分配器
	
	//allocator<int> alloc;//声明分配器
	//int* p = alloc.allocate(2);
	//alloc.deallocate(p,2);
	return 0;
}
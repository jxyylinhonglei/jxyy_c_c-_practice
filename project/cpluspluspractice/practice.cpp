//#include<iostream>
////using namespace std;
//#include<string>
//#include<vector>
////struct Student
////{
////	int num;
////	string name;
////};
//int main()
//{
//	//vector<int> haha = { 1,2,3,4,5,6,7,8,9 };
//	//vector<int> vecvalue;
//	vector<int> ahah = { 0 };
//}
	//int sz = haha.size();
	//if (!haha.empty())
	//{
	//	cout << "ЮЊПе" << endl;
	//}
	//for (i = 0; i < sz; i++)
	//{
	//	cout << haha[i] << endl;
	//}
	/*vector<int> haha(10);
	int sz = haha.size();
	cout << haha.size() << endl;
	for (int i = 0; i < sz; i++)
	{
		cout << haha[i] << endl;
	}
	vector<int> haha1(haha);
	cout << haha1.size() << endl;
	for (int i = 0; i < haha1.size(); i++)
	{
		cout << haha[i] << endl;
	}*/
	//struct Student s1;
	//s1.name = "zahgnsan";
	//s1.num = 10;
	/*vector<struct Student> haha = {s1};
	cout << haha[0].name << endl;
	cout << haha[0].num << endl;*/
	/*vector<int> iv = { 100,200,300 };
	iv.push_back(400);
	iv.push_back(500);
	for (vector<int>::iterator iter = iv.begin(); iter != iv.end(); iter++)
	{
		cout << *iter << endl;
	}
	for (vector<int>::reverse_iterator iter = iv.rbegin(); iter != iv.rend(); iter++)
	{
		cout << *iter << endl;
	}*/
//	vector<struct Student> haha;
//	haha.push_back(s1);
//	vector<struct Student>::iterator ii = haha.begin();
//	cout << ii->name << " " << ii->num << endl;
//	return 0;
////}
//#include<iostream>
//using namespace std;
//#include<vector>
//#include<string>
//void test()
//{
//	vector<string> test = { "zhangsan","lisi","wanwu" };
	/*cout << test.size() << endl;
	cout << test.empty() << endl;*/
	/*test.clear();
	cout << test.empty() << endl;*/
	/*test.push_back("liujia");*/
	/*for (auto& c : test)
	{
		cout << c << endl;
	}*/
	/*vector<string>::iterator begin = test.begin();
	vector<string>::iterator end = test.end();*/
	/*for (auto x = begin; x != end; x++)
	{
		cout << *x << endl;
	}*/
	/*for (vector<string>::reverse_iterator itr = begin; itr != end; itr++)
	{
		cout << *itr << endl;
	}*/
	/*int count = 0;
	for (vector<string>::iterator itr = test.begin(); itr != test.end(); itr++)
	{
		test.insert(itr,"liujia");
		break;
		count++;
	}
	for (vector<string>::iterator itr = test.begin(); itr != test.end(); itr++)
	{
		cout << *itr << endl;
	}*/
//	int cout = 0;
//	vector<string>::iterator itr = test.begin();
//	while (itr != test.end())
//	{
//		if (cout == 2)
//			break;
//		/*itr = test.insert(itr, "sss");*/
//		cout++;
//	}
//	vector<string>::iterator begin = test.begin();
//	while (begin != test.end())
//	{
//		cout << begin << endl;
//		begin++;
//	}
//}
//void test()
//{
//	vector<string> test = { "zhangsan","lisi","wanwu" };
//	vector<string>::iterator itr = test.begin();
//	//vector<string>::iterator iitr = test.end();
//	int a = 0;
//	while (itr != test.end())
//	{
//		if (a == 5)
//			break;
//		itr= test.insert(itr, "sss");
//		itr++;
//		a++;
//	}
//	/*	int cout = 0;
//	vector<string>::iterator itr = test.begin();*/
//	/*while (itr != test.end())
//	{
//		if (cout == 2)
//			break;
//		itr = test.insert(itr, "sss");
//		cout++;
//	}*/
//	
//	/*vector<string>::iterator begin = test.begin();
//		while (begin != test.end())
//		{
//			cout << *begin << endl;
//			begin++;
//		}*/
//	for (auto& x : test)
//	{
//		cout << x << endl;
//	}
//}
//void test()
//{
//	int* a = new int(1);
//	int* b = new int(2);
//	int* c = new int(3);
//	vector<int*> vecvalue = { a,b,c };
//	vector<int*>::iterator begin = vecvalue.begin();
//	while (begin != vecvalue.end())
//	{
//		/*cout << **begin << endl;*/
//		delete* begin;
//		begin=vecvalue.erase(begin);
//	}
//
//	cout <<vecvalue.empty() << endl;
//}
//void test()
//{
//	string haha = { "i sdofh g" };
//	string::iterator begin = haha.begin();
//	string::iterator end = haha.end();
//	while (begin != end)
//	{
//		cout << *begin;
//		begin++;
//	}
//}
//
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<vector>
//void test()
//{
//	vector<int> ahah={0};
//	ahah.push_back(1);
//	/*vecvalue.push_back(2);
//	vecvalue.push_back(3);
//	vecvalue.push_back(4);
//	vecvalue.push_back(5);*/
//	//std::cout << vecvalue[0] << std::endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
#include<iostream>
using namespace std;
#include<vector>
#include<unordered_set>
#include<string>
//int test()
//{
//	//vector<int> vec;
//	//vec.push_back(1);
//	//vec.push_back(2);
//	//vec.push_back(3);
//	//vec.push_back(4);
//	//vector<int>::iterator ite;
//	//for (ite = vec.begin(); ite != vec.end(); ite++)
//	//{
//	//	cout << *ite << endl;
//	//}
//	//vec.erase(ite-1);
//	//for (ite = vec.begin(); ite != vec.end(); ite++)
//	//{
//	//	cout << *ite << endl;
//	//}
//	/*vector<string> strva = {"zhangsan","wangwu","lisi"};
//	vector<string>::iterator itt = strva.begin();
//	while (itt!=strva.end())
//	{
//		cout << *itt << endl;
//		itt++;
//	}*/
//	/*string value = "asdffg";
//	for (string::iterator i = value.begin(); i != value.end(); i++)
//	{
//		cout << *i << endl;
//	}
//	int a = value.size();
//	cout << a << endl;*/
//	string value = "abca";
//	int tmp = 0;
//	for (string::iterator i = value.begin(); i != value.end() - 1; i++)
//	{
//		for (string::iterator j = i + 1; j != value.end(); j++)
//		{
//			if (*i == *j)
//			{
//				tmp = 1;
//			}
//			cout <<*i<<"  "<<*j<< tmp<<endl;
//		}
//	}
//	if (tmp == 1)
//	{
//		return -1;
//	}
//	return value.end() - value.begin();
//}
//int compare(string::iterator a,string::iterator b)
//{
//	int tmp = 0;
//	for (string::iterator i = a; i != b-1; i++)
//	{
//		for (string::iterator j = i + 1; j != b; j++)
//		{
//			if (*i == *j)
//			{
//				tmp = 1;
//			}
//		}
//	}
//	if (tmp == 1)
//	{
//		return -1;
//	}
//	return b - a;
//}
//void test1()
//{
//	int max = -1;
//	string value = "abc";
//	if (value.size() == 0)
//		return ;
//	vector<int> record;
//	for (string::iterator i = value.begin(); i != value.end(); i++)
//	{
//		for (string::iterator j = i; j != value.end(); j++)
//		{
//			record.push_back(compare(i,j+1));
//		}
//	}
//	for (vector<int>::iterator i = record.begin(); i != record.end(); i++)
//	{
//		if (*i > max)
//		{
//			max = *i;
//		}
//	}
//	cout << max << endl;
//}
//class Solution {
//public:
//	int compare(string::iterator a, string::iterator b)
//	{
//
//		int tmp = 0;
//		for (string::iterator i = a; i != b - 1; i++)
//		{
//			for (string::iterator j = i + 1; j != b; j++)
//			{
//				if (*i == *j)
//				{
//					tmp = 1;
//				}
//			}
//		}
//		if (tmp == 1)
//		{
//			return -1;
//		}
//		return b - a;
//	}
//	int lengthOfLongestSubstring(string s) {
//		if (s.size() == 0)
//		{
//			return 0;
//		}
//		int max = -1;
//		vector<int> record;
//		string value = s;
//		for (string::iterator i = value.begin(); i != value.end(); i++)
//		{
//			for (string::iterator j = i; j != value.end(); j++)
//			{
//				record.push_back(compare(i, j + 1));
//			}
//		}
//		for (vector<int>::iterator i = record.begin(); i != record.end(); i++)
//		{
//			if (*i > max)
//			{
//				max = *i;
//			}
//		}
//		return max;
//	}
//};
class Solution
{
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> m(128, 0);
		int ans = 0;
		int i = 0;
 		for (int j = 0; j < s.size(); j++) {
			i = max(i, m[s[j]]);
			m[s[j]] = j + 1;
			ans = max(ans, j - i + 1);
		}
		return ans;
	}
};
int main()
{
	//test1();
	//Solution  ss;
	//string s =  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzAB";
	////string s = "abcab";
	//cout << ss.lengthOfLongestSubstring(s) << endl;
	//vector<int> a(1,1);
	unordered_set<char> occ;
	char arr1 = 'a';
	char arr2 = 'b';
	char arr3 = 'a';
	//cout << occ.count() << endl;
	occ.insert('arr1');
	occ.insert('arr2');
	occ.insert('arr3');
	cout << occ.size() << endl;
	cout << occ.count(arr1) << endl;
	return 0;
}
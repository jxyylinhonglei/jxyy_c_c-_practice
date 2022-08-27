//#include<iostream>
//using namespace std;
//template<typename T>class A {
//public:
//	A() {
//		num = T(6.6);
//	}
//	void print() {
//		cout << "A'num:" << num << endl;
//	}
//	T num;
//};
//
//template<> class A<char*> {
//	const char* str;
//public:
//	A() {
//		str = "A' special definition ";
//	}
//	void print() {
//		cout << str << endl;
//	}
//};
//
//int main() {
//	A<int> a1;      //显示模板实参的隐式实例化
//	a1.print();
//	A<char*> a2;    //使用特化的类模板
//	a2.print();
//	a2.print();
//	return 0;
//}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//template<class T>
//class A {
//public:
//	T num;
//	void print() {
//		cout<<"template<class T>" << endl;
//	}
//};
//template<>
//class A<int> {
//public:
//	void print() {
//		cout << "template<>" << endl;
//	}
//};

//当一个类由泛化与特化，编译器会优先调用特化
template<class T>
class table {
public:
	T name;
	table(const T& tmp):name(tmp) {}
	void operator()(T& a) {
		cout<<"name="<<name <<"   "<<a << endl;
	}
};
template<>
class table<char> {
public:
	void operator()(char a) {
		cout << a << endl;
	}
};
//模板偏特化
//范围上偏特化，个数上偏特化
template<typename T,typename alloc>
class AA {
public:
	void test(){
		cout<<"test1" << endl;
	}
};
template<typename alloc>
class AA<bool, alloc> {//个数上偏特化
public:
	void test() {
		cout << "test2" << endl;
	}
};
template<typename T>
class BB {
public:
	void test() {
		cout << "test11" << endl;
	}
};
template<typename T>//范围上偏特化
class BB<T*> {
public:
	void test() {
		cout << "test22" << endl;
	}
};
//模板模板参数 
template<typename T,template<typename T> class contain>
class XCls {
public:
	contain<T> temp;
};
template<typename T>
class result {
public:
	T data;
};
//模板参数
template<typename T,typename... Types>
void print(const T& a, const Types&... aaa) {
	cout <<sizeof...(aaa)<< endl;
	//print(aaa..);
}
void FormatPrint()
{
	//std::cout << std::endl;
}

template <class T, class ...Args>
void FormatPrint(T first, Args... args)
{
	std::cout << "[" << first << "]";
	FormatPrint(args...);
}
int main22() {
	double a = 10;
	double& b = a;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(&a)<<endl;
	cout<<sizeof(b)<<endl;//这是个假象，经过处理的
	cout << sizeof(&b) << endl;//引用的大小与地址和被引用的大小一样
	cout << &a << endl;//引用通常使用在参数传递上，函数返回值上
	cout << &b << endl;
	//FormatPrint(1,2,'b',"itamade");
	//int a = 10;
	//int& b = a;//int =&a;
	//print(1,2,"abc",0.11);

	//vector<int> tt{1,2,3,4};
	////vector<int>::iterator ite = tt.begin();
	//auto ite = tt.begin();
	//while (ite!=tt.end()) {
	//	cout<<*ite<<endl;
	//	ite++;
	//}

	//string str= "123456789";
	//for (char c:str) {
	//	cout<<c<<endl;
	//}
	//for (auto i:str) {//auto自动类型推断，C++11新特性
	//	cout << i << endl;
	//}
	//for (auto& i:str) {
	//	i = '1';
	//}
	//cout<<str<<endl;
	// 
	
	//XCls<string, result> test;
	//cout <<sizeof(test.temp.data)<< endl;
	//test.temp.data = "hahaha";
	//cout << test.temp.data <<endl;

	//BB<int> b1;

	//BB<int*> b2;
	//b1.test();
	//b2.test();
	//AA<int, int> t1;
	//t1.test();
	//AA<bool, int> t2;
	//t2.test();
	// 
	//cout << __cplusplus<<endl;


	return 0;
}
class Solution {
public:
	/*
		给你一个 无重叠的 ，按照区间起始端点排序的区间列表。
		在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。
		输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
		输出：[[1,2],[3,10],[12,16]]
	*/
	vector<vector<int>> insert1(vector<vector<int>>& intervals, vector<int>& newInterval) {
		intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		for (int i = 0; i < intervals.size(); i++) {
			if (ans.size() != 0 && ans.back()[1] >= intervals[i][0]) {
				ans.back()[1] = max(ans.back()[1], intervals[i][1]);
			}
			else {
				ans.push_back(intervals[i]);
			}
		}
		return ans;
	}
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int left = newInterval[0];
		int right = newInterval[1];
		bool pace = false;
		vector<vector<int>> ans;
		for (int i = 0; i < intervals.size();i++) {
			if (right< intervals[i][0]) {//区间
				if (!pace) {
					ans.push_back(vector<int>{left,right});
					pace = true;
				}
				ans.push_back(intervals[i]);
			}
			else if (left> intervals[i][1]) {
				ans.push_back(intervals[i]);
			}
			else {
				left = min(intervals[i][0],left);
				right = max(intervals[i][1], right);
			}
		}
		if (!pace) {
			ans.push_back(vector<int>{left,right});
		}
		return ans;
	}
	vector<vector<int>> insert2(vector<vector<int>>& intervals, vector<int>& newInterval) {
		int left = newInterval[0];//左边
		int right = newInterval[1];//右边
		bool placed = false;//代表new有没有插入
		vector<vector<int>> ans;
		for (const auto& interval : intervals) {
			if (interval[0] > right) {
				// 在插入区间的右侧且无交集
				if (!placed) {
					ans.push_back({ left, right });
					placed = true;
				}
				ans.push_back(interval);
			}
			else if (interval[1] < left) {
				// 在插入区间的左侧且无交集
				ans.push_back(interval);
			}
			else {
				// 与插入区间有交集，计算它们的并集
				left = min(left, interval[0]);
				right = max(right, interval[1]);
			}
		}
		if (!placed) {
			ans.push_back({ left, right });
		}
		return ans;
	}
	/*
	* 有效 IP 地址 正好由四个整数
	（每个整数位于 0 到 255 之间组成，且不能含有前导 0），
	整数之间用 '.' 分隔。
		输入：s = "25525511135"
		输出：["255.255.11.135","255.255.111.35"]
		输入：s = "101023"
		输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
	*/
	void dfs(string& s, string& tmp, vector<string>& ans,int index,int pos) {
		//if (pos==3&&index!=s.size()) {
		//	return;
		//}
		//if () {
		//	
		//}
		//for (int i = 0; i < 3;i++) {//substr(i,j)截取下标从i到j
		//	tmp += s.substr(index,index+i);
		//	dfs();
		//}
	}
	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		string tmp;
		dfs(s,tmp,ans,0,0);
		return ans;
	}
};
class virA {
public:
	int data;
	int data1;
	virtual void func() {
		
	}
};
int main_() {
	//A<int> a;
	//A<double> a1;
	//a.print();
	//a1.print();
	//a1.num = 10;
	//int aa = 11;
	//table<int>(10)(aa);
	//table<char>()('a');
	
	//string s = "12345678910";
	//cout << s.substr(1,3)<<endl;//substr(i,j)截取下标从i到j
	cout<<sizeof(virA)<<endl;
	return 0;
}
//
//只要类中有虚函数，就会有虚函数指针。可以通过sizeof()进行对比
// 虚函数指针指向虚函数表，虚函数表指向虚函数所在的位置
// 使用虚函数，p是对象指针，调用虚函数底层是(* (p->vptr)[n])(p);
// 动态绑定是使用指针，静态绑定调用不是通过指针
//
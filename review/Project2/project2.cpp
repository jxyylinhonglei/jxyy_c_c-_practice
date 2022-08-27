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
//	A<int> a1;      //��ʾģ��ʵ�ε���ʽʵ����
//	a1.print();
//	A<char*> a2;    //ʹ���ػ�����ģ��
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

//��һ�����ɷ������ػ��������������ȵ����ػ�
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
//ģ��ƫ�ػ�
//��Χ��ƫ�ػ���������ƫ�ػ�
template<typename T,typename alloc>
class AA {
public:
	void test(){
		cout<<"test1" << endl;
	}
};
template<typename alloc>
class AA<bool, alloc> {//������ƫ�ػ�
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
template<typename T>//��Χ��ƫ�ػ�
class BB<T*> {
public:
	void test() {
		cout << "test22" << endl;
	}
};
//ģ��ģ����� 
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
//ģ�����
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
	cout<<sizeof(b)<<endl;//���Ǹ����󣬾��������
	cout << sizeof(&b) << endl;//���õĴ�С���ַ�ͱ����õĴ�Сһ��
	cout << &a << endl;//����ͨ��ʹ���ڲ��������ϣ���������ֵ��
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
	//for (auto i:str) {//auto�Զ������ƶϣ�C++11������
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
		����һ�� ���ص��� ������������ʼ�˵�����������б�
		���б��в���һ���µ����䣬����Ҫȷ���б��е�������Ȼ�����Ҳ��ص�������б�Ҫ�Ļ������Ժϲ����䣩��
		���룺intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
		�����[[1,2],[3,10],[12,16]]
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
			if (right< intervals[i][0]) {//����
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
		int left = newInterval[0];//���
		int right = newInterval[1];//�ұ�
		bool placed = false;//����new��û�в���
		vector<vector<int>> ans;
		for (const auto& interval : intervals) {
			if (interval[0] > right) {
				// �ڲ���������Ҳ����޽���
				if (!placed) {
					ans.push_back({ left, right });
					placed = true;
				}
				ans.push_back(interval);
			}
			else if (interval[1] < left) {
				// �ڲ��������������޽���
				ans.push_back(interval);
			}
			else {
				// ����������н������������ǵĲ���
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
	* ��Ч IP ��ַ �������ĸ�����
	��ÿ������λ�� 0 �� 255 ֮����ɣ��Ҳ��ܺ���ǰ�� 0����
	����֮���� '.' �ָ���
		���룺s = "25525511135"
		�����["255.255.11.135","255.255.111.35"]
		���룺s = "101023"
		�����["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
	*/
	void dfs(string& s, string& tmp, vector<string>& ans,int index,int pos) {
		//if (pos==3&&index!=s.size()) {
		//	return;
		//}
		//if () {
		//	
		//}
		//for (int i = 0; i < 3;i++) {//substr(i,j)��ȡ�±��i��j
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
	//cout << s.substr(1,3)<<endl;//substr(i,j)��ȡ�±��i��j
	cout<<sizeof(virA)<<endl;
	return 0;
}
//
//ֻҪ�������麯�����ͻ����麯��ָ�롣����ͨ��sizeof()���жԱ�
// �麯��ָ��ָ���麯�����麯����ָ���麯�����ڵ�λ��
// ʹ���麯����p�Ƕ���ָ�룬�����麯���ײ���(* (p->vptr)[n])(p);
// ��̬����ʹ��ָ�룬��̬�󶨵��ò���ͨ��ָ��
//
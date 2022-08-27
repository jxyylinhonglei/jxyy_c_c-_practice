//#include<iostream>
//#include<climits>
//int main() {
//	using namespace std;
//	int uncle{ 10 };
//	int ows(20);
//	int test = {5};
//	int test2 = (9);
//	cout << uncle << "	" <<ows<< endl;
//	cout << test << "	" << test2 << endl;
//	return 0;
//}
//int main0() {
//	using namespace std;
//	int int_max = INT_MAX;
//	int int_min = INT_MIN;
//	short short_min = SHRT_MAX;
//	short short_max = SHRT_MAX;
//	long long_min = LONG_MIN;
//	long long_max = LONG_MIN;
//	char char_min = CHAR_MIN;
//	char char_max = CHAR_MAX;
//	long long llong_min = LLONG_MIN;
//	long long llong_max = LLONG_MAX;
//	cout << "int_max=" << int_max << "	" << "int_min" << int_min << "	" << "int的大小为" << sizeof(int) << endl;
//	cout << "short_max=" << short_max << "	" << "short_min" << short_min << "	" << "short的大小为" << sizeof(short) << endl;
//	cout << "long_max=" << long_max << "	" << "long_min" << long_min << "	" << "long的大小为" << sizeof(long) << endl;
//	cout << "char_max=" << (int)char_max << "	" << "char_min" << (int)char_min << "	" << "char的大小为" << sizeof(char) << endl;
//	cout << "llong_max=" << llong_max << "	" << "llong_min" << llong_min << "	" << "long long的大小为" << sizeof(long long) << endl;
//	cout << sizeof int_min << "		" << sizeof short_min << "		" << sizeof char_min << "		" << endl;
//	return 0;
//}
//#include<iostream>
//#include<climits>
//#include<string>
//using namespace std;
//int main() {
	//int tmp = INT_MAX;
	//cout << tmp << endl;
	//cout << tmp+1 << endl;
	//cout << "tamade\b\b";
	//int age = 0;
	//cin >> age;
	//float a = 2.34E-7f;
	//a++;
	//cout << a << endl;
	//char a = 'b';
	//int tmp = int(a);
	//int tmp1 = (int)a;
	//int tmp2 = static_cast<int> (a);
	//cout << tmp << endl;
	//cout << tmp1 << endl;
	//cout << tmp2 << endl;
	//float a = 0.23;
	//float b = 0.12;
	//int tmp = a + b;
	//cout << tmp << endl;
	//char arr[10];
	//char arr1[10];
	//cin.get(arr1, 10);//get()与getline()遇到换行符就停止，getline会丢弃换行符，而get将换行符保留在输入队列中
	//cin.getline(arr, 10);
	//cout << "66" << endl;
	//cout << arr << "  " << arr1 << endl;
	//string str1 = "abc";
	//string str2 = "def";
	//string str = str1 + str2;
	//cout << str << endl;
	//string str;
	//str += "aa";
	//cout << str << endl;
	//string str;
	//getline(cin,str);
	//cout << str << endl;
	//string str1;
	//cin >> str;
	//cin >> str1;
	//cout << str << "  " << str1 << endl;
//	return 0;
//}
//#include<iostream>
//struct intflattable {
//	char name[20];
//	float volume;
//	double price;
//}tmp1, tmp2, tmp3{ "sun",9.3f,434.1 };
//struct torget {
//	int a : 2;
//	unsigned int b : 2;
//	int c : 4;
//};
//union oneall {
//	int a;
//	double b;
//};
//enum spectrum {
//	red,
//	orange,
//	yellow,
//	green,
//	blue,
//	violet,
//	indigo,
//	ultraviolet
//};
//int main() {
//	using namespace std;
//	int arr[] = {1,2,3,4};
//	int(*ps)[4]=&arr;
//	cout <<(*ps)[0]<<endl;
//	cout << (*ps)[1] << endl;
//	cout << (*ps)[2] << endl;
//	cout << (*ps)[3] << endl;
//	cout << *(*ps) << endl;
//	cout << *(*ps+1) << endl;
//	cout << *(*ps+2) << endl;
//	cout << *(*ps+3) << endl;
	//for (int i = 0; i < 10; i++) {
	//	*(arr+i) = i;
	//}
	//cout << *arr<<endl;
	//arr=arr + 1;
	//cout << *arr << endl;
	//arr++;
	//cout << *arr << endl;
	//int* aa = new int;
	//int a = 10;
	//int b = 20;
	//double c = 100;
	//cout << "aa的地址为" << aa << endl;
	//cout << "a的地址为" << &a << endl;
	//cout << "b的地址为" << &b << endl;
	//cout << "c的地址为" << &c << endl;
	//int tmp = &a - &b;
	//cout << tmp << endl;
	//spectrum test;
	//cout << orange << endl;
	//union {
	//	int a;
	//	double b;
	//};
	//a = 10;
	//cout << a << endl;
	//b = 10.22;
	//cout << b << endl;
	//all.b = 10.2222;
	//cout << all.b << endl;
	//struct intflattable bouque={"sunflower",3.3f,44.2 };
	//cout << bouque.name << "  " << bouque.price << "   " << bouque.volume << endl;
	//tmp1= { "tmp1sunflower",3.3f,44.2 };
	//cout << tmp1.name << "  " << tmp1.price << "   " << tmp1.volume << endl;
	//tmp2={ "tmp2sunflower",3.3f,44.2 };
	//cout << tmp2.name << "  " << tmp2.price << "   " << tmp2.volume << endl;
	//cout << tmp3.name << "  " << tmp3.price << "   " << tmp3.volume << endl;
	//torget bit = {1,3,10};
	//cout << bit.a << "  " << bit.b << "   " << bit.c << endl;
	//cout << sizeof(bit) << endl;
//	return 0;
//}
//#include<iostream>
//#include<cstring>
//#define _CRT_SECURE_NO_WARNINGS 1
//#pragma warning(disable:4996)
//int main() {
//	using namespace std;
	//char animal[20] = "bear";
	//const char* bird = "wren";
	//char* ps=nullptr;
	//cout << animal << endl;//bear
	//cout << bird << endl;//wren
	//cout << "Enter a kind of aimal:";
	//cin >> animal;
	//ps = animal;
	//cout << ps << "!\n";
	//cout << "before using strcpy():\n";
	//cout << animal << "at" << (int*)animal << endl;
	//cout << ps << "at" << (int*)ps << endl;
	//ps = new char[strlen(animal) + 1];
	//strcpy(ps, animal);
	//cout << "After using strcpy():\n";
	//cout << animal << "at" << (int*)animal << endl;
	//cout << ps << "at" << (int*)ps << endl;
	//delete[] ps;
//	struct inflatable {
//		char name[20];
//		float volume;
//		double price;
//	};
//	inflatable* ps = new inflatable;
//	(*ps) = {"Tom",3.3f,8.8};
//	cout<<ps->name<<"	"<< ps->price<<"  "<<ps->volume << endl;
//	cout << (*ps).name << "	" << (*ps).price << "  " << (*ps).volume << endl;
//	cin.get(ps->name, 20).get();
//	cin >> ps->price;
//	cin >> ps->volume;
//	cout << (*ps).name << "	" << (*ps).price << "  " << (*ps).volume << endl;
//	delete ps;
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<array>
//int main() {
//	using namespace std;
	//double a1[4] = {1.2,2.4,3.6,4.8};
	//vector<double> a2(4); 
	//a2.at(0)=1.2;
	//a2.at(1) = 2.4;
	//a2.at(2) = 3.6;
	//a2.at(3) = 4.8;
	//vector<double> b2(4);
	//b2 = a2;
	//for (int i = 0; i < 4;i++) {
	//	cout << a2.at(i)<<"   "<<b2.at(i) << endl;
	//}
	//array<double, 4> a3 = { 1.2,2.4,3.6,4.8 };
	//array<double, 4> b3;
	//b3 = a3;
	//for (int i = 0; i < 4; i++) {
	//	cout << a3.at(i) << "   " << b3.at(i) << endl;
	//}
	//cout << a1[0] << "  " << &a1[0] << endl;
	//cout << a2[0] << "  " << &a2[0] <<"   "<<b2[0]<<"    "<<&b2[0] << endl;
	//cout << a3[0] << "  " << &a3[0] << "   " << b3[0] << "    " << &b3[0] << endl;
	//int x = 20,40,50,60,70,80;
	//int y = 30;
	//{
	//	cout << x << endl;
	//	int x = 80;
	//	cout << x << endl;
	//}
	//cout << x << endl;
	//cout << y << endl;
	//for (;;) {
	//	cout << "66" << endl;
	//}
	//double a1[4] = { 1.2,2.4,3.6,4.8 };
	//for (double i:a1) {
	//	cout<<i<<endl;
	//}
	//vector<double> a2 = { 1.2,2.4,3.6,4.8 };
	//for (double i : a1) {
	//	cout << i << endl;
	//}
	//int count = 0;
	//char bit;
	//while(cin.get(bit)) {
	//	cout << bit << endl;
	//	count++;
	//	cin >> bit;
	//}
	//int i = 0;
	//cin >> i;
	//switch (i) 
	//{
	//case 10:
	//	cout << i << endl;
	//	break;
	//case 20:
	//	cout << i << endl;
	//	break;
	//case 50:
	//	cout << i << endl;
	//	break;
	//default:
	//	cout << "其他数字" << endl;
	//	break;
	//}
//	int i = 0;
//	while (cin >> i) {
//		cout << i << endl;
//	}
//	cout << i << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int sum(int a,int b) {
//	return  a + b;
//}
//int diff(int a, int b) {
//	return  a - b;
//}
//void swap(int& a,int& b) {
//	cout<<666<<endl;
//	cout << "a=" << a << "地址" << &a << endl;
//	cout << "b=" << b << "地址" << &b << endl;
//	int tmp = a;
//	a = b;
//	b = a;
//}
//void swap1(const long& a, const long& b) {
//	cout << 666 << endl;
//	cout << "a=" << a << "地址" << &a << endl;
//	cout << "b=" << b << "地址" << &b << endl;
//	long tmp = a;
//}
//int main() {
//	//int (*)(int, int);  (*arr)
//	//int (*(arr[2]))(int, int) = {sum,diff};
//	//cout<< (*arr[0])(1, 2) <<endl;
//	//long a = 100;
//	//long b = 20;
//	//swap(a,b);
//	//cout << "a=" << a << "地址" <<&a<< endl;
//	//cout << "b=" << b << "地址" << &b << endl;
//
//	double aa = 100.1;
//	double bb = 20.1;
//	swap1(aa, bb);
//	//cout << "aa=" << aa << "地址" <<&aa<< endl;
//	//cout << "bb=" << bb << "地址" << &bb << endl;
//	return 0;
//}

//
//#include<iostream>
//#include<string>
//using namespace std;
//struct testt {
//	int a;
//	double b;
//};
//void test(int& a,int& b) {
//	cout <<"a=" << a<<"		&a=" <<&a<< endl;
//	cout << "b=" << b << "		&b=" << &b << endl;
//}
//const string& testString(string& a) {
//	return a;
//}
//void test01(int a) {
//	cout << "a=" << a << endl;
//}
//void test01(const int a) {
//	cout << "a=" << a << endl;
//}
//void test01(int a,int b) {
//	cout << "a=" << a << "b" << b << endl;
//}
//struct size {
//
//};
//class A {
//private:
//	int value;
//public:
//	A(int n) { this->value = n; };
//	A(A& n) { this->value = n.value; };
//	void Print() {
//		cout << value << endl;
//	}
//};
//template<typename T>
//void swap1(T& a,T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//int main() {
//	int a = 10;
//	int b = 20;
//	swap1(a, b);
	//A a = 10;
	//testt t1 = {10,20.1};
	//testt t2 = t1;
	//cout << &t1 << "  " << &t2 << endl;
	//cout <<t2.a<<"  "<<t2.b << endl;
	//test t2;
	//long  aa = 10;
	//long  bb = 20;
	//test(aa, bb);
	//cout << "aa=" << aa << "		&aa=" << &aa << endl;
	//cout << "bb=" << bb << "		&bb=" << &bb << endl;
	//string a = "abc";
	//string b=testString(a);
	//b[1]='0';
	//cout << a << endl;
	//test(b=10,a=1);
	//struct size s;
	//cout << sizeof(s) << endl;
//	return 0;
//}

//#include<iostream>
//using namespace std;
//struct job {
//	char name[40];
//	double salary;
//	int floor;
//};
//template<typename T>
//void swap1(T& a,T& b) {
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//template<> 
//void swap1<job>(job& a, job& b) {
//	double tmp_salary=a.salary;
//	int tmp_floor=a.floor;
//	a.salary = b.salary;
//	a.floor = b.floor;
//	b.salary = tmp_salary;
//	b.salary = tmp_floor;
//}
//namespace test_tmp {
//	int a=10;
//	double b = 40;
//}
//class Stock {
//private :
//	string company;
//	long shares;
//	void
//};
//int main() {
	//int a = 10;
	//int b = 20;
	//swap1(a,b);
	//cout << "a=" << a << endl;
	//cout << "b=" << b << endl;
	//

	//job b1 = {"张三",200.01,20};
	//job b2 = { "李四",450.01,30 };
	//swap1(b1,b2);
	//cout << b1.name << "    " << b1.salary << "     " << b1.floor << endl;
	//cout << b2.name << "    " << b2.salary << "     " << b2.floor << endl;
	//extern int c;
	//cout << c << endl;
	//cout<<test_tmp::a<<endl;
	//namespace test_pp=test_tmp;
	//cout << test_pp::a << endl;
	//extern static int  c10;
	//cout << c10 << endl;
//	return 0;
//}
//
//#include"stock.h"
//int main() {
//	Stock s;
//	//Stock s1{ "腾讯",999,20.22 };
//	//Stock s2( "腾讯",999,20.22 );
//	Stock s3= Stock( "腾讯",999,20.22 );
//	s = s3;
//	std::cout<<&s<<"   "<< &s3<< std::endl;
//	std::cout << s.company << std::endl;
//
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class A {
//public:
//	A(int a,string _str) :data(a),str(_str) {
//		
//	}
//	int getData() {
//		return data;
//	}
//	string getStr() {
//		return str;
//	}
//	void show() {
//
//		cout << "101010101" << endl;
//	}
//	//friend A operator+(A& tmp1, A& tmp2);
//	friend ostream& operator<<(ostream& os, A& tmp1);
//	//A operator+(A& tmp) {
//	//	A a;
//	//	a.data = this->data + tmp.data;
//	//	a.str = this->str + tmp.str;
//	//	return a;
//	//}
//	int data;
//private:
//	string str;
//};
//class B :public A {
//public:
//	B():A(10,"qwe") {
//	
//	}
//	void show() {
//
//		cout << "20202020202" << endl;
//	}
//};
////A operator+(A& tmp1, A& tmp2) {
////	A a;
////	a.data = tmp1.data + tmp2.data;
////	a.str = tmp1.str + tmp2.str;
////	return a;
////}
//ostream& operator<<(ostream& os, A& tmp1) {
//	os << tmp1.data << " str=" << tmp1.str << endl;
//	return os;
//}
//int main() {
//	B b;
//	cout << b.data << endl;
//	cout << b.getStr() << endl;
//	b.A::show();
//	return 0;
//}
//
//#include<iostream>
//#include<string>
//using namespace std;
//class base;
//class A {
//public:
//	void test(base& bb);
//};
//class base {
//private:
//	int a;
//public:
//	string str;
//	friend void A::test(base& bb);
//	base(const int& _a, const string& _str) :a(_a), str(_str) {
//		cout << "有参构造函数" << endl;
//	}
//	virtual void show() {
//		cout << "base show()" << endl;
//	}
//	virtual void test() = 0;
//	virtual ~base() {
//		cout << "析构函数" << endl;
//	}
//};
//
//void A::test(base& bb) {
//	cout << bb.a << endl;
//}
//
//
//
//class basePluse :public base {
//public:
//	basePluse():base(10,"abc") {
//		cout << "无参构造函数" << endl;
//	}
//	void show() {
//		cout << "basePluse show()" << endl;
//	}
//	void print() {
//		cout << "basePluse print()" << endl;
//	}
//	void test() {
//		int a = 100;
//		cout << a << endl;
//	}
//	~basePluse() {
//		cout << "析构函数" << endl;
//	}
//};
//
//int main() {
//	//base b(20,"abcd");
//	//basePluse* ps = (basePluse*)&b;
//	//ps->print();
//	//ps->test();
//	//base bb(10,"abc");
//	//A aa;
//	//aa.test(bb);
//	base* ps=new basePluse;
//	ps->test();
//	return 0;
//}

//#include<iostream>
//using namespace std;
//template<typename T>
//class A {
//public :
//	T a;
//	class B {
//	public:
//		string str;
//		void fun() {
//			A aa;
//			cout << aa.a << endl;
//			aa.test.fun();
//		}
//	};
//	B test;
//};
//int main() {
//	//A<int> a;
//	//a.a = 100;
//	//a.test.str = "12345";
//	//cout << a.test.str << endl;
//	//a.test.fun();
//	const int a = 100;
//	int* ps = const_cast<int*>(&a);
//	*ps = 200;
//	cout<<a<<endl;
//	cout << *ps << endl;
//	return 0;
//}

#include<iostream>
#include<map>
#include<vector>
#include<climits>
using namespace std;
/*             ' '     '+'|'-'     数字         other   
start         start      signal    in_number    end
signal        end        end       in_number    end
in_number     end        end       in_number    end
end           end        end       end          end


*/
class Automaton {
public:
	int sig = 1;
	long ans = 0;
	string status = "start";
	map<string,vector<string>> table = {
									 {"start",{"start","signal","in_number","end"}},
									  {"signal",{"end","end","in_number","end"}},
									  {"in_number",{"end","end","in_number","end"}},
									  {"end",{"end","end","end","end"}}
	                               };
	int get_c(char c) {
		if (c==' ') {
			return 0;
		}
		else if (c=='+'||c=='-') {
			if (status =="start") {
				sig = -1;
			}
			return 1;
		}
		else if (c>='0'&&c<='9') {
			return 2;
		}else{
			return 3;
		}
	}
	void get(char c) {
		status = table[status][get_c(c)];
		if (status=="in_number") {
			ans = ans * 10 + c - '0';
			if (sig == 1) {
				ans = ans > INT_MAX ? INT_MAX : ans;
			}
			else {
				ans = ans > 2147483648 ? 2147483648 : ans;
			}
		}
	}
};
class Solution {
public :
	int myAtoi1(string s) {
		Automaton automa;
		for (char ss:s) {
			automa.get(ss);
		}
		return automa.sig * automa.ans;
	}
	/*
	'.' 匹配任意单个字符
	'*' 匹配零个或多个前面的那一个元素
	    字符串 s 和一个字符规律 p
	*/
	bool isMatch(string s, string p) {
		int len_s = s.length()-1;
		int len_p = p.length()-1;
		int i_s = 0;
		int i_p = 0;
		while (i_s<=len_s&& i_p <= len_p) {
			if (p[i_p]=='.') {
				if (p[i_p+1]=='*'&&i_p+1==len_s) {
					break;
				}
				else {
				
				}
			}
			if (s[i_s]==p[i_p]) {
				i_s++;
				i_p++;
			}
		}
		return true;
	}
};
int main() {
	Solution s;
	cout<<s.myAtoi1("words and 987") << endl;
	return 0;
}
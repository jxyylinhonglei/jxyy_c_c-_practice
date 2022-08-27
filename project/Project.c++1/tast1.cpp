//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	/*cout <<  sizeof(int)<<endl;
//	cout << "aaaa\tnnnnnn" << endl;
//	cout << "aa\thello world" << endl;*/
///*	char arr[] = "hello world";
//	cout << arr << endl;
//	string arr1 = "hello world";
//	cout << arr1 << endl*/
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
	//cout << sizeof(bool) << endl;
	//bool flag = true;
	//bool flag1 = false;
	//cout << flag << endl;
	////cout <<"flag="<<flag1<< endl;
	//int a = 0;
	//float b = 0;
	////cin >> a;
	////cout << a << endl;
	///*cout << "vnboinbihdsnv" << a << endl;*/
	//cin >> b;
	//cout << b << endl;
	/*char b = 0;
	cin >> b;
	cout << b << endl;*/
	//string arr ;
	//cin >> arr;
	//cout << arr << endl;
	/*return 0;
}*/
//#include<iostream>
//using namespace std;
//int main()
//{
//	int A = 0;
//	int B = 0;
//	int C = 0;
//	int tmp = 0;
//	cout << "请输入A猪的体重" << endl;
//	cin >> A;
//	cout << "请输入B猪的体重" << endl;
//	cin >> B;
//	cout << "请输入C猪的体重" << endl;
//	cin >> C;
//	if (A > B)
//		 tmp = A;
//	else
//		 tmp = B;
//	if (tmp <C)
//		tmp = C;
//	cout << "体重最大的是" << tmp << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int score = 0;
//	cout << "你认为这部电影怎么样?请评分" << endl;
//	cin >> score;
//	switch (score)
//	{
//	case 10:
//		cout << "非常好" << endl;
//		break;
//	case 9:
//		cout << "好" << endl;
//		break;
//	case 8:
//		cout << "比较好" << endl;
//		break;
//	case 7:
//		cout << "一般" << endl;
//		break;
//	default:
//		cout << "不行" << endl;
//		break;
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//#include<ctime>
//int main()
//{
//	srand((unsigned int)time(NULL));
//	cout << "请输入数字猜大小";
//	int ch = rand() % 100;
//	int num = 0;
//	do
//	{
//		cin >> num;
//		if (num > ch)
//		{
//			cout << "猜大了";
//		}
//		else if (num < ch)
//		{
//			cout << "猜小了";
//		}
//		else
//		{
//			cout << "恭喜你！猜对了";
//			break;
//		}
//	} while (1);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a = 0;//个位
//	int b = 0;//十位
//	int c = 0;//百位
//	int num = 999;
//	do
//	{
//		a=num % 10;
//		b = num / 10 % 10;
//		c = num / 100;
//		if (a* a* a + b * b * b + c * c * c == num && num > 100)
//			cout << num<<endl;
//		num--;
//	} while (num);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		for (int j = 0; j < 20; j++)
//		{
//			cout <<'*';
//		}
//		cout << '\n';
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int main()
//{
//	goto flag;
//	cout << "hahaha1" << endl;
//	cout << "hahaha2" << endl;
//	cout << "hahaha3" << endl;
//	cout << "hahaha4" << endl;
//	flag:
//	cout << "hahaha5" << endl;
//	cout << "hahaha6" << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//void add(int a,int b=10)
//{
//	cout << "1"<< a + b << endl;
//}
//void add(int a, int b )
//{
//	cout << 2<< a + b << endl;
//}
//int main()
//{
//	int a = 0;
//	cin >> a;
//	add(a);
//	return 0;
//}
//#include<iostream>
//using namespace std;
////void func()
//{
//	cout << "1" << endl;
//}
//void func(int a)
//{
//	cout << "2" << endl;
//}
//void func(double a)
//{
//	cout << "3" << endl;
//}
//void func(int a,double b)
//{
//	cout << "4" << endl;
//}
//void func( double b,int a)
//{
//	cout << "4" << endl;
//}
//int main()
//{
//	//func();
//	//func(10);
//	//func(3.13);
//	//func(1,3.5);
//	//func(6.4,6);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int& func()
//{
//	static int b = 1999;
//	return b;
//}
//int main()
//{
//	/*int a = 9;
//	int& b = a;
//	cout << b << endl;*/
//	int a = 0;
//	//func(a);
//	int& ret = func();
//	func() = 1888;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class circle
//{
//public:
//	double r;
//	double calculate()
//	{
//		return 3.14 * 2 * r;
//	}
//};
//int main()
//{
//	circle a;
//	a.r = 8.3;
//	cout << a.calculate() << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class circle
//{
//public:
//	int r;
//	double calculate()
//	{
//		return 2 * 3.14 * r;
//    }
//};
//int main()
//{
//	circle s;
//	s.r = 10;
//	cout << s.calculate() << endl;
//	return 0;
//}#
//#include<iostream>
//using namespace std;
//#include<string>
//class test
//{
//public:
//	void set_name(string x)
//	{
//		name = x;
//	}
//	string get_name()
//	{
//		return name;
//	}
//	void set_age(int age1)
//	{
//		age = age1;
//	}
//	int get_age()
//	{
//		return age;
//	}
//private:
//	string name;
//	string love;
//	int age;
//};
//int main()
//{
//	test s;
//	s.set_name("haha");
//	cout << s.get_name() << endl;
//	s.set_age(33);
//	cout << s.get_age() << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class cube
//{
//public:
//	void set_cube_long(int _long)
//	{
//		cube_long = _long;
//	}
//	int get_cube_long()
//	{
//		return cube_long;
//	}
//	void set_cube_height(int _height)
//	{
//		cube_height = _height;
//	}
//	int get_cube_height()
//	{
//		return cube_height;
//	}
//	void set_cube_weight(int _weight)
//	{
//		cube_weight = _weight;
//	}
//	int get_cube_weight()
//	{
//		return cube_weight;
//	}
//	int calculute_v()
//	{
//		return cube_long * cube_height * cube_weight;
//	}
//	bool is_equality1(cube& s2)
//	{
//		if (get_cube_weight() == s2.get_cube_weight() &&get_cube_long() == s2.get_cube_long() &&get_cube_height() == s2.get_cube_height())
//					return true;
//				else
//					return false;
//	}
//private:
//	int cube_long;
//	int cube_height;
//	int cube_weight;
//};
//bool is_equality(cube &s1,cube & s2)
//{
//	if (s1.get_cube_weight() == s2.get_cube_weight() && s1.get_cube_long() == s2.get_cube_long() && s1.get_cube_height() == s2.get_cube_height())
//		return true;
//	else
//		return false;
//}
//int main()
//{
//	cube s1;
//	cube s2;
//	s1.set_cube_height(20);
//	s1.set_cube_long(20);
//	s1.set_cube_weight(20);
//	/*cout << "体积为 ：" << s1.calculute_v() << endl;*/
//	s2.set_cube_height(30);
//	s2.set_cube_long(20);
//	s2.set_cube_weight(25);
//	if (s1.is_equality1(s2) == true)
//		cout << "两个立方体相等" << endl;
//	else
//		cout << "两个立方体不相等" << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class Point
//{
//public:
//	void set_m_x(int x)
//	{
//		m_x = x;
//	}
//	int get_m_x()
//	{
//		return m_x;
//	}
//	void set_m_y(int y)
//	{
//		m_y = y;
//	}
//	int get_m_y()
//	{
//		return m_y;
//	}
//private:
//	int m_x;
//	int m_y;
//};
//class Circle
//{
//public:
//	void setm_r(int r)
//	{
//		m_r = r;
//	}
//	int getm_r()
//	{
//		return m_r;
//	}
//	void set_point_x(int point_x)
//	{
//		point.set_m_x(point_x);
//	}
//	int get_point_x()
//	{
//		return point.get_m_x();
//	}
//	void set_point_y(int point_y)
//	{
//		point.set_m_y(point_y);
//	}
//	int get_point_y()
//	{
//		return point.get_m_y();
//	}
//private:
//	int m_r;//半径
//	Point point;//圆心
//};
//void compare(Circle& circle)
//{
//	if (circle.getm_r() * circle.getm_r() ==circle.get_point_x() * circle.get_point_x()+ circle.get_point_y() * circle.get_point_y())
//		cout << "在圆上" << endl;
//	if (circle.getm_r() * circle.getm_r() <circle.get_point_x() * circle.get_point_x()+ circle.get_point_y() * circle.get_point_y())
//		cout << "在圆外" << endl;
//	else
//		cout << "在圈内" << endl;
//}
//int main()
//{
//	Circle circle;
//	circle.setm_r(10);
//	circle.set_point_x(6);
//	circle.set_point_y(10);
//	compare(circle);
//	return 0;
//}
//#include<iostream>
//using  namespace std;
//class Person
//{
//public:
//	//Person()//构造函数
//	//{
//	//	cout << "默认构造函数" << endl;
//	//}
//	Person(int a)//构造函数/       提供了有参构造函数编译器就不会提供默认构造函数了
//	{
//		cout << "有参构造函数" << endl;
//		_a = a;
//	}
//	Person(const Person& p)
//	{
//		_a = p._a;
//		cout << "拷贝构造函数" << endl;
//	}
//	~Person()//析构函数
//	{
//		cout << "默认析构函数" << endl;
//	}
//	void show()
//	{
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//Person test1()
//{
//	Person s(10);
//	return s;
//}
//void test()
//{
//	////Person s = 10;
//	////Person s1(s);
//
//	////Person(10);
//	//Person s3;
//	//Person s(12);
//	///*s.show();*/
//	//Person s3(s);
//	//s3.show();
//	Person a = test1();
//	a.show();
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(int age,int point)
//	{
//		m_age = age;
//		m_point = new int(point);
//		cout << "moren构造函数调用" << endl;
//	}
//	Person(const Person& p )
//	{
//		m_age = p.m_age;
//		m_point = new int(*p.m_point);
//		cout << "构造函数调用" << endl;
//	}
//	int m_age;
//	int* m_point;
//	~Person()
//	{
//		if(m_point!=NULL)
//		delete m_point;
//		m_point = NULL;
//		cout << "析构函数调用" << endl;
//	}
//};
//void test()
//{
//	int bbb = 20;
//	Person aaa(10,bbb);
//	cout << aaa.m_age <<*aaa.m_point<<endl;
//	Person c(aaa);
//	cout << c.m_age << *c.m_point << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(int y) :hight(y) 
//	{
//		cout << "morengouzaohanshu" << endl;
//
//	}
//	int show()
//	{
//		return hight;
//	}
//	~Person()
//	{
//		cout << "xigouhanshudiaoyong" << endl;
//	}
//private:
//	int hight;
//};
//void test()
//{
//	Person a;
//	//cout << a.show() << endl;
//	cout << sizeof(a) << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person(int _a,int _b,int _c):a(_a),b(_b),c(_c)
//	{
//		cout << "默认构造函数" << endl;
//	}
//	int a;
//	int b;
//	int c;
//	~Person()
//	{
////
////
////	Person p(22,444,66);
////	cout << p.a << p.b << p.c << endl;
////}
////int main()
////{
////	test();
////	return 0;
////}	}
////};
////void test()
////{
//#include<iostream>
//using namespace std;
//#include<string>
//class phone
//{
//public:
//	phone(string a):m_phone(a)
//	{
//	/*	m_phone = a;*/
//		cout << "phone构造函数调用" << endl;
//	}
//	string m_phone;
//	~phone()
//	{
//		cout << "phone析构函数调用" << endl;
//	}
//};
//class Person
//{
//public:
//	Person(string Mane,string Name):name(Mane),_name(Name)
//	{
//		cout << "Person构造函数调用" << endl;
//	}
//	string name;
//	phone _name;
//	~Person()
//	{
//		cout << "Person析构函数调用" << endl;
//	}
//};
//void test()
//{
//	Person a("张三","小米");
//	cout << a.name << " " << a._name.m_phone << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class aaa
//{
//public:
//	void func()
//	{
//		if (this == NULL)
//			return;
//		cout << "jj" << endl;
//	}
//	int t;
//};
//void test()
//{
//	aaa *b=NULL;
//	b->func();
//	
//}
//int main()
//{
//	test();
//	return 0;
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	void set_ma(int m_a)
//	{
//		this->m_a = m_a;
//	}
//	void show()
//	{
//		cout << m_a << endl;
//	}
//	int m_a;
//};
//void test()
//{
//	person cold;
//	/*int a = 0;
//	cin >> a;*/
//	cold.set_ma(5);
//	cold.show();
//}
//int mian()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
// public:
//		/*void set_ma(int m_a)
//		{
//			this->m_a = m_a;
//		}*/
//	 person(int m_a)
//	 {
//		 this ->m_a=m_a;
//		 cout << "析构函数调用" << endl;
//
//	 }
//		void show()
//		{
//			cout << m_a << endl;
//		}
//	    person& Personadd(person &p1)
//		{
//			this->m_a += p1.m_a;
//			return *this;
//		}
//		int m_a;
//};
//void test()
//{
//	person a(10);
//	person b(a);
//	/////*int b;
//	////cin >> b;
//	////a.set_ma(b);*/
//	//a.show();
//	//b.show();
//	b.Personadd(a).Personadd(a);
//	b.show();
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	void show()
//	{
//		cout << "hahaha" << endl;
//	}
//};
//void test()
//{
//	person* a = NULL;
//	a->show();
//
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	void setm_a(int a) const
//	{
//		  m_a = a;
//	}
//	void setm_b(int b)
//	{
//		m_b = b;
//	}
//	void showm_a()
//	{
//		cout<<m_a<<endl;
//	}
//	void showm_b()
//	{
//		cout << m_b << endl;
//	}
//	mutable	int m_a;
//	mutable int m_b;
//};
//void test()
//{
//	const	person b;
//	b.setm_a(10);
//	b.m_a = 10;
//	b.m_b = 22;
//
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//#include<string>
//class buil
//{
//	friend void test(buil* aaa);
//public:
//	buil()
//	{
//		m_bedroom = "卧室";
//		m_Sittingroom = "客厅";
//	}
//public:
//	string m_Sittingroom;
//private:
//	string m_bedroom;
//};
//void test(buil *aaa)
//{
	//buil aaa;
	//cout << aaa.m_Sittingroom << endl;
	//cout << aaa.m_bedroom << endl;
	//cout << aaa->m_Sittingroom << endl;
//	cout << aaa->m_bedroom << endl;
//}
//int main()
//{
//	buil aaa;
//
//	test(&aaa);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//#include<string>
//class build
//{
//	friend class Goodgay;
//public:
//	build();
//public:
//	string m_Sttingroom;
//private:
//	string m_bedroom;
//};
//class Goodgay
//{
//public:
//	Goodgay();
//public:
//	void test();
//	build* aaa;
//};
//Goodgay::Goodgay()
//{
//	aaa = new build;
//}
//build::build()
//{
//	m_Sttingroom = "客厅";
//	m_bedroom = "卧室";
//}
//void Goodgay:: test()
//{
//	cout << aaa->m_Sttingroom << endl;
//	cout << aaa->m_bedroom << endl;
//}
//void host()
//{
//	Goodgay bbb;
//	bbb.test();
//}
//int main()
//{
//	host();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//#include<string>
//class build
//{
//	friend void Goodgay ::test();
//public:
//	build();
//public:
//	string m_Sttingroom;
//private:
//	string m_bedroom;
//};
//class Goodgay
//{
//public:
//	Goodgay();
//public:
//	void test();
//private:
//	build* aaa;
//};
//
//build::build()
//{
//	m_Sttingroom = "客厅";
//	m_bedroom = "卧室";
//}
//Goodgay::Goodgay()
//{
//	aaa = new build;
//}
//void Goodgay::test()
//{
//	cout << "正在访问" << aaa->m_Sttingroom << endl;
//	cout << "正在访问" << aaa->m_bedroom << endl;
//}
//void host()
//{
//	Goodgay bbb;
//	bbb.test();
//}
//int main()
//{
//	host();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	/*person operator+(person& p)//运算操作符两个类相加
//	{
//		person temp;
//		temp.m_a = this->m_a + p.m_a;
//		return temp;
//	}*/
//	int m_a;
//};
////person::person()
////{
////	cout << "hahahahha" << endl;
////}
//person operator+(person& q, person& w)//运算操作符两个类相加
//{
//	person temp;
//	temp.m_a = q.m_a + w.m_a;
//	return temp;
//}
//person operator+(person& q, int w)
//{
//	person temp;
//	temp.m_a = q.m_a + w;
//	return temp;
//}
//void test()
//{
//	person aaa;
//	aaa.m_a = 12;
//	person bbb;
//	bbb.m_a = 10;
//	/*int a = aaa.m_a + bbb.m_a;*/
//	person ccc =  aaa +  bbb;
//	cout <<ccc.m_a << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	int aaa;
//};
//ostream operator<<(ostream& cout, person& p)
//{
//	cout << p.aaa << endl;
//	return cout;
//}
//void test()
//{
//	person haha;
//	haha.aaa = -1111;
//	cout << haha ;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	int m_a;
//	int m_b;
//};
//ostream& operator<<(ostream& cout, person& bbb)
//{
//	cout << bbb.m_a <<bbb.m_b<< endl;
//	cout << bbb.m_b << endl;
//	return cout;
//}
//void test()
//{
//	person aaa;
//	aaa.m_a = 12;
//	aaa.m_b = 23;
//	cout << aaa << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	person()
//	{
//		m_a = 10;
//		m_b = 33;
//	}
//	/*person& operator + (person& aaa)
//	{
//		person bbb;
//		bbb.m_a = this->m_a + aaa.m_a;
//		bbb.m_b = this->m_b + aaa.m_b;
//		return bbb;
//	}*/
//	int m_a;
//	int m_b;
//};
//person operator+(person& aaa, person& bbb)
//{
//	person ccc;
//	ccc.m_a = aaa.m_a + bbb.m_a;
//	ccc.m_b = aaa.m_b + bbb.m_b;
//	return ccc;
//}
//void Printf(person heihei)
//{
//	cout << heihei.m_a << "   " << heihei.m_b << endl;
//}
//void test()
//{
//	person haha;
//	person hehe;
//	person heihei = haha + hehe;
//	Printf(heihei);
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	person(int a,int b)
//	{
//		m_a = a;
//		m_b = b;
//	}
//	person operator-(person& haha)
//	{
//		person heihei(0,0);
//		heihei.m_a = this->m_a - haha.m_a;
//		heihei.m_b = this->m_b - haha.m_b;
//		return heihei;
//	}
//	int m_a;
//	int m_b;
//};
//void test()
//{
//	person aaa(19, 99);
//	person bbb(554, 566);
//	person ccc = bbb - aaa;
//	cout << ccc.m_a << " " << ccc.m_b << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//	friend ostream& operator<<(ostream& cout, person bbb);
//public:
//	person()
//	{
//		m_a = 0;
//	}
//	person& operator++()
//	{
//		this->m_a++;
//		return *this;
//	}
//private:
//	int m_a;
//};
//ostream& operator<<(ostream& t,person bbb)
//{
//	cout << bbb.m_a << endl;
//	return t;
//}
//void test()
//{
//	person aaa;
//	cout << ++aaa << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{	
//	friend person& operator++(person& aaa);
//    friend void test();
//public:
//	person()
//	{
//		m_a = 0;
//	}
//private:
//	int m_a;
//};
//person& operator++(person& aaa)
//{
//	aaa.m_a++;
//	return aaa;
//}
//void test()
//{
//	person aaa;
//	/*++aaa;
//	++aaa;*/
//	aaa++;
//	cout << aaa.m_a << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//	friend void test();
//	/*friend ostream& operator<<(ostream& ooo, person bbb);*/
//public:
//	person()
//	{
//		m_a = 0;
//	}
//	void operator++()
//	{
//		this->m_a++;
//	/*	return *this;*/
//	}
//private:
//	int m_a;
//};
////ostream& operator<<(ostream& ooo, person bbb)
////{
////	cout <<bbb.m_a << endl;
////	return ooo;
////}
//void test()
//{
//	person aaa;
//	++aaa;
//	cout <<aaa.m_a<< endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//	friend void test();
//	friend ostream& operator<<(ostream& ooo, person bbb);
//public:
//	person()
//	{
//		m_a = 0;
//	}
//	person operator++()
//	{
//		person lll;
//		lll = *this;
//		this->m_a++;
//		return lll;
//	}
//private:
//	int m_a;
//};
//ostream& operator<<(ostream& ooo, person bbb)
//{
//	cout <<bbb.m_a << endl;
//	return ooo;
//}//aaa.operator()
//void test()
//{
//	person aaa;
//	
//	cout << aaa++ << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	person(int a)
//	{
//		m_a = new int(a);
//	}
//	person& operator=(person& aaa)//aaa.operator()=bbb
//	{
//		delete this->m_a;
//		this->m_a = NULL;
//		this->m_a = new int(*aaa.m_a);
//		return *this;
//	}
//	int* m_a;
//	~person()
//	{
//		if (m_a != NULL)
//		{
//			delete m_a;
//			m_a = NULL;
//		}
//	}
//};
//void test()
//{
//	person aaa(99);
//	person bbb(55);
//	person ccc(5);
//	ccc=bbb = aaa;//报错原因是因为调用类里面的函数返回值是void
//	cout << *aaa.m_a << endl;
//	cout << *ccc.m_a << endl;
//	cout << *bbb.m_a << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//#include<string>
//class person
//{
//public:
//	person(int age,string name)
//	{
//		m_age = age;
//		m_name = name;
//	}
//	int m_age;
//	string m_name;
//	bool operator==(person bbb)
//	{
//		if (this->m_age == bbb.m_age && this->m_name == bbb.m_name)
//			return true;
//		else
//			return false;
//	}
//};
//void test()
//{
//	person aaa(19, "张三");
//	person bbb(19, "张三");
//	if (aaa == bbb)
//	{
//		cout << "aaa与bbb相等" << endl;
//	}
//	else
//	{
//		cout << "aaa与bbb不相等" << endl;
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	void operator()(int a,int b)
//	{
//		cout <<a+b<< endl;
//	}
//};
//void test()
//{
//	person aaa;
//	//aaa("hahahahhaha");
//	aaa(121, 3232);
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	int m_a;
//	/*void operator()(int a, int b)
//	{
//		cout << a + b << endl;
//	}*/
//};
//ostream& operator<<(ostream& ooo, person aa)
//{
//	cout << aa.m_a << endl;
//	return ooo;
//}
//void test()
//{
//	person p1;
//	p1.m_a = 121;
//	//p1(1215, 6464);//p1.operator()
//	cout << p1 << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//继承
//#include<iostream>
//using namespace std;
//class java
//{
//public:
//	void header()
//	{
//		cout << "首页  公开课  登录  注册......(公共头部)" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心  交流中心 站内地图...(公共底部)" << endl;
//	}
//	void left()
//	{
//		cout << "java python c++...（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "java学科视频" << endl;
//	}
//};
//class python
//{
//public:
//	void header()
//	{
//		cout << "首页  公开课  登录  注册......(公共头部)" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心  交流中心 站内地图...(公共底部)" << endl;
//	}
//	void left()
//	{
//		cout << "java python c++...（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "python学科视频" << endl;
//	}
//};
//class cpp
//{
//public:
//	void header()
//	{
//		cout << "首页  公开课  登录  注册......(公共头部)" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心  交流中心 站内地图...(公共底部)" << endl;
//	}
//	void left()
//	{
//		cout << "java python c++...（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "cpp学科视频" << endl;
//	}
//};
//class base
//{
//		public:
//			void header()
//			{
//				cout << "首页  公开课  登录  注册......(公共头部)" << endl;
//			}
//			void footer()
//			{
//				cout << "帮助中心  交流中心 站内地图...(公共底部)" << endl;
//			}
//			void left()
//			{
//				cout << "java python c++...（公共分类列表）" << endl;
//			}
//};
//class java :public base
//{
//public:
//	void content()
//	{
//		cout << "java学科视频下载" << endl;
//	}
//};
//class python :public base
//{
//public:
//	void content()
//	{
//		cout << "python学科视频下载" << endl;
//    }
//};
//class cpp :public base
//{
//public:
//	void content()
//	{
//		cout << "cpp学科视频下载" << endl;
//	}
//};
//void test()
//{
//	java p1;
//	cout << "java下载视频如下" << endl;
//	p1.header();
//	p1.footer();
//	p1.left();
//	p1.content();
//	cout << "----------------------------------------" << endl;
//	python py;
//	cout << "python下载视频如下" << endl;
//	py.header();
//	py.footer();
//	py.left();
//	py.content();
//	cout << "----------------------------------------" << endl;
//	cpp c;
//	cout << "cpp下载视频如下" << endl;
//	c.header();
//	c.footer();
//	c.left();
//	c.content();
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<stdio.h>
//using namespace std;
//class base
//{
//public:
//	int m_a;
//protected:
//	int m_c;
//private:
//	int m_b;
//
//};
//class son1 :public base//公共部分继承父类，父类公共部分为子类的公共部分
//{                      //父类的隐私部分为子类的隐私部分
//	                  //父类的保护部分，子类不能访问
//public:
//	void contect()
//	{
//		m_a = 10;
//		//m_b = 20;
//		m_c = 30;
//	}
//};
//class son2 :private base//隐私部分继承父类
//	                    //父类的公共部分与隐私部分为子类的隐私部分
//{                         //父类的保护部分子类无法继承与访问
//	void content1()
//	{
//		m_a = 11;
//		//m_b = 12;
//		m_c = 13;
//	}
//};
//class son3 :protected base//父类的保护继承
//{                         //父类的公共部分与隐私部分是子类的保护部分
//public:                   //父类的保护部分子类无法访问
//	void contect3()
//	{
//		m_a = 11;
//		//m_b = 11;
//		m_c = 11;
//	}
//};
//void test()
//{
//	son1 aaa;
//	aaa.m_a = 100;
//	//aaa.m_c = 222;
//	son2 bbb;
//	son3 ccc;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	person(int a)
//	{
//		m_a = a;
//	}
//	int m_a;
//};
//ostream& operator<<(ostream& cout,person aaa)
//{
//	cout << aaa.m_a << endl;
//	return cout;
//}
//void test()
//{
//	person aaa(50);
//	cout << aaa << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//继承中的对象模型
//#include<iostream>
//using namespace std;
//class person
//{
//public:
//	int m_a;
//private:
//	int m_b;
//protected:
//	int m_c;
//};
//class son :public person
//{
//public:
//	int m_d;
//	void content()
//	{
//		m_a = 0;
//		//m_b = 1;
//		m_c = 2;
//	}
//};
//void test()
//{
//	son aaa;
//	cout << sizeof(aaa) << endl;//结果是16
//}                               //结论是父类的所有非静态成员属性都会被子类继承
//int main()                      //父类中私有成员树形是被编译器隐藏了
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class father
//{
//public:
//	father()
//	{
//		cout << "father构造函数调用" << endl;
//	}
//	~father()
//	{
//		cout << "father析构函数调用" << endl;
//	}
//};
//class son :public father
//{
//public:
//	son()
//	{
//		cout << "son构造函数调用" << endl;
//	}
//	~son()
//	{
//		cout << "son析构函数调用" << endl;
//	}
//};
//void test()
//{
//	//father aaa;
//	son bbb;//子类继承父类
//	//父类的构造函数比子类先构造，析构与之相反
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class father
//{
//public:
//	father()
//	{
//		m_a = 100;
//	}
//	int m_a;
//};
//class san :public father
//{
//public:
//	san()
//	{
//		m_a = 200;
//	}
//	int m_a;
//};
//void test()
//{
//	san aaa;
//	//cout << aaa.m_a << " " << aaa.father::m_a << endl;
//}
//int mian()
//{
//	//test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class mother
//{
//public:
//	mother()
//	{
//		m_a = 300;
//	}
//	int m_a;
//};
//class father
//	{
//	public:
//		father()
//		{
//			m_a = 100;
//		}
//		int m_a;
//		//static int n_a;//静态变量类内声明类外初始化
//		//static void fuction()
//		//{
//		//	cout << "haha1" << endl;
//		//}
//	};
////int father::n_a = 100;
////class mother
////{
////public:
////	mother()
////	{
////		m_a = 300;
////	}
////	int m_a;
////};
//class san :virtual public father,public mother
//{
//	public:
//		/*san()
//		{
//			m_a = 200;
//		}
//		int m_a;*/
//		/*cstatic int n_a;
//		static void fuction()
//		{
//			cout << "haha2" << endl;
//		}*/
//	
//};
////int san:: n_a = 200;
//void test()
//{//继承中子类与父类相同的成员，子类会把父类中的全部屏蔽掉
//	san aaa;
//	//cout << aaa.m_a << " " << aaa.father::m_a << endl;
//   //子类调用父类需用 子类名.父类:;父类内容
//	//cout << aaa.n_a << endl;
//	//cout << aaa.father::n_a << endl;
//	//cout << san::n_a << endl;
//	//cout << father::n_a << endl;
//	///*aaa.fuction();
//	//*/aaa.father::fuction();
//	/*san::fuction();
//	father::father::fuction();*/
//	cout << aaa.father:: m_a << endl;
//	cout << aaa.mother::m_a << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//菱形继承

//class animal
//{
//public:
//	int m_a;
//};
//class sheep:virtual public animal
//{
//	
//};
//class tuo:virtual public animal
//{
//
//};
//class sheepyuo:public sheep,public tuo
//{
//
//};
//void test()
//{
//	sheepyuo aaa;
//	cout << aaa.sheep::animal::m_a << endl;
//}
//#include<iostream>
//using namespace std;
//class animal
//{
//public:
//	int m_a;
//};
//class sheep: virtual public animal
//{
//public:
//};
//class tuo:virtual public animal
//{
//public:
//};
//class sheepyuo:public sheep,public tuo
//{
//public:
//};
//void test()
//{
//	sheepyuo aaa;
//	aaa.sheep::animal::m_a = 10;
//	aaa.tuo::animal::m_a = 30;
//	cout << aaa.sheep::animal::m_a << endl;
//	cout << aaa.tuo::animal::m_a << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class animal
//{
//public:
//	cout << "动物在叫" << endl;
//};
//int mian()
//{
//	return 0;
//}
#include<iostream>
#include<string>
int main()
{
	std::string a = "abcde";
	std::cout << a[2] << std::endl;
	return 0;
}
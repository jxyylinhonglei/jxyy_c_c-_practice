//#include<iostream>
//using namespace std;
//namespace aa
//{
//	int a = 100;
//}
//namespace aa
//{
//	int c = 9;
//}
//namespace bb
//{
//	int a = 30;
//}
//namespace
//{
//	int q = 100;
//}
//int& func()
//{
//	static int a = 0;
//	a++;
//	return a;
//}
//#define maax(x,y) x>y?x:y;
//class circle
//{
//public:
//	double circlelength(int& len)
//	{
//		return 2 * len * 3.14;
//	}
//};
//class Student//属性:名字，学号
//{
//public:
//	void getage(int _age)
//	{
//		age = _age;
//	}
//	void getname(string _name)
//	{
//		name = _name;
//	}
//	int reage()
//	{
//		return age;
//	}
//	string rename()
//	{
//		return name;
//	}
//private:
//	int age;
//	string name;
//};
//void fun(const int& a)//不然修改
//{
//	cout << a;
//}
//inline int func1(int a)
//{
//	return a + 1;
//}
//void func2(int c,int a=10,int b=10)
//{
//	cout << a + b +c<< endl;
//}
//void test()
//{
	//using namespace aa;
	//namespace _a = aa;
	//int a = 10;
	//cout <<a << endl;
	//cout << _a::c << endl;
	//cout << ::q << endl;
	//int a = 0;
	//const int b = a;
	//int* tmp = (int*)&b;
	//*tmp = 100;
	//cout << b;
	//int a = 10;
	//int b = 20;
	//int a1 = a;
	//int a1 = b;
	//a > b ? a : b = 200;
	//cout << a<<" " << b << endl;
	//int arr[10];
	//int(&parr)[10]=arr;
	//for (int i = 0; i < 10; i++)
	//{
	//	parr[i] = i;
	//}
	//for (int i = 0; i < 10; i++)
	//{
	//	cout << arr[i];
	//}
	//cout << endl;
	//int& ret = func();
	//cout << ret << endl;
	//func()=100;
	//cout <<ret<<endl;
	//const int& a = 10;//相当于int tmp=10；const int &a=tmp；
	//int* t = (int*)&a;
	//*t = 20;
	//cout << a;
	//int b = 100;
	//fun(b);
	/*circle s;
	int a = 10;
	cout << s.circlelength(a) << endl;
	Student xiaoming;
	xiaoming.getage(10);
	xiaoming.getname("小明");
	cout << "名字" << xiaoming.rename() << " " << xiaoming.reage() << endl;*/
	//int a = 10;
	//int b = 20;
	//int ret = maax(a, b)+ maax(a, b);//x>y?x:y+x>y?x:y
	//cout <<func1(10) << endl;
//	func2(30,20);
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
////函数重载
//void func()
//{
//	cout << "wu" << endl;
//}
//void func(int a)
//{
//	cout << "a" << a << endl;
//}
//void func(string str,int a)
//{
//	cout << str << a << endl;
//}
//void func(int a,string str)
//{
//	cout << a << str;
//}
//void func1(int& a)
//{
//	cout <<"1" << a << endl;
//}
//void func1( const int &a)
//{
//	cout << a << endl;
//}
//int main()
//{
//	//func();//1
//	//func(10);//2
//	//func("fehg",4);//3
//	//func(5,"ferg");//4
//	func1(10);
//	return 0;
//}
//#include<iostream>
//#include"haha.h"
//using namespace std;
//struct Person
//{
//	int age;
//	char name[64];
//	void PersonEat()
//	{
//		cout << "renzaichi" <<name;
//	}
//};
//struct Dog
//{
//	int age;
//	char name[64];
//	void DogEat()
//	{
//		cout << "gouliang" ;
//	}
//};
//void test()
//{
//	struct Person zhangsan;
//	struct Dog wangwang;
//	strcpy_s(zhangsan.name,"zhangsan");
//	strcpy_s(wangwang.name, "wangwang");
//	zhangsan.PersonEat();
//}
//int main()
//{
//	//show();
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//#include<string>
//class Person
//{
//public:
//	void SetAge(int _age)
//	{
//		if (_age<=0||_age>150)
//		{
//			cout << "老妖精" << endl;
//		}
//		else
//		{
//			age = _age;
//		}
//	}
//	int GetAge()
//	{
//		return age;
//	}
//	void SetName(string _name)
//	{
//		name = _name;
//	}
//	string GetName()
//	{
//		return name;
//	}
//	void Setm_love(string _mlove)
//	{
//		m_love = _mlove;
//	}
//private:
//	int age;//可读
//	string name;//可读，
//	string m_love;//不可读，可写
//};
//class Cube
//{
//public:
//	void setchang(int c)
//	{
//		chang = c;
//	}
//	void setkunag(int k)
//	{
//		kuang = k;
//	}
//	void setgao(int g)
//	{
//		gao = g;
//	}
//	int Getchang()
//	{
//		return chang;
//	}
//	int Getkuang()
//	{
//		return kuang;
//	}
//	int Getgao()
//	{
//		return gao;
//	}
//	int area()
//	{
//		return 2 * (chang*gao+chang*kuang+kuang*gao);
//	}
//	int tiji_v()
//	{
//		return chang * kuang * gao;
//	}
//	bool compa(class Cube& a)
//	{
//		return Getchang() == a.Getchang() && Getkuang() == a.Getkuang() && Getgao() == a.Getgao();
//	}
//private:
//	int chang;
//	int kuang;
//	int gao;
//};
//bool compare1(class Cube& c1, class Cube& c2)
//{
//	return c1.Getchang() == c2.Getchang() && c1.Getkuang() == c2.Getkuang() && c1.Getgao() == c2.Getgao();
//}
//void test()
//{
//	Person zhangsan;
//	zhangsan.SetAge(2000);
//	zhangsan.SetName("zhangsan");
//	zhangsan.Setm_love("changjin");
//	cout <<zhangsan.GetName() << " " << zhangsan.GetAge() << endl;
//	Cube c1;
//	c1.setchang(10);
//	c1.setkunag(10);
//	c1.setgao(10);
//	Cube c2;
//	c2.setchang(10);
//	c2.setkunag(10);
//	c2.setgao(10);
//	cout << c1.compa(c2)<< endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//#include"circle.h"
//class Point
//{
//public:
//	void setm_x(int x)
//	{
//		m_x = x;
//	}
//	void setm_y(int y)
//	{
//		m_y = y;
//	}
//	int getm_x()
//	{
//		return m_x;
//	}
//	int getm_y()
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
//	void setPoint(Point& tt)
//	{
//		m_xy = tt;
//	}
//	int getm_r()
//	{
//		return m_r;
//	}
//	Point getPoint()
//	{
//		return m_xy;
//	}
//private:
//	int m_r;
//	Point m_xy;
//};
//void compare(Circle& c,Point & d)
//{
//	int distance = (c.getPoint().getm_x() - d.getm_x()) * (c.getPoint().getm_x() - d.getm_x()) + (c.getPoint().getm_y() - d.getm_y()) * (c.getPoint().getm_y() - d.getm_y());
//	if (distance == c.getm_r() * c.getm_r())
//	{
//		cout << "点在圆上" << endl;
//	}
//	else if (distance < c.getm_r() * c.getm_r())
//	{
//		cout << "点在圆内" << endl;
//	}
//	else
//	{
//		cout << "点在圆外" << endl;
//	}
//}
//class Person11
//{
//public:
//	Person11()
//	{
//		cout << "默认构造函数调用" << endl;
//	}
//	Person11(int _a)
//	{
//		cout << "值构造函数调用" << endl;
//		a = _a;
//	}
//	Person11(const Person11& t)
//	{
//		cout << "拷贝构造函数调用" << endl;
//		a = t.a;
//	}
//	int a;
//	~Person11()
//	{
//		cout << "析构函数" << endl;
//	}
//};
//void test()
//{
	//Point d1;
	//Circle c1;
	//d1.setm_x(0);
	//d1.setm_y(0);
	//c1.setm_r(10);
	//c1.setPoint(d1);
	//Point d2;
	//d2.setm_x(10);
	//d2.setm_y(0);
	//c1.compare00(d2);
	//Person11 ss;
	//Person11 s1(1);//括号法
	//Person11 s2(s1);
	//Person11 s11 = 10;
	//Person11 s12 = s11;
	//Person11 s11 = 10;
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
//	Person()
//	{
//		age = (int*)malloc(4);
//		*age = 100;
//	}
//	Person(const Person& p)
//	{
//		age = (int*)malloc(4);
//		*age = *p.age;
//		cout << "拷贝构造函数" << endl;
//	}
//	~Person()
//	{
//		if (age!=NULL)
//		{
//			free(age);
//			age = NULL;
//		}
//		cout << "析构函数" << endl;
//	}
//	int* age;
//};
//void test()
//{
//	Person p1;
//	Person p2(p1);
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
//	Person(int a,int b,int c):m_a(a),m_b(b),m_c(c)
//	{
//		cout << "有参构造函数" << endl;
//	}
//	void test()
//	{
//		cout << "m_a" << " " << m_a;
//		cout << "m_b" << " " << m_b;
//		cout << "m_c" << " " << m_c;
//	}
//	int m_a;
//	int m_b;
//	int m_c;
//};
//int main()
//{
//	Person r1(100,200,10);
//	r1.test();
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//class Game
//{
//public:
//	Game(string name):m_Game(name)
//	{
//		cout << "Game构造函数" << endl;
//	}
//	string _Game()
//	{
//		return m_Game;
//	}
//private:
//	string m_Game;
//};
//class Phone
//{
//public:
//	Phone(string name):m_ohnoe(name)
//	{
//		cout << "Phone构造函数" << endl;
//	}
//	string _Phone()
//	{
//		return m_ohnoe;
//	}
//private: 
//	string m_ohnoe;
//};
//class Person
//{
//public:
//	Person(string name,string mphone,string mgame):m_name(name),m_phone(mphone),m_game(mgame)
//	{
//		cout << "Person构造函数" << endl;
//	}
//	void test()
//	{
//		cout << m_name << "拿着" << m_phone._Phone() << "打着" << m_game._Game() << endl;
//	}
//private:
//	string m_name;
//	Phone m_phone;
//	Game m_game;
//};
//class String
//{
//public:
//	String()
//	{
//		cout << "默认构造函数" << endl;
//	}
//	explicit  String(int _len)
//	{
//		cout << "1";
//		len = _len;
//	}
//	explicit String(string slen)
//	{
//		cout << "2";
//		tt = slen;
//	}
//	~String()
//	{
//		cout << "析构函数" << endl;
//	}
//	int len;
//	string tt;
//};
//int main()
//{
//	String* tt = new String[2];
//	//Person zhangsan("张三","iphone","王者农药");
//	//zhangsan.test();
//	delete [2] tt;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class ChairMan//单列实例化对象,只允许创建一个类
//{
//public:
//	static ChairMan* test()
//	{
//		return tt;
//	}
//	void haha()
//	{
//		cout << "pp";
//	}
//private:
//	 ChairMan()
//	 {
//
//	 }
//	 ChairMan(const ChairMan& )
//	 {
//
//	 }
//	 static ChairMan* tt;
//};
//ChairMan* ChairMan::tt = new ChairMan;
//class Person
//{
//public:
//	static int stam_a()
//	{
//		return m_a;
//	}
//private:
//	static int m_a;//静态成员变量，类内声明，类外访问
//};
//int Person::m_a = 10;
//
//int main()
//{
//	//Person a;
//	//cout << a.stam_a() << endl;//通过对象访问
//	//cout << Person:: stam_a() << endl;//通过类名访问.
//	ChairMan* c1=ChairMan::test();
//	ChairMan* c2 = ChairMan::test();
//	if(c1==c2)
//	{
//		cout << "yy";
//	}
//	c1->haha();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	static Person* getper()
//	{
//		return obj;
//	}
//	void test()
//	{
//		cout << "hello" << endl;
//	}
//private:
//	Person()
//	{
//
//	}
//	Person(const Person&)
//	{
//
//	}
//	static Person* obj;
//};
//Person* Person::obj = new Person;
//int main()
//{
//	Person* ps = Person::getper();
//	ps->test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class Printer
//{
//public:
//	static Printer* getPrinter()
//	{
//		return ps;
//	}
//	//void test(string str)
//	//{
//	//	cout << str << endl;
//	//	m_count++;
//	//}
//	/*int m_count = 0;*/
//private:
//	Printer()
//	{
//		cout << "单列对象" << endl;
//	}
//	Printer(const Printer&)
//	{
//
//	}
//	static Printer* ps;
//};
//Printer* Printer::ps = new Printer;
//int main()
//{
//	Printer* tt = Printer::getPrinter();
//	//tt->test("1");
//	//tt->test("2");
//	//tt->test("3");
//	//cout << tt->m_count<< endl;
//	cout << sizeof(Printer) << endl;
//	return 0;
//}
#include<iostream>
using namespace std;
class Person
{
public:
	Person(int m_a)
	{
		this->m_a=m_a;
	}
	void showclass()
	{
		cout << "hello" << endl;
	}
	void test1()
	{
		if (this==NULL)
		{
			return;
		}
		cout << this->m_a << endl;
	}
	void test2() const
	{
	}
	const Person* sum() const//常函数
	{
		this->m_a += this->m_a;
		return this;
	}
	mutable int m_a;
};
void ttt()
{
	const Person zhangsan(10);//常对象
	const Person* ps=&zhangsan;
	ps->sum()->sum();//链式编程
	ps->test2();
	zhangsan.test2();
	Person* ps1 = NULL;
	ps1->showclass();
	ps1->test1();
}
int main()
{
	ttt();
	return 0;
//}
//#include<iostream>
//using namespace std;
//#include<string>
//class Room
//{
//	//friend void test(Room* r1);
//	friend class Goodgay;
//	//friend void Goodgay::vist();
//public:
//	Room()
//	{
//		sofa = "沙发";
//		bedroom = "卧室";
//	}
//	string sofa;
//private:
//	string bedroom;
//};
//class Goodgay
//{
//public:
//	Goodgay()
//	{
//		this->ps = new Room;
//	}
//	void vist()
//	{
//		cout << this->ps->bedroom << endl;
//	}
//	Room* ps;
//};
////void test(Room* r1)
////{
////	cout << r1->sofa << endl;
////	cout << r1->bedroom<< endl;
////}
//void test1()
//{
//	Goodgay good1;
//	//cout << good1.ps->bedroom << endl;
//	good1.vist();
//}
//int main()
//{
//	Room r1;
//	/*test(&r1);*/
//	test1();
//	return 0;
//}






//#include<iostream>
//using namespace std;
//#include<string>
//class Building
//{
//friend void Goodgay::vist();
//public:
//	Building()
//	{
//		sofa = "沙发";
//		bedroom = "卧室";
//	}
//	string sofa;
//private:
//	string bedroom;
//};
//class Goodgay
//{
//public:
//	Goodgay()
//	{
//		m_Building=new Building;
//	}
//	void vist()
//	{
//		cout << m_Building->bedroom << endl;
//	}
//	Building* m_Building;
//};
//
//void test()
//{
//	Goodgay gg;
//	gg.vist();
//}
//int main()
//{
//	test();
//	return 0;
//}

//#include"myArray.h"
//class person
//{
//friend ostream& operator<<(ostream& cout, person& a);
//friend person operator+(person& a, person& b);
//public:
//	person()
//	{
//		a = 0;
//		b = 0;
//	}
//	person(int _a,int _b):a(_a),b(_b)
//	{
//
//	}
//	person& operator+(person& e)
//	{
//		person tmp;
//		tmp.a = this->a + e.a;
//		tmp.b = this->b + e.b;
//		return tmp;
//	}
//private:
//	int a;
//	int b;
//};
//class myInter
//{
//	friend myInter& operator++(myInter& aaa);
//	friend ostream& operator<<(ostream& cout, myInter& in);
//public:
//	myInter()
//	{
//		num = 0;
//	}
//	myInter(int _a):num(_a)
//	{
//	}
//	//myInter& operator++()//前置加加
//	//{
//	//	this->num++;
//	//	return *this;
//	//}
//	bool operator==(myInter& pp)
//	{
//		return this->num == pp.num;
//	}
//	myInter& operator++(int)//前置加加
//	{
//		myInter t;
//		t = *this;
//		this->num++;
//		return t;
//	}
//	void operator()(int a,int b)
//	{
//		if (a > b)
//		{
//			cout << "最大的是" << a<<endl;
//		}
//		else
//		{
//			cout << "最大的是" << b << endl;
//		}
//	}
//	myInter& operator=(myInter& iii)
//	{
//		this->num=iii.num;
//		return *this;
//	}
//	void print()
//	{
//		cout << num << endl;
//	}
//private:
//	int num;
//};
//class smartPoint
//{
//public:
//	smartPoint(myInter* ps)
//	{
//		m_smartPoint=ps;
//	}
//	~smartPoint()
//	{
//		if (m_smartPoint)
//		{
//			cout << "shangchu";
//			delete m_smartPoint;
//		}
//	}
//	myInter* operator->()
//	{
//		return this->m_smartPoint;
//	}
//	myInter& operator*()
//	{
//		return *m_smartPoint;
//	}
//private:
//	myInter* m_smartPoint;
//};
//myInter& operator++(myInter& aaa)//前置加加
//{
//	++aaa.num;
//	return aaa;
//}
//ostream& operator<<(ostream& cout,myInter& in)
//{
//	cout << in.num;
//	return cout;
//}
//person operator+(person& a, person& b)
//{
//	person tmp;
//	tmp.a=a.a + b.a;
//	tmp.b = a.b + b.b;
//	return tmp;
//}
//ostream& operator<<(ostream& cout,person& a)
//{
//	cout << a.a << " " << a.b;
//	return  cout;
//}
//void test()
//{
//	//person zhangsan(11,2);
//	//person lisi(22,4);
//	///*person c = zhangsan + lisi;*/
//	//person c =operator+(zhangsan,lisi);
//	////cout << c.a << " " << c.b;
//	//cout << c<<endl;
//	/*myInter aaa;*/
//	/*++(++aaa);*/
//	//cout <<++aaa<< endl;
//	//cout <<aaa << endl;
//	//myInter aaa(11);
//	//myInter bbb(11);
//	//aaa=bbb = aaa;
//	//bbb.print();
//	//aaa.print();
//	//smartPoint pt(new myInter(10));
//	//++*pt;
//	//(*pt).print();
//	//pt->print();
//	//if (aaa == bbb)
//	//{
//	//	cout << "yiyang";
//	//}
//	myInter bbb;
//	bbb(10,20);
//}
//void testt()
//{
//	Array ar1;
//	for (int i = 0; i < 10; i++)
//	{
//		ar1.pushBack(i);//插入数据
//	}
//	/*cout << ar1.getSize() << endl;*/
//	ar1.setData(3, 100);
//	//for (int i=0;i<ar1.getSize();i++)
//	//{
//	//	cout << ar1.gerData(i) << endl;//打印数据
//	//}
//	cout << ar1[3];
//	ar1[3] = 11;
//	cout << ar1[3];
//}
//int main()
//{
//	//testt();
//	test();
//	return 0;
//}
//#include"mystring.h"
//void test()
//{
//	//mystring ss("aaaaa");
//	//cin >> ss;
//	//char* t = ss.m_print();
//	//cout << t << endl;
//	/*mystring ss("abcd");*/
//	//mystring s2;
//	//s2= ss;
//	//s2[2]='1';
//	//char* t = s2.m_print();
//	//cout << t << endl;
//	mystring ss("abcd");
//	mystring bb("efgh");
//	mystring tmp;
//	tmp = ss + bb;
//	char* t = tmp.m_print();
//	cout << t << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class Basecl
//{
//public:
//	void head()
//	{
//		cout << "head";
//	}
//	void news()
//	{
//		cout << "news";
//	}
//	void sport()
//	{
//		cout << "sport";
//	}
//};
//class news1 :public Basecl
//{
//
//};
//int main()
//{
//	news1 nn;
//	nn.head();
//	nn.news();
//	nn.sport();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class base
//{
//public:
//	base(int _a):a(_a)
//	{
//		cout << "base构造函数调用" << endl;
//	}
//	void func()
//	{
//		cout << "base" << endl;
//	}
//	void func(int qq)
//	{
//		cout << "base有参调用" << endl;
//	}
//	int a;
//protected:
//	int b;
//private:
//	int c;
//};
//class base_pub :public base
//{
//public:
//	base_pub():base(20)
//	{
//		cout << "base_pub构造函数调用" << endl;
//		a = 10;
//	}
//	void func()
//	{
//		cout << "base_pub调用";
//	 }
//	int a;
//};
//class base_pro :protected base
//{
//public:
//	base_pro()
//	{
//		cout << " base_pro构造函数调用" << endl;
//	}
//	void func()
//	{
//		a = 10;
//		b = 100;
//	}
//};
//class base_pri :private base
//{
//public:
//	base_pri()
//	{
//		cout << " base_pri构造函数调用" << endl;
//	}
//	void func()
//	{
//		a = 10;
//		b = 100;
//	}
//};
//void test()
//{
//	base_pub aa;
//	cout << aa.base::a << endl;
//	aa.base::func(111);
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class base
//{
//public:
//	//virtual void func()//虚函数
//	//{
//	//	cout << " base";
//	//}
//	 void func()//虚函数
//	{
//		cout << " base";
//	}
//};
//class son :public base
//{
//public:
//	void func()
//	{
//		cout << "son";
//	}
//	void haha()
//	{
//		cout << "sdf";
//	}
//};
////void test(base* ps)
////{
////	ps->func();
////}
//int main()
//{
//	base* s1=new son;
//	s1->func();
//	s1->
//	//test(&s1);
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class Drink
//{
//public:
//	virtual void Boil() = 0;//烧水
//	virtual void Brew() = 0;//倒入杯中
//	virtual void PutInCup() = 0;//放入配料
//	virtual void eat() = 0;//喝茶
//};
//class Tea:public Drink
//{
//public:
//	virtual void Boil()
//	{
//		cout << "导入农夫三拳" << endl;
//	}
//	virtual void Brew()
//	{
//		cout << "将烧好的农夫三拳倒入杯中" << endl;
//	}
//	virtual void PutInCup()
//	{
//		cout << "将铁观音倒入杯中" << endl;
//	}
//	virtual void eat()
//	{
//		cout << "喝一口真难喝" << endl;
//	}
//	void test()
//	{
//		Boil();
//		Brew();
//		PutInCup();
//		eat();
//	}
//};
//int main()
//{
//	Tea tieguanyin;
//	tieguanyin.test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class animal
//{
//public:
//	animal()
//	{
//		cout << "animal构造函数"<<endl;
//	}
//	virtual void speak() = 0;
//	virtual ~animal() = 0;
//};
//animal::~animal()
//{
//	cout << "animal析构函数" << endl;
//}
//class dog:public animal
//{
//public:
//	dog()
//	{
//		cout << "dog构造函数" << endl;
//	}
//	void speak()
//	{
//		cout << "haha";
//	}
//	~dog()
//	{
//		cout << "dog析构函数" << endl;
//	}
//};
//void test()
//{
//	animal* tt = new dog;
//	delete tt;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class CPU
//{
//public:
//	virtual void calculate() = 0;
//};
//class VideoCard
//{
//public:
//	virtual void display() = 0;
//};
//class Memory
//{
//public:
//	virtual void storage() = 0;
//};
//class IntelCpu :public CPU
//{
//public:
//	void calculate()
//	{
//		cout << "IntelCpu" << endl;
//	}
//};
//class IntelVideoCard :public VideoCard
//{
//public:
//	void display()
//	{
//		cout << "IntelVideoCard" << endl;
//	}
//};
//class IntelMemory :public Memory
//{
//public:
//	void storage()
//	{
//		cout << "Intelstorage" << endl;
//	}
//};
//class compute
//{
//public:
//	compute(CPU* _c, VideoCard* _v, Memory* _m)
//	{
//		c = _c;
//		v = _v;
//		m = _m;
//	}
//	CPU* c;
//	VideoCard* v;
//	Memory* m;
//	void Dowork()
//	{
//		c->calculate();
//		v->display();
//		m->storage();
//	}
//};
//template<typename T>
//void mySwap(T& a, T& b)
//{
//	T tmp = a;
//	a = b;
//	b = tmp;
//}
//void test()
//{
//	//compute co(new IntelCpu, new IntelVideoCard, new IntelMemory);
//	//co.Dowork();
//	int a = 10;
//	int b = 100;
//	mySwap<int>(a,b);
//	cout << a << " " << b;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
////template<typename A>
////void Swap(A& a1, A& a2)
////{
////	A tmp = a1;
////	a1 = a2;
////	a2 = tmp;
////}
////template<typename T>
////void Sort(T& arr,int len)
////{
////	for (int i=0;i<len;i++)
////	{
////		int max = i;
////		for (int j=i+1;j<len;j++)
////		{
////			if (arr[max] < arr[j])
////			{
////				max = j;
////			}
////		}
////		Swap(arr[max], arr[i]);
////	}
////}
////void test()
////{
////	//int arr[] = { 2,15,4,8,9 };
////	//Sort(arr,sizeof(arr)/sizeof(arr[0]));
////	char arr[] ="fdgfdbfbfd";
////	Sort(arr, strlen(arr));
////	for (int i = 0; i < strlen(arr); i++)
////	{
////		cout << arr[i] << endl;
////	}
////}
////void myPrint(int a, int b)
////{
////	cout << "myPrint(int a,int b)调用" << endl;
////}
////template<typename T>
////void myPrint(T a, T b)
////{
////	cout << "函数模板1调用" << endl;
////}
////template<class T>
////void myPrint(T a, T b,T c)
////{
////	cout << "函数模板2调用" << endl;
////}
////class Person
////{
////public:
////	Person(int _age, string _name) :age(_age), name(_name)
////	{
////	}
////	//bool operator==(Person& tmp)
////	//{
////	//	if (this->age == tmp.age && this->name == tmp.name)
////	//	{
////	//		return true;
////	//	}
////	//	return false;
////	//}
////	int age;
////	string name;
////};
////template<class T>
////bool compare(T& a1,T& a2)
////{
////	if (a1 == a2)
////	{
////		return true;
////	}
////	else
////	{
////		return false;
////	}
////}
////template<> bool compare(Person& a1, Person& a2)
////{
////	if (a1.age == a2.age && a1.name == a2.name)
////	{
////		return true;
////	}
////	return false;
////}
//class Person
//{
//public:
//	Person(string _name,int _age)
//	{
//		this->name = _name;
//		this->age = _age;
//	}
//	//bool operator==(Person& a)
//	//{
//	//	if (this->age == a.age && this->name == a.name)
//	//	{
//	//		return true;
//	//	}
//	//	return false;
//	//}
//	int age;
//	string name;
//};
//template<typename T>
//bool compare(T& a,T& b)
//{
//	if (a == b)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//template<> bool compare(Person& a, Person& b)
//{
//	if (a.age == b.age && a.name == b.name)
//	{
//		return true;
//	}
//	return false;
//}
//template<class T,class B=string>
//class Animal
//{
//public:
//	Animal(T _age,B _name)
//	{
//		age = _age;
//		name = _name;
//	}
//	void Print()
//	{
//		cout << age << " " << name;
//	}
//	T age;
//	B name;
//};
//void test()
//{
//	//char a = 'a';
//	//char b = 'f';
//	//myPrint<>(a, b);
//	//Person tom(19, "tom");
//	//Person lisi(19, "tom");
//	//if (compare(tom, lisi))
//	//{
//	//	cout << "a==b";
//	//}
//	//else
//	//{
//	//	cout << "a!=b";
//	//}
//	//Person a("Tom",11);
//	//Person b("Bob", 30);
//	//if (compare(a, b))
//	//{
//	//	cout << "a==b";
//	//}
//	//else
//	//{
//	//	cout << "a!b";
//	//}
//	Animal<int> dog(100,"hashiqi");
//	dog.Print();
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//template<class T1,class T2>
////class Person
////{
////public:
////	Person(T1 _age,T2 _name)
////	{
////		age = _age;
////		name = _name;
////	}
////	void print()
////	{
////		cout << "xingmina" << " " << name << "nianling" << " " << age;
////	}
////	T1 age;
////	T2 name;
////};
//////类模板做参数
////void test1(Person<int, string>& p)//方式一
////{
////	p.print();
////}
////template<class T1,class T2>
////void test2(Person<T1,T2>& p)
////{
////	p.print();
////}
////template<class T>
////void test3(T& p)
////{
////	p.print();
////}
////void test()
////{
////	Person<int,string> zha(100,"hifo");
////	test3(zha);
////}
//template<class T>
//class base
//{
//public:
//	T m_a;
//};
//class person 
//{
//public:
//	int aa;
//};
//void test()
//{
//
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
////template<class T>
////class base
////{
////public:
////	T m_a;
////};
////template<class A,class B>
////class son1 :public base<B>
////{
////public:
////	son1(A a,B b)
////	{
////		m_a = a;
////		m = b;
////	}
////	void ttt();
////	//{
////	//	cout << m << " " << m_a;
////	//}
////	int m;
////};
////template<class T1,class T2>
////void son1<T1,T2>::ttt()
////{
////	{
////	cout << m << " " << m_a;
////	}
////}
//template<class A,class B>
//class person;
//
//template<class A,class B>
//void print(person<A,B>& p)//类内实现
//{
//	cout << p.age << " " << p.name;
//}
//
////template<class A, class B>//类模板遇到友元函数
////class person;
////template<class A, class B>
////void print(person<A, B>& p);
//template<class A,class B>//类模板遇到友元函数
//class person
//{
//public:
//	friend void print<>(person<A, B>& p);
//	//friend void print(person<A,B>& p)//类内实现
//	//{
//	//	cout << p.age << " " << p.name;
//	//}
//	person(A a,B b)
//	{
//		age = a;
//		name = b;
//	}
//private:
//	A age;
//	B name;
//};
////template<class A,class B>
////void print(person<A,B>& p)//类内实现
////{
////	cout << p.age << " " << p.name;
////}
//void test()
//{
//	//son1 aa(11,11);
//	//aa.ttt();
//	//son1<int,int> a(11,99);
//	//a.ttt();
//	person<int,string> aa(100, "lisi");
//	print(aa);
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//template<class T1,class T2>
//class person;
//template<class T1, class T2>
//void print(person<T1,T2>& p)
//{
//	cout << p.age << " " << p.name << endl;
//}
//template<class T1,class T2>
//class person
//{
//public:
//	friend void print<>(person<T1, T2>& p);
//	//friend void print(person<T1,T2>& p)
//	//{
//	//	cout <<p.age << " " << p.name << endl;
//	//}
//	person(T1 _age,T2 _name)
//	{
//		age = _age;
//		name = _name;
//	}
//	T1 age;
//	T2 name;
//};
//void test()
//{
//	person<int, string> ttt(19,"Tom");
//	print(ttt);
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include"myarr.hpp"
//using namespace std;
//void test()
//{
//	arraya<int> aa(100);
//	for (int i = 0; i < 10; i++)
//	{
//		aa.pushback(i);
//	}
//	aa.print();
//	aa[2] = 100;
//	cout << aa[2];
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int mid(int a, int b)
//{
//	if (b == 0)
//	{
//		throw '1';
//	}
//}
//void test()
//{
//	//int a = 10;
//	//double d = static_cast<double>(a);
//	//base aa;
//	//son bb=static_cast<son>(aa);
//	//string aa = "aaaa";
//	//char* bb = const_cast<char*>(&aa);
//	try
//	{
//		mid(10, 0);
//	}
//	catch (int)
//	{
//		cout << "int异常";
//	}
//	catch (char)
//	{
//		throw;
//		cout << "char1异常";
//	}
//	catch (...)
//	{
//		cout << "其他异常";
//	}
//}
//int main()
//{
//	try
//	{
//		test();
//	}
//	catch (int)
//	{
//		cout << "int异常";
//	}
//	catch (char)
//	{
//		cout << "char异常";
//	}
//	catch (...)
//	{
//		cout << "其他异常";
//	}
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class test
//{
//public:
//	test(int a):m_a(a)
//	{
//		cout << "拷贝构造调用" << endl;
//	}
//	~test()
//	{
//		cout << "析构函数调用" << endl;
//	}
//	int m_a;
//};
//void yichang(int b)
//{
//	if (b == 0)
//	{
//		throw test(100);//匿名对象
//	}
//}
//int main()
//{
//	try
//	{
//		yichang(0);
//	} 
//	catch (test& e)
//	{
//		cout << e.m_a <<endl;
//	}
//	return 0;
//}
//#include<iostream>
//#include<stdexcept>
//using namespace std;
//class baseException
//{
//public:
//	virtual void printErroe() = 0;
//};
//class NULLException:public baseException
//{
//public:
//	void printErroe()
//	{
//		cout << "指针异常" << endl;
//	}
//};
//class outOfRange :public baseException
//{
//public:
//	void printErroe()
//	{
//		cout << "数组越界" << endl;
//	}
//};
//void doWork(int age)
//{
//	//throw NULLException();
//	/*throw outOfRange();*/
//	if (age < 0 || age>150)
//	{
//		throw out_of_range("越界了");
//	}
//	else
//	{
//		cout << "年龄为" << age << endl;
//	}
//}
//void test()
//{
//	//try
//	//{
//	//	doWork();
//	//}
//	//catch (baseException& e)
//	//{
//	//	e.printErroe();
//	//}
//	try
//	{
//		doWork(151);
//	}
//	catch (exception& e)
//	{
//		cout << e.what() << endl;
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<stdexcept>
//#include<string>
//using namespace std;
//class myout_if_range:public exception
//{
//public:
//	myout_if_range(const char* str)
//	{
//		sstr = str;
//	}
//	virtual char const* what() const
//	{
//		return sstr.c_str();
//	}
//private:
//	string sstr;
//};
//class person
//{
//public:
//	person(int age)
//	{
//		if (age<0||age>150)
//		{
//			throw myout_if_range("老妖精");
//		}
//		else
//		{
//			this->m_age = age;
//		}
//	}
//private:
//	int m_age;
//};
//void test()
//{
//	//try
//	//{
//	//	person aa(151);
//	//}
//	//catch (exception& e)
//	//{
//	//	cout<< e.what();
//	//}
//	char c=cin.get();
//	cout << c;
//	cin.putback(c);
//	cout << cin.get();
//	//cin.ignore(2);
//	//char buff[2] = { 0 };
//	//cin.get(buff,2);
//	//cout << buff << endl;
//	//if (cin.get() == '\n')
//	//{
//	//	cout << "还有换行符";
//	//}
//	//char buff[10] = { 0 };
//	//cin.get(buff,10);//最多读取是十字符放入buff中，多余的放入缓冲区
//	//cout << buff << endl;
//	//char c = cin.get();//输入一个字符
//	//cout << c << endl;
//	//c = cin.get();//输入一个字符
//	//cout << c << endl;
//	//c = cin.get();//输入一个字符
//	//cout << c << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//void test()
//{
//	//int num = 0;
//	//cin >> num;
//	//cout << num<<endl;
//	//cout << cin.fail();//输入异常，0为正常
//	while (true)
//	{
//		cout << "请输入0到9的数字" << endl;
//		int num=0;
//		cin >> num;
//		if (num >= 0 && num <= 9&&!cin.fail())
//		{
//			cout << "你输入的数字是" << num << endl;
//			break;
//		}
//		cin.clear();
//		cin.sync();
//		cin.ignore();
//		cout << num;
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<fstream>
//using namespace std;
//void testxie()
//{
//	ofstream ofs("./test.txt",ios::app);
//	if (!ofs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//	}
//	ofs << "张三";
//	ofs.close();
//}
//void testdu()
//{
//	ifstream ofs("D:/login.txt",ios::in);
//	if (!ofs.is_open())
//	{
//		cout << "打开失败" << endl;
//	}
//	char buff[1024] = { 0 };
//	ofs.getline(buff, 1024);
//		cout << buff<<endl;
//	ofs.close();
//}
//void test()
//{
//	ifstream ofs1("D:/login.txt", ios::in);
//	ofstream ofs2("./test.txt", ios::out);
//	if (!ofs1.is_open()|| !ofs2.is_open())
//	{
//		cout << "打开失败" << endl;
//	}
//	char buff[1024] = { 0 };
//	while (ofs1)
//	{
//		ofs1.getline(buff, 1024);
//		ofs2<<buff;
//		ofs2 << "\n";
//	}
//	ofs1.close();
//	ofs2.close();
//}
//int main()
//{
//	//testxie();
//	//testdu();
//	test();
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<string>
//#include<algorithm>
//using namespace std;
////void myprint(int a)
////{
////	cout << a << endl;
////}
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
//};
//void myprint(person* a)
//{
//	cout << "年龄为" << a->m_age<<"姓名为" << a->m_name << endl;
//}
//void test()
//{
////	vector<int> df;
////	df.push_back(1);
////	df.push_back(2);
////	df.push_back(3);
////	df.push_back(4);
////	vector<int>::iterator iter= df.begin();
////	while (iter!=df.end())
////	{
////		cout << *iter << endl;
////		iter++;
////	}
//	//vector<int> df;
//	//df.push_back(1);
//	//df.push_back(2);
//	//df.push_back(3);
//	//df.push_back(4);
//	//for_each(df.begin(),df.end(),myprint);
//	person a1(10,"zhangsan1");
//	person a2(20, "zhangsan2");
//	person a3(30, "zhangsan3");
//	person a4(40, "zhangsan4");
//	person a5(50, "zhangsan5");
//	person b1(10, "lisi1");
//	person b2(20, "lisi2");
//	person b3(30, "lisi3");
//	person b4(40, "lisi4");
//	person b5(50, "lisi5");
//	person c1(10, "wangwu1");
//	person c2(20, "wangwu2");
//	person c3(30, "wangwu3");
//	person c4(40, "wangwu4");
//	person c5(50, "wangwu5");
//	vector<person*> df1;
//	df1.push_back(&a1);
//	df1.push_back(&a2);
//	df1.push_back(&a3);
//	df1.push_back(&a4);
//	df1.push_back(&a5);
//	vector<person*> df2;
//	df2.push_back(&b1);
//	df2.push_back(&b2);
//	df2.push_back(&b3);
//	df2.push_back(&b4);
//	df2.push_back(&b5);
//	vector<person*> df3;
//	df3.push_back(&c1);
//	df3.push_back(&c2);
//	df3.push_back(&c3);
//	df3.push_back(&c4);
//	df3.push_back(&c5);
//	vector<vector<person*>>df = {df1,df2,df3};
//	/*for_each(df.begin(),df.end(),myprint);*/
//	//for (vector<person>::iterator i=df.begin();i!=df.end();i++)
//	//{
//	//	cout << "年龄为" <<(*i).m_age<< "姓名为" <<i->m_name<< endl;
//	//}
//	for (vector<vector<person*>>::iterator i=df.begin();i!=df.end();i++)
//	{
//		for_each((*i).begin(),(*i).end(),myprint);
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//int main()
//{
//	//string ret1 = "qwertuyi";
//	////cout << ret1.find('i');
//	////cout << ret1.replace(1,2,"aaaaa");
//	//string ret2 = "aa";
//	//cout << ret1 + ret2 << endl;
//	//cout << ret1.append(ret2) << endl;
//	//string str;
//	//str.assign(ret1);
//	//cout << str<<endl;
//	//try
//	//{
//	//	str.at(100);
//	//}
//	//catch (out_of_range& e)
//	//{
//	//	cout <<e.what()<< endl;
//	//}
//	//string aaa = "zhangtao@189.cn";
//	//cout <<aaa.substr(0, aaa.find("@"));
//	string aaa = "www.baidu.com.cn";
//	vector<string> v;
//	int begin = 0;
//	int end = 0;
//	while (aaa.find('.',end)!=-1)
//	{
//		end = aaa.find('.',begin);
//		v.push_back(aaa.substr(begin,end-begin));
//		begin = aaa.find('.',end)+1;
//	}
//	for (vector<string>::iterator i=v.begin();i!=v.end();i++)
//	{
//		cout << *i;
//	}
//	return 0;
//}
//#include<iostream>
//#include<string>
//using namespace std;
//void test()
//{
//	//string ret = "asdf";
//	//ret.insert(1,"111");
//	//ret.erase(1,3);
//	//const char* ss = "asddfg";
//	//ret = ss;
//	//const char* tmp1=ret.c_str();
//	//cout << tmp1;
//	//string ret = "abcdef";
//	// char& t=ret[1];
//	//t = 'q';
//	//ret = "a1aaa";
//	//t = '2';
//	//cout << t;
//	string ret = "acbDDds";
//	for (int i = 0; i < ret.size(); i++)
//	{
//		/*ret[i]=toupper(ret[i]);*/
//		ret[i] = tolower(ret[i]);
//	}
//	cout << ret;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//void test()
//{
//	//vector<int> ret;
//	//for (int i=0;i<10;i++)
//	//{
//	//	ret.push_back(i+100);
//	//}
//	//ret.insert(ret.begin()+2,0);
//	//for (int i = 0; i < ret.size(); i++)
//	//{
//	//	cout<<ret.at(i)<<" ";
//	//}
//	//vector<int> v1(ret.begin(),ret.end());
//	//ret[1] = 500;
//	//v1.swap(ret);
//	//for (int i = 0; i < v1.size(); i++)
//	//{
//	//cout<<v1.at(i)<<" ";
//	//}
//	//cout << endl;
//	//cout << ret.front() << " " << ret.back();
//	//ret.clear();
//	//cout << ret.size() << endl;
//	//vector<int> ret;
//	//int* a = NULL;
//	//int num = 0;
//	//for (int i=0;i<10000;i++)
//	//{
//	//	ret.push_back(i);
//	//	if (a != &ret[0])
//	//	{
//	//		a = &ret[0];
//	//		num++;
//	//	}
//	//}
//	//cout << num;
//	vector<int> ret;
//	for (int i = 0; i < 10000; i++)
//	{
//		ret.push_back(i);
//	}
//	cout << "容量为" << ret.capacity() << endl;
//	ret.resize(5);
//	vector<int>(ret).swap(ret);
//	for (int i = 0; i < ret.size(); i++)
//	{
//		cout << ret[i];
//	}
//	cout << "容量为" << ret.capacity() << endl;
//}
//int main()
//{
//	test();
//	return 0;
////}
//#include<iostream>
//#include<vector>
//#include<deque>
//#include<algorithm>
//using namespace std;
//class Player
//{
//public:
//	deque<int> sore;
//};
//void dafen(vector<Player>& ans)
//{
//	for (int i=0;i<ans.size();i++)
//	{
//		for(int j=0;j<10;j++)
//		{
//			int tmp = 0;
//			cin >> tmp;
//			ans[i].sore.push_back(tmp);
//		}
//	}
//}
//bool comparesort(int a,int b)
//{
//	if (a > b)
//	{
//		return true;
//	}
//	return false;
//}
//void test()
//{
//	Player a1;
//	Player a2;
//	Player a3;
//	Player a4;
//	Player a5;
//	vector<Player> ans = {a1,a2,a3,a4,a5};
//	dafen(ans);
//	//sort默认排序是从小到大
//	for (int i = 0; i < ans.size(); i++)
//	{
//		sort(ans[i].sore.begin(), ans[i].sore.end(), comparesort);
//		ans[i].sore.pop_front();
//		ans[i].sore.pop_back();
//	}
//	for (int i = 0; i < ans.size(); i++)
//	{
//
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<stack>
//#include<queue>
//using namespace std;
//void test()
//{
//	stack<int> mystack;
//	queue<int> myqueue;
//	for (int i = 0; i < 10; i++)
//	{
//		mystack.push(i);
//		myqueue.push(i+10);
//	}
//	cout << "mysyack.size=" << mystack.size() << " " << "myqueue.size*()" << myqueue.size() << endl;
//	cout << "mysyack.front=" << mystack.top() << " " << "myqueue.back()" << myqueue.back() << endl;
//		while (!myqueue.empty()||!mystack.empty())
//		{
//			cout<< " mystack.top()=" << mystack.top() <<" myqueue.back()=" << myqueue.back()<<endl;
//			mystack.pop();
//			myqueue.pop();
//		}
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<list>
//using namespace std;
//class person
//{
//public:
//	person(int age,string name)
//	{
//		this->age = age;
//		this->name = name;
//	}
//	bool operator==(const person& a)const
//	{
//		return (a.age == this->age && a.name == this->name);
//	}
//	int age;
//	string name;
//};
////void myprint(list<int>& tmp)
////{
////	for (list<int>::iterator it=tmp.begin();it!=tmp.end();it++)
////	{
////		cout << *it << endl;
////	}
////}
//void myprint(list<person>& tmp)
//{
//	for (list<person>::iterator it=tmp.begin();it!=tmp.end();it++)
//	{
//		cout << (*it).name << " " << (*it).age << endl;
//	}
//}
//bool compare(person& a,person& b)
//{
//	return a.age < b.age;
//}
//void test()
//{
//	//list<int> tmp;
//	//for (int i = 0; i < 10; i++)
//	//{
//	//	/*tmp.push_back(i);*/
//	//	tmp.push_front(i);
//	//}
//	//tmp.remove(5);
//	//tmp.sort(compare);
//	//myprint(tmp);
//	//tmp.reverse();
//	//myprint(tmp);
//	person a(20,"张三");
//	person b(30, "李四");
//	person c(24, "王五");
//	person d(40, "唐僧");
//	list<person> tmp;
//	tmp.push_back(a);
//	tmp.push_back(b);
//	tmp.push_back(c);
//	tmp.push_back(d);
//	tmp.sort(compare);
//	tmp.remove(d);
//	myprint(tmp);
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<set>
//using namespace std;
//void test()
//{
//	//set<int> tmp;
//	//tmp.insert(30);
//	//tmp.insert(10);
//	//tmp.insert(500);
//	//for (set<int>::iterator it=tmp.begin();it!=tmp.end();it++)
//	//{
//	//	cout << *it << endl;
//	//}
//	//set<int>::iterator ret = tmp.find(500);
//	//if (ret!=tmp.end())
//	//{
//	//	cout << *ret;
//	//}
//	//set<int>::iterator ret1 = tmp.upper_bound(30);
//	//set<int>::iterator ret2 = tmp.lower_bound(30);
//	//if (ret1!=tmp.end())
//	//{
//	//cout << *ret1<<endl;
//	//}
//	//if (ret1 != tmp.end())
//	//{
//	//	cout << *ret2 << endl;
//	//}
//	//pair<set<int>::iterator,set<int>::iterator>ret=tmp.equal_range(30);
//	//cout << *(ret.first) << endl;
//	//cout << *(ret.second) << endl;
//	//set<string> tmp;
//	//tmp.insert("ssdfg");
//	//tmp.insert("gdgg");
//	//tmp.insert("sdfgdg");
//	//for (set<string>::iterator it=tmp.begin();it!=tmp.end();it++)
//	//{
//	//	cout << *it << endl;
//	//}
//	//pair<string, int>tmp("张三", 20);
//	//cout << tmp.first << " " << tmp.second << endl;
//	pair<string, int> tmp = make_pair("张三",10);
//	cout << tmp.first << " " << tmp.second << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<map>
//using namespace std;
//class mycompare
//{
//public:
//	bool operator()(const int a,const int b)
//	{
//		return a < b;
//	}
//};
//void test()
//{
//	map<int, int> tmp;
//	tmp.insert(pair<int,int>(1,1));
//	tmp.insert(make_pair<int, int>(2, 2));
//	tmp[3] = 3;
//	for (map<int, int>::iterator it = tmp.begin(); it != tmp.end(); it++)
//	{
//		cout << it->first << " " << it->second << endl;
//	}
//	//map<int, int>::iterator ret = tmp.lower_bound(1);
//	//if (ret == tmp.end())
//	//{
//	//	cout << "没有找到" << endl;
//	//}
//	//else
//	//{
//	//	cout << ret->first << " " << ret->second << endl;
//	//}
//	//map<int, int>::iterator ret = tmp.upper_bound(1);
//	//if (ret == tmp.end())
//	//{
//	//	cout << "没有找到" << endl;
//	//}
//	//else
//	//{
//	//	cout << ret->first << " " << ret->second << endl;
//	//}
//	pair<map<int, int>::iterator, map<int, int>::iterator> ret = tmp.equal_range(1);
//	if (ret.first==tmp.end())
//	{
//		cout << "没有找到" << endl;
//	}
//	else
//	{
//		cout << ret.first->first << " " << ret.first->second << endl;
//	}
//	if (ret.second == tmp.end())
//	{
//		cout << "没有找到" << endl;
//	}
//	else
//	{
//		cout << ret.second->first << " " << ret.second->second << endl;
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//class myprint
//{
//public:
//	void operator()(int val)
//	{
//		cout << val <<endl;
//	}
//};
////void myprint(int val)
////{
////	cout << val << endl;
////}
//bool mypare(int val)
//{
//	return val > 3;
//}
//void test()
//{
//	vector<int> tmp;
//	tmp.push_back(1);
//	tmp.push_back(2);
//	tmp.push_back(3);
//	tmp.push_back(4);
//	tmp.push_back(5);
//	//for_each(tmp.begin(),tmp.end(),myprint());
//	//vector<int>::iterator ret=find_if(tmp.begin(),tmp.end(),mypare);
//	//cout << *ret;
//	for_each(tmp.begin(), tmp.end(), [](int val) {cout << val << endl; });
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<functional>
//#include<algorithm>
//using namespace std;
//void test()
//{
//	//negate<int> n;
//	//cout << n(10) << endl;
//	//plus<int> p;
//	//cout << p(10,20);
//	vector<int> tmp;
//	tmp.push_back(1);
//	tmp.push_back(2);
//	tmp.push_back(3);
//	tmp.push_back(4);
//	tmp.push_back(5);
//	sort(tmp.begin(),tmp.end(),greater<int>());
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<functional>
//using namespace std;
////class myprint:public binary_function<int,int,void>
////{
////public:
////	void operator()(int val,int star) const
////	{
////		cout << val+star << endl;
////	}
////};
////class myprint :public binary_function<int,int ,void>
////{
////public:
////	void operator()(int val,int start) const
////	{
////		cout << val+start << endl;
////	}
////};
////class mycompare:public binary_function<int,int,bool>
////{
////public:
////	bool operator()(int a，int start) const
////	{
////		return a > start;
////	}
////};
//void myprint(int val,int start)
//{
//	cout << val+start<<endl;
//}
//class person
//{
//public:
//	person(int age,string name)
//	{
//		this->age = age;
//		this->name = name;
//	}
//	void show()
//	{
//		cout << this->age << this->name<<endl;
//	}
//	int age;
//	string name;
//};
//void test()
//{
//	/*vector<int> tmp = {1,2,3,4,5,6,7,8,9};*/
//	//for_each(tmp.begin(), tmp.end(), [](int val) {cout << val << endl; });
//	//int start = 100;
//	//for_each(tmp.begin(),tmp.end(),bind2nd(myprint(), start));
//	//for_each(tmp.begin(),tmp.end(),bind2nd(myprint(),start));//适配器
//	//vector<int>::iterator ans=find_if(tmp.begin(),tmp.end(),bind2nd(greater<int>(),6));//取反适配器
//	//cout << *ans <<endl;
//	//for_each(tmp.begin(),tmp.end(),bind2nd(ptr_fun(myprint),10));//函数适配器
//	person a1(19,"张三");
//	person a2(20, "李四");
//	person a3(21, "王五");
//	person a4(22, "唐僧");
//	vector<person*> tmp;
//	tmp.push_back(&a1);
//	tmp.push_back(&a2);
//	tmp.push_back(&a3);
//	tmp.push_back(&a4);
//	/*for_each(tmp.begin(),tmp.end(),mem_fun_ref(&person::show));*/
//	for_each(tmp.begin(),tmp.end(),mem_fun(&person::show));
//}
//int main()
//{
//	test();
//	return 0;
//}
#include<iostream>
#include<vector>
//#include<algorithm>
//#include<functional>
//using namespace std;
//class myprint:public binary_function<int,int ,void>
//{
//public:
//	void operator()(int val,int start) const
//	{
//		cout << val << endl;
//	}
//};
//int mytranform(int val)
//{
//	return val;
//}
//void test()
//{
//	vector<int> tmp = {1,2,3,4,5,6,7,8,9};
//	for_each(tmp.begin(),tmp.end(),bind2nd(myprint(),20));
//	vector<int> v1;
//	v1.resize(tmp.size());
//	transform(tmp.begin(),tmp.end(),v1.begin(),mytranform);
//	for_each(v1.begin(), v1.end(), bind2nd(myprint(), 0));
//}
//int main()
//{
//	test();
//	return 0;
//}
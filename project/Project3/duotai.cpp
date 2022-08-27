//#include<iostream>
//using namespace std;
//class animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "动物在叫" << endl;
//	}
//};
//class cat:public animal
//{
//public:
//	void speak()
//	{
//		cout << "小猫在叫" << endl;
//	}
//};//静态多态函数在编译是才确定地址
//void tall(animal& aaa)//动态多态函数地址在运行时才确定动态多态满足条件1有继承关系子类重写父类中虚函数
//{
//	aaa.speak();
//}
//void test()
//{
//	cat aaa;
//	tall(aaa);
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
//	virtual void func() = 0;//纯虚函数，类中有一个纯虚函数就为抽象类
//};
//class son :public person
//{
//public:
//	virtual void func()
//	{
//		cout << "haha" << endl;
//	};
//};
//class daughter:public person
//{
//	virtual void func()
//	{
//		cout << "heihei" << endl;
//	}
//};
//void test()
//{
//	//person aaa;//抽象类无法实例化对象
//	//son aaa;//子类继承抽象类必须重写纯虚函数否则无法是咧化对象
//	/*person* ps = new son;
//	ps->func();*/
//	person* bbb = new daughter;
//	bbb->func();
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class Makedrink
//{
//public:
//	virtual void boil() = 0;
//	virtual void paotea() = 0; 
//	virtual void put_in_cup() = 0;
//	virtual void addthing() = 0;
//	void test()
//	{
//		boil();
//		paotea();
//		put_in_cup();
//		addthing();
//	}
//};
//class coffee:public Makedrink
//{
//public:
//	virtual void boil()
//	{
//		cout << "烧水煮咖啡" << endl;
//	};
//	virtual void paotea()
//	{
//		cout << "泡咖啡" << endl;
//	};
//	virtual void put_in_cup()
//	{
//		cout << "将咖啡放入被子里" << endl;
//	};
//	virtual void addthing()
//	{
//		cout << "加入白糖" << endl;
//	};
//};
//class tea:public Makedrink
//{
//public:
//	virtual void boil()
//	{
//		cout << "烧水煮龙井" << endl;
//	};
//	virtual void paotea()
//	{
//		cout << "泡茶叶" << endl;
//	};
//	virtual void put_in_cup()
//	{
//		cout << "将茶放入杯子里" << endl;
//	};
//	virtual void addthing()
//	{
//		cout << "盖上盖子" << endl;
//	};
//};
//void Makedrink_m(Makedrink* aaa)
//{
//	aaa->test();
//	delete aaa;
//}
//void test0()
//{
//	Makedrink_m(new coffee);
//	Makedrink_m(new tea);
//}
//int main()
//{
//	test0();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//class animal
//{
//public:
//	animal()
//	{
//		cout << "animal构造函数调用" << endl;
//	}
//	virtual void speak() = 0;
//	virtual~animal() = 0;
//};
//animal::~animal()
//{
//	cout << "animal析构函数调用" << endl;
//}
//class dog :public animal
//{
//public:
//	dog(string aaa)
//	{
//		cout << "dog构造函数调用" << endl;
//		m_aaa = new string(aaa);
//	}
//	virtual void speak()
//	{
//		cout << *m_aaa<<"小狗在叫" << endl;
//
//	}
//	~dog()
//	{
//		if (m_aaa != NULL)
//		{
//			delete m_aaa;
//		}
//		cout << "dog析构函数调用" << endl;
//	}
//	string* m_aaa;
//};
//void dospeak(animal* aaa)
//{
//	aaa->speak();//父类的指针在析构时不会调用子类中的析构函数
//}//将父类的析构函数改称虚析构就好了
//void test()
//{
//
//	animal* aaa=new dog("tom");
//	dospeak(aaa);
//}
//int main()
//{
//	test();
////	return 0;
////}
//#include<iostream>
//using namespace std;
//class CPU
//{
//public:
//	virtual void calculator() = 0;
//};
//class GPU
//{
//public:
//	virtual void display() = 0;
//};
//class MEMORY
//{
//public:
//	virtual void storage() = 0;
//};
//class computer
//{
//public:
//	computer(CPU* cpu,
//	GPU* gpu,
//	MEMORY* memory)
//	{
//		m_cpu = cpu;
//		m_gpu = gpu;
//		m_memory = memory;
//	}
//	void work()
//	{
//		m_cpu->calculator();
//		m_gpu->display();
//		m_memory->storage();
//	}
//	~computer()
//	{
//		if (m_cpu != NULL && m_gpu != NULL && m_memory != NULL)
//		{
//			delete m_cpu;
//			m_cpu = NULL;
//			delete m_gpu;
//			m_gpu = NULL;
//			delete m_memory;
//			m_memory = NULL;
//		}
//	}
//private:
//	CPU* m_cpu;
//	GPU* m_gpu;
//	MEMORY* m_memory;
//};
//class intelCPU :public CPU
//{
//public:
//	virtual  void calculator()
//	{
//		cout << "intel的cpu开示计算了" << endl;
//	}
//};
//class intelGPU :public GPU
//{
//public:
//	virtual  void display()
//	{
//		cout << "intel的gpu开示显示了" << endl;
//	}
//};
//class intelMEMORY :public MEMORY
//{
//public:
//	virtual  void storage()
//	{
//		cout << "intel的memory开示储存了" << endl;
//	}
//};
//class LenovoCPU :public CPU
//{
//public:
//	virtual  void calculator()
//	{
//		cout << "Lenovo的cpu开示计算了" << endl;
//	}
//};
//class LenovoGPU :public GPU
//{
//public:
//	virtual  void display()
//	{
//		cout << "Lenovo的gpu开示显示了" << endl;
//	}
//};
//class LenovoMEMORY :public MEMORY
//{
//public:
//	virtual  void storage()
//	{
//		cout << "Lenovo的memory开示储存了" << endl;
//	}
//};
//void test()
//{
//	CPU* intelcpu = new LenovoCPU;
//	GPU* intelcard = new LenovoGPU;
//	MEMORY* intelmen = new LenovoMEMORY;
//	computer* computer1 = new computer(intelcpu, intelcard, intelmen);
//	computer1->work();
//	delete computer1;
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//#include<fstream>
//#include<string>
//void test()
//{
//	//string m_a;
//	//ofstream ps;//创建一个对象写文件形式
//	//cin >>m_a;
//	//ps.open("test1.txt", ios::binary);
//	//ps << m_a << endl;
//	//ps << "姓名  " << "李四" << endl;
//	//ps.close();
//	//ifstream ps;
//	//ps.open("test.txt", ios::in);//判断是否打开成功
//	//if (!ps.is_open())
//	//{
//	//	cout << "打开失败" << endl;
//	//	return;
//	//}
//	////char arr[30];
//	///*while (ps>>arr)
//	//{
//	//	cout << arr << endl;
//	//*/}
//	ifstream ps;
//	ps.open("test.txt", ios::in);
//	if (!ps.is_open())
//	{
//		cout << "打开失败" << endl;
//	}
//	char arr[50] = { 0 };
//		/*while (ps>>arr)
//		{
//			cout << arr << endl;
//		}*/
//		//while (ps.getline(arr,sizeof(arr)))//一行一行进行读取不会因为空格而换行
//		//{
//		//	cout << arr << endl;//getline(数组，数组的大小)
//		//}
//	string buff;
//		while (getline(ps,buff))//一行一行进行读取不会因为空格而换行
//		{
//			cout <<buff << endl;//getline(对象，字符串)
//		}
//		char c;
//		while((c = ps.get()) != EOF)
//		{
//			cout << c;
//		}
//	ps.close();
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//using namespace std;
//#include<fstream>
//#include<string>
//void test()
//{
//	ofstream pa;
//	pa.open("test.txt", ios::app);
//	if (!pa.is_open())
//	{
//		cout << "打开文件出错" << endl;
//		return;
//	}
//	pa << "姓名3  张三    年龄   30    性别    男" << endl;
//	pa << "姓名3  张三    年龄   30    性别    男" << endl;
//	pa.close();
//}
//void test1()
//{
//	ifstream ps;
//	ps.open("test.txt", ios::in);
//	if (!ps.is_open())
//	{
//		cout << "打开失败" << endl;
//	}
//	char aaa[50];
//	while (ps.getline(aaa,sizeof(aaa)))
//	{
//		cout << aaa << endl;
//	}
//	ps.close();
//}
//int main()
//{
//	test();
//	test1();
//	return 0;
//}
#include<iostream>
using namespace std;
#include<fstream>
#include<string>
class person
{
public:
	string m_name;
	int m_age;
};
void test()
{
	ofstream ps;
	ps.open("test1.txt",ios::out| ios::binary);
	if (!ps.is_open())
	{
		cout << "打开文件失败" << endl;
	}
	person bbb;
	bbb.m_age = 30;
	bbb.m_name = "李四";
	ps.write((const char*) &bbb,sizeof(person));
	ps.close();
}
void test1()
{
	ifstream aaa;
	aaa.open("test1.txt", ios::in | ios::binary);
	person bbb;
	aaa.read((char*)&bbb,sizeof(person));
	aaa.close();
	cout << bbb.m_name << " " << bbb.m_age << endl;
}
int main()
{
	//test();
	test1();
	return 0;
}
//#include<iostream>
//using namespace std;
//class animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "�����ڽ�" << endl;
//	}
//};
//class cat:public animal
//{
//public:
//	void speak()
//	{
//		cout << "Сè�ڽ�" << endl;
//	}
//};//��̬��̬�����ڱ����ǲ�ȷ����ַ
//void tall(animal& aaa)//��̬��̬������ַ������ʱ��ȷ����̬��̬��������1�м̳й�ϵ������д�������麯��
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
//	virtual void func() = 0;//���麯����������һ�����麯����Ϊ������
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
//	//person aaa;//�������޷�ʵ��������
//	//son aaa;//����̳г����������д���麯�������޷����ֻ�����
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
//		cout << "��ˮ�󿧷�" << endl;
//	};
//	virtual void paotea()
//	{
//		cout << "�ݿ���" << endl;
//	};
//	virtual void put_in_cup()
//	{
//		cout << "�����ȷ��뱻����" << endl;
//	};
//	virtual void addthing()
//	{
//		cout << "�������" << endl;
//	};
//};
//class tea:public Makedrink
//{
//public:
//	virtual void boil()
//	{
//		cout << "��ˮ������" << endl;
//	};
//	virtual void paotea()
//	{
//		cout << "�ݲ�Ҷ" << endl;
//	};
//	virtual void put_in_cup()
//	{
//		cout << "������뱭����" << endl;
//	};
//	virtual void addthing()
//	{
//		cout << "���ϸ���" << endl;
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
//		cout << "animal���캯������" << endl;
//	}
//	virtual void speak() = 0;
//	virtual~animal() = 0;
//};
//animal::~animal()
//{
//	cout << "animal������������" << endl;
//}
//class dog :public animal
//{
//public:
//	dog(string aaa)
//	{
//		cout << "dog���캯������" << endl;
//		m_aaa = new string(aaa);
//	}
//	virtual void speak()
//	{
//		cout << *m_aaa<<"С���ڽ�" << endl;
//
//	}
//	~dog()
//	{
//		if (m_aaa != NULL)
//		{
//			delete m_aaa;
//		}
//		cout << "dog������������" << endl;
//	}
//	string* m_aaa;
//};
//void dospeak(animal* aaa)
//{
//	aaa->speak();//�����ָ��������ʱ������������е���������
//}//����������������ĳ��������ͺ���
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
//		cout << "intel��cpu��ʾ������" << endl;
//	}
//};
//class intelGPU :public GPU
//{
//public:
//	virtual  void display()
//	{
//		cout << "intel��gpu��ʾ��ʾ��" << endl;
//	}
//};
//class intelMEMORY :public MEMORY
//{
//public:
//	virtual  void storage()
//	{
//		cout << "intel��memory��ʾ������" << endl;
//	}
//};
//class LenovoCPU :public CPU
//{
//public:
//	virtual  void calculator()
//	{
//		cout << "Lenovo��cpu��ʾ������" << endl;
//	}
//};
//class LenovoGPU :public GPU
//{
//public:
//	virtual  void display()
//	{
//		cout << "Lenovo��gpu��ʾ��ʾ��" << endl;
//	}
//};
//class LenovoMEMORY :public MEMORY
//{
//public:
//	virtual  void storage()
//	{
//		cout << "Lenovo��memory��ʾ������" << endl;
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
//	//ofstream ps;//����һ������д�ļ���ʽ
//	//cin >>m_a;
//	//ps.open("test1.txt", ios::binary);
//	//ps << m_a << endl;
//	//ps << "����  " << "����" << endl;
//	//ps.close();
//	//ifstream ps;
//	//ps.open("test.txt", ios::in);//�ж��Ƿ�򿪳ɹ�
//	//if (!ps.is_open())
//	//{
//	//	cout << "��ʧ��" << endl;
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
//		cout << "��ʧ��" << endl;
//	}
//	char arr[50] = { 0 };
//		/*while (ps>>arr)
//		{
//			cout << arr << endl;
//		}*/
//		//while (ps.getline(arr,sizeof(arr)))//һ��һ�н��ж�ȡ������Ϊ�ո������
//		//{
//		//	cout << arr << endl;//getline(���飬����Ĵ�С)
//		//}
//	string buff;
//		while (getline(ps,buff))//һ��һ�н��ж�ȡ������Ϊ�ո������
//		{
//			cout <<buff << endl;//getline(�����ַ���)
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
//		cout << "���ļ�����" << endl;
//		return;
//	}
//	pa << "����3  ����    ����   30    �Ա�    ��" << endl;
//	pa << "����3  ����    ����   30    �Ա�    ��" << endl;
//	pa.close();
//}
//void test1()
//{
//	ifstream ps;
//	ps.open("test.txt", ios::in);
//	if (!ps.is_open())
//	{
//		cout << "��ʧ��" << endl;
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
		cout << "���ļ�ʧ��" << endl;
	}
	person bbb;
	bbb.m_age = 30;
	bbb.m_name = "����";
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
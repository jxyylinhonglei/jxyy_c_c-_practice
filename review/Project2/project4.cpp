#include<iostream>
#include<vector>
#include<array>
#include<forward_list>
#include<deque>
#include<stack>
#include<list>
#include<algorithm>
#include<functional>
#include<windows.h>
#include<queue>
#include<cstdlib>
using namespace std;
int test() {//����Ĵ����STL���������������
	int arr[6] = {1,2,3,4,5,6};
	vector<int, allocator<int>> vi(arr,arr+6);//allocator�Ƿ�������vector<int, allocator<int>>��������Ԫ����int���ͣ������һ����������������Ҫ�з�����֧�֣���������д��Դ�������Ĭ�Ϸ�������allocator<int>ÿ�η����int����
	cout << count_if(vi.begin(), vi.end(),not1(bind2nd(less<int>(),40)) ) << endl;
	return 0;
}
/*
	clock(),�������п�ʼ�����ڵĺ�����
*/
int compare(const void* a,const void* b) {
	return (*(int*)a - *(int*)b);
}
int test1() {
	//Sleep(1000);
	//cout<<clock()<<endl;
	//array<int, 100000> c;
	//for (int i = 0; i < 100000;i++) {
	//	c[i] = rand();
	//}
	// 
	//srand(time(0));
	//for (int i = 0; i < 10;i++) {
	//	cout<<rand()<<endl;
	//}
	long begin = clock();
	array<int, 1000000> arr;
	srand(time(0));
	for (int i = 0; i < 100000;i++) {
		arr[i] = rand();
	}
	qsort(arr.data(), 100000,sizeof(int),compare);
	long end = clock();
	cout<<"��ʱ" << end - begin <<"����" << endl;
	cout << arr.front() << endl;
	cout<<arr.back()<<endl;
	cout << "arr�Ĵ�СΪ" << sizeof(arr)/1024 << endl;
	cout<<&arr<<"	"<<arr.data() << endl;
	cout << arr.at(0) << endl;
	cout << arr[1] << endl;
	cout << arr[2] << endl;
	cout << arr[99] << endl;
	cout << arr[100] << endl;
	return 0;
}
int test2() {
/*	vector<int> vec;
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 10000;i++) {
		vec.push_back(rand());
		cout <<"Ԫ�ظ���"<< vec.size() <<"����"<< vec.capacity() << endl;
	}
	sort(vec.begin(),vec.end());
	cout << "vec�ĵ�ַ" << &vec << "vec����ʼ��ַ" << vec.data() << endl;
	long end = clock();
	cout << "��ʱ" << end - begin << endl;*/	
	vector<int> vec;
	srand(time(0));
	for (int i = 50; i >= 0; i--) {
		vec.push_back(rand());
	}
	sort(vec.begin(),vec.end());
	cout << vec.front() << vec[0] << endl;
	cout << vec.back() << vec[vec.size()-1] << endl;
	vector<int>::iterator t = find(vec.begin(),vec.end(),vec[4]);
	if (t==vec.end()) {
		cout << "û���ҵ�" << endl;
	}
	else {
		cout << "�ҵ���"<<*t <<"λ��Ϊ"<<t-vec.begin()<< endl;
	}
	return 0;
}
void test3() {
	list<int> list_table;
	list<int> list_table1;
	srand(time(0));
	long begin1 = clock();
	for (int i = 0; i < 100000;i++) {
		list_table.push_back(rand());
	}
	long end1 = clock();
	list_table.sort();
	long end2 = clock();//��������������ʱ��
	cout << "����Ԫ�������ʱ��" << end1 - begin1 << endl;
	cout << "���������ʱ��" << end2 - end1 << endl;
	cout <<"���һλ��Ԫ��"<< list_table.back() << endl;
	cout << "ͷԪ��" << list_table.front() << endl;
	cout << "�������" << list_table.max_size() << endl;
	auto t=find(list_table.begin(),list_table.end(),666);
	if (t==list_table.end()) {
		cout << "û���ҵ�" << endl;
	}
	else {
		cout << "�ҵ���" << *t<< endl;
	}
}
void test4() {
	forward_list<int> list_table;
	srand(time(0));
	long begin1 = clock();
	for (int i = 0; i < 100000;i++) {
		list_table.push_front(rand());
	}
	long end1 = clock();
	list_table.sort();
	long end2 = clock();
	cout << "����Ԫ�������ʱ��" << end1 - begin1 << endl;
	cout << "���������ʱ��" << end2 - end1 << endl;
	//cout << "���һλ��Ԫ��" << list_table.back() << endl;//��������û��back()����
	cout << "ͷԪ��" << list_table.front() << endl;
	cout << "�������" << list_table.max_size() << endl;
	auto t = find(list_table.begin(), list_table.end(), 666);
	if (t == list_table.end()) {
		cout << "û���ҵ�" << endl;
	}
	else {
		cout << "�ҵ���" << *t << endl;
	}
}
void test5() {
	deque<int> arr;
	srand(time(0));
	long begin = clock();
	for (int i = 0; i < 1000;i++) {
		if (i%2) {
			arr.push_back(rand());
		}
		else {
			arr.push_front(rand());
		}
	}
	long end1 = clock();
	sort(arr.begin(),arr.end());
	long end2 = clock();
	cout << "����Ԫ�������ʱ��" << end1 - begin << endl;
	cout << "���������ʱ��" << end2 - end1 << endl;
	cout << "���һλ��Ԫ��" << arr.back() << endl;
	cout << "ͷԪ��" << arr.front() << endl;
	cout << "�������" << arr.max_size() << endl;
	auto t = find(arr.begin(), arr.end(), 666);
	if (t == arr.end()) {
		cout << "û���ҵ�" << endl;
	}
	else {
		cout << "�ҵ���" << *t << endl;
	}
}
void test6() {
	stack<int> tmp;
	srand(time(0));
	for (int i = 0; i < 1000; i++) {
		tmp.push(rand());
	}
	long end1 = clock();
	long end2 = clock();
	cout << "ջ����Ԫ��" <<tmp.top() << endl;	
	cout << "����" << tmp.size() << endl;
	tmp.pop();//��ջ
	cout << "����" << tmp.size() << endl;
}
void test7() {
	queue<int> tmp;
	srand(time(0));
	for (int i = 0; i < 1000; i++) {
		tmp.push(rand());
	}
	cout << "����" << tmp.size() << endl;
	cout << "��ͷ��Ԫ��" << tmp.front() << endl;
	cout << "��β��Ԫ��" << tmp.back() << endl;
	tmp.pop();//������
	cout << "����" << tmp.size() << endl;
	cout << "��ͷ��Ԫ��" << tmp.front() << endl;
	cout << "��β��Ԫ��" << tmp.back() << endl;
}
int main4() {
	test7();
	return 0;
}
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
int test() {//下面的代码把STL六大组件都包含了
	int arr[6] = {1,2,3,4,5,6};
	vector<int, allocator<int>> vi(arr,arr+6);//allocator是分配器，vector<int, allocator<int>>代表容器元素是int类型，允许放一个分配器，容器是要有分配器支持，分配器不写，源代码会有默认分配器。allocator<int>每次分配的int类型
	cout << count_if(vi.begin(), vi.end(),not1(bind2nd(less<int>(),40)) ) << endl;
	return 0;
}
/*
	clock(),程序运行开始到现在的毫秒数
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
	cout<<"耗时" << end - begin <<"毫秒" << endl;
	cout << arr.front() << endl;
	cout<<arr.back()<<endl;
	cout << "arr的大小为" << sizeof(arr)/1024 << endl;
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
		cout <<"元素个数"<< vec.size() <<"容量"<< vec.capacity() << endl;
	}
	sort(vec.begin(),vec.end());
	cout << "vec的地址" << &vec << "vec的起始地址" << vec.data() << endl;
	long end = clock();
	cout << "耗时" << end - begin << endl;*/	
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
		cout << "没有找到" << endl;
	}
	else {
		cout << "找到了"<<*t <<"位置为"<<t-vec.begin()<< endl;
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
	long end2 = clock();//计算出排序所需的时间
	cout << "插入元素所需的时间" << end1 - begin1 << endl;
	cout << "排序所需的时间" << end2 - end1 << endl;
	cout <<"最后一位的元素"<< list_table.back() << endl;
	cout << "头元素" << list_table.front() << endl;
	cout << "最大容量" << list_table.max_size() << endl;
	auto t=find(list_table.begin(),list_table.end(),666);
	if (t==list_table.end()) {
		cout << "没有找到" << endl;
	}
	else {
		cout << "找到了" << *t<< endl;
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
	cout << "插入元素所需的时间" << end1 - begin1 << endl;
	cout << "排序所需的时间" << end2 - end1 << endl;
	//cout << "最后一位的元素" << list_table.back() << endl;//单向链表没有back()函数
	cout << "头元素" << list_table.front() << endl;
	cout << "最大容量" << list_table.max_size() << endl;
	auto t = find(list_table.begin(), list_table.end(), 666);
	if (t == list_table.end()) {
		cout << "没有找到" << endl;
	}
	else {
		cout << "找到了" << *t << endl;
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
	cout << "插入元素所需的时间" << end1 - begin << endl;
	cout << "排序所需的时间" << end2 - end1 << endl;
	cout << "最后一位的元素" << arr.back() << endl;
	cout << "头元素" << arr.front() << endl;
	cout << "最大容量" << arr.max_size() << endl;
	auto t = find(arr.begin(), arr.end(), 666);
	if (t == arr.end()) {
		cout << "没有找到" << endl;
	}
	else {
		cout << "找到了" << *t << endl;
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
	cout << "栈顶的元素" <<tmp.top() << endl;	
	cout << "容量" << tmp.size() << endl;
	tmp.pop();//出栈
	cout << "容量" << tmp.size() << endl;
}
void test7() {
	queue<int> tmp;
	srand(time(0));
	for (int i = 0; i < 1000; i++) {
		tmp.push(rand());
	}
	cout << "容量" << tmp.size() << endl;
	cout << "对头的元素" << tmp.front() << endl;
	cout << "对尾的元素" << tmp.back() << endl;
	tmp.pop();//出队列
	cout << "容量" << tmp.size() << endl;
	cout << "对头的元素" << tmp.front() << endl;
	cout << "对尾的元素" << tmp.back() << endl;
}
int main4() {
	test7();
	return 0;
}
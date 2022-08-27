#include<stdio.h>
gettest(w, h) {//c++对c语言进行扩展，函数检测增强
	//返回值没有检测  形参类型没有检测   函数调用参数个数没有检测
	return w * h;
}
//struct Person {//struct增强，可以定义函数
//
//	//void print() {
//	//	
//	//}
//};
#define __TEST__	
int main00() {
	int a = 10;
	int b = 20;
	*(a > b ? &a : &b) = 100;
	printf("11 b=%d\n",b);
	//const int len = 10;
	//int arr[len];//const增强，允许const修饰的变量初始化数组
	const int aa = 10;
	int* p = (int*)&aa;
	*p = 20;
	printf("%d\n",aa);
	printf("%x   %x",&aa, p);
#ifndef __TEST__
	printf("test");
#endif 
}
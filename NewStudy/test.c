#include<stdio.h>
gettest(w, h) {//c++��c���Խ�����չ�����������ǿ
	//����ֵû�м��  �β�����û�м��   �������ò�������û�м��
	return w * h;
}
//struct Person {//struct��ǿ�����Զ��庯��
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
	//int arr[len];//const��ǿ������const���εı�����ʼ������
	const int aa = 10;
	int* p = (int*)&aa;
	*p = 20;
	printf("%d\n",aa);
	printf("%x   %x",&aa, p);
#ifndef __TEST__
	printf("test");
#endif 
}
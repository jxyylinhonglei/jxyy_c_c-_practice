#include"SLisk.h"
void test()
{
	struct StackNode phead;
	LiskInit(&phead);
	//LiskPushBack(&phead,2);
	//LiskPushBack(&phead,4);
	//LiskPrintElement(&phead);
	//LiskPushFront(&phead, 1);
	//LiskPushBack(&phead, 5);
	//LiskInsert(&phead, 3,3);
	//LiskPushBack(&phead, 6);
 //   LiskDelete(&phead, 4);
	//LiskInsert(&phead, 4, 4);
	//LiskPushFront(&phead, 0);
	//LiskPrintElement(&phead);
	LiskInsert(&phead, 1, 1);
	LiskInsert(&phead, 2, 2);
	LiskInsert(&phead, 3, 3); 
	LiskInsert(&phead, 4, 4);
	LiskInsert(&phead, 5, 5);
	LiskPrintElement(&phead);
	LiskDelete(&phead, 1); 
	LiskDelete(&phead, 1);
	LiskPrintElement(&phead);
	LiskDelete(&phead, 1);
	LiskDelete(&phead, 1);
	LiskPrintElement(&phead);
}
int main()
{
	test();
	return 0;
}
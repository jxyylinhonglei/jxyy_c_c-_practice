#include"DLList.h"
void test()
{
	struct DuLNode* head=NULL;
	DuLInit(&head);
	DuLListPushFront(&head, 2);
	DuLListPushFront(&head, 1);
	DuLListPushBack(&head, 3);
	DuLListPushBack(&head, 4);
	DuLListPushBack(&head, 5);
	DuLListPushBack(&head, 9);
	DuLLPrint(head);
	DuLListInsert(&head, 6, 6);
	DuLListInsert(&head, 7, 7);
	DuLListInsert(&head, 8, 8);
	DuLListDelete(&head, 8);
	DuLListInsert(&head, 8, 8);
	DuLLPrint(head);
	DuLListPopBack(&head);
	DuLListPopFront(&head);
	DuLLPrint(head);
	/*DuLListPopFront(&head);
	DuLListPopFront(&head);
	DuLListInsert(&head, 1, 2);
	DuLListInsert(&head, 1, 1);*/
	/*DuLListDelete(&head, 2);*/
	/*DuLListPopFront(&head);
	DuLListPopBack(&head);
	DuLListPopFront(&head);*/
	/*DuLListPushFront(&head, 2);
	DuLListPushFront(&head, 1);
	DuLLPrint(head);
	DuLListPushBack(&head, 4);
	DuLListPushBack(&head, 5);
	DuLListPopBack(&head);
	DuLLPrint(head);
	DuLListInsert(&head, 1, 0);
	DuLListInsert(&head, 6, 5);
	DuLLPrint(head);*/
	DestoryList(&head);
}
void test1()
{
	struct DuLNode* head = NULL;
	DuLInit(&head);
	DuLListPushFront(&head, 2);
	DuLListPushFront(&head, 1);
	DuLListPushBack(&head, 3);
	DuLListPopBack(&head);
	DuLLPrint(head);
	DestoryList(&head);
}
int main()
{
	test0();
	return 0;

}
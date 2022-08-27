#include"SLisk.h"
void LiskInit(struct StackNode* ps)
{
	ps->data = 0;
	ps->next = NULL;
}
void LiskPushBack(struct StackNode* ps, ElementType x)
{
	assert(ps);
	struct StackNode* pp = ps;
	while (pp->next!= NULL)
	{
		pp= pp->next;
	}
	struct StackNode* Node = (struct StackNode*)malloc(sizeof(struct StackNode));
	Node->next = NULL;
	if (Node == NULL)
	{
		printf("ÉêÇë¿Õ¼äÊ§°Ü\n");
		exit(-1);
	}
	else
	{
		Node->data = x;
		pp->next = Node;
	}
}//Î²²å
void LiskPopBack(struct StackNode* ps)
{
	struct StackNode* pp = ps;
	while (pp->next != NULL)
	{
		ps = pp;
		pp= pp->next;
	}
	free(pp);
	pp = NULL;
	ps->next = NULL;
}//Î²É¾
void LiskPushFront(struct StackNode* ps, ElementType x)
{
	assert(ps);
	struct StackNode* pp = ps;
	struct StackNode* Node = (struct StackNode*)malloc(sizeof(struct StackNode));
	Node->next = NULL;
	if (Node == NULL)
	{
		printf("ÉêÇë¿Õ¼äÊ§°Ü\n");
		exit(-1);
	}
	else
	{
		Node->data = x;
		Node->next = pp->next;
		ps->next = Node;
	}
}//Í·²å
void LiskPopFront(struct StackNode* ps)
{
	struct StackNode* pp = ps->next;
	ps->next = pp->next;
	free(pp);
	pp = NULL;
}//Í·É¾
void LiskInsert(struct StackNode* ps, int pos, ElementType x)//ÈÎÒâ²å
{
	struct StackNode* pp = ps;
	assert(ps);
	struct StackNode* NewNode = (struct StackNode*)malloc(sizeof(struct StackNode));
	NewNode->next = NULL;
	NewNode->data = x;
	while (pos-1)
	{
		pp = pp->next;
		pos--;
	}
	NewNode->next = pp->next;
	pp->next = NewNode;
}//ÈÎÒâ²å
void LiskDelete(struct StackNode* ps, int pos)
{
	assert(ps);
	struct StackNode* pp = NULL;
	while (pos-1)
	{
		ps = ps->next;
		pos--;
	}
	pp = ps->next;
	ps->next = pp->next;
	free(pp);
	pp=NULL;
}
void LiskPrintElement(struct StackNode* ps)
{
	assert(ps);
	struct StackNode* pp = ps->next;
	while (pp != NULL)
	{
		printf(" %d-> ", pp->data);
		pp = pp->next;
	}
	printf("NULL\n");
}
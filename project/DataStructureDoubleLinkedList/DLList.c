#include"DLList.h"
void DuLInit(struct DuLNode** ps)
{
	assert(ps);
	*ps = (struct DuLNode*)malloc(sizeof(struct DuLNode));
	(*ps)->data = 0;
	(*ps)->next = *ps;
	(*ps)->perv = *ps;
}
struct DuLNode* buyNode(DataType x)
{
	struct DuLNode* Node = (struct DuLNode*)malloc(sizeof(struct DuLNode));
	Node->data = x;
	Node->next = NULL;
	Node->perv = NULL;
	return Node;
}
int Elementtotal(struct DuLNode* ps)
{
	int total = 0;
	struct DuLNode* tail = ps->perv;
	struct DuLNode* cur = ps;
	while (cur != tail)
	{
		cur = cur->next;
		total++;
	}
	return total ;
}
void DuLLPrint(struct DuLNode* ps)
{
	assert(ps);
	struct DuLNode* cur = ps;
	while (ps->perv!=cur)
	{
		cur = cur->next;
		printf("%d->", cur->data);
	}
	printf("\n");
}
void DuLListInsert(struct DuLNode** ps, int pos, DataType x)
{
	struct DuLNode* cur = (*ps);
	struct DuLNode* Node = buyNode(x);
	struct DuLNode* pp = NULL;
	while (pos)
	{
		pos--;
		cur = cur->next;
	}
	pp = cur->perv;
	pp->next = Node;
	Node->perv = pp;
	Node->next = cur;
	cur->perv = Node;

}
void DuLListDelete(struct DuLNode** ps, int pos)
{
	struct DuLNode* cur = (*ps);
	struct DuLNode* pp = NULL;
	while (pos)
	{
		pos--;
		cur = cur->next;
	}
	pp = cur->perv;
	pp->next = cur->next;
	cur->next->perv = pp;
	free(cur);
	cur = NULL;
}
void DuLListPushBack(struct DuLNode** ps, DataType x)
{
	//assert(ps);
	//struct DuLNode* phead = *ps;
	//struct DuLNode* tail = phead->perv;//tailÎª¿Õ
	//struct DuLNode* Node = buyNode(x);
	//tail->next = Node;
	//Node->perv = tail;
	//Node->next = phead;
	//phead->perv = Node;
	DuLListInsert(ps, Elementtotal(*ps)+1, x);
}
void DuLListPushFront(struct DuLNode** ps, DataType x)
{
	/*struct DuLNode* phead = (*ps)->next;
	struct DuLNode* NewNode=buyNode(x);
	(*ps)->next = NewNode;
	NewNode->perv = (*ps);
	NewNode->next=phead;
	phead->perv = NewNode;*/
	DuLListInsert(ps, 1, x);
}
void DuLListPopBack(struct DuLNode** ps)
{
	assert(*ps);
	/*struct DuLNode* tail = (*ps)->perv;
	struct DuLNode* tailperv = tail->perv;
	tailperv->next = (*ps);
	(*ps)->perv = tailperv;
	free(tail);
	tail = NULL;*/
	DuLListDelete(ps, Elementtotal(*ps));
}
void DuLListPopFront(struct DuLNode** ps)
{
	/*struct DuLNode* pp = NULL;
	struct DuLNode* pheadnext = (*ps)->next;
	pp = pheadnext->next;
	(*ps)->next = pp;
	pp->perv = (*ps);
	free(pheadnext);
	pheadnext = NULL;*/
	DuLListDelete(ps, 1);
}
void DestoryList(struct DuLNode** ps)
{
	struct DuLNode* cur = (*ps);
	struct DuLNode* tail = cur->perv;
	struct DuLNode* pp = NULL;
	while (cur!=tail)
	{
		pp = cur;
		cur = cur->next;
		free(pp);
		pp = NULL;
	}
	free(tail);
	tail = NULL;
	cur = NULL;
	(*ps) = NULL;
}
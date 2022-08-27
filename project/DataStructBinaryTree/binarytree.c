#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct binarytree* DataType;
struct List
{
	DataType data;
	struct Queue* next;
};
struct Queue
{
	struct List* head;
	struct List* tail;
};
void InitQueue(struct Queue* ps)
{
	ps->head = ps->tail = NULL;
}
void QueuePush(struct Queue* ps,int x)
{
	struct List* tmp = (struct List*)malloc(sizeof(struct List));
	tmp->data = x;
	tmp->next = NULL;
	if (ps->head == NULL)
	{
		ps->head = ps->tail = tmp;
	}
	else
	{
		ps->tail->next = tmp;
		ps->tail = tmp;
	}
}
DataType QueuePop(struct Queue* ps)
{
	if (ps->head == NULL)
	{
		return;
	}
	else
	{
		DataType tmp;
		if (ps->head->next == NULL)
		{
			tmp = ps->head->data;
			free(ps->head);
			ps->head = ps->tail = NULL;
			return tmp;
		}
		else
		{
			struct List* pp = ps->head;
			ps->head = pp->next;
			tmp = pp->data;
			free(pp);
			pp = NULL;
			return tmp;
		}
	}
}
bool QueueEmpty(struct Queue* ps)
{
	if (ps->head == NULL)//没有节点
	{
		return true;
	}
	else
	{
		return false;
	}
}
DataType QueueTop(struct Queue* ps)
{
	return ps->head->data;
}
void QueueDestory(struct Queue* ps)
{
	if (ps->head == NULL)
	{
		return;
	}
	else
	{
		struct List* tmp = NULL;
		if (ps->head->next == NULL)
		{
			free(ps->head);
			ps->head = ps->tail = NULL;
		}
		else
		{;
			while (ps->head)
			{
				tmp = ps->head;
				ps->head = tmp->next;
				free(tmp);
				tmp = NULL;
			}
			ps->tail=NULL;
		}
	}
}
typedef char TreeDataType;
struct binarytree
{
	TreeDataType data;
	struct binarytree* leftchild;
	struct binarytree* rightchild;
};
//void PrevOrder(struct binarytree* ps)
//{
//	if (ps == NULL)
//	{
//	/*	printf("NULL ");*/
//		return;
//	}
//	printf("%c ", ps->data);
//	PrevOrder(ps->leftchild);
//	PrevOrder(ps->rightchild);
//}
//void TreeSize(struct binarytree* ps,int* size)
//{
//	if (ps == NULL)
//	{
//		return;
//	}
//	else
//	{
//		(*size)++;
//		TreeSize(ps->leftchild,size);
//		TreeSize(ps->rightchild, size);
//	}
//}
//int TreeSizeq(struct binarytree* ps)
//{
//	return ps == NULL ? 0 : TreeSizeq(ps->leftchild) + TreeSizeq(ps->rightchild) + 1;
//}
//int Treeleaf(struct binarytree* ps)
//{
//	if (ps == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		if (ps->leftchild == NULL && ps->rightchild == NULL)
//		{
//			return 1;
//		}
//		else
//		{
//			return Treeleaf(ps->leftchild) + Treeleaf(ps->rightchild);
//		}
//	}
//}
//int TreeSize(struct binarytree* root)
//{
//	if (root == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return TreeSize(root->leftchild) + TreeSize(root->rightchild) + 1;
//	}
//}
int TreeDepthl(struct binarytree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int left = TreeDepthl(root->leftchild);
		int right = TreeDepth(root->rightchild);
		if (left > right)
		{
			return left + 1;
		}
		else
		{
			return right + 1;
		}
	}
}
void test()
{
	struct Queue t;
	InitQueue(&t);
	struct binarytree A;
	struct binarytree B;
	struct binarytree C;
	struct binarytree D;
	struct binarytree E;
	struct binarytree F;
	A.data = 'A';
	B.data = 'B';
	C.data = 'C';
	D.data = 'D';
	E.data = 'E';
	F.data = 'F';
	A.leftchild = &B;
	A.rightchild = &C;
	B.leftchild = NULL;
	B.rightchild = &D;
	D.leftchild = &F;
	D.rightchild = NULL;
	F.leftchild = NULL;
	F.rightchild = NULL;
	C.leftchild = &E;
	C.rightchild = NULL;
	E.leftchild = NULL;
	E.rightchild = NULL;
	//QueuePush(&t,&A);
	//while (!QueueEmpty(&t))//空为真
	//{
	//	DataType tmp = QueueTop(&t);
	//	if (tmp->leftchild!=NULL)//判断是否有左孩子
	//	{
	//		QueuePush(&t,tmp->leftchild);
	//	}
	//	if(tmp->rightchild != NULL)//判断是否有右孩子
	//	{
	//		QueuePush(&t, tmp->rightchild);
	//	}
	//	tmp=QueuePop(&t);
	//	printf("%c", tmp->data);
	//}
	//QueueDestory(&t);
	/*printf("%d", TreeSize(&A));
	printf("%d", Treeleaf(&A));*/
	printf("%d", TreeDepthl(&A));
}
int main()
{
	/*struct binarytree A;
	struct binarytree B;
	struct binarytree C;
	struct binarytree D;
	struct binarytree E;
	struct binarytree F;
	A.data ='A';
	B.data = 'B';
	C.data ='C';
	D.data = 'D';
	E.data = 'E';
	F.data = 'F';
	A.leftchild = &B;
	A.rightchild = &C;
	B.leftchild = NULL;
	B.rightchild = &D;
	D.leftchild = &F;
	D.rightchild = NULL;
	F.leftchild = NULL;
	F.rightchild = NULL;
	C.leftchild = &E;
	C.rightchild = NULL;
	E.leftchild = NULL;
	E.rightchild = NULL;
	PrevOrder(&A);
	int size = 0;
	TreeSize(&A,&size);
	printf("%d", size);
	printf("%d", TreeSizeq(&A));
	printf("%d", Treeleaf(&A));*/
	test();
	return 0;
}
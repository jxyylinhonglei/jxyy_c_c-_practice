#include<stdio.h>
#include<stdlib.h>
typedef char DataType;
typedef struct BinaryTree* StackDataType;
struct Stack
{
	StackDataType value;
	int flat;
	struct Stack* next;
};//¼òÒ×Õ»£¬Ñ¹Õ»£¬³öÕ»£¬ÅÐ¶ÏÊÇ·ñÎª¿Õ
struct BinaryTree
{
	DataType val;
	struct BinaryTree* lchild;
	struct BinaryTree* rchild;
};
void StackInit(struct Stack* ps)
{
	ps->flat = 0;
	ps->next = NULL;
}
void PushBack(struct Stack* ps, struct BinaryTree* root)
{
	struct Stack* pp = ps;
	struct Stack* tmp=(struct Stack*)malloc(sizeof(struct Stack));
	tmp->flat = 0;
	tmp->next = NULL;
	tmp->value = root;
	while (ps->next!=NULL)
	{
		ps=ps->next;
	}
	ps->next=tmp;
}
StackDataType PopBack(struct Stack* ps)
{
	struct Stack* cur = ps->next;
	if (cur == NULL)
	{
		return;
	}
	if (cur->next==NULL)
	{
		StackDataType tt = cur->value;
		ps->next = NULL;
		free(cur);
		return tt;
	}
	struct Stack* prev = NULL;
	while (cur->next!=NULL)
	{
		prev = cur;
		cur=cur->next;
	}
	StackDataType tt = cur->value;
	prev->next = NULL;
	free(cur);
	return tt;
}
int EmployStack(struct Stack* ps)
{
	if (ps->next == NULL)
	{
		return 0;
	}
	return 1;
}
void PrevTraveBinaryTree(struct BinaryTree* root)
{
	if (root==NULL)
	{
		return;
	}
	printf("%c->", root->val);
	PrevTraveBinaryTree(root->lchild);
	PrevTraveBinaryTree(root->rchild);
}
int BinaryTreeNULL(struct BinaryTree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->lchild==NULL&&root->rchild==NULL)
	{
		printf("%c ",root->val);
		return 1;
	}
	else
	{
		return BinaryTreeNULL(root->lchild) + BinaryTreeNULL(root->rchild);
	}
}
int BinaryTreeHight(struct BinaryTree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeHight(root->lchild) > BinaryTreeHight(root->rchild) ? BinaryTreeHight(root->lchild)+1 : BinaryTreeHight(root->rchild)+1;
}
struct BinaryTree* CopyBinaryTree(struct BinaryTree* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	struct BinaryTree* tmp = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
	tmp->val = root->val;
	tmp->lchild = CopyBinaryTree(root->lchild);
	tmp->rchild = CopyBinaryTree(root->rchild);
	return tmp;
}
void DeleteBinaryTree(struct BinaryTree* root)
{
	if (root == NULL)
	{
		return;
	}
	DeleteBinaryTree(root->lchild);
	DeleteBinaryTree(root->rchild);
	printf("%c ", root->val);
	free(root);
	root = NULL;
}
void StackTraveBinaryTree(struct BinaryTree* root)
{
	struct Stack zhang;
	StackInit(&zhang);
	PushBack(&zhang,root);
	while (EmployStack(&zhang))
	{
		struct BinaryTree* ps = PopBack(&zhang);
		if (ps->rchild != NULL)
		{
			PushBack(&zhang, ps->rchild);
		}
		if (ps->lchild != NULL)
		{
			PushBack(&zhang, ps->lchild);
		}
		printf("%c ",ps->val);
	}
}
void test()
{
	struct BinaryTree a1 = {'A',NULL,NULL};
	struct BinaryTree a2 = { 'B',NULL,NULL };
	struct BinaryTree a3 = { 'C',NULL,NULL };
	struct BinaryTree a4 = { 'D',NULL,NULL };
	struct BinaryTree a5 = { 'E',NULL,NULL };
	struct BinaryTree a6 = { 'F',NULL,NULL };
	struct BinaryTree a7 = { 'G',NULL,NULL };
	struct BinaryTree a8 = { 'H',NULL,NULL };
	//a1.val = 'A';
	//a2.val = 'B';
	//a3.val = 'C';
	//a4.val = 'D';
	//a5.val = 'E';
	//a6.val = 'F';
	//a7.val = 'G';
	//a8.val = 'H';
	a1.lchild = &a2;
	a1.rchild = &a6;
	a2.lchild = NULL;
	a2.rchild = &a3;
	a3.lchild = &a4;
	a3.rchild = &a5;
	a4.lchild = NULL;
	a4.rchild = NULL;
	a5.lchild = NULL;
	a5.rchild = NULL;
	a6.lchild = NULL;
	a6.rchild = &a7;
	a7.lchild = NULL;
	a7.rchild = &a8;
	a8.lchild = NULL;
	a8.rchild = NULL;
	//PrevTraveBinaryTree(&a1);
	//printf("%d", BinaryTreeNULL(&a1));
	//printf("%d", BinaryTreeHight(&a1));
	/*struct BinaryTree* copy=CopyBinaryTree(&a1);*/
	/*PrevTraveBinaryTree(copy);*/
	/*DeleteBinaryTree(copy);*/
	StackTraveBinaryTree(&a1);
}//A B C D E F G H
int main(int arg,char* argv[])
{
	//int i = 0;
	//for (i = 0; i < arg; i++)
	//{
	//	printf("argv[%d]=%s\n", i, argv[i]);
	//}
	test();
	return 0;
}
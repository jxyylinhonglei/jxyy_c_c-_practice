#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int DataType;

struct DuLNode
{
	struct DuLNode* next;
	struct DuLNode* perv;
	DataType data;
};
void DuLInit(struct DuLNode** ps);//初始化头指针
void DuLLPrint(struct DuLNode* ps);//打印链表
void DuLListPushBack(struct DuLNode** ps, DataType x);//尾插
void DuLListPushFront(struct DuLNode** ps, DataType x);//头插
void DuLListPopBack(struct DuLNode** ps);//尾删
void DuLListPopFront(struct DuLNode** ps);//头删
void DuLListInsert(struct DuLNode** ps, int pos, DataType x);
void DuLListDelete(struct DuLNode** ps, int pos);//任意删
void DestoryList(struct DuLNode** ps);//销毁链表

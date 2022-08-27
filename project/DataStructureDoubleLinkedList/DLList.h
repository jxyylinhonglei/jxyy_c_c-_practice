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
void DuLInit(struct DuLNode** ps);//��ʼ��ͷָ��
void DuLLPrint(struct DuLNode* ps);//��ӡ����
void DuLListPushBack(struct DuLNode** ps, DataType x);//β��
void DuLListPushFront(struct DuLNode** ps, DataType x);//ͷ��
void DuLListPopBack(struct DuLNode** ps);//βɾ
void DuLListPopFront(struct DuLNode** ps);//ͷɾ
void DuLListInsert(struct DuLNode** ps, int pos, DataType x);
void DuLListDelete(struct DuLNode** ps, int pos);//����ɾ
void DestoryList(struct DuLNode** ps);//��������

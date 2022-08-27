#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int ElementType;
struct StackNode
{
	ElementType data;
	struct StackNode* next;
};
void LiskInit(struct StackNode* ps);//��ʼ��ͷ�ڵ�
void LiskPrintElement(struct StackNode* ps);//��ӡ��ӡ������
void LiskPushBack(struct StackNode* ps, ElementType x);//β��
void LiskPopBack(struct StackNode* ps);//βɾ
void LiskPushFront(struct StackNode* ps, ElementType x);//ͷ��
void LiskPopFront(struct StackNode* ps);//ͷɾ
void LiskInsert(struct StackNode* ps, int pos, ElementType x);//�����
void LiskDelete(struct StackNode* ps, int pos);//����ɾ

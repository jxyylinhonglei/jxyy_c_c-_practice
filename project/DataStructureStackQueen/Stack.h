#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int DataType;
struct Stack
{
	DataType* data;
	int capacity;
	int top;
};
void StackInit(struct Stack** ps);//��ʼ��ջ
void StackPush(struct Stack** ps, DataType x);//ѹջ
void Stackpop(struct Stack** ps);//��ջ
DataType GetTop(struct Stack* ps);//ȡջ��Ԫ��
int StackSize(struct Stack* ps);//��ջ��Ԫ�ظ���
bool StackEmpty(struct Stack* ps);//�ж��Ƿ�Ϊ��
void StackDestory(struct Stack** ps);//����ջ

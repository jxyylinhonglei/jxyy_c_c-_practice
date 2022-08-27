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
void StackInit(struct Stack** ps);//初始化栈
void StackPush(struct Stack** ps, DataType x);//压栈
void Stackpop(struct Stack** ps);//出栈
DataType GetTop(struct Stack* ps);//取栈顶元素
int StackSize(struct Stack* ps);//求栈中元素个数
bool StackEmpty(struct Stack* ps);//判断是否为空
void StackDestory(struct Stack** ps);//销毁栈

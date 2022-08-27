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
void LiskInit(struct StackNode* ps);//初始化头节点
void LiskPrintElement(struct StackNode* ps);//打印打印数据域
void LiskPushBack(struct StackNode* ps, ElementType x);//尾插
void LiskPopBack(struct StackNode* ps);//尾删
void LiskPushFront(struct StackNode* ps, ElementType x);//头插
void LiskPopFront(struct StackNode* ps);//头删
void LiskInsert(struct StackNode* ps, int pos, ElementType x);//任意插
void LiskDelete(struct StackNode* ps, int pos);//任意删

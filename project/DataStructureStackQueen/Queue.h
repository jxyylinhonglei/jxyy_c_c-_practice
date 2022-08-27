#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int QDataType;
struct QueueNode
{
	QDataType data;
	struct QueueNode* Node;
};
struct Queue
{
	struct QueueNode* head;
	struct QueueNode* tail;
};
void QueueInit(struct Queue* ps);//初始化
void QueuePush(struct Queue* ps,QDataType x);//入队
void QueuePop(struct Queue* ps);//出队
QDataType QueueTop(struct Queue* ps);//取头元素
bool QueueEmpty(struct Queue* ps);//判断是否为空
int QueueSize(struct Queue* ps);//计算队中元素个数
void QueueDertory(struct Queue* ps);//销毁队列

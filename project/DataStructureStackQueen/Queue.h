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
void QueueInit(struct Queue* ps);//��ʼ��
void QueuePush(struct Queue* ps,QDataType x);//���
void QueuePop(struct Queue* ps);//����
QDataType QueueTop(struct Queue* ps);//ȡͷԪ��
bool QueueEmpty(struct Queue* ps);//�ж��Ƿ�Ϊ��
int QueueSize(struct Queue* ps);//�������Ԫ�ظ���
void QueueDertory(struct Queue* ps);//���ٶ���

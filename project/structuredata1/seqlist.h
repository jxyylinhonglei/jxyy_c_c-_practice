#pragma once
//#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//typedef int SLDatatype;��̬˳���
//#define N 10
//struct Seqlist
//{
//	int arr[10];
//	int size;
//};
//void Seqlistpushbck(struct Seqlist* ps);
typedef int SLDatatype;
struct Seqlist
{
	SLDatatype* array;
	int size;//��Ч����
	int capacity;//����
};
void SeqlistInit(struct Seqlist* s);//��ʼ���ṹ��
void SeqlistPrint(struct Seqlist* ps);//��ӡ��
void SeqlistPushback(struct Seqlist* ps, SLDatatype x);//β��
void SeqlistPopback(struct Seqlist* ps);//βɾ
void SeqlistPushFront(struct Seqlist* ps, SLDatatype x);//ͷ��
void SeqlistPopFront(struct Seqlist* ps);//ͷɾ
void SeqlistInsert(struct Seqlist* ps, int pos, SLDatatype y);//����λ�ò���
void SeqlistErase(struct Seqlist* ps, int pos);//����λ��ɾ��
void SeqlistDestory(struct Seqlist* ps);//���˳���

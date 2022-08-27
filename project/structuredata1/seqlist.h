#pragma once
//#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//typedef int SLDatatype;静态顺序表
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
	int size;//有效数据
	int capacity;//容量
};
void SeqlistInit(struct Seqlist* s);//初始化结构体
void SeqlistPrint(struct Seqlist* ps);//打印表
void SeqlistPushback(struct Seqlist* ps, SLDatatype x);//尾插
void SeqlistPopback(struct Seqlist* ps);//尾删
void SeqlistPushFront(struct Seqlist* ps, SLDatatype x);//头插
void SeqlistPopFront(struct Seqlist* ps);//头删
void SeqlistInsert(struct Seqlist* ps, int pos, SLDatatype y);//任意位置插入
void SeqlistErase(struct Seqlist* ps, int pos);//任意位置删除
void SeqlistDestory(struct Seqlist* ps);//清空顺序表

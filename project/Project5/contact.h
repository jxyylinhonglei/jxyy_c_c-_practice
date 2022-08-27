#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct contact
{
	char name[10];
	char sex[4];
	int age;
	char addr[10];
	char tele[12];
};
struct con
{
	int site;
	int capacity;
	struct contact* add;
};
void my_memset(struct contact* ps);
void add_contact(struct con* ps);
void show_contact(struct con* ps);
void dele_contact(struct con* ps);
void search_contact(struct con* ps);
void modify_contact(struct con* ps);
void save_contact(struct con* ps);
void read_contact(struct con* ps);
//void sort(struct con* ps);
#include"seqlist.h"
void SeqlistCheck(struct Seqlist* ps)
{
	int* arr = NULL;
	if (ps->size == ps->capacity)
	{
		ps->capacity += 2;
		arr = (SLDatatype*)realloc(ps->array, sizeof(SLDatatype) * ps->capacity);
		if (arr == NULL)
		{
			printf("À©ÈÝÊ§°Ü\n");
			exit(-1);
		}
		else
		{
			ps->array = arr;
		}
	}
}

void SeqlistInit(struct Seqlist* s)
{
	s->array = NULL;
	s->size = 0;
	s->capacity = 0;
	s->array = (SLDatatype*)malloc(sizeof(SLDatatype) * 4);
	if (s->array == NULL)
	{
		printf("ÉêÇëÊ§°Ü\n");
		exit(-1);
	}
	s->capacity = 4;
	s->size = 0;
}
void SeqlistPrint(struct Seqlist* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%4d", ps->array[i]);
	}
	printf("\n");
}
void SeqlistInsertElement(struct Seqlist* ps,int pos, SLDatatype x)
{
	int i = 0;
	SeqlistCheck(ps);
	for (i=ps->size;i>=pos;i--)
	{
		ps->array[i] = ps->array[i-1];
	}
	ps->array[pos-1] = x;
	ps->size++;
}
void SeqlistElementDelete(struct Seqlist* ps,int pos)
{
	int i = 0;
	for (i=pos;i<ps->size;i++)
	{
		ps->array[i-1] = ps->array[i];
	}
	ps->size--;
}
void SeqlistPushBack(struct Seqlist* ps, SLDatatype x)//Î²²å
{
	SeqlistInsertElement(ps, ps->size+1, x);
}
void SeqlistPushFront(struct Seqlist* ps, SLDatatype x)
{
	SeqlistInsertElement(ps,1,x);
}
void SeqlistInsert(struct Seqlist* ps, int pos, SLDatatype y)
{
	SeqlistInsertElement(ps,pos,y);
}
void SeqlistPopback(struct Seqlist* ps)
{
	SeqlistElementDelete(ps, ps->size);
}
void SeqlistPopFront(struct Seqlist* ps)
{
	SeqlistElementDelete(ps,1);
}
void SeqlistErase(struct Seqlist* ps, int pos)
{
	SeqlistElementDelete(ps, pos);
}
void SeqlistDestory(struct Seqlist* ps)
{
	if (!ps->array)
	{
		free(ps->array);
		ps->array = NULL;
	}
	ps->size = 0;
}
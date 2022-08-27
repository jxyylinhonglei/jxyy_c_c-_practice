#include"Stack.h"
void StackInit(struct Stack** ps)
{
	(*ps)->top =0;
	(*ps)->capacity = 2;
	DataType* arr = (DataType*)malloc(sizeof(DataType) * (*ps)->capacity);
	if (arr == NULL)
	{
		printf("ÉêÇëÊ§°Ü\n");
		exit(-1);
	}
	else
		(*ps)->data = arr;
}
void CheckCapacity(struct Stack** ps)
{
	struct Stack* NewNode = *ps;
	if (NewNode->capacity == NewNode->top)
	{
		NewNode->capacity += 2;
		DataType* Tmp = (DataType*)realloc( NewNode->data,sizeof(DataType)* NewNode->capacity);
		if (Tmp == NULL)
		{
			printf("ÉêÇëÊ§°Ü\n");
			exit(-1);
		}
		else
			NewNode->data = Tmp;
	}
}
void StackPush(struct Stack** ps, DataType x)
{
	CheckCapacity(ps);
	struct Stack* NewNode = *ps;
	NewNode->data[NewNode->top] = x;
	(NewNode->top)++;
}
void Stackpop(struct Stack** ps)
{
	struct Stack* NewNode = *ps;
	printf("%d", NewNode->data[NewNode->top - 1]);
	NewNode->top--;
}
DataType GetTop(struct Stack* ps)
{
	return ps->data[ps->top - 1];
}
int StackSize(struct Stack* ps)
{
	return ps->top;
}
bool StackEmpty(struct Stack* ps)
{
	return ps->top == 0;//ÕæÎª¿Õ£¬¼ÙÎª·Ç¿Õ
}
void StackDestory(struct Stack** ps)
{
	struct Stack* pp = *ps;
	pp->top = 0;
	free(pp->data);
	pp->data = NULL;
	free(*ps);
	(*ps) = NULL;
}
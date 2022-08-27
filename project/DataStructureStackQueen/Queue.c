#include"Queue.h"
void QueueInit(struct Queue* ps)//初始化
{
	 ps->tail = NULL;
	 ps->head = NULL;
}
void QueuePush(struct Queue* ps, QDataType x)//入队
{
	struct QueueNode* NewNode= (struct QueueNode*)malloc(sizeof(struct QueueNode));
	NewNode->data = x;
	NewNode->Node = NULL;
	if (ps->head!=NULL)
	{
			ps->tail->Node = NewNode;	
			ps->tail = NewNode;
	}
	else
	{
		ps->head = NewNode;
		ps->tail = ps->head;
	}
}
bool QueueEmpty(struct Queue* ps)//空为真非空为假
{
	if (ps->tail == NULL)//空队列
		return true;//返回真
	else
		return false;
}
void QueuePop(struct Queue* ps)//出队
{
	if (QueueEmpty(ps))//空为真非空为假
	{
		printf("此战现在为空队列");
		exit(-1);
	}
	else
	{
		if (ps->head->Node == NULL)
		{
			printf(" %d ", ps->head->data);
			free(ps->head);
			ps->tail = ps->head = NULL;
		}
		else
		{
			printf(" %d ", ps->head->data);
			struct QueueNode* pp = ps->head->Node;
			free(ps->head);
			ps->head = NULL;
			ps->head = pp;
		}
	}
}
QDataType QueueTop(struct Queue* ps)//取头元素
{
	return ps->head->data;
}
int QueueSize(struct Queue* ps)//计算队中元素个数
{
	int i = 0;
	struct QueueNode* pp = ps->head;
	while (pp)
	{
		pp = pp->Node;
		i++;
	}
	return i;
}
void QueueDertory(struct Queue* ps)//销毁队列
{
	struct QueueNode* pp = NULL;
	while (ps->tail!=ps->head)
	{
		pp = ps->head;
		ps->head = ps->head->Node;
		free(pp);
		pp = NULL;
	}
	free(ps->tail);
	ps->tail = ps->head = NULL;
}
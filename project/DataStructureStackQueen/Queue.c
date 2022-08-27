#include"Queue.h"
void QueueInit(struct Queue* ps)//��ʼ��
{
	 ps->tail = NULL;
	 ps->head = NULL;
}
void QueuePush(struct Queue* ps, QDataType x)//���
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
bool QueueEmpty(struct Queue* ps)//��Ϊ��ǿ�Ϊ��
{
	if (ps->tail == NULL)//�ն���
		return true;//������
	else
		return false;
}
void QueuePop(struct Queue* ps)//����
{
	if (QueueEmpty(ps))//��Ϊ��ǿ�Ϊ��
	{
		printf("��ս����Ϊ�ն���");
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
QDataType QueueTop(struct Queue* ps)//ȡͷԪ��
{
	return ps->head->data;
}
int QueueSize(struct Queue* ps)//�������Ԫ�ظ���
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
void QueueDertory(struct Queue* ps)//���ٶ���
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
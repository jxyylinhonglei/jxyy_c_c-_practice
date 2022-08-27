#include"Stack.h"
#include"Queue.h"
void TestStack()
{
	struct Stack* Node =(struct Stack*)malloc(sizeof(struct Stack));
	StackInit(&Node);
	StackPush(&Node, 1);
	StackPush(&Node, 2);
	StackPush(&Node, 3);
	StackPush(&Node, 4);
	StackPush(&Node, 5);
	int sz=StackSize(Node);
	printf("ջ��Ԫ�ظ���%d\n", sz);
	printf("ջ��Ԫ��%d\n", GetTop(Node));
	Stackpop(&Node);
	Stackpop(&Node);
	Stackpop(&Node);
	if (!StackEmpty(Node))
	{
		printf("ջΪ�ǿ�\n");
	}
	StackDestory(&Node);
}
void TestQueue()
{
	struct Queue qq;
	QueueInit(&qq);
	QueuePush(&qq, 1);
	QueuePush(&qq, 2);
	QueuePush(&qq, 3);//123
	QueuePush(&qq, 4);
	QueuePush(&qq, 5);
	printf("%d\n", QueueTop(&qq));
	QueuePop(&qq);
	QueuePop(&qq);
	printf("��ʱ������Ԫ����%d��\n",QueueSize(&qq));
	if (!QueueEmpty(&qq))//��Ϊ�� �ǿ�Ϊ��
	{
		printf("��ʱ������Ϊ�ǿ�\n");
	}
	else
		printf("��ʱ������Ϊ��\n");
	QueueDertory(&qq);
}
int main()
{
	//TestStack();
	TestQueue();
	return 0;
}
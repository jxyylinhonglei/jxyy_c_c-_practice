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
	printf("栈中元素个数%d\n", sz);
	printf("栈顶元素%d\n", GetTop(Node));
	Stackpop(&Node);
	Stackpop(&Node);
	Stackpop(&Node);
	if (!StackEmpty(Node))
	{
		printf("栈为非空\n");
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
	printf("此时队列中元素有%d个\n",QueueSize(&qq));
	if (!QueueEmpty(&qq))//空为真 非空为假
	{
		printf("此时队列中为非空\n");
	}
	else
		printf("此时队列中为空\n");
	QueueDertory(&qq);
}
int main()
{
	//TestStack();
	TestQueue();
	return 0;
}
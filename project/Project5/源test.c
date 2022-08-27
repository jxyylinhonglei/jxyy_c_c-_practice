#include"contact.h"
void meun()
{
	printf("*****1.add*************************2.dele************\n");
    printf("*****3.search**********************4.modify**********\n");
	printf("*****5.show************************6.save************\n");
	printf("*****7.sort************************0.exit************\n");
}
enum
{
	EXIT,
	ADD,
	DELE,
	SEARCH,
	MODIFY,
	SHOW,
	SAVE,
	SORT,
};
int main()
{
	int input = 0;
	struct con* ps = (struct con*)malloc(sizeof(struct con));
	ps->site = 0;
	ps->capacity = 2;
	ps->add=(struct contact*)malloc(sizeof(struct contact) *(ps->capacity));
	my_memset(ps->add);
	read_contact(ps);
	do
	{
		meun();//打印菜单
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			printf("退出\n");
			save_contact(ps);
			break;
		case ADD:
			add_contact(ps);
			break;
		case DELE:
			dele_contact(ps);
			break;
		case SEARCH:
			search_contact(ps);
			break;
		case MODIFY:
			modify_contact(ps);
			break;
		case SHOW:
			show_contact(ps);
			break;
		case SAVE:
			save_contact(ps);
			break;
		case SORT:
			//sort(ps);//地址 宽度  拷贝多少字节 函数比较
			break;
		}
	} while (input);
	free(ps->add);
	ps->add = NULL;
	free(ps);
	ps = NULL;
	return 0;
}
#define CONTAIN 4
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct contact
{
	char arr[20];
};
struct con
{
	struct contact arr[CONTAIN];
};
int main()
{
	int i = 0;
	struct con s = { 0 };
	FILE* ps = fopen("file.tex","r");
	if (ps == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	while (CONTAIN)
	{
		fputs(s.arr[i].arr, ps);
		i++;
	}

	return 0;
}
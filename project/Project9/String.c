#include<stdio.h>
#include<string.h>
#include<assert.h>
//字符串匹配，匹配成功返回子串第一个字符在主串第一个位置，否则返回-1
int BruteForce(char* str, char* sub)
{
	assert(str!=NULL&&sub!=NULL);
	int stlen = strlen(str);
	int sulen = strlen(sub);
	int i = 0;
	int j = 0;
	if (stlen == 0 || sulen == 0)
	{
		return -1;
	}
	while (i<stlen&&j<sulen)
	{
		if (*(str + i) == *(sub + j))
		{
			i++;
			j++;
		}
		else
		{
			j = 0;
			i = i - j + 1;
		}
	}
	if (j>=sulen)
	{
		return i-j;
	}
	return -1;
}
int main()
{
	char* str = "abfyiic";
	char* sub = "ygooo";
	printf("%d", BruteForce(str, sub));
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
//#include<string.h>
//#include<assert.h>
//void reverse(char * left,char * right)
//{
//	while (left<right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_move(char *arr,int k)
//{
//	assert(arr);
//	int ret = strlen(arr);
//	reverse(arr, arr + k-1);
//	reverse(arr+k, arr+ret-1);
//	reverse(arr, arr+ret-1);
//}
//int main()
//{
//	char arr[] = "abcdef";   
//	left_move(arr,3);
//	printf("%s",arr);    
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//int is_left_move(char* left, char* right)
//{
//	int len = strlen(left);
//	int i = 0;
//	for (i = 0; i < len - 1; i++)
//	{
//		int j = 0;
//		char tmp = *left;
//		for (j = 0; j < len-1; j++)
//		{
//			*(left + j) = *(left + j + 1);
//		}
//		*(left + len - 1) = tmp;
//		int a = strcmp(left, right);
//		if (a == 1)
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "cfefab";
//	int ret = is_left_move(arr1,arr2);
//	if (ret == 1)
//		printf("yes");
//	else
//		printf("no");
//	return 0;
//}#
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//int is_left_move(char* left, char* right)
//{
//	int len1 = strlen(left);
//	int len2 = strlen(right);
//	if (len1 != len2)
//	{
//		return 0;
//	}
//	strncat(left,right, 6);
//	char* ret = strstr(left, right);
//	if (ret == NULL)
//		return 0;
//	else
//		return 1;
//}
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret=is_left_move(arr1,arr2);
//	if (ret == 1)
//		printf("yes\n");
//	else
//		printf("no\n");
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//int is_left_move(char* left,char* right)
//{
//	int len1 = strlen(left);
//	int len2 = strlen(right);
//	if (len1!= len2)
//		return 0;
//	int j = 0;
//	for (j = 0; j < len1 - 1; j++)
//	{
//		char tmp = *left;
//		int i = 0;
//		for (i = 0; i < len1 - 1; i++)
//		{
//			*(left + i) = *(left + i + 1);
//		}
//		*(left + len1 - 1)=tmp;
//		int ret = strcmp(left, right);
//		if (ret == 1)
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "cdefab";
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//		printf("yes\n");
//	else
//		printf("no\n");
//	return 0;
//}
//#include<stdio.h>
//int find_num(int arr[3][3], int k,int* a,int *b)
//{
//	int x = *a;
//	int y = *b;
//	while (x<3&&y>=0)
//	{
//		if (arr[x][y] > k)
//			y--;
//		else if (arr[x][y] < k)
//			x++;
//		else
//			*a = x;
//		*b = y;
//			return 1;
//	}
//	return 0;
//}
//int main()
//{
//	int arr[3][3] = { {1,2,3},{2,3,4},{3,4,5} };
//	int k = 3;
//	int x = 0;
//	int y = 2;
//	int ret=find_num(arr, k,&x,&y);
//	if (ret == 1)
//		printf("yes,%d,%d\n",x,y);
//	else
//		printf("no\n");
//	return 0;
//}#
//#include<stdio.h>
//int my_strlen(char* arr)利用递归实现
//{
//	if (*arr != '\0')
//	{
//		return 1 + my_strlen(arr + 1);
//	}
//	else
//	{
//		return 0;
//	}
//}
//int my_strlen(char* arr)
//{
//	int count = 0;
//	while (*arr++)
//	{
//		count++;
//	}
//	return count;
//}
//#include<assert.h>
//c/*har* my_strcpy(char* arr1, char* arr2)
//{
//	assert(arr1 && arr2);
//	while (*arr1++ = *arr2++)
//	{
//		;
//	}
//	return arr1;
//}*/
//char* my_strcat(char* arr1, char* arr2)
//{
//	//找到斜杠零
//	while (*arr1)
//	{
//		arr1++;
//	}
//	while (*arr1++ = *arr2++)
//	{
//		;
//	}
//	return arr1;
//}
//int my_strcmp(char* arr1, char* arr2)
//{
//	while (*arr1 == *arr2)
//	{
//		arr1++;
//		arr2++;
//	}
//	if (*arr1 == '\0')
//		return 0;
//	return *arr1 - *arr2;
//}
//int main()
//{
//	char arr1[30]= "abcdefgh";
//	char arr2[] = "hello";
//	//int ret = my_strlen1(arr);
//	//int ret = my_strlen(arr);
//	/*printf("%d", ret);*/
//	//my_strcpy(arr1, arr2);
//	//my_strcat(arr1, arr2);
//	//printf("%s", arr1);
//	int ret = my_strcmp(arr1, arr2);
//	if (ret > 0)
//	{
//		printf("arr1>arr2");
//	}
//	else if (ret < 0)
//	{
//		printf("arr1<arr2");
//	}
//	else
//	{
//		printf("arr1=arr2");
//	}
//		return 0;
//}
//#include<stdio.h>
//char* my_strncat(char* arr1, char* arr2, int num)
//{
//	while (*arr1)
//	{
//		arr1++;
//	}
//	while (num)
//	{
//		if (*arr2 == '\0')
//		{
//			*arr1 = '\0';
//		}
//		else
//		{
//			*arr1 = *arr2;
//			arr1++;
//			arr2++;
//		}
//		num--;
//	}
//	return arr1;
//}
//int main()
//{
//	char arr1[30] = "fbuvapruv";
//	char arr2[] = "hello";
//	my_strncat(arr1, arr2, 5);
//	printf("%s", arr1);
//	return 0;
//}#
//#include<stdio.h>
//#include<assert.h>
//char* my_strstr(char* arr1, char* arr2)
//{
//	assert(arr1 != NULL);
//	assert(arr2 != NULL);
//	char* s1 = arr1;
//	char* s2 = arr2;
//	if (*arr2 == '\0')
//	{
//		return arr1;
//	}
//	while (*arr1!='\0')
//	{
//		s1 = arr1;
//		while (*s1&&*s2&&*s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return arr1;
//		}
//		if (*s1 == '\0')
//		{
//			return NULL;
//		}
//		arr1++;
//	}
//	return NULL;
//}
//int main()
//{
//	char arr1[] = "a";
//	char arr2[] = "fgh";
//	char* ret = my_strstr(arr1, arr2);
//	if (ret == NULL)
//		printf("no\n");
//	else
//		printf("yes\n");
//	return 0;
//}
 
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	char arr2[] = "csvvdkbj,vksgjhb";
//	char arr1[] = ",";
//	char arr[30] = { 0 };
//	strcpy(arr, arr2);
//	char* i = 0;
//	for (i = strtok(arr, arr1); i != NULL;i=strtok(NULL,arr1))
//	{
//		printf("%s\n", i);
//	}
//	return 0;
//}
//
//int main()
//{
//	char i = 'a';
//	char j = toupper('a');
//	printf("%c", j);
////	return 0;
////}
//int main()
//{
//	char arr[] = { 'a','v','t' };
//	char buft[99] = { 0 };
//	memcpy(buft, arr,sizeof(arr));
//	printf("%s", buft);
//	return 0;
//}
//char* my_memcpy(void* arr2, void* arr1, int num)
//{
//	while (num)
//	{
//		*(char*)arr2 = *(char*)arr1;
//		++(char*)arr2;
//		++(char*)arr1;
//		num--;
//	}
//	return arr2;
//}
//int main()
//{
//	char arr1[]= { 'a','d','g','o','e' };
//	char arr2[41] = { 0 };
//	my_memcpy(arr2, arr1, sizeof(arr1));
//	printf("%s", arr2);
//	return 0;
//}

//struct S
//{
//	int n;
//	int arr[];
//};
//int main()
//{
//	int i = 0;
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	ps->n = 100;
//	for (i = 0; i < 5; i++)
//	{
////		ps->arr[i] = i;
////	}
////	for (i = 0; i < 5; i++)
////	{
////		printf("%d", ps->arr[i]);
////	}
////	free(ps);
////	ps = NULL;
////	return 0;
////}
//#include<stdio.h>
//#include<stdlib.h>
//struct S
//{
//	int n;
//	int* arr;
//};
//int main()
//{
//	int i = 0;
//	struct S*ps=malloc(sizeof(struct S));
//	ps->arr=(int*)malloc(sizeof(int) * 5);
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d", ps->arr[i]);
//	}
//	free(ps->arr);
//	ps->arr = NULL;
//	free(ps);
//	ps = NULL;
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//#include<errno.h>
//int main()
//{
//	int n = 3;
//	FILE* pf=fopen("text.txt", "r+");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	while (n)
//	{
//		fputc('w', pf);
//		n--;
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
#include<stdio.h>
#include<string.h>
#include<errno.h>
//int main()
//{
//	int n = 3;
//	FILE* ps=fopen("text.txt", "r+");
//	if (ps == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	fputs("hello world",ps);
//	fclose(ps);
//	ps = NULL;
//	return 0;
//}
int main()
{
	char arr[200] = { 0 };
	int i = 2;
	FILE* ps=fopen("text.txt", "r+");
	if (ps == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	while (i)
	{
		fgets(arr, 150, ps);
		printf("%s", arr);
		i--;
	}
	fclose(ps);
	ps = NULL;
	return 0;
}
//int main()
//{
//	char arr[] = "hello world1";
//	FILE* ps=fopen("text.txt","r+");
//	if (ps == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	fprintf(ps,"%s",arr);
//	fclose(ps);
//	ps = NULL;
//	return 0;
//}
//#include<stdio.h>
//int cmp(const void* e1,const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//void swap(char* buft1,char* buft2,int wight)
//{
//	int i = 0;
//	for (i = 0; i < wight; i++)
//	{
//		char tmp = *buft1;
//		*buft1  = *buft2;
//		*buft2  = tmp;
//		buft1++;
//		buft2++;
//	}
//}
//void my_bubble(void* e1, int wight, int sz, int (*cmp)(void* e2, void* e3))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz-1-i; j++)
//		{
//			if (cmp((char*)e1+j*wight,(char*)e1+wight*(j+1))>0)
//				swap((char*)e1 + j * wight, (char*)e1 + wight * (j + 1),wight);
//		}
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[] = { 2,4,6,7,9,0,1 };
//	int sz = sizeof(arr);
//	my_bubble(arr,sizeof(arr[0]),sz,cmp);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a[5] = { 5,8,9,2,6 };
//	int i, j;
//	int temp;
//	int sz = sizeof(a) / sizeof(a[0]);
//	for (i = 0; i < sz-1; i++)
//	{
//		for (j =i; j < sz-1-i; j++)
//		{
//			if (a[j] > a[j+1])
//			{
//				temp = a[j];
//				a[j] = a[j+1];
//				a[j+1] = temp;
//			}
//		}
//	}
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d  ", a[i]);
//	}
//	return 0;
//}
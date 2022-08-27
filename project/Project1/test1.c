#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//void swap(char * buft1,char * buft2,int wigth)
//{
//	int i = 0;
//    for(i=0;i<wigth;i++)
//	{
//		char tmp = *buft1;
//		*buft1 = *buft2;
//		*buft2 = tmp;
//		buft1++;
//		buft2++;
//		
//	}
//}
//void bubble_sort(void * base,int num,int wigth,int (*p)(const void  * e1,const void * e2))
//{
//	int i = 0;
//	for (i = 0;i<num - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			if (p((char*)base + j * wigth, (char*)base + (j + 1) * wigth) > 0)
//				swap((char*)base + j * wigth, (char*)base + (j + 1) * wigth,wigth);
//		}
//	}
//}
//Print(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%2d", *(arr + i));
//	}
//}
//void test1()
//{
//	int arr[] = { 6,7,0,1,3,2,9,5,4,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//	Print(arr, sz);
//}
//int main()
//{
//	test1();
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	int i = 0;
//	for (i = 0; i < 10000; i++)
//	{
//		int tmp = i;
//		int total = 0;
//		int sum = 0;
//		while (tmp)
//		{
//			tmp= tmp / 10;
//			total++;
//		}
//		tmp = i;
//		while (tmp)
//		{
//			sum += (int)pow(tmp % 10, total);
//			tmp = tmp / 10;
//		}
//		if (sum==i)
//			printf("%d\n", sum);
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int n = 0;
//	scanf_s("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		for (j = 0; j < n-1-i; j++)
//		{
//			printf(" ");
//		}
//		int k = 0;
//		for (k = 0; k <2*i+1; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 0; i < n-1; i++)
//	{
//		 int j = 0;
//		for (j = 0; j <i+1; j++)
//		{
//			printf(" ");
//		}
//		 int k = 0;
//		for (k = 0; k <2*(n-1-i)-1; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//void swap(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left<right)
//	{
//		while ((left<right)&&arr[left] % 2 == 0)//偶数
//		{
//			left++;
//		}
//		while ((left < right)&&arr[right] % 2== 1)//奇数
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//	}
//	}
//}
//int main()
//{
//	int arr[] = { 2,5,8,1,3,9,4,7,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	swap(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//		printf("%2d", arr[i]);
//	return 0;
//}
//#include<stdio.h>
//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;}
//
//void swap(char* buft1, char* buft2, int widht)
//{
//	int i = 0;
//	for (i = 0; i < widht; i++)
//	{
//		char tmp = *buft1;
//		*buft1 = *buft2;
//		*buft2 = tmp;
//		buft1++;
//		buft2++;
//	}
//}
//void my_bubble(void* e1, int sz, int widht, int (*cmp)(void* buft1, void* buft2))
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (cmp((char*)e1 + j * widht, (char*)e1 + widht * (j + 1)) > 0)
//			{
//				swap((char*)e1 + j * widht, (char*)e1 + widht * (j + 1), widht);
//			}
//		}
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[] = { 2,4,6,7,9,0,1 };
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	my_bubble(arr,sz, sizeof(arr[0]), cmp);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	return 0;
//}
//#include<stdio.h>
//void func(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d",&(*(arr + i)));
//	}
//}
//int compare(int* arr,int sz)
//{
//	int tmp = *arr;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if (tmp < *(arr + i))
//		{
//			tmp = *(arr + i);
//		}
//	}
//	return tmp;
//}int find(int* arr, int sz,int tmp)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		if (tmp == *(arr + i))
//			{
//			return i + 1;
//			}
//	}
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int iMax = 0;
//	int Max = 0;
//	func(arr,sz);
//	Max = compare(arr,sz);
//    iMax = find(arr,sz,Max);
//	printf("%d", iMax);
//	printf("%d", Max);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	int tmp = 0;
//	int i = 0;
//	int a = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	tmp = arr[0];
//	for (i = 1; i < 10; i++)
//	{
//		if (tmp < arr[i])
//			tmp = arr[i];
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if (tmp == arr[i])
//			a = i;
//	}
//	printf("最大值为%d", tmp);
//	printf("最大值为%d",a);
//	return 0;
//}
//#include<stdio.h>
//int test(int a)
//{
//	if (a < 3)
//		return 1;
//	else
//		return test(a - 1) + test(a - 2);
//}
//int main()
//{
//	int a = 0;
//	scanf_s("%d", &a);
//	printf("%d",test(a));
//	return 0;
//}
//#include<stdio.h>
//void PrintArray(int* arr,int x)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		printf(" %d ", *(arr+i));
//	}
//}
//void BubbleSort(int* arr,int a)
//{
//	int i ,j= 0;
//	for (i = 0; i < a; i++)
//	{
//		for (j = i; j < a; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//void test()
//{
//	int arr[10] = { 5,6,1,2,7,9,0,3,4,8 };
//	//BubbleSort(arr,sizeof(arr));
//	PrintArray(arr, sizeof(arr));
//}
//int main()
//{
//	//test();
//	int i = 0;
//	int arr[10] = { 5,6,1,2,7,9,0,3,4,8 };
//	for (i = 0; i < sizeof(arr); i++)
//	{
//		printf(" %d ",arr[i]);
//	}
//	return 0;
//}
#include<stdio.h>
int removeElement(int* nums,int numsSize,int val)
{
	int cur = 0;
	int prev = 0;
	if (numsSize == 0)
		return 0;
	while (cur < numsSize)
	{
		if (nums[cur] == val)
			cur++;
		else
		{
			nums[prev] = nums[cur];
			cur++;
			prev++;
		}
	}
	return prev;
}
int removeDuplicated(int* nums, int numsSize)
{
	int cur = 1;
	int des = 0;
	int prev = 0;
	if (numsSize < 2)
		return 0;
	while (cur < numsSize)
	{
		if (nums[prev] != nums[cur])
		{
			nums[des] = nums[prev];
			cur++;
			prev++;
			des++;
		}
		else
		{
			cur++;
			prev++;
		}
	}
	nums[des] = nums[prev];
	des++;
	return des;
}
int* addToArrayForm(int* A, int ASize, int K)//returnSize
{
	int KK = K;
	int Ki = 0;//算K中有多少位
	int next = 0;//进位
	int i = 1;//计数
	while (KK)
	{
		KK /= 10;
		Ki++;
	}
	int lenth = Ki > ASize? Ki:ASize;
	/*printf("%d\n",lenth);*///2151  806
	int* returnSize = (int*)malloc(sizeof(int)*(lenth+1));
	while (i<=ASize)
	{
		int k = K;
		k = k%10;
		returnSize[lenth+1-i] =  (k + A[ASize - i] + next)%10;
		if (k + A[ASize - i] + next > 9)
			next = 1;
		else
			next = 0;
		i++;
		K /= 10;
	}
	returnSize[0] = next;
	/*int left = 0;
	int right = lenth ;
	while (left<right)
	{
		int tmp=returnSize[left];
		returnSize[left] = returnSize[right];
		returnSize[right] = tmp;
		left++;
		right--;
	}*/
	return returnSize;
}
//时间复杂度为o(n),空间复杂度为o(1)
int* SingleNumber(int* num,int numSize)//求这个数组中只出现一次的数字（数组中只有两个数字出现一次，其他的都出现了两次）
{
	int m = 0;
	int i = 0;
	int n = 0;
	for (int i = 0; i < numSize; i++)
	{
		m ^= num[i];
	}
	while (n < 32)
	{
		if (m & (1 << n))
		{
			break;
		}
		n++;
	}
	int x1 = 0;
	int x2 = 0;
	for (int j = 0; j < numSize; j++)
	{
		if (num[j]& (1 << n))
		{
			x1 ^= num[j];
		}
		else
			x2 ^= num[j];
	}
	int* arr = (int*)malloc(sizeof(int) * 2);
	arr[0] = x1;
	arr[1] = x2;
	return arr;
}
int main()
{
	/*int i = 0;
	int j = 0;
	int nums[] = { 7,7,3};
	i = removeDuplicated(nums, sizeof(nums) / sizeof(nums[0]));
	while (i)
	{
		printf("%d", nums[j]);
		j++;
		i--;
	}*/
	//int i = 0;
	//int num[] = { 2,1,5,1 };
	//int K=906;
 //   int* arr = addToArrayForm(num,sizeof(num)/sizeof(num[0]),K);//int* addToArrayForm(int* A, int ASize, int K)
	//free(arr);
	//arr = NULL;
	int num[] = { 2,2,6,4,8,8,4,7 };
	int* arr=SingleNumber(num, sizeof(num) / sizeof(num[0]));
	printf("%d %d", arr[0], arr[1]);
	return 0;
}

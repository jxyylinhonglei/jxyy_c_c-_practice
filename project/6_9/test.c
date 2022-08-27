#include<stdio.h>
void PrintArray(int* arr, int x)
{
	int i = 0;
	for (i = 0; i < x; i++)
	{
		printf("%d", *(arr + i));
	}
}
void BubbleSort(int* arr, int a)
{
	int i, j = 0;
	for (i = 0; i < a-1; i++)
	{
		for (j = 0; j < a-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
void test()
{
	int arr[10] = { 5,6,1,2,7,9,0,3,4,8 }; 
	BubbleSort(arr,sizeof(arr)/sizeof(int));
	PrintArray(arr, sizeof(arr) / sizeof(int));
}
int main()
{
	test();
	return 0;
}
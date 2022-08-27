#include<stdio.h>
//void InsertSort(int* arr,int sz)//插入排序
//{
//	int end = 0;
//	for (end = 0; end < sz - 1; end++)
//	{
//		if (arr[end] > arr[end + 1])
//		{
//			int tmp = arr[end + 1];
//			while (end>-1)
//			{
//				if (arr[end] > tmp)
//				{
//					arr[end + 1] = arr[end];
//					end--;
//				}
//				else
//				{
//					arr[end + 1] = tmp;
//					break;
//				}
//			}
//			arr[end + 1] = tmp;
//		}
//	}
//}
//void PrintArr(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void test()
//{
//	int arr[] = { 5,9,7,0,3,4 };
//	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
//	PrintArr(arr, sizeof(arr) / sizeof(arr[0]));
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<stdio.h>
//void InsertSort(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		if(arr[i]>arr[i+1])
//			{
//				int tmp=arr[i+1];
//				while (i>-1)
//				{
//					arr[i+1]=arr[i];
//						if (arr[i] >tmp)
//						{
//							i--;
//						}
//						else
//						{
//							arr[i+1] = tmp;
//							break;
//						}
//				}
//				arr[i + 1] = tmp;
//			}
//	}
//}
//void ShellSort(int* arr,int sz)//希尔排序
//{
//	int gap = sz;
//	while (gap>1)
//	{
//		gap = gap / 2;
//		int i = 0;
//		for (i = 0; i < sz - 1; i++)
//		{
//			if (arr[i] > arr[i + gap]&&(i + gap < sz))
//			{
//				int tmp = arr[i + gap];
//				while (i > -1)
//				{
//					arr[i + gap] = arr[i];
//					if (arr[i] > tmp)
//					{
//						i -= gap;
//					}
//					else
//					{
//						arr[i + gap] = tmp;
//						break;
//					}
//				}
//				arr[i + gap] = tmp;
//			}
//		}
//	}
//}
//void Swap(int* p1,int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//void DownAdjust(int* arr, int sz,int i)//向下调整算法前提是左右子树都是小堆
//{//建小堆
//	int parent = i;
//	int chile = 2 * parent+ 1;
//	while (chile<sz)
//	{
//		if (arr[chile] > arr[chile + 1]&&chile+1<sz)
//		{
//			if (arr[parent] > arr[chile + 1])
//			{
//				Swap(&arr[chile + 1], &arr[parent]);//交换使父亲最小
//				parent = chile + 1;//继续循环
//				chile = 2 * parent + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else
//		{
//			if (arr[parent] > arr[chile])
//			{
//				Swap(&arr[chile], &arr[parent]);//交换使父亲最小
//				parent = chile;//继续循环
//				chile = 2 * parent + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//}
//void CreateHeap(int* arr, int sz)//建堆，但左右子树不是小堆或者大堆时从最后一个父节点向下调整（非叶子节点）
//{
//	int i = 0;
//	for (i = (sz - 1 - 1) / 2; i > -1; i--)//需要知道最后一个父节点
//	{
//		DownAdjust(arr,sz,i);
//	}
//}
//void ArrayPrint(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void test()
//{
//	//int arr[] = { 9,7,8,0,77,2,11,66,3,5,4,6 };
//	//InsertSort(arr, sizeof(arr) / sizeof(int));
//	//ShellSort(arr, sizeof(arr) / sizeof(int));27,15,19,18,28,34,65,49,25,37
//	int arr[] = {11,9,10,7,2,3,4,0};
//	//DownAdjust(arr, sizeof(arr) / sizeof(int),0);
//	CreateHeap(arr, sizeof(arr) / sizeof(int));
//	ArrayPrint(arr, sizeof(arr) / sizeof(int));
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<stdio.h>
//void Swap(int* p1,int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//void AdjustDown(int* arr,int sz,int i)
//{
//	int parent = i;
//	int child = 2 * parent + 1;
//	while (child<sz)
//	{
//		if (arr[child] > arr[child + 1]&&child+1<sz)
//		{
//			if (arr[parent] > arr[child+1])
//			{
//				Swap(&arr[parent], &arr[child + 1]);
//				parent = child + 1;
//				child = 2 * parent + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else
//		{
//			if (arr[parent] > arr[child])
//			{
//				Swap(&arr[parent], &arr[child]);
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//}
//void SmartHeapSort(int* arr,int sz)
//{
//	int i = 0;
//	for(i=2;i>-1;i--)
//	AdjustDown(arr,sz,i);
//}
//void ArrayPrint(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void test()
//{
//	int arr[] = {30,5,19,10,11,20,6};
//	//AdjustDown(arr,sizeof(arr)/sizeof(int),0);
//	SmartHeapSort(arr, sizeof(arr) / sizeof(int));
//	ArrayPrint(arr, sizeof(arr) / sizeof(int));
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<stdio.h>
//void ArrayPrint(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void  Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//void AdjustDownShortHeap(int* arr,int sz,int i)//向下调整法前提是子树都是堆排序
//{//小堆排序
//	int parent = i;
//	int child = 2 * parent + 1;
//	while (child < sz)
//	{
//		if (arr[child] >arr[child + 1]&&child+1<sz)
//		{
//			if (arr[child + 1] < arr[parent])
//			{
//				Swap(&arr[child + 1], &arr[parent]);
//				parent = child + 1;
//				child = 2 * parent + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else//左子树小于等于右子树
//		{
//			if (arr[child] < arr[parent])
//			{
//				Swap(&arr[child], &arr[parent]);
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//}
//void AdjustDownLongHeap(int* arr, int sz, int i)
//{
//	int parent = i;
//	int child = 2 * parent + 1;
//		while (child < sz)
//		{
//			if (child + 1 == sz)
//			{
//				if (arr[child] > arr[parent])
//				{
//					Swap(&arr[child], &arr[parent]);
//				}
//			}
//			if (arr[child] > arr[child + 1] && child + 1 < sz)
//			{
//				if (arr[child] > arr[parent])
//				{
//					Swap(&arr[child], &arr[parent]);
//					parent = child;
//					child = 2 * parent + 1;
//				}
//				else
//				{
//					break;
//				}
//			}
//			else//左子树小于等于右子树
//			{
//				if (arr[child + 1] > arr[parent] && child + 1 < sz)
//				{
//					Swap(&arr[child + 1], &arr[parent]);
//					parent = child + 1;
//					child = 2 * parent + 1;
//				}
//				else
//				{
//					break;
//				}
//			}
//		}
//}
//void CreateHeap(int* arr, int sz)
//{
//	for (int i = (sz-1)/2; i >= 0; i--)
//	{
//		AdjustDownShortHeap(arr,sz,i);
//		/*AdjustDownLongHeap(arr, sz, i);*/
//	}
//}
//void HeapSort(int* arr, int sz)
//{
//	/*int left = 0;
//	int right = sz - 1;
//	CreateHeap(arr,sz);
//	while (left<right)
//	{
//		Swap(&arr[left], &arr[right]);
//		left++;
//		right--;
//		AdjustDownLongHeap(arr, right + 1, left);
//	}*/
//	CreateHeap(arr, sz);
//	int end = sz - 1;
//	while (end>0)
//	{
//		Swap(&arr[0], &arr[end]);
//		//AdjustDownLongHeap(arr,end,0);
//		AdjustDownShortHeap(arr, end, 0);
//		end--;
//	}
//}
//void test()
//{
//	int arr[] = {16,11,9,0,5,6,1,77,4,55,7};
//	//CreateHeap(arr, sizeof(arr) / sizeof(int));
//	HeapSort(arr, sizeof(arr) / sizeof(int));
//	ArrayPrint(arr, sizeof(arr) / sizeof(int));
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<stdio.h>
//void InsertSort(int* arr,int sz)
//{//升序
//	int end = 0;
//	int i = 0;
//	while (i<sz-1)
//	{
//		end = i;
//		if (arr[end] > arr[end + 1])
//		{
//			int tmp = arr[end + 1];
//			while (end>=0)
//			{
//				arr[end + 1] = arr[end];
//				if (tmp > arr[end])
//				{
//					break;
//				}
//				end--;
//			}
//			arr[end + 1] = tmp;
//		}
//		i++;
//	}
//}
//void ShellSort(int* arr,int sz)
//{
//	int gap = sz;
//	int end = 0;
//	int i = 0;
//	while (gap>0)
//	{
//		gap = gap / 2;//6,3,1
//		i = 0;
//		while (i<sz-1)
//		{
//			end = i;
//			if (arr[end] > arr[end + gap]&& end + gap<sz)
//			{
//				int tmp=arr[end + gap];
//				while (end>=0)
//				{
//					arr[end + gap] = arr[end];
//					if (arr[end] < tmp)
//					{
//						break;
//					}
//					end -= gap;
//				}
//				arr[end + gap] = tmp;
//			}
//			i++;
//		}
//	}
//}
//void Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//void AdjustDownShortHeap(int* arr,int sz,int i)//前提是左右子树都是小堆或者大堆
//{//建小堆
//	int parent = i;
//	int child = 2 * parent + 1;
//	while (child<sz)
//	{
//		if (arr[child] > arr[child + 1]&&child+1<sz)
//		{
//			if (arr[child + 1] < arr[parent])
//			{
//				Swap(&arr[child + 1], &arr[parent]);
//				parent = child + 1;
//				child = 2 * parent + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//		else
//		{
//			if (arr[child] < arr[parent])
//			{
//				Swap(&arr[child], &arr[parent]);
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//}
//void CreateShortHeap(int* arr, int sz)
//{
//	int i = 0;
//	for (i=(sz-1)/2;i>=0;i--)
//	{
//		AdjustDownShortHeap(arr,sz,i);
//	}
//}
//void ArrayPrint(int* arr, int sz);
//void ShortHeapSort(int* arr,int sz)
//{
//	CreateShortHeap(arr, sz);
//	//ArrayPrint(arr, sz);
//	int end = 0;
//	while (end<sz)
//	{
//		Swap(&arr[0], &arr[sz - end-1]);
//		end++;
//	//	ArrayPrint(arr, sz);
//		AdjustDownShortHeap(arr, sz-end, 0);
//		//ArrayPrint(arr, sz);
//	}
//}
//void ArrayPrint(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0;i < sz; i++)
//	{
//		printf("%d ",arr[i]);
//	}
//	printf("\n");
//}
//void SelectSort(int* arr,int sz)
//{
//	int max = 0,min=0,i=0,begin=0,end=sz-1;//找到最大一的个数的下标
//	while (begin<end)
//	{
//		max=begin;
//		min =end;
//		for (i =begin; i <= end; i++)
//		{
//			if (arr[max] < arr[i])
//			{
//				max = i;
//			}
//			if (arr[min] > arr[i])
//			{
//				min = i;
//			}
//		}
//			Swap(&arr[max], &arr[end]);
//			if (min == end)
//			{
//				min = max;
//			}
//			Swap(&arr[min], &arr[begin]);
//			begin++;
//			end--;
//	}
//}
//void SelectSort(int* arr,int sz)
//{
//	int begin = 0;
//	int end = sz - 1;
//	int i = 0;
//	int max = begin;
//	int min = end;
//	while (begin < end)
//	{
//		for (i = begin; i <= end; i++)
//		{
//			if (arr[max] < arr[i])
//			{
//				max = i;
//			}
//			if (arr[min] > arr[i])
//			{
//				min = i;
//			}
//		}
//		Swap(&arr[max], &arr[end]);
//		if (min == end)
//		{
//			min = max;
//		}
//		Swap(&arr[min], &arr[begin]);
//		begin++;
//		end--;
//	}	
//}
//void QuickSort(int* arr,int left,int right)
//{
//	if (left == right+1)
//	{
//		return;
//	}
//	int begin =left;
//	int end = right;
//	int key = arr[begin];
//	while (begin<end)
//	{
//		while (arr[end] > key)//右指针找币key小的值
//		{
//			end--;
//		}
//		arr[begin] = arr[end];
//		while (arr[begin] < key)//左指针找比key大的值
//		{
//			begin++;
//		}
//		arr[end] = arr[begin];
//	}
//	arr[end] = key;
//	QuickSort(arr,0,end-1);
//	QuickSort(arr,end+1,right);
//}
//void test()
//{
//	//int arr[] = { 5,6,1,8,12,7,-5 };//9,77,0,4,,2,3
//	//InsertSort(arr,sizeof(arr)/sizeof(int));
//	/*ShellSort(arr, sizeof(arr) / sizeof(int));*/
//	//CreateShortHeap(arr, sizeof(arr) / sizeof(int));
//	/*int arr[] = { 12,4,5,7,9,6,11,15 };
//	AdjustDown(arr, sizeof(arr) / sizeof(int), 0);*/
//	/*ShortHeapSort(arr, sizeof(arr) / sizeof(int));*/
//	//int arr[] = { 5,4,3,2,1 };
//	//SelectSort(arr, sizeof(arr) / sizeof(int));
//	int arr[] = { 12,4,5,7,9,6,11,15 };
//	QuickSort(arr,0,sizeof(arr) / sizeof(int)-1);
//	ArrayPrint(arr, sizeof(arr) / sizeof(int));
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<stdio.h>
//void Swap(int* p1, int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//void SelectSort(int* arr,int sz)
//{
//	int min = 0;
//	int max = 0;
//	int left = 0;
//	int right = sz - 1;
//	int i = 0;
//	while (left<right)
//	{
//		i=max = min = left;
//		while (i<=right)
//		{
//			if (arr[i] < arr[min])
//			{
//				min = i;
//			}
//			if (arr[i] > arr[max])
//			{
//				max = i;
//			}
//			i++;
//		}
//		Swap(&arr[left],&arr[min]);
//		if (arr[max] == arr[left])
//		{
//			max = min;
//		}
//		Swap(&arr[right],&arr[max]);
//		left++;
//		right--;
//	}
//}
//void QuickSort1(int*arr,int le,int ri)//挖坑法
//{
//	if (le >= ri)
//	{
//		return;
//	}
//	int left = le;
//	int right = ri;
//	int begin = left;
//	int end = right;
//	int pivot = left;
//	int key = arr[pivot];
//	while (begin <end)
//	{
//		while (arr[end]>=key&& begin < end)//右指针找小
//		{
//			end--;
//		}
//		Swap(&arr[end],&arr[pivot]);
//		pivot =end;//记录坑位
//		while (arr[begin]<=key&& begin < end)//左指针找大
//		{
//			begin++;
//		}
//		Swap(&arr[begin],&arr[pivot]);
//		pivot = begin;
//	}
//	arr[pivot] = key;
//	QuickSort1(arr, left, pivot - 1);
//	QuickSort1(arr, pivot+1, right);
//}
//void ArrayPrint(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//void QuickSort(int* arr, int le, int ri)
//{
//	int left = le, right = ri, end = ri, begin = le;
//	int pivot = left;
//	int key = arr[left];
//	if (le >= ri)
//	{
//		return NULL;
//	}
//	while (begin < end)
//	{
//		while (arr[end]>=key&&begin<end)
//		{
//			end--;
//		}
//		Swap(&arr[end], &arr[pivot]);
//		pivot = end;
//		while (arr[begin] <= key&&begin<end)
//		{
//			begin++;
//		}
//		Swap(&arr[begin], &arr[pivot]);
//		pivot = begin;
//	}
//	arr[pivot] = key;
//	QuickSort(arr,left,pivot-1);
//	QuickSort(arr, pivot + 1, right);
//}
//void _MergeSort(int* arr, int* tmp, int left,int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int mid =(left+right) >> 1;
//	_MergeSort(arr, tmp,left,mid);
//	_MergeSort(arr, tmp,mid+1,right);
//	int i = left;
//	int begin1 = left;
//	int begin2 = mid + 1;
//	int end1 = mid;
//	int end2 = right;
//	while (begin1<=end1&&begin2<=end2)
//	{
//		if (arr[begin1]>arr[begin2])
//		{
//			tmp[i] = arr[begin2];
//			begin2++;
//		}
//		else
//		{
//			tmp[i] = arr[begin1];
//			begin1++;
//		}
//		i++;
//	}
//	while (begin1 <= end1)
//	{
//		tmp[i++] = arr[begin1++];
//		/*begin1++;
//		i++;*/
//	}
//	while (begin2 <= end2)
//	{
//		tmp[i] = arr[begin2];
//		begin2++;
//		i++;
//	}
//	for (int j=left;j<=right;j++)
//	{
//		arr[j] = tmp[j];
//	}
//}
//void MergeSort(int* arr, int sz)
//{
//	int* tmp = (int*)malloc(sizeof(int) * sz);
//	_MergeSort(arr,tmp,0,sz-1);
//	free(tmp);
//}
//void test()
//{
//	int arr[] = { 2,5,9,3,4,2 };
//	//SelectSort(arr,sizeof(arr)/sizeof(int));
//  QuickSort(arr,0,sizeof(arr) / sizeof(int)-1);
//	//MergeSort(arr, sizeof(arr) / sizeof(int));
//	ArrayPrint(arr, sizeof(arr) / sizeof(int));
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<stdio.h>
void Swap(int* p1,int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//void QuickSort(int* arr,int left,int right)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int begin = left;
//	int end =right;
//	int pivot = left;
//	int key = arr[pivot];
//	while (begin<end)
//	{
//		while (arr[end] >= key && begin < end)
//		{
//			end--;
//		}
//		Swap(&arr[end], &arr[pivot]);
//		pivot = end;
//		while (arr[begin] <= key && begin < end)
//		{
//			begin++;
//		}
//		Swap(&arr[begin], &arr[pivot]);
//		pivot = begin;
//	}
//	arr[pivot] = key;
//	QuickSort(arr,left,pivot-1);
//	QuickSort(arr,pivot+1,right);
//}
void _MergeSort(int* arr, int* tmp, int left,int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) >> 1;
	_MergeSort(arr,tmp,left,mid);
	_MergeSort(arr,tmp,mid+1,right);
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] > arr[begin2])
		{
			tmp[i] = arr[begin2];
			begin2++;
		}
		else
		{
			tmp[i] = arr[begin1];
			begin1++;
		}
		i++;
	}
	while (begin1 <= end1)
	{
		tmp[i] = arr[begin1];
		i++;
		begin1++;
	}
	while (begin2 <= end2)
	{
		tmp[i] = arr[begin2];
		i++;
		begin2++;
	}
	int j = 0;
	for (j = left; j <= right; j++)
	{
		arr[j] = tmp[j];
	}
}
void MergeSort(int* arr,int sz)
{
	int* tmp = (int*)malloc(sizeof(int) * sz);
	_MergeSort(arr,tmp,0,sz-1);
	free(tmp);
}
void ArrayPrint(int* arr,int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ",arr[i]);
	}
}
void test()
{
	int arr[] = { 5,9,6,3,8,-5,11,54,2 };
	MergeSort(arr, sizeof(arr) / sizeof(int));
	//QuickSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
	ArrayPrint(arr,sizeof(arr)/sizeof(int));
}
int main()
{
	test();
	return 0;
}
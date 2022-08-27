#include<stdio.h>
int c_sum(int a,int b)//从a开始，b结束
{
	int sum = 0;
	int i = a;
	while (i<=b)
	{
		sum = sum + i;
		i = i + 1;
	}
	return sum;
}
void print(int i, int j)//从i打印到j
{
	while (i<=j)
	{
		printf("%d ", i);
		i++;
	}
	printf("\n");
}
void test_1(int in)
{
	int i = 1;
	int j = 1;
	int k = in;
	int tmp = 0;
	while (i<100)
	{
		j = 1;
		while (j < 100)
		{
			if (i != j)
			{
				tmp = c_sum(i, j);
			}
			if (tmp == k)
			{
				/*addele(ps,i,j);*/
				print(i,j);
			}
			j = j + 1;
		}
		i++;
	}
}
void test()
{
	int in = 0;
	printf("输入一个两位数的整数\n");
	scanf_s("%d", &in);
	test_1(in);
}
int main()
{
	//test();
	double tmp1 = 77 * 250 * (12000 - 4263) + 98 * 250 * 10800 + 117 * 150 * (11200 - 4532) + 103 * 150 * (6400 - 2663) * 0.3391 + 129 * 150 * (6800 - 2791) * 0.3391;
	double tmp2 = 145 * 250 * (12800 - 5288) + 156 * 250 * (12800 - 5268) + 167 * 250 * (13600 - 5533) + 178 * 250 * (14000 - 5685) + 126 * 75 * 10400 + 133 * 75 * 7200 + 103 * 150 * (6400 - 2663) * 0.6709 + 129 * 150 * (6800 - 2791)*0.6709;
	printf("%f,%f",tmp1,tmp2);
	return 0;
}
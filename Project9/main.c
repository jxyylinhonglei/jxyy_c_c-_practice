#include<stdio.h>//uncle-lu
#include<stdlib.h>
//���Է��֣�������x,y�ض��Ǵ�������ķ��飬��С��x�ض�����С��y���䣬�ڶ�С��x�ض��͵ڶ�С��y���䣬���Կ�������ֱ�Ӵ���ͬ�����Է��֣����統ǰ�߶α��ཻ������������߶αض�Ҳ�ཻ��
//���Կ��Խ��߶����򣬶����ҳ��ཻ�߶ε�������һ����-Megumin
int x[100100], y[100010];
int n, m;
int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b; //��С��������
	//return *(int *)b - *(int *)a; �ɴ�С����
}//objective 1����Ҫʹ��qsort��������Ӧ��дһ��cmp�����Ը���ôд��

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)scanf("%d", &x[i]);
	for (int i = 1; i <= n; ++i)scanf("%d", &y[i]);

	//objective1.2��x��y�������¿�
	qsort(x, n, sizeof(int), cmp);
	qsort(y, n, sizeof(int), cmp);

	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int x_1, y_1;
		scanf("%d %d", &x_1, &y_1);

		int l = 0, r = n;
		while (l < r)
		{
			int mid = (l + r) / 2;//objective 2���
			/*
			 * ʹ�ò���ж��߶��Ƿ��ཻ  �ж��߶��Ƿ��ཻ�İ취:https://www.cnblogs.com/CielWater/p/10961803.html
			 * ����ཻ��ö��������
			 * ������ཻ��ö��������
			 * �Ķ�������վ��գ�
			 */
			if ((long long)y[mid] + (long long)x[mid] * (-1 * y[mid] / x[mid]) >= (long long)y[mid])
				l = mid + 1;//�������
			else r = mid;//�������
		}
		//objective 3ʲô�����ȫ�����ཻ��
		  // if((long long)______+(long long)_______ >= (long long)_________)
		printf("%d", l);
		// else printf("%d",0);
		printf("\n");
	}
	return 0;
}


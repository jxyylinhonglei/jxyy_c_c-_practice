#include<stdio.h>//uncle-lu
#include<stdlib.h>
//可以发现，给出的x,y必定是从里向外的分组，最小的x必定和最小的y搭配，第二小的x必定和第二小的y搭配，所以可以排序直接处理，同样可以发现，假如当前线段被相交，在它里面的线段必定也相交。
//所以可以将线段排序，二分找出相交线段的最靠外的那一条。-Megumin
int x[100100], y[100010];
int n, m;
int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b; //由小到大排序
	//return *(int *)b - *(int *)a; 由大到小排序
}//objective 1我们要使用qsort所以我们应该写一个cmp。所以该怎么写？

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)scanf("%d", &x[i]);
	for (int i = 1; i <= n; ++i)scanf("%d", &y[i]);

	//objective1.2对x，y排序，填下空
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
			int mid = (l + r) / 2;//objective 2填空
			/*
			 * 使用叉积判断线段是否相交  判断线段是否相交的办法:https://www.cnblogs.com/CielWater/p/10961803.html
			 * 如果相交，枚举右区间
			 * 如果不相交，枚举左区间
			 * 阅读以上网站填空：
			 */
			if ((long long)y[mid] + (long long)x[mid] * (-1 * y[mid] / x[mid]) >= (long long)y[mid])
				l = mid + 1;//处理二分
			else r = mid;//处理二分
		}
		//objective 3什么情况完全不会相交？
		  // if((long long)______+(long long)_______ >= (long long)_________)
		printf("%d", l);
		// else printf("%d",0);
		printf("\n");
	}
	return 0;
}


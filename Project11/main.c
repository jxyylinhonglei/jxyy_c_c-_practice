#include<stdio.h>
#include <climits>
const int INF= INT_MAX;
const int N=5;
//点与点之间的距离
int dist[5];//记录最短路径的距离
int p[5];//记录前驱，更形象给出最短路径
int flag[5];//判断是否在S集合中
int G[5][5];
void Dijkstra(int u) {
	//初始化
	int i = 0,j=0;
	for (; i < N;i++) {
		dist[i] = G[u][i];
		flag[i] = -1;//-1代表不在S中，0代表在S中
		if (G[u][i]!=INF) {
			p[i] =0 ;
		}
		else {
			p[i] = -1;//-1代表没有前驱
		}
	}
	p[u] = -1;//起始点没有前驱
	flag[u] = 0;//将u点放入S集合中
	for (i = 1; i < N;i++) {//从剩下N-1个节点中去寻找到达u点的最短路径
		int tmp = INF,index=0;
		for (j = 0; j < N;j++) {//从V-S中找出dist距离最少的
			if (flag[j]!=0&&dist[j]<tmp) {
				tmp = dist[j];
				index = j;
			}
		}
		if (index!=0) {
			flag[index] =0 ;//将找出的放入S中
			for (j = 0; j < N;j++) {
				if (flag[j]!=0&&dist[j]>dist[index]+G[index][j]) {//松弛操作
					dist[j] = dist[index] + G[index][j];
					p[j] = index;
				}
			}
		}
		else {
			break;
		}
	}
}
void _print(int index) {
	printf("%d点到u点的路径为   ",index);
	while (p[index]!=-1) {
		printf("->",p[index]);
		index = p[index];
	}
	printf("\n");
}
void Print() {
	for (int i = 0; i < N;i++) {
		_print(i);
	}
}
int main() {
	int tmp[5][5] = { {0,2,5,INF,INF},{INF,0,INF,6,INF},{INF,INF,0,7,1},{INF,INF,2,0,4},{INF,INF,INF,INF,0} };
	for (int i = 0; i < 5;i++) {
		for (int j = 0; j < 5;j++) {
			G[i][j] = tmp[i][j];
		}
	}
	Dijkstra(0);
	Print();
	return 0;
}

//	= { {0,2,5,INF,INF},
//{INF,0,INF,6,INF},
//{INF,INF,0,7,1},
//{INF,INF,2,0,4},
//{INF,INF,INF,INF,0} }
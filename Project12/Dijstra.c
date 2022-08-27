#include<stdio.h>
#include<limits.h>
//int G[5][5] = {
//	{0,2,5,INT_MAX,INT_MAX},
//	{INT_MAX,0,2,6,INT_MAX},
//	{INT_MAX,INT_MAX,0,7,1},
//	{INT_MAX,INT_MAX,2,0,4},
//	{INT_MAX,INT_MAX,INT_MAX,INT_MAX,0}
//};
//int dist[5];
//int p[5];
//int flag[5];
//void dijstra(int u) {
//	//初始化操作
//	int i = 0, j = 0, index = 0,min = 0;
//	for (i = 0; i < 5;i++ ) {
//		dist[i] = G[u][i];
//		flag[i] = -1;
//		if (dist[i]==0||dist[i]==INT_MAX) {
//			p[i] = -1;
//		}
//		else {
//			p[i] = u+1;
//		}
//	}
//	flag[u] = 0;
//	for (i = 1; i < 5;i++) {//从V-S找最小的
//		index = 0; min = INT_MAX;
//		for (j = 0; j < 5;j++) {
//			if (flag[j]!=0&&min>dist[j]) {
//				min = dist[j];
//				index = j;
//			}
//		}
//		if (index==0) {
//			break;
//		}
//		flag[index] = 0;
//		for (j = 0; j < 5;j++) {
//			if (flag[j]!=0&& dist[index]!=INT_MAX&& G[index][j] !=INT_MAX&&dist[j]>dist[index]+G[index][j]) {
//				dist[j] = dist[index] + G[index][j];
//				p[j]=index;
//			}
//		}
//	}
//}
int dist[4][4];
int G[4][4] = { {0,1,INT_MAX,4},{INT_MAX,0,9,2},{3,5,0,8},{INT_MAX,INT_MAX,6,0} };
int p[4][4];
void Floyd() {
	//初始化
	int i = 0, j = 0,k=0;
	for (i = 0; i < 4;i++) {
		for (j = 0; j < 4; j++) {
			dist[i][j] = G[i][j];
			if (dist[i][j]==0|| dist[i][j] == INT_MAX) {
				p[i][j] = -1;
			}
			else {
				p[i][j] = i+1;
			}
		}
	}
	for (k = 0; k < 4;k++) {
		for (i = 0; i < 4;i++) {
			for (j = 0; j < 4; j++) {
				if (dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX &&dist[i][j]>dist[i][k]+dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					p[i][j] = p[k][j];
				}
			}
		}
	}
}
int main() {
	Floyd();
	int i = 0,j=0;
	for (i = 0; i < 4;i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	printf("\n");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	return 0;
}
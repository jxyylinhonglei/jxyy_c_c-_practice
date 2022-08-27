//#include<stdio.h>
//#include <climits>
//const int INF = INT_MAX;
//int G[4][4] = { {0,1,INT_MAX,4},{INT_MAX,0,9,2},{3,5,0,8},{INT_MAX,INT_MAX,6,0} };
//int dist[4][4];
//int p[4][4];
//const int N = 4;
//void Flyod() {
//	//初始化
//	int i = 0,j = 0,k=0;
//	for (i = 0; i < N;i++) {
//		for (j = 0; j < N;j++) {
//			dist[i][j] = G[i][j];
//			if (i==j||dist[i][j]==INF) {
//				p[i][j] = -1;
//			}
//			else {
//				p[i][j] = i+1;
//			}
//		}
//	}
//	for (k = 0; k < N;k++) {//插入N个点
//		for (i = 0; i < N;i++) {
//			for (j = 0; j < N;j++) {
//				if ( (dist[i][k] != INF && dist[k][j] != INF)&&dist[i][j]>dist[i][k]+dist[k][j]) {
//					dist[i][j] = dist[i][k] + dist[k][j];
//					p[i][j] = p[k][j];
//				}
//			}
//		}
//	}
//}
//void _print(int i,int j) {
//	if (i==p[i-1][j-1]) {
//		printf("%d->",i);
//		printf("%d->", j);
//		return;
//	}
//	_print(i,p[i-1][j-1]);
//	printf("%d->", j);
//}
//void print() {
//	int i = 0, j = 0;
//	for (i = 0; i < N;i++) {
//		for (j = 0; j < N;j++) {
//			if (i!=j) {
//				printf("%d到%d的最短路径为 %d ",i+1,j+1,dist[i][j]);
//				_print(i+1, j+1);
//				printf("\n");
//			}
//		}
//	}
//}
//int main() {
//	Flyod();
//	int i = 0, j = 0;
//	for (i = 0; i < N; i++) {
//		for (j = 0; j < N; j++) {
//			printf("%d  ",dist[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	printf("\n");
//	for (i = 0; i < N; i++) {
//		for (j = 0; j < N; j++) {
//			printf("%d  ", p[i][j]);
//		}
//		printf("\n");
//	}
//	print();
//	return 0;
//}








//#include<stdio.h>
//#include<limits.h>
//int G[4][4] = { {0,1,INT_MAX,4},{INT_MAX,0,9,2},{3,5,0,8},{INT_MAX,INT_MAX,6,0} };
//int dist[4][4];
//p[5][5];
//const int INF = INT_MAX;
//const int N = 4;
//void Floyd() {
//	//初始化
//	int i = 0, j = 0,k=0;
//	for (i = 0; i < N;i++) {
//		for (j = 0; j < N;j++) {
//			dist[i][j] = G[i][j];
//			if (dist[i][j]!=0&&dist[i][j]!=INF) {
//				p[i][j] = i+1;
//			}
//			else {
//				p[i][j] =-1 ;
//			}
//		}
//	}
//	for (k = 0; k < N;k++) {
//		for (i = 0; i < N;i++) {
//			for (j = 0; j < N;j++) {
//				if (dist[i][k] !=INF&&dist[k][j]!=INF&&dist[i][j]>dist[i][k]+dist[k][j]) {
//					dist[i][j] = dist[i][k] + dist[k][j];
//					p[i][j] = p[k][j];
//				}
//			}
//		}
//	}
//}
//int main() {
//	Floyd();
//	int i = 0, j = 0;
//	for (i = 0; i < N; i++) {
//		for (j = 0; j < N; j++) {
//			printf("%d  ", dist[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	printf("\n");
//	for (i = 0; i < N; i++) {
//		for (j = 0; j < N; j++) {
//			printf("%d  ", p[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//#include<stdio.h>
//#include<limits.h>
//int G[5][5] = { {0,2,5,INT_MAX,INT_MAX},{INT_MAX,0,2,6,INT_MAX},{INT_MAX,INT_MAX,0,7,1},{INT_MAX,INT_MAX,2,0,4},{INT_MAX,INT_MAX,INT_MAX,INT_MAX,0} };;//记录点与点之间的距离
//int dist[5];//记录节点到源点的距离
//int flag[5];//记录是否载S集合中，0代表在集合中，-1代表不在。
//int p[5];
//const int INF = INT_MAX;
//const int N = 5;
//void Dijstra(int u) {//传入源点
//	//进行初始化操作
//	int i = 0, j = 0,index=0,min=0;
//	for (i = 0; i < N;i++) {
//		dist[i] = G[u][i];
//		flag[i] = -1;
//		if (dist[i]==INF||dist[i]==0) {
//			p[i] = -1;
//		}
//		else {
//			p[i] = u + 1;
//		}
//	}
//	//将u加入到S集合中
//	flag[u] = 0;
//	//从剩下N-1个节点中去寻找到达u点的最短路径
//	for (i = 1; i < N;i++) {
//		//贪心思想从V-S集合中找到dist[]最小的
//		index = 0,min=INT_MAX;
//		for (j = 0; j < N;j++) {
//			if (flag[j]!=0&&min>dist[j]) {
//				min = dist[j];
//				index = j;
//			}
//		}
//		if (index == 0) {//没有在V-S集合中找到距离源点最小值
//			break;
//		}
//		flag[index] = 0;//将dist[]最小的点加入到S中
//		for (j = 0; j < N;j++) {//进行松弛操作
//			if (flag[j]!=0&& dist[index] !=INF&& G[index][j] !=INF&&dist[j]>dist[index]+G[index][j]) {
//				dist[j] = dist[index] + G[index][j];
//				p[j] = index + 1;//记录前驱
//			}
//		}
//	}
//}
//void  show(i) {//打印最短路径
//	if (p[i]==-1) {
//		printf("%d->",i+1);
//		return;
//	}
//	show(p[i]-1);
//	printf("%d->", i + 1);
//}
//void showPath(int u) {
//	int i=0;
//	for (i = 0; i < N;i++) {
//		printf("%d到%d的最短路径为%d  ",i+1,u+1,dist[i]);
//		show(i);
//		printf("\n");
//	}
//}
//int main() {
//	Dijstra(0);
//	showPath(0);
//	return 0;
//}

#include<stdio.h>
#include<limits.h>
int G[4][4]= { {0,1,INT_MAX,4},{INT_MAX,0,9,2},{3,5,0,8},{INT_MAX,INT_MAX,6,0} };//记录两点之间的距离
int p[4][4];//记录前驱
int dist[4][4];//最短距离
const int INF = INT_MAX;
const int N = 4;
void Floyd() {
	//初始化
	int i = 0, j = 0,k=0;
	for (i = 0; i < N;i++) {
		for (j = 0; j < N;j++) {
			dist[i][j] = G[i][j];
			if (dist[i][j]==INF||dist[i][j]==0) {
				p[i][j] = -1;
			}
			else {
				p[i][j] =i+1 ;
			}
		}
	}
	////进行插点	
	for (k = 0; k < N;k++) {
		for (i = 0; i < N;i++) {
			for (j = 0; j < N; j++) {
				//进行松弛操作
				if (dist[i][k] !=INF&& dist[k][j]!=INF &&dist[i][j]>dist[i][k]+ dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					//记录前驱
					p[i][j] = p[k][j];
				}
			}
		}
	}


}
int main() {
	Floyd();
	int i = 0, j = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d  ", dist[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d  ", p[i][j]);
		}
		printf("\n");
	}
	return 0;
}
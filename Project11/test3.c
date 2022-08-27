//#include<stdio.h>
//#include<limits.h>
//const int INF = INT_MAX;
//const int N=5;//记录有多少个点
//int G[5][5]={ {0,2,5,INT_MAX,INT_MAX},{INT_MAX,0,2,6,INT_MAX},{INT_MAX,INT_MAX,0,7,1},{INT_MAX,INT_MAX,2,0,4},{INT_MAX,INT_MAX,INT_MAX,INT_MAX,0} };//用来储存两点之间的距离
//int dist[5];//用来储存源点到个点的最短距离
//int p[5];//用来记录前驱
//int flag[5];//用来判断是否在S集合中
//void Dijkstra(int u) {
//	//初始化
//	int i = 0, j = 0, index = 0, min = 0;
//	for (i = 0; i < N;i++) {
//		dist[i] = G[u][i];
//		flag[i] = -1;
//		if (dist[i]==INF|| dist[i]==0) {
//			p[i] = -1;
//		}
//		else {
//			p[i] = u;
//		}
//	}
//	flag[u] = 0;
//	//从剩下的N-1个点中去寻找距离·U的最短路径
//	for (i = 1; i < N;i++) {
//		//基于贪心思想从dist中找最小值,并记录下标与值
//		min = INF; index = 0;
//		for (j = 0; j < N;j++) {
//			if (flag[j]!=0&&min>dist[j]) {
//				min = dist[i];
//				index = j;
//			}
//		}
//		if (index==0) {//说明V-S中没有元素了
//			break;
//		}
//		//将从V-S中中出距离源点最小值找出，放入S集合中
//		flag[index] = 0;
//		//进行松弛操作
//		for (j = 0; j < N;j++) {
//			if (flag[j]!=0&& dist[index]!=INF&& G[index][j] !=INF&&dist[j]>dist[index]+G[index][j]) {//从V-S中进行松弛操作
//				dist[j] = dist[index] + G[index][j];
//				p[j] = index;
//			}
//		}
//	}
//}
//void _print(int i) {
//	if (p[i]==-1) {
//		printf("%d->",i+1);
//		return;
//	}
//	_print(p[i]);
//	printf("%d->",i+1);
//}
//void print(int u) {
//	int i = 0;
//	for (i = 0; i < N;i++) {
//		printf("%d点到%d点的最短距离为%d ",i,u,dist[i]);
//		_print(i);//打印路径
//		printf("\n");
//	}
//}
//int main() {
//	Dijkstra(0);
//	print(0);
//	return 0;
//}
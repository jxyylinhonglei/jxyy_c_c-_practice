//#include<stdio.h>
//#include<limits.h>
//const int INF = INT_MAX;
//const int N=5;//��¼�ж��ٸ���
//int G[5][5]={ {0,2,5,INT_MAX,INT_MAX},{INT_MAX,0,2,6,INT_MAX},{INT_MAX,INT_MAX,0,7,1},{INT_MAX,INT_MAX,2,0,4},{INT_MAX,INT_MAX,INT_MAX,INT_MAX,0} };//������������֮��ľ���
//int dist[5];//��������Դ�㵽�������̾���
//int p[5];//������¼ǰ��
//int flag[5];//�����ж��Ƿ���S������
//void Dijkstra(int u) {
//	//��ʼ��
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
//	//��ʣ�µ�N-1������ȥѰ�Ҿ��롤U�����·��
//	for (i = 1; i < N;i++) {
//		//����̰��˼���dist������Сֵ,����¼�±���ֵ
//		min = INF; index = 0;
//		for (j = 0; j < N;j++) {
//			if (flag[j]!=0&&min>dist[j]) {
//				min = dist[i];
//				index = j;
//			}
//		}
//		if (index==0) {//˵��V-S��û��Ԫ����
//			break;
//		}
//		//����V-S���г�����Դ����Сֵ�ҳ�������S������
//		flag[index] = 0;
//		//�����ɳڲ���
//		for (j = 0; j < N;j++) {
//			if (flag[j]!=0&& dist[index]!=INF&& G[index][j] !=INF&&dist[j]>dist[index]+G[index][j]) {//��V-S�н����ɳڲ���
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
//		printf("%d�㵽%d�����̾���Ϊ%d ",i,u,dist[i]);
//		_print(i);//��ӡ·��
//		printf("\n");
//	}
//}
//int main() {
//	Dijkstra(0);
//	print(0);
//	return 0;
//}
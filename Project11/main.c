#include<stdio.h>
#include <climits>
const int INF= INT_MAX;
const int N=5;
//�����֮��ľ���
int dist[5];//��¼���·���ľ���
int p[5];//��¼ǰ����������������·��
int flag[5];//�ж��Ƿ���S������
int G[5][5];
void Dijkstra(int u) {
	//��ʼ��
	int i = 0,j=0;
	for (; i < N;i++) {
		dist[i] = G[u][i];
		flag[i] = -1;//-1������S�У�0������S��
		if (G[u][i]!=INF) {
			p[i] =0 ;
		}
		else {
			p[i] = -1;//-1����û��ǰ��
		}
	}
	p[u] = -1;//��ʼ��û��ǰ��
	flag[u] = 0;//��u�����S������
	for (i = 1; i < N;i++) {//��ʣ��N-1���ڵ���ȥѰ�ҵ���u������·��
		int tmp = INF,index=0;
		for (j = 0; j < N;j++) {//��V-S���ҳ�dist�������ٵ�
			if (flag[j]!=0&&dist[j]<tmp) {
				tmp = dist[j];
				index = j;
			}
		}
		if (index!=0) {
			flag[index] =0 ;//���ҳ��ķ���S��
			for (j = 0; j < N;j++) {
				if (flag[j]!=0&&dist[j]>dist[index]+G[index][j]) {//�ɳڲ���
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
	printf("%d�㵽u���·��Ϊ   ",index);
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
//#include<stdio.h>
//#include <climits>
//const int INF = INT_MAX;
//int G[4][4] = { {0,1,INT_MAX,4},{INT_MAX,0,9,2},{3,5,0,8},{INT_MAX,INT_MAX,6,0} };
//int dist[4][4];
//int p[4][4];
//const int N = 4;
//void Flyod() {
//	//��ʼ��
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
//	for (k = 0; k < N;k++) {//����N����
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
//				printf("%d��%d�����·��Ϊ %d ",i+1,j+1,dist[i][j]);
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
//	//��ʼ��
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
//int G[5][5] = { {0,2,5,INT_MAX,INT_MAX},{INT_MAX,0,2,6,INT_MAX},{INT_MAX,INT_MAX,0,7,1},{INT_MAX,INT_MAX,2,0,4},{INT_MAX,INT_MAX,INT_MAX,INT_MAX,0} };;//��¼�����֮��ľ���
//int dist[5];//��¼�ڵ㵽Դ��ľ���
//int flag[5];//��¼�Ƿ���S�����У�0�����ڼ����У�-1�����ڡ�
//int p[5];
//const int INF = INT_MAX;
//const int N = 5;
//void Dijstra(int u) {//����Դ��
//	//���г�ʼ������
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
//	//��u���뵽S������
//	flag[u] = 0;
//	//��ʣ��N-1���ڵ���ȥѰ�ҵ���u������·��
//	for (i = 1; i < N;i++) {
//		//̰��˼���V-S�������ҵ�dist[]��С��
//		index = 0,min=INT_MAX;
//		for (j = 0; j < N;j++) {
//			if (flag[j]!=0&&min>dist[j]) {
//				min = dist[j];
//				index = j;
//			}
//		}
//		if (index == 0) {//û����V-S�������ҵ�����Դ����Сֵ
//			break;
//		}
//		flag[index] = 0;//��dist[]��С�ĵ���뵽S��
//		for (j = 0; j < N;j++) {//�����ɳڲ���
//			if (flag[j]!=0&& dist[index] !=INF&& G[index][j] !=INF&&dist[j]>dist[index]+G[index][j]) {
//				dist[j] = dist[index] + G[index][j];
//				p[j] = index + 1;//��¼ǰ��
//			}
//		}
//	}
//}
//void  show(i) {//��ӡ���·��
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
//		printf("%d��%d�����·��Ϊ%d  ",i+1,u+1,dist[i]);
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
int G[4][4]= { {0,1,INT_MAX,4},{INT_MAX,0,9,2},{3,5,0,8},{INT_MAX,INT_MAX,6,0} };//��¼����֮��ľ���
int p[4][4];//��¼ǰ��
int dist[4][4];//��̾���
const int INF = INT_MAX;
const int N = 4;
void Floyd() {
	//��ʼ��
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
	////���в��	
	for (k = 0; k < N;k++) {
		for (i = 0; i < N;i++) {
			for (j = 0; j < N; j++) {
				//�����ɳڲ���
				if (dist[i][k] !=INF&& dist[k][j]!=INF &&dist[i][j]>dist[i][k]+ dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					//��¼ǰ��
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
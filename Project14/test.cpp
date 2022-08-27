#include<stdio.h>
#include<Windows.h>
#include<mmsystem.h>//�������ֵ�ͷ�ļ�
#include<opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>
#pragma comment(lib,"winmm.lib")//����winmm.lib�����
#include <fstream>
using namespace cv;
using namespace std;

/*
����opencvͷ�ļ�
#include<opencv2/opencv.hpp>
using namespace cv;//ʹ��cv�����ռ�
*/

/*
������־
1.��������Ŀ
2.��ӻ���ͷ�ļ�
ԭ��
	1.��ȡ��Ƶ
	2.��ȡ��Ƶ�е�ÿһ��֡��
	3.��ÿһ��֡ת�����ı��ļ�
	4.ѭ����ӡ�ı��ļ�
*/
/*
	����Ƶ��ʹ��opencv����Ƶ��ͼ����һ�㶼��ʹ��opencv��Ƶ�����ܣ���������
	opencv�ײ��ܵĻ����ϣ���װ�����׽ӿ�
		һ����C/C++�ӿ�
		һ����python�ӿ�
	3�����ļ�
*/
int main() {
//	cv::utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);//���������־
//	VideoCapture video;
//	bool ret = false;
//	ret = video.open("D:\\yeyepaodecha.mp4");
//	if (ret == false) {
//		printf("��ӡʧ��\n");
//		return -1;
//	}
//	int cols = video.get(CAP_PROP_FRAME_WIDTH);//��ȡ���
//	int rows = video.get(CAP_PROP_FRAME_HEIGHT);//��ȡ�߶�
//	Mat frameImg;//opencv���ʾͼƬ����������
//	Mat grayImg;//�ڰ�ͼƬ
//	int hSize = 10;//ÿ��10��
//	int wSize = 5;//ÿ��5��
//	char charImgs[] = "., -'`:!1+*abcdevwxyz<>():{}[]2FGHIJKLMNOPQRSTUVWXYZ%&@#$";
//	int len = 256 / strlen(charImgs);
//	int frameSize = (rows / hSize) * (cols / wSize + 1) + 1;//�����ڴ�
//	char* data = (char*)malloc(2*frameSize);
//	for (int i = 0; i < 200;i++) {
//		video.read(frameImg);
//	}
//	cvtColor(frameImg, grayImg, COLOR_BGR2GRAY);
//	int k = 0;
//	for (int row = 0; row < rows - hSize; row += hSize) {
//		for (int col = 0; col < cols - wSize; col += wSize) {
//			int value = grayImg.at<uchar>(row, col);
//			//�ѻҰ�����ȡ����֮�󣬱���ַ�
//			if ((value >= 256)) {
//				printf("������\n");
//				return -1;
//			}
//			data[k++] = charImgs[value / (len+5)];
//			if ((int)charImgs[value / len]<0) {
//				printf("%d    %c\n", charImgs[value / len], charImgs[value / len]);
//				printf("%d    %d\n",value,len);
//			}
//		}
//		data[k++] = '\n';
//	}
//	//   57���ַ�  
//	data[k++] = '\0';
//	ofstream examplefile("example.txt");
//	examplefile<<data;
//	examplefile.close();
//}


	cv::utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);//���������־
	VideoCapture video;
	bool ret = false;
	ret = video.open("D:\\mv.mp4");
	if (ret == false) {
		printf("��ӡʧ��\n");
		return -1;
	}
	int frameCount = video.get(CAP_PROP_FRAME_COUNT);//��ȡ�ж�����ͼƬ
	int cols = video.get(CAP_PROP_FRAME_WIDTH);//��ȡ���
	int rows = video.get(CAP_PROP_FRAME_HEIGHT);//��ȡ�߶�
	int fps = video.get(CAP_PROP_FPS);//��ȡ��Ƶ֡��
	Mat frameImg;//opencv���ʾͼƬ����������
	Mat grayImg;//�ڰ�ͼƬ
	int hSize = 10;//ÿ��10��
	int wSize = 5;//ÿ��5��
	char charImgs[] = "., -'`:!1+*abcdevwxyz<>():{}[]2FGHIJKLMNOPQRSTUVWXYZ%&@#$";//׼��һ���ַ����飬������ʾ�������ص�  11��  �Ҷ�0��255����13��
	int len = 256 / strlen(charImgs);
	int frameSize = (rows / hSize) * (cols / wSize + 1) + 1;//�����ڴ�
	char* data = (char*)malloc(frameSize * frameCount);
	memset(data,0x00, frameSize * frameCount);
	if (data == NULL) {
		return -1;
	}

	for (int i = 0; i < frameCount; i++) {
		char* p = data + i * frameSize;
		int k = 0;
		video.read(frameImg);//�����Ǹ��ж�ȡһ��ͼƬ
		cvtColor(frameImg, grayImg, COLOR_BGR2GRAY);//������ͼ����ת���ɺڰ�,�Ҷ�(0 255)
		for (int row = 0; row < rows - hSize; row += hSize) {
			char* p = data + i * frameSize;
			for (int col = 0; col < cols - wSize; col += wSize) {
				int value = grayImg.at<uchar>(row, col);
				//�ѻҰ�����ȡ����֮�󣬱���ַ�
				if ((value>260)) {
					printf("������\n");
					return -1;
				}
				p[k++] = charImgs[value /(len+15)];
				if ((value / (len +5))<0&&(value / (len + 15))>=57) {
					printf("%d   %d\n",value,len);
				}
			}
			p[k++] = '\n';
		}
		data[k++] = '\0';
	}
	//mciSendString(L"open D:\\mv_.mp3 alias bkmusic", NULL, 0, NULL);
	//mciSendString(L"play bkmusic repeat", NULL, 0, NULL);     //ѭ����������

	//mciSendString(L"play D:\\mv_.mp3 repeat", 0, 0, 0);

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0,0 };
	while (1) {
		for (int i = 0; i < frameCount; i++) {
			SetConsoleCursorPosition(h, pos);
			char* p = data + i * frameSize;
			printf("%s", p);
			Sleep(1000 / fps);
		}
	}
	system("pause");
	return 0;
}
























/*
	videoCapture video;//����һ���������������ͱ����ı���������Ƶ��Ƶ������ͷ
	bool ret=video.open("�ļ�·��")//���ָ�ʽ��Ƶ�ļ������Դ�
	if(ret==false){
		printf("��ʧ��");
	}
	int frameCount=video.get(CV_CAP_PROP_FRAME_COUNT);//��ȡ�ж�����ͼƬ
	int cols=video.get(CV_CAP_PROP_FEAME_WIDTH);//��ȡ���
	int rows=video.get(CV_CAP_PROP_FEAME_HEIGHT);//��ȡ�߶�
	int fps=video.get(CV_CAP_PROP_FPS)//��ȡ��Ƶ֡��
	//����һ��ͼƬ����
	Mat frameImg;//opencv���ʾͼƬ����������
	Mat grayImg;//�ڰ�ͼƬ
	for(int i=0;i<frameCount;i++){
		video.read(frameImg);//�����Ǹ��ж�ȡһ��ͼƬ
		//�й����������������Ƭ�Ǻڰ׵ģ�GPS�ǲŲ�ɫ�ġ��ڰ���Ƭ�лҶȣ�����ֻ�к����
		//��ͼƬת�����ı��ļ�,����һ��ͼƬ�����ص�̫�࣬ȫ��ת��̫���ˣ�ʹ�ò�����ÿ�������и���ȡһ���㣬ÿ�������и���ȡһ���㣩
		int hSize=10;//ÿ��10��
		int wSize=10;//ÿ��5��
		char charImgs[]=" .,-!+=*&@3$";//׼��һ���ַ����飬������ʾ�������ص�
		cvtColor(frameImg,grayImg,COLOR_BGR2GRAY);//������ͼ����ת���ɺڰ�,�Ҷ�(0 255)
		int frameSize=(rows/hSize)*(cols/wSize+1)+1;//�����ڴ�
		char* data=(char*)malloc(frameSize*frameCount);
		if(data==NULL){
			return -1;
		}
		int k=0;
		for(int row=0;row<rows-hSize;row+=hSize){
			char* p=data+i*frameSize;
			for(int col=0;col<cols-wSize;col+=wSize){
				int value=grayImg.at<uchar>(row,col);
				//�ѻҰ�����ȡ����֮�󣬱���ַ�
				p[k++]=charImg[value/20]
			}
			p[k++]='\n';
		}
		p[k++]='\0';
	}
	//��������
	mciSendString("�ļ� repeat",0,0,0);
	//���
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos={0,0};
	for(int i=0;i<frameCount;i++){
		SetConsoleCursorPosition(h,pos);
		char* p=data+i*frameSize;
		printf("%s",p);
	}
*/ 

/*

test
*/
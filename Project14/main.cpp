//#include<stdio.h>
//#include<Windows.h>
//#include<mmsystem.h>//�������ֵ�ͷ�ļ�
//#include<opencv2/opencv.hpp>
//#include<graphics.h>
//#include <opencv2/core/utils/logger.hpp>
//#pragma comment(lib,"winmm.lib")//����winmm.lib�����
//using namespace cv;
//using namespace std;
//int main() {
//	cv::utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);//���������־
//	initgraph(500,400);//����һ������
//	Mat mat=imread("D:\\Sunrise.jpg");//��ȡͼƬ����ÿһ�����ص����ɫ
//	imshow("����",mat);//��ʾͼƬ
//	//moveWindow("�ƶ����ڵı���",200,200);//�ƶ�����,���⣬λ��
//	Mat result;
//	cvtColor(mat,result,COLOR_BGR2GRAY);
//	imshow("�Ҷ�", result);//��ʾͼƬ
//
//	//cvtColor(mat, result, COLOR_BGR2HSV);
//	//imshow("hsv", result);//��ʾͼƬ
//	waitKey();
//	closegraph();
//	return 0;
//}
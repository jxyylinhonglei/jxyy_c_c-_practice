#include<stdio.h>
#include<Windows.h>
#include<mmsystem.h>//播放音乐的头文件
#include<opencv2/opencv.hpp>
#include <opencv2/core/utils/logger.hpp>
#pragma comment(lib,"winmm.lib")//加载winmm.lib这个库
#include <fstream>
using namespace cv;
using namespace std;

/*
加上opencv头文件
#include<opencv2/opencv.hpp>
using namespace cv;//使用cv命名空间
*/

/*
开发日志
1.创建空项目
2.添加基础头文件
原理：
	1.读取视频
	2.读取视频中的每一个帧数
	3.把每一个帧转化成文本文件
	4.循环打印文本文件
*/
/*
	打开视频，使用opencv打开视频（图像处理一般都是使用opencv视频处理框架，军工级）
	opencv底层框架的基础上，封装了两套接口
		一套是C/C++接口
		一套是python接口
	3配置文件
*/
int main() {
//	cv::utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);//不再输出日志
//	VideoCapture video;
//	bool ret = false;
//	ret = video.open("D:\\yeyepaodecha.mp4");
//	if (ret == false) {
//		printf("打印失败\n");
//		return -1;
//	}
//	int cols = video.get(CAP_PROP_FRAME_WIDTH);//获取宽度
//	int rows = video.get(CAP_PROP_FRAME_HEIGHT);//获取高度
//	Mat frameImg;//opencv里表示图片的数据类型
//	Mat grayImg;//黑白图片
//	int hSize = 10;//每隔10行
//	int wSize = 5;//每隔5行
//	char charImgs[] = "., -'`:!1+*abcdevwxyz<>():{}[]2FGHIJKLMNOPQRSTUVWXYZ%&@#$";
//	int len = 256 / strlen(charImgs);
//	int frameSize = (rows / hSize) * (cols / wSize + 1) + 1;//分配内存
//	char* data = (char*)malloc(2*frameSize);
//	for (int i = 0; i < 200;i++) {
//		video.read(frameImg);
//	}
//	cvtColor(frameImg, grayImg, COLOR_BGR2GRAY);
//	int k = 0;
//	for (int row = 0; row < rows - hSize; row += hSize) {
//		for (int col = 0; col < cols - wSize; col += wSize) {
//			int value = grayImg.at<uchar>(row, col);
//			//把灰白像素取出来之后，变成字符
//			if ((value >= 256)) {
//				printf("出错了\n");
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
//	//   57个字符  
//	data[k++] = '\0';
//	ofstream examplefile("example.txt");
//	examplefile<<data;
//	examplefile.close();
//}


	cv::utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);//不再输出日志
	VideoCapture video;
	bool ret = false;
	ret = video.open("D:\\mv.mp4");
	if (ret == false) {
		printf("打印失败\n");
		return -1;
	}
	int frameCount = video.get(CAP_PROP_FRAME_COUNT);//获取有多少张图片
	int cols = video.get(CAP_PROP_FRAME_WIDTH);//获取宽度
	int rows = video.get(CAP_PROP_FRAME_HEIGHT);//获取高度
	int fps = video.get(CAP_PROP_FPS);//获取视频帧数
	Mat frameImg;//opencv里表示图片的数据类型
	Mat grayImg;//黑白图片
	int hSize = 10;//每隔10行
	int wSize = 5;//每隔5行
	char charImgs[] = "., -'`:!1+*abcdevwxyz<>():{}[]2FGHIJKLMNOPQRSTUVWXYZ%&@#$";//准备一个字符数组，用来表示各个像素点  11级  灰度0到255，分13级
	int len = 256 / strlen(charImgs);
	int frameSize = (rows / hSize) * (cols / wSize + 1) + 1;//分配内存
	char* data = (char*)malloc(frameSize * frameCount);
	memset(data,0x00, frameSize * frameCount);
	if (data == NULL) {
		return -1;
	}

	for (int i = 0; i < frameCount; i++) {
		char* p = data + i * frameSize;
		int k = 0;
		video.read(frameImg);//从是那个中读取一张图片
		cvtColor(frameImg, grayImg, COLOR_BGR2GRAY);//将彩蛇图排尿转换成黑白,灰度(0 255)
		for (int row = 0; row < rows - hSize; row += hSize) {
			char* p = data + i * frameSize;
			for (int col = 0; col < cols - wSize; col += wSize) {
				int value = grayImg.at<uchar>(row, col);
				//把灰白像素取出来之后，变成字符
				if ((value>260)) {
					printf("出错了\n");
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
	//mciSendString(L"play bkmusic repeat", NULL, 0, NULL);     //循环播放音乐

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
	videoCapture video;//定义一个变量，这种类型变量的变量可以视频视频与摄像头
	bool ret=video.open("文件路径")//各种格式视频文件都可以打开
	if(ret==false){
		printf("打开失败");
	}
	int frameCount=video.get(CV_CAP_PROP_FRAME_COUNT);//获取有多少张图片
	int cols=video.get(CV_CAP_PROP_FEAME_WIDTH);//获取宽度
	int rows=video.get(CV_CAP_PROP_FEAME_HEIGHT);//获取高度
	int fps=video.get(CV_CAP_PROP_FPS)//获取视频帧数
	//定义一个图片变量
	Mat frameImg;//opencv里表示图片的数据类型
	Mat grayImg;//黑白图片
	for(int i=0;i<frameCount;i++){
		video.read(frameImg);//从是那个中读取一张图片
		//中国北斗卫星拍摄的照片是黑白的，GPS是才彩色的。黑白照片有灰度，不是只有黑与白
		//把图片转换成文本文件,由于一张图片的像素点太多，全部转换太大了，使用采样（每隔多少行个点取一个点，每隔多少列个点取一个点）
		int hSize=10;//每隔10行
		int wSize=10;//每隔5行
		char charImgs[]=" .,-!+=*&@3$";//准备一个字符数组，用来表示各个像素点
		cvtColor(frameImg,grayImg,COLOR_BGR2GRAY);//将彩蛇图排尿转换成黑白,灰度(0 255)
		int frameSize=(rows/hSize)*(cols/wSize+1)+1;//分配内存
		char* data=(char*)malloc(frameSize*frameCount);
		if(data==NULL){
			return -1;
		}
		int k=0;
		for(int row=0;row<rows-hSize;row+=hSize){
			char* p=data+i*frameSize;
			for(int col=0;col<cols-wSize;col+=wSize){
				int value=grayImg.at<uchar>(row,col);
				//把灰白像素取出来之后，变成字符
				p[k++]=charImg[value/20]
			}
			p[k++]='\n';
		}
		p[k++]='\0';
	}
	//播放音乐
	mciSendString("文件 repeat",0,0,0);
	//输出
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
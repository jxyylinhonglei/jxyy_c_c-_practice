//#include<stdio.h>
//#include<Windows.h>
//#include<mmsystem.h>//播放音乐的头文件
//#include<opencv2/opencv.hpp>
//#include<graphics.h>
//#include <opencv2/core/utils/logger.hpp>
//#pragma comment(lib,"winmm.lib")//加载winmm.lib这个库
//using namespace cv;
//using namespace std;
//int main() {
//	cv::utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);//不再输出日志
//	initgraph(500,400);//创建一个窗口
//	Mat mat=imread("D:\\Sunrise.jpg");//读取图片储存每一个像素点的颜色
//	imshow("标题",mat);//显示图片
//	//moveWindow("移动窗口的标题",200,200);//移动窗口,标题，位置
//	Mat result;
//	cvtColor(mat,result,COLOR_BGR2GRAY);
//	imshow("灰度", result);//显示图片
//
//	//cvtColor(mat, result, COLOR_BGR2HSV);
//	//imshow("hsv", result);//显示图片
//	waitKey();
//	closegraph();
//	return 0;
//}
//#include <math.h>				// sin
//#include <stdint.h>				// uint64_t
//#include <vector>				// array
//#include <easyx.h>				// window
//#include <graphics.h>
//#include <conio.h>
#undef UNICODE
#include <graphics.h>
#include <conio.h>
#include<stdio.h>
int main()
{
	MOUSEMSG m;
	// ��ʼ����ͼ����
	initgraph(640, 480);
	// ���ñ���ɫΪ��ɫ
	setbkcolor(WHITE);
	// �ñ���ɫ�����Ļ
	cleardevice();
	/*setfillcolor(RED);
	fillrectangle(100, 100, 300, 150);
	settextstyle(15, 0, "΢�����");*/
	setbkmode(TRANSPARENT);
	outtextxy(150, 120, "�齱��ʼ");
	while (1) {
		m = GetMouseMsg();
		if (m.x >= 100 && m.x <= 300 && m.y >= 100 && m.y <= 150) {
			setlinecolor(BLUE);
			rectangle(90, 95, 310, 160);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.
				closegraph();
				printf("6666\n");
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ����ɫ�߿�.
			setlinecolor(WHITE);
			rectangle(90, 95, 310, 160);
		}
	}
	// ��������˳�
	_getch();
	closegraph();//�رմ���
}




//using std::vector;
//
//#define	WIDTH			800		// ��
//#define	HEIGHT			600		// ��
//
//struct Point { double x, y; };
//
//// ��ʼ�����Ƶ�
//vector<Point> controlPoints;
//
//Point operator+(const Point& a, const Point& b) {
//	return Point({ a.x + b.x, a.y + b.y });
//}
//Point operator*(double f, const Point& p) {
//	return Point({ f * p.x, f * p.y });
//}
//
//// �������ʽϵ���� C(n, k) = n! / (k!(n-k)!)
//// �������ǲ��ù�ʽ��ʹ�� Pascal's Triangle
//// [1],					n = 0
//// [1, 1],				n = 1
//// [1, 2, 1],			n = 2
//// [1, 3, 3, 1],		n = 3
//// [1, 4, 6, 4, 1],		n = 4
//int C(int n, int k) {
//	vector<int> array(n + 1, 1);
//	for (int i = 2; i <= n; i++)
//		for (int j = i - 1; j > 0; j--)
//			array[j] += array[j - 1];
//	return array[k];
//}
//
//// ���Ʊ��������ߣ����� t [0 - end_t] ��Χ
//void drawBezier(const vector<Point>& points, double end_t) {
//	if (points.size() <= 1) return;
//	int n = points.size() - 1; // �״�Ϊ���� - 1
//	setfillcolor(RED);
//	for (double t = 0.0; t <= end_t; t += 0.001) {
//		Point p{ 0 };
//		for (int k = 0; k <= n; k++)
//			p = p + C(n, k) * pow(t, k) * pow(1 - t, (double)n - k) * points[k];
//		// λ����������
//		p.x += 0.5;
//		p.y += 0.5;
//		solidcircle((int)p.x, (int)p.y, 3);
//	}
//}
//
//// �ݹ��ȡÿһ��Ŀ��Ƶ�
//void bezierLevelPoints(vector<vector<Point>>& levels, double t) {
//	vector<Point>& pre = levels.back();
//	vector<Point> next;
//	int n = pre.size();
//	if (n <= 1) return;
//
//	for (int i = 0; i < n - 1; i++) {
//		Point point = (1 - t) * pre[i] + t * pre[i + 1];
//		next.push_back(point);
//	}
//	levels.push_back(next);
//	bezierLevelPoints(levels, t);
//}
//
//// ���������¼�
//void processInput() {
//	ExMessage msg;
//	if (peekmessage(&msg, EM_MOUSE | EM_KEY)) {
//		// ��ס����϶����Ƶ�
//		if (WM_MOUSEMOVE == msg.message && msg.lbutton) {
//			for (auto& p : controlPoints) {
//				int dx = (int)p.x - msg.x;
//				int dy = (int)p.y - msg.y;
//				if (dx * dx + dy * dy < 50) {
//					p.x = msg.x;
//					p.y = msg.y;
//				}
//			}
//		}
//		// ����Ҽ����������Ƶ�
//		else if (WM_RBUTTONDOWN == msg.message && msg.rbutton) {
//			controlPoints.push_back({ (double)msg.x, (double)msg.y });
//		}
//		// ���ո�����
//		else if (WM_KEYDOWN == msg.message && msg.vkcode == VK_SPACE) {
//			controlPoints.clear();
//		}
//	}
//}
//
//// ���㡢����
//void drawControlLines(vector<vector<Point>>& levels) {
//	int k = levels.size();
//	COLORREF color[8] = { YELLOW, BROWN, CYAN, LIGHTRED, WHITE, GREEN, MAGENTA, RED };
//	for (int i = 0; i < k; i++) {
//		vector<Point> cur = levels[i];
//		int n = cur.size();
//		setlinecolor(color[i & 0XF]);
//		setfillcolor(color[i & 0XF]);
//		for (auto& point : cur)
//			solidcircle((int)(point.x + 0.5), (int)(point.y + 0.5), 3);
//		if (k <= 2) continue;
//		for (int j = 0; j < n - 1; j++)
//			line((int)(cur[j].x + 0.5), (int)(cur[j].y + 0.5), \
//				(int)(cur[j + 1].x + 0.5), (int)(cur[j + 1].y + 0.5));
//	}
//}
//
//int main() {
//	TCHAR  buf[32];
//	double t = 0.f;
//	double time = -1.57079632679489661923;   // pi / 2;
//	double deltaTime = 0.f; // ��ǰ֡����һ֡��ʱ���
//	double lastTime = 0.f;
//	double currentTime = 0.f;
//	uint64_t start, now, frequency;
//	initgraph(WIDTH, HEIGHT);
//	BeginBatchDraw();
//	QueryPerformanceCounter((LARGE_INTEGER*)&start);
//	QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
//	while (1) {
//		cleardevice();
//		QueryPerformanceCounter((LARGE_INTEGER*)&now);
//		currentTime = (double)(now - start) / frequency;
//		deltaTime = currentTime - lastTime;
//		lastTime = currentTime;
//
//		// ��֤��ͬ֡���»����ٶ�һ��
//		time += 1.5 * deltaTime;
//		t = 0.5 * (1 + sin(time));
//
//		// ��������϶����¿��Ƶ�
//		processInput();
//		// �õ�ÿһ��Ŀ��Ƶ�
//		vector<vector<Point>> levels({ controlPoints });
//		bezierLevelPoints(levels, t);
//		// ���ƿ��Ƶ㡢������
//		drawControlLines(levels);
//		// ���� 0 - t ��Χ�ڵı���������
//		drawBezier(controlPoints, t);
//
//		// ��ʾ��Ϣ
//		outtextxy(0, 0, L"  Right Mouse Button to Create Points.");
//		outtextxy(0, 16, L"  Left  Mouse Button to Drag Points.");
//		outtextxy(0, 32, L"  Press SPACE to Clear.");
//		swprintf_s(buf, _T("  t: %.3f"), t);
//		outtextxy(0, 48, buf);
//		swprintf_s(buf, _T("  time: %.0fms"), 1000 * deltaTime);
//		outtextxy(0, 64, buf);
//		swprintf_s(buf, _T("  fps: %d\n"), (int)(1.f / deltaTime));
//		outtextxy(0, 80, buf);
//		FlushBatchDraw();
//	}
//	return 0;
//}
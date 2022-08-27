//#include<graphics.h>
//#include<conio.h>
//#include<math.h>
//
//#define PI acos(-1.0)
//
//void Background();		// 背景
//void Hat();				// 帽子
//void Hair();			// 头发
//void Face();			// 脸
//void Food();			// 食物
//void Clothes();			// 衣服
//void Redface();			// 红色脸蛋
//void Eyes();			// 眼睛
//void Logo();			// 标志
//
//int main()
//{
//	initgraph(640, 640);
//	Background();
//	Clothes();
//	Hat();
//	Face();
//	Food();
//	Hair();
//	Logo();
//	_getch();
//	return 0;
//}
//
//void Background()
//{
//	setbkcolor(RGB(237, 202, 160));
//	cleardevice();
//	setfillcolor(RGB(249, 211, 172));
//	for (int i = 0; i < 10; i++)
//	{
//		bar(0, i * 65, 640, 25 + i * 65);
//		bar(i * 65, 0, 25 + i * 65, 640);
//	}
//}
//
//void Hat()
//{
//	setlinecolor(RGB(154, 97, 78));
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
//	arc(111, 31, 575, 400, 318.0 / 180 * PI, 191.5 / 180 * PI);
//	arc(97, 107, 557, 425, 352.5 / 180 * PI, 160.0 / 180 * PI);
//	setfillcolor(RGB(199, 62, 44));
//	floodfill(390, 80, RGB(154, 97, 78));
//	arc(115, 122, 522, 423, 354.0 / 180 * PI, 190.0 / 180 * PI);
//	arc(376, 206, 521, 383, 335.0 / 180 * PI, 45.0 / 180 * PI);
//	arc(461, 307, 517, 397, 275.0 / 180 * PI, 55.0 / 180 * PI);
//	setfillcolor(RGB(184, 46, 27));
//	floodfill(393, 128, RGB(154, 97, 78));
//}
//
//void Face()
//{
//	setlinecolor(RGB(154, 97, 78));
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
//	arc(157, 166, 500, 426, 189.0 / 180 * PI, 346.0 / 180 * PI);
//	arc(118, 272, 167, 334, 58.0 / 180 * PI, 317.0 / 180 * PI);
//	arc(155, 172, 267, 360, 156.0 / 180 * PI, 237.0 / 180 * PI);
//	arc(167, 177, 289, 389, 120.0 / 180 * PI, 212.0 / 180 * PI);
//	line(171, 257, 184, 222);
//	arc(160, 136, 605, 487, 106.0 / 180 * PI, 165.0 / 180 * PI);
//	arc(316, -74, 622, 274, 194.0 / 180 * PI, 259.0 / 180 * PI);
//	arc(417, 91, 610, 312, 193.0 / 180 * PI, 254.0 / 180 * PI);
//	arc(450, 298, 494, 359, 355.0 / 180 * PI, 54.0 / 180 * PI);
//	setfillcolor(RGB(254, 228, 215));
//	floodfill(315, 267, RGB(154, 97, 78));
//	setlinecolor(RGB(255, 214, 198));
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);
//	arc(165, 142, 605, 493, 108.0 / 180 * PI, 165.0 / 180 * PI);
//	arc(312, -62, 622, 280, 193.0 / 180 * PI, 259.0 / 180 * PI);
//	Redface();
//	Eyes();
//	// 耳朵
//	setlinecolor(RGB(154, 97, 78));
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 3);
//	line(136, 297, 150, 292);
//	line(150, 292, 142, 312);
//	line(142, 312, 151, 316);
//	// 脖子
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
//	line(287, 423, 287, 446);
//	line(287, 446, 321, 467);
//	line(321, 467, 360, 441);
//	line(360, 441, 359, 423);
//	setfillcolor(RGB(254, 228, 215));
//	floodfill(320, 445, RGB(154, 97, 78));
//
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 20);
//	setlinecolor(RGB(249, 210, 193));
//	arc(147, 183, 508, 433, 259.0 / 180 * PI, 280.0 / 180 * PI);
//}
//
//void Redface()
//{
//	setlinestyle(PS_SOLID, 2);
//	float H = 11.f;
//	float V = 1.f;
//	float S;
//	for (int i = 0; i < 32; i++)
//	{
//		S = (50 - i) / 100.f;
//		setlinecolor(HSVtoRGB(H, S, V));
//		circle(206, 336, i);
//		circle(443, 333, i);
//	}
//}
//
//void Eyes()
//{
//	setfillcolor(RGB(113, 102, 97));
//	solidellipse(220, 254, 248, 309);
//	setlinestyle(PS_SOLID, 8);
//	setlinecolor(RGB(113, 102, 97));
//	line(383, 289, 429, 277);
//	line(383, 289, 421, 291);
//	line(421, 291, 436, 298);
//	setlinestyle(PS_SOLID, 2);
//	// 嘴巴
//	setlinecolor(RGB(154, 97, 78));
//	setfillcolor(RGB(216, 107, 74));
//	fillellipse(310, 307, 331, 337);
//}
//
//void Food()
//{
//	setlinecolor(RGB(154, 97, 78));
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
//	setfillcolor(RGB(250, 171, 114));
//	fillellipse(243, 426, 319, 617);
//	setfillcolor(RGB(252, 164, 93));
//	fillellipse(168, 384, 243, 627);
//	setlinecolor(RGB(221, 138, 84));
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
//	for (int i = 265; i < 288; i++)
//	{
//		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, i - 265);
//		line(i, 481, 288, 481);
//	}
//	for (int i = 261; i < 283; i++)
//	{
//		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, i - 261);
//		line(i, 515, 283, 515);
//	}
//	setlinecolor(RGB(154, 97, 78));
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 3);
//	line(285, 470, 264, 481);
//	line(264, 481, 290, 488);
//	line(285, 508, 259, 515);
//	line(259, 515, 283, 523);
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 4);
//	setlinecolor(RGB(255, 212, 176));
//	line(190, 426, 190, 522);
//	line(210, 401, 210, 524);
//	line(225, 434, 225, 530);
//	// 食物袋子
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
//	setlinecolor(RGB(156, 103, 71));
//	setfillcolor(RGB(232, 187, 156));
//	line(329, 640, 325, 547);
//	line(325, 547, 164, 528);
//	line(164, 528, 155, 535);
//	line(155, 535, 156, 569);
//	line(156, 569, 312, 579);
//	line(312, 579, 325, 551);
//	line(308, 589, 306, 640);
//	line(160, 569, 154, 640);
//	floodfill(214, 554, RGB(156, 103, 71));
//	floodfill(220, 600, RGB(156, 103, 71));
//}
//
//void Hair()
//{
//	setlinecolor(RGB(154, 97, 78));
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
//	arc(132, 283, 195, 391, 172.0 / 180 * PI, 266.0 / 180 * PI);
//	arc(131, 351, 197, 445, 138.0 / 180 * PI, 257.0 / 180 * PI);
//	arc(136, 421, 183, 496, 136.0 / 180 * PI, 262.0 / 180 * PI);
//	arc(143, 461, 192, 543, 156.0 / 180 * PI, 246.0 / 180 * PI);
//	// 右边辫子
//	arc(446, 333, 491, 418, 200.0 / 180 * PI, 264.0 / 180 * PI);
//	arc(441, 382, 515, 474, 138.0 / 180 * PI, 210.0 / 180 * PI);
//	arc(430, 424, 490, 503, 125.0 / 180 * PI, 251.0 / 180 * PI);
//	arc(420, 469, 473, 539, 122.0 / 180 * PI, 250.0 / 180 * PI);
//	arc(406, 363, 503, 446, 271.0 / 180 * PI, 15.0 / 180 * PI);
//	arc(419, 416, 489, 475, 280.0 / 180 * PI, 18.0 / 180 * PI);
//	arc(410, 439, 476, 513, 262.0 / 180 * PI, 16.0 / 180 * PI);
//	arc(422, 479, 462, 536, 278.0 / 180 * PI, 5.0 / 180 * PI);
//	arc(406, 552, 452, 684, 300.0 / 180 * PI, 250.0 / 180 * PI);
//	// 蝴蝶结
//	setfillcolor(RGB(204, 62, 48));
//	fillellipse(396, 518, 431, 558);
//	fillellipse(436, 535, 479, 566);
//	fillcircle(433, 545, 9);
//	line(169, 527, 154, 540);
//	// 染头发
//	setfillcolor(RGB(254, 253, 251));
//	floodfill(167, 380, RGB(154, 97, 78));
//	floodfill(394, 187, RGB(154, 97, 78));
//	floodfill(429, 585, RGB(154, 97, 78));
//	setlinecolor(RGB(253, 247, 231));
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 14);
//	arc(120, 130, 515, 430, 20.0 / 180 * PI, 170.0 / 180 * PI);
//	arc(425, 87, 610, 305, 215.0 / 180 * PI, 254.0 / 180 * PI);
//	arc(155, 180, 560, 446, 189.0 / 180 * PI, 215.0 / 180 * PI);
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
//	setlinecolor(RGB(154, 97, 78));
//	setfillcolor(RGB(200, 82, 68));
//	fillcircle(144, 325, 4);
//	fillellipse(139, 332, 151, 373);
//	fillellipse(485, 341, 497, 385);
//	line(421, 577, 423, 607);
//	line(430, 589, 433, 629);
//}
//
//void Clothes()
//{
//	setlinecolor(RGB(140, 106, 96));
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
//	setfillcolor(RGB(204, 155, 148));
//	fillellipse(122, 427, 509, 907);
//	setfillcolor(RGB(255, 220, 216));
//	fillellipse(280, 410, 380, 758);
//	setlinecolor(RGB(191, 141, 130));
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 7);
//	ellipse(285, 412, 385, 760);
//	setlinecolor(RGB(140, 106, 96));
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
//	setfillcolor(RGB(249, 211, 172));
//	fillellipse(280, 409, 365, 530);
//	setfillcolor(RGB(202, 72, 48));
//	fillellipse(311, 475, 342, 534);
//	fillcircle(326, 475, 10);
//	line(337, 482, 346, 495);
//	line(346, 495, 365, 477);
//	line(463, 575, 466, 640);
//	line(399, 451, 434, 501);
//	line(434, 501, 400, 640);
//}
//
//void Logo()
//{
//	setlinecolor(WHITE);
//	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
//	rectangle(151, 546, 201, 593);
//	settextcolor(WHITE);
//	settextstyle(25, 0, L"微软雅黑", 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
//	setbkmode(TRANSPARENT);
//	outtextxy(154, 546, _T("@ 令"));
//	outtextxy(154, 568, _T("也 小"));
//}
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    string addBinary(string a, string b) {
        int left = a.size() - 1;
        int right = b.size() - 1;
        string ans;
        int index = 0;
        while (left >= 0 && right >= 0) {
            if (index==1) {
                if (a[left]=='1'&&b[right]=='1') {
                    ans.push_back('1');
                    index = 1;
                }
                else if (a[left] == '1' || b[right] == '1') {
                    ans.push_back('0');
                    index = 1;
                }
                else {
                    ans.push_back('1');
                    index = 0;
                }
            }
            else {
                if (a[left] == '1' && b[right] == '1') {
                    ans.push_back('0');
                    index = 1;
                }
                else if (a[left] == '1' || b[right] == '1') {
                    ans.push_back('1');
                    index = 0;
                }
                else {
                    ans.push_back('0');
                    index = 0;
                }
            }
            left--;
            right--;
        }
        if (left<0&&right<0&&index==1) {
            ans.push_back('1');
        }
        if (left<0 && right>=0) {
            while (right>=0) {
                if (index==1) {
                    if (b[right]=='1') {
                        ans.push_back('0');
                        index = 1;
                    }
                    else {
                        ans.push_back('1');
                        index = 0;
                    }
                }   
                else {
                    if (b[right] == '1') {
                        ans.push_back('1');
                        index = 0;
                    }
                    else {
                        ans.push_back('0');
                        index = 0;
                    }
                }
                right--;
            }
            if (index==1) {
                ans.push_back('1');
            }
        }
        if (right < 0 && left >= 0) {
            while (left >= 0) {
                if (index == 1) {
                    if (a[left] == '1') {
                        ans.push_back('0');
                        index = 1;
                    }
                    else {
                        ans.push_back('1');
                        index = 0;
                    }
                }
                else {
                    if (a[left] == '1') {
                        ans.push_back('1');
                        index = 0;
                    }
                    else {
                        ans.push_back('0');
                        index = 0;
                    }
                }
                left--;
            }
            if (index == 1) {
                ans.push_back('1');
            }
        }
        left = 0;
        right = ans.size() - 1;
        while (left <= right) {
            char tmp = ans[left];
            ans[left] = ans[right];
            ans[right] = tmp;
            left++;
            right--;
        }
        return ans;
    }
    int mySqrt(int x) {
        int left = 0;//3
        int right = x;//3
        while (left <= right) {//5
            int mid = left + ((right - left) >> 1);//2
            if ((long long)mid * mid > x) {
                right = mid - 1;
            }
            else if ((long long)mid *mid < x) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        return right;
    }
    void sortColors(vector<int>& nums) {
        int k = nums.size();
        while (k > 1) {
            k = k / 2;
            for (int i = 1; i < nums.size(); i++) {
                if (i - k >= 0 && nums[i] < nums[i - k]) {
                    int end = i;
                    int tmp = nums[i];
                    while (end >= k) {
                        if (nums[end] < nums[end - k]) {
                            nums[end] = nums[end - k];
                            nums[end - k] = tmp;//3 2 1   1 2 3
                        }
                        else
                        {
                            break;
                        }
                        end = end - k;
                    }
                }
            }
        }
    }
    //void _uniquePaths(int m, int n, int& ans) {
    //    if (m == 1 && n == 1) {
    //        ans++;
    //        return;
    //    }
    //    else if (m == 1 && n != 1) {
    //        _uniquePaths(m, n - 1, ans);
    //    }
    //    else if (m != 1 && n == 1) {
    //        _uniquePaths(m - 1, n, ans);
    //    }
    //    else {
    //        _uniquePaths(m - 1, n, ans);
    //        _uniquePaths(m, n - 1, ans);
    //    }
    //}
    //int uniquePaths(int m, int n) {
    //    int ans = 0;
    //    _uniquePaths(m, n, ans);
    //    return ans;
    //}
    //f(m,n)=f(m-1,n)+f(m,n-1)
    int uniquePaths(int m, int n) {
        vector<vector<int>> ans(m,vector<int>(n));
        for (int i = 0; i < m;i++) {
            ans[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            ans[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                ans[i][j] = ans[i-1][j]+ans[i][j-1];
            }
        }
        return ans[m-1][n-1];
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1,a=0,b=0,c=n,d=n,i=0;
        while (n>=1) {
            a = i, b = i, c = n, d = n;
            while (a < n && b < n && c > i && d > i) {
                int tmp1 = matrix[b][n];
                int tmp2 = matrix[n][c];
                matrix[b][n] = matrix[i][a];
                matrix[n][c] = tmp1;
                tmp1 = matrix[d][i];
                matrix[d][i] = tmp2;
                matrix[i][a] = tmp1;
                a++;
                b++;
                c--;
                d--;
            }
            n--;
            i++;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> tmp;
        vector<vector<int>> ans;
        tmp.push(root);
        int i = 0;
        while (!tmp.empty()) {
            TreeNode* ret = tmp.front();
            tmp.pop();
            if (ret) {
                tmp.push(ret->left);
                tmp.push(ret->right);
            }
        }
        return ans;
    }
//    void dfs(int cur, int target) {
//        if (target == 0) {
//            ans.push_back(ret);
//            return;
//        }
//        if (cur == tmp.size() || target < tmp[cur].first) {
//            return;
//        }
//
//        dfs(cur + 1, target);
//
//        int most = min(target /tmp[cur].first, tmp[cur].second);
//        for (int i = 1; i <= most; ++i) {
//            ret.push_back(tmp[cur].first);
//            dfs(cur + 1, target - i * tmp[cur].first);
//        }
//        for (int i = 1; i <= most; ++i) {
//            ret.pop_back();
//        }
//    }
//    void _combinationSum2( int target,int cur) {
//        if (target == 0) {
//            ans.push_back(ret);
//            return;
//        }
//        if (cur == tmp.size() || target < tmp[cur].first) {
//            return;
//        }
//       //_combinationSum2(target, cur+1);
//        //int most = min(target / tmp[cur].first, tmp[cur].second);
//        for (int i = 1; i <= tmp[cur].second;i++) {
//            ret.push_back(tmp[cur].first);
//            _combinationSum2(target-i*tmp[cur].first, cur+1);
//        }
//        //_combinationSum2(target, cur + 1);
//        for (int i = 1; i <= tmp[cur].second; i++) {
//            ret.pop_back();
//        }
//        _combinationSum2(target, cur + 1);
//    }
//    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//        sort(candidates.begin(), candidates.end());
//        for (int i = 0; i < candidates.size();i++) {
//            if (i==0) {
//                tmp.push_back(pair<int,int>(candidates[i],1));
//            }
//            else {
//                if (candidates[i-1]!= candidates[i]) {
//                    tmp.push_back(pair<int, int>(candidates[i], 1));
//                }
//                else {
//                    tmp[tmp.size() - 1].second++;
//                }
//            }
//        }
//        //for (int num : candidates) {
//        //    if (tmp.empty() || num != tmp.back().first) {
//        //       tmp.emplace_back(num, 1);
//        //    }
//        //    else {
//        //        ++tmp.back().second;
//        //    }
//        //}
//        _combinationSum2(target,0);
//        //dfs(0,target);
//        return ans;
//    }
//private:
//    vector<pair<int, int>> tmp;
//    vector<int> ret;
//    vector<vector<int>> ans;
    void DFS(int cur,int target) {
        if (target==0) {
            ans.push_back(ret);
            return;
        }
        if (cur == tmp.size() || target < tmp[cur].first) {
            return;
        }
        for (int i = 1; i <= tmp[cur].second;i++) {
            ret.push_back(tmp[cur].first);
            DFS(cur+1,target-i*tmp[cur].first);
        }
        for (int i = 0; i < tmp[cur].second;i++) {
            ret.pop_back();
        }
        DFS(cur+1,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        for (int i = 0; i < candidates.size();i++) {
            if (tmp.empty()|| candidates[i-1]!= candidates[i]) {
                tmp.emplace_back(candidates[i],1);
            }
            else {
                tmp[tmp.size()-1].second++;
            }
        }
        DFS(0,target);
        return ans;
    }
    private:
        vector<int> ret;
        vector<pair<int, int>> tmp;
        vector<vector<int>> ans;
};
void test() {
    Solution s;
    //string a = "101111";
    //string b = "10";
    //string ret=s.addBinary(a,b);
    //cout << ret << endl;
    //cout<<s.mySqrt(2147395599)<<endl;
    //vector<int> tmp = {2, 0, 2, 1, 1, 0};
    //s.sortColors(tmp);
    //cout << s.uniquePaths(19,18) << endl;
    //1,2,3],[4,5,6],[7,8,9
    //vector<vector<int>> matrix{ {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };
    //vector<vector<int>> matrix{ {1,2},{3,4} };
    //s.rotate(matrix);
    //for (int i = 0; i < matrix.size();i++) {
    //    for (int j = 0; j < matrix.size(); j++) {
    //        cout << matrix[i][j]<<" ";
    //    }
    //    cout << endl;
    //}
    vector<int> candidates = { 10,1,2,7,6,1,5 };
    vector<vector<int>> ret=s.combinationSum2(candidates,8);
    for (int i = 0; i < ret.size();i++) {
        for (int j = 0; j <ret[i].size(); j++) {
            cout <<ret[i][j]<< " ";
        }
        cout << endl;
    }
}
int main() {
    //mciSendString("open 1.mp3 alias bkmusic", NULL, 0, NULL);
    //mciSendString("play bkmusic repeat", NULL, 0, NULL);     //循环播放音乐
    test();
    system("pause");
	return 0;
}
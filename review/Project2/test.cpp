//
#include <iostream>

#include <String>
using namespace std;

#define ll long long
const int N = 1e6 + 5;
ll n, k, f[N], id[N], sum, ans;
//f[i]表示前i个数中，删除掉第i个数并且满足题目要求，删掉数最小是多少
ll head, tail, q[N];
//队首指针，队尾指针，队列

int main() {
	int k = 0,j=0;
	cin >> k >> j;
	cout << "k" << k << "j" << j << endl;
	//cin >> n >> k;
	//for (int i = 1; i <= n; i++) {
	//	ll x; cin >> x; sum += x;
	//	//正难则反，我们改变思路，
	//	//求每隔不超过k个数 就必须删去一个数 使得删去数的和最小
	//	f[i] = q[i] + x;//我们引入单调队列的思想，
	//	//单调队列即在队列中的值是单调的，要不递增要不递减，本题是递减，
	//	//因为想贪心的从最小的f[]数组继承过来，
	//	//而这个f[]数组依次保存在q[]队列中，我们取队首肯定最小
	//	while (head <= tail && q[i] > f[tail])tail--;
	//	//因为q[]队列里面的数是单调的，那么当我们把f[i]添加进队尾时，
	//	//如果队尾的元素比f[i]大，那么不保证单调了，所以把比f[i]大的队尾元素弹出，弹出即tail--
	//	q[++tail] = f[i], id[tail] = i;
	//	//f[i]加入队尾，id保存队列中元素之前在数组中的位置
	//	while (head <= tail && id[head] < i - k)head++;
	//	//队首的元素如果跟i已经超过了k的距离，
	//	//那么就不符合每隔最多k个数就必须删除一个数的规则了，故要将不合法的队首值弹出，即head++
	//}for (int i = n - k; i <= k; i++)ans = max(ans, sum - f[i]);//答案为之前所有数的总和减去f[n-k~k]之间的最小值
	//cout << ans << endl;
	//return 0;
}
// 
// 
//#include <iostream>
//#include <fstream>
//#include <math.h>
//#include <ctime>
//#include <vector>
//#include "bc_csem.h"
//int main()
//{
//    using namespace std;
//    int dn = 40;
//    int layer_number = 40;
//    std::vector<Real> T_l(layer_number - 1);
//    for (int i = 0; i < T_l.size(); i++) {
//        T_l[i] = 20 + pow(10, 0.057 * i);
//    }
//    int data_number = 100000;
//    Real allfre[40] = { 10400.0,8800.0,7200.0,6000.0,5200.0,4400.0,3600.0,2200.0,1800.0,1100.0,780.0,640.0,530.0,460.0,390.0,320.0,265.0,229.0,194.0,
//                        159.0,132.0,115.0,97.0,79.0,66.0,57.0,49.0,40.0,33.0,27.5,22.5,18.8,16.2,13.7,11.2,9.4,8.1,6.9,5.6,4.7 };
//    Real allres[16] = { 2.0,4.0,6.0,8.0,10.0,20.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,220.0 };
//    Point s = Point(0.0, 0.0, 0.0);
//    Point p = Point(50000, 0, 0);
//    std::vector<Dcomplex> e, h;
//    std::vector<Real> ar(dn);
//    std::vector<Real> phase(dn);
//    std::vector<std::vector<Real> > EP;
//    std::ofstream output("sample sets1");
//    srand(time(0));
//    for (int k = 0; k < data_number; k++)
//    {
//        EP.resize(layer_number + 1);
//        std::vector<Real> six_res(6);
//        for (int i = 0; i < six_res.size(); i++) {
//            int num = rand() % 16; six_res[i] = allres[num];
//        }
//        std::vector<Real> four_l(4);
//        for (int i = 0; i < four_l.size(); i++) {
//            int num2;
//            if (i == 0) {
//                num2 = rand() % 6; four_l[i] = 3.0 + num2;
//            }
//            else if (i == 1) {
//                num2 = rand() % 6; four_l[i] = 12.0 + num2;
//            }
//            else if (i == 2) {
//                num2 = rand() % 6; four_l[i] = 22.0 + num2;
//            }
//            else {
//                num2 = rand() % 6; four_l[i] = 32.0 + num2;
//            }
//            //std::cout<<"four_l[]: "<<four_l[i]<<std::endl;
//        }
//        for (int i = 0; i < (layer_number + 1); i++)
//        {
//            EP[i].resize(4);
//            if (i == 0)
//            {
//                EP[i][0] = 1e-12; EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = 0;
//            }
//            else if (i == 1)
//            {
//                EP[i][0] = 1 / six_res[0]; EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = EP[i - 1][3] + T_l[i - 1];
//            }
//            else if (1 < i && i < four_l[0])
//            {
//                EP[i][0] = 1 / (six_res[0] + ((i - 1) / (four_l[0] - 1.0)) * (six_res[1] - six_res[0])); EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = EP[i - 1][3] + T_l[i - 1];
//            }
//            else if (i == four_l[0])
//            {
//                EP[i][0] = 1 / six_res[1]; EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = EP[i - 1][3] + T_l[i - 1];
//            }
//            else if (four_l[0] < i && i < four_l[1])
//            {
//                EP[i][0] = 1 / (six_res[1] + ((i - four_l[0]) / (four_l[1] - four_l[0])) * (six_res[2] - six_res[1])); EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = EP[i - 1][3] + T_l[i - 1];
//            }
//            else if (i == four_l[1])
//            {
//                EP[i][0] = 1 / six_res[2]; EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = EP[i - 1][3] + T_l[i - 1];
//            }
//            else if (four_l[1] < i && i < four_l[2])
//            {
//                EP[i][0] = 1 / (six_res[2] + ((i - four_l[1]) / (four_l[2] - four_l[1])) * (six_res[3] - six_res[2])); EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = EP[i - 1][3] + T_l[i - 1];
//            }
//            else if (i == four_l[2])
//            {
//                EP[i][0] = 1 / six_res[3]; EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = EP[i - 1][3] + T_l[i - 1];
//            }
//            else if (four_l[2] < i && i < four_l[3])
//            {
//                EP[i][0] = 1 / (six_res[3] + ((i - four_l[2]) / (four_l[3] - four_l[2])) * (six_res[4] - six_res[3])); EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = EP[i - 1][3] + T_l[i - 1];
//            }
//            else if (i == four_l[3])
//            {
//                EP[i][0] = 1 / six_res[4]; EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = EP[i - 1][3] + T_l[i - 1];
//            }
//            else if (four_l[3] < i && i < 40)
//            {
//                EP[i][0] = 1 / (six_res[4] + ((i - four_l[3]) / (40.0 - four_l[3])) * (six_res[5] - six_res[4])); EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = EP[i - 1][3] + T_l[i - 1];
//            }
//            else
//            {
//                EP[i][0] = 1 / six_res[5]; EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = 1e50;
//            }
//        }
//        //std::cout<<"six_res: "<<six_res[0]<<", "<<six_res[1]<<", "<<six_res[2]<<", "<<six_res[3]<<", "<<six_res[4]<<", "<<std::endl;
//        //std::cout<<"EP[][]: "<<EP[1][0]<<", "<<EP[2][0]<<", "<<EP[3][0]<<", "<<EP[4][0]<<", "<<EP[5][0]<<", "<<EP[10][0]<<", "<<EP[15][0]<<", "<<EP[20][0]<<std::endl;
//        for (int j = 0; j < dn; j++)
//        {
//            BC_CSEM  be_csem(EP, allfre[j], 5);
//            be_csem.Set_E_H_A(p, s, 1);
//            be_csem.get_E_H(e, h);
//            ar[j] = 1.0 / (EM::mu0 * 2.0 * EM::pi * allfre[j]) * std::real((e[1] / h[0]) * conj(e[1] / h[0]));
//            phase[j] = arg(e[1] / h[0]) * 180 / pi;
//            if (phase[j] == 0) { phase[j] = -phase[j]; }
//        }
//        for (int i = 1; i < layer_number + 1; i++)
//        {
//            EP[i][0] = 1 / EP[i][0];
//        }
//        output << ar[0] << '\t' << ar[1] << '\t' << ar[2] << '\t' << ar[3] << '\t' << ar[4] << '\t' << ar[5] << '\t' << ar[6] << '\t' << ar[7] << '\t' << ar[8] << '\t' << ar[9] << '\t' <<
//            ar[10] << '\t' << ar[11] << '\t' << ar[12] << '\t' << ar[13] << '\t' << ar[14] << '\t' << ar[15] << '\t' << ar[16] << '\t' << ar[17] << '\t' << ar[18] << '\t' << ar[19] << '\t' <<
//            ar[20] << '\t' << ar[21] << '\t' << ar[22] << '\t' << ar[23] << '\t' << ar[24] << '\t' << ar[25] << '\t' << ar[26] << '\t' << ar[27] << '\t' << ar[28] << '\t' << ar[29] << '\t' <<
//            ar[30] << '\t' << ar[31] << '\t' << ar[32] << '\t' << ar[33] << '\t' << ar[34] << '\t' << ar[35] << '\t' << ar[36] << '\t' << ar[37] << '\t' << ar[38] << '\t' << ar[39] << '\t' <<
//            EP[1][0] << '\t' << EP[2][0] << '\t' << EP[3][0] << '\t' << EP[4][0] << '\t' << EP[5][0] << '\t' << EP[6][0] << '\t' << EP[7][0] << '\t' << EP[8][0] << '\t' << EP[9][0] << '\t' << EP[10][0] << '\t' <<
//            EP[11][0] << '\t' << EP[12][0] << '\t' << EP[13][0] << '\t' << EP[14][0] << '\t' << EP[15][0] << '\t' << EP[16][0] << '\t' << EP[17][0] << '\t' << EP[18][0] << '\t' << EP[19][0] << '\t' << EP[20][0] << '\t' <<
//            EP[21][0] << '\t' << EP[22][0] << '\t' << EP[23][0] << '\t' << EP[24][0] << '\t' << EP[25][0] << '\t' << EP[26][0] << '\t' << EP[27][0] << '\t' << EP[28][0] << '\t' << EP[29][0] << '\t' << EP[30][0] << '\t' <<
//            EP[31][0] << '\t' << EP[32][0] << '\t' << EP[33][0] << '\t' << EP[34][0] << '\t' << EP[35][0] << '\t' << EP[36][0] << '\t' << EP[37][0] << '\t' << EP[38][0] << '\t' << EP[39][0] << '\t' << EP[40][0] << '\n';
//        if (k % 2000 == 0) {
//            std::cout << "This is the " << k << " forward." << std::endl;
//        }
//    }
//    output.close();
//    return 0;
//}
//
//

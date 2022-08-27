
#include <iostream>
#include <fstream>
#include<math.h>
#include<ctime>
#include<vector>
#include"bc_csem.h"
int main()
{
    using namespace std;
    int dn = 40;
    int layer_number = 6;
    int mn = 40;
    int data_number = 100000;
    //std::vector<Real> allfre(dn);
    std::vector<Real> layer(mn);
    std::vector<Real> resistivity(mn);
    Real allfre[40] = { 10400.0,8800.0,7200.0,6000.0,5200.0,4400.0,3600.0,2200.0,1800.0,1100.0,780.0,640.0,530.0,460.0,390.0,320.0,265.0,229.0,194.0,
                        159.0,132.0,115.0,97.0,79.0,66.0,57.0,49.0,40.0,33.0,27.5,22.5,18.8,16.2,13.7,11.2,9.4,8.1,6.9,5.6,4.7 };
    Real allres[16] = { 2.0,4.0,6.0,8.0,10.0,20.0,40.0,60.0,80.0,100.0,120.0,140.0,160.0,180.0,200.0,220.0 };
    //Real allfre[48]={0.5,0.7,0.9,1,1.5,2,2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5,8,8.5,9,9.5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,150,200,500,900,2000,5000,8000,10000};
   /* for(int i=0;i<dn;i++)
    {
            allfre[i]=pow(10,0.104*(dn-1-i))-0.9;
        cout<<"fre"<<i<<"="<<allfre[i]<<endl;
    }*/
    Point s = Point(0.0, 0.0, 0.0);
    Point p = Point(50000, 0, 0);
    std::vector<Dcomplex> e, h;
    std::vector<Real> ar(dn);
    std::vector<std::vector<Real> > EP;
    std::ofstream output("sample sets");
    srand(time(0));
    for (int k = 0; k < data_number; k++)
    {
        EP.resize(layer_number + 1);
        for (int i = 0; i < layer_number + 1; i++)
        {
            EP[i].resize(4);
            if (i == 0)
            {
                EP[i][0] = 1e-12; EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = 0;
            }
            else if (i == layer_number)
            {
                int num = rand() % 16; EP[i][0] = 1 / (allres[num]); EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = 1e50;
            }
            else if (i == 1)
            {
                int num = rand() % 16; EP[i][0] = 1 / (allres[num]); EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = rand() % 4; EP[i][3] = EP[i - 1][3] + 50 * (EP[i][3] + 1);
            }
            else if (i == 2)
            {
                int num = rand() % 16; EP[i][0] = 1 / (allres[num]); EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = rand() % 4; EP[i][3] = EP[i - 1][3] + 50 * (EP[i][3] + 1);
            }
            else if (i == 3)
            {
                int num = rand() % 16; EP[i][0] = 1 / (allres[num]); EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = rand() % 8; EP[i][3] = EP[i - 1][3] + 50 * EP[i][3] + 100;
            }
            else if (i == 4)
            {
                int num = rand() % 16; EP[i][0] = 1 / (allres[num]); EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = rand() % 9; EP[i][3] = EP[i - 1][3] + 50 * EP[i][3] + 100;
            }
            else
            {
                int num = rand() % 16; EP[i][0] = 1 / (allres[num]); EP[i][1] = 1.0; EP[i][2] = 1.0; EP[i][3] = rand() % 9; EP[i][3] = EP[i - 1][3] + 50 * EP[i][3] + 200;
            }
        }
        for (int j = 0; j < dn; j++)
        {
            BC_CSEM  be_csem(EP, allfre[j], 5);
            be_csem.Set_E_H_A(p, s, 1);
            be_csem.get_E_H(e, h);
            ar[j] = 1.0 / (EM::mu0 * 2.0 * EM::pi * allfre[j]) * std::real((e[1] / h[0]) * conj(e[1] / h[0]));
        }
        for (int i = 1; i < layer_number + 1; i++)
        {
            EP[i][0] = 1 / EP[i][0];
        }
        for (int i = 0; i < mn; i++)
        {
            if (i == mn - 1) { layer[i] = 1e50; }
            else { layer[i] = 50 * (i + 1); }
        }
        for (int i = 0; i < mn; i++)
        {
            if (layer[i] <= EP[1][3]) { resistivity[i] = EP[1][0]; }
            else if (layer[i] <= EP[2][3]) { resistivity[i] = EP[2][0]; }
            else if (layer[i] <= EP[3][3]) { resistivity[i] = EP[3][0]; }
            else if (layer[i] <= EP[4][3]) { resistivity[i] = EP[4][0]; }
            else if (layer[i] <= EP[5][3]) { resistivity[i] = EP[5][0]; }
            else { resistivity[i] = EP[6][0]; }
        }
        output << ar[0] << '\t' << ar[1] << '\t' << ar[2] << '\t' << ar[3] << '\t' << ar[4] << '\t' << ar[5] << '\t' << ar[6] << '\t' << ar[7] << '\t' << ar[8] << '\t' << ar[9] << '\t' <<
            ar[10] << '\t' << ar[11] << '\t' << ar[12] << '\t' << ar[13] << '\t' << ar[14] << '\t' << ar[15] << '\t' << ar[16] << '\t' << ar[17] << '\t' << ar[18] << '\t' << ar[19] << '\t' <<
            ar[20] << '\t' << ar[21] << '\t' << ar[22] << '\t' << ar[23] << '\t' << ar[24] << '\t' << ar[25] << '\t' << ar[26] << '\t' << ar[27] << '\t' << ar[28] << '\t' << ar[29] << '\t' <<
            ar[30] << '\t' << ar[31] << '\t' << ar[32] << '\t' << ar[33] << '\t' << ar[34] << '\t' << ar[35] << '\t' << ar[36] << '\t' << ar[37] << '\t' << ar[38] << '\t' << ar[39] << '\t' <<
            resistivity[0] << '\t' << resistivity[1] << '\t' << resistivity[2] << '\t' << resistivity[3] << '\t' << resistivity[4] << '\t' << resistivity[5] << '\t' << resistivity[6] << '\t' << resistivity[7] << '\t' << resistivity[8] << '\t' << resistivity[9] << '\t' << resistivity[10] << '\t' << resistivity[11] << '\t' << resistivity[12] << '\t' << resistivity[13] << '\t' << resistivity[14] << '\t' << resistivity[15] << '\t' << resistivity[16] << '\t' << resistivity[17] << '\t' << resistivity[18] << '\t' << resistivity[19] << '\t' << resistivity[20] << '\t' << resistivity[21] << '\t' << resistivity[22] << '\t' << resistivity[23] << '\t' << resistivity[24] << '\t' << resistivity[25] << '\t' << resistivity[26] << '\t' << resistivity[27] << '\t' << resistivity[28] << '\t' << resistivity[29] << '\t' << resistivity[30] << '\t' << resistivity[31] << '\t' << resistivity[32] << '\t' << resistivity[33] << '\t' << resistivity[34] << '\t' << resistivity[35] << '\t' << resistivity[36] << '\t' << resistivity[37] << '\t' << resistivity[38] << '\t' << resistivity[39] << '\n';
    }
    output.close();
    return 0;
}



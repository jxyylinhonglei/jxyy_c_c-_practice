#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
    //int myAtoi(string s) {
    //    string tmp;
    //    bool flat =true;
    //    int jishu = 0;
    //    for (char t:s)
    //    {
    //        if (t!=' '&&t!='-'&&t!='-'&&t!='+')
    //        {
    //            tmp += t;
    //        }
    //        if (t=='-')
    //        {
    //            flat = false;
    //        }
    //    }
    //    string tmpp;
    //    int panduan = 0;
    //    if (tmp[0]!= '0'&& tmp[0] != '1' && tmp[0] != '2' && tmp[0] != '3' && tmp[0] != '4' && tmp[0] != '5' && tmp[0] != '6' && tmp[0] != '7' && tmp[0] != '8' && tmp[0] != '9')
    //    {
    //        return 0;
    //    }
    //    for (char t:tmp)
    //    {
    //        if (panduan==0)
    //        {
    //            if (t == '0' || t == '1' || t == '2' || t == '3' || t == '4' || t == '5' || t == '6' || t == '7' || t == '8' || t == '9')
    //            {
    //                tmpp += t;
    //            }
    //        }
    //        else
    //        {
    //            if (t == '0' || t == '1' || t == '2' || t == '3' || t == '4' || t == '5' || t == '6' || t == '7' || t == '8' || t == '9')
    //            {
    //                tmpp += t;
    //            }
    //            else
    //            {
    //                break;
    //            }
    //        }
    //        panduan++;
    //    }
    //    if (tmpp.size()>10)
    //    {
    //        return flat ? 2147483647 : -2147483648;
    //    }
    //    long long ans = 0;
    //    int i = 1;
    //    for (int j=tmpp.size()-1;j>=0;j--)
    //    {
    //        if (tmpp[j]== '0')
    //        {
    //            ans += 0 * i;
    //        }
    //        else if(tmpp[j] =='1')
    //        {
    //            ans += 1 * i;
    //        }
    //        else if (tmpp[j] == '2')
    //        {
    //            ans += 2 * i;
    //        }
    //        else if (tmpp[j] == '3')
    //        {
    //            ans += 3 * i;
    //        }
    //        else if (tmpp[j] == '4')
    //        {
    //            ans += 4 * i;
    //        }
    //        else if (tmpp[j] == '5')
    //        {
    //            ans += 5 * i;
    //        }
    //        else if (tmpp[j] == '6')
    //        {
    //            ans += 6 * i;
    //        }
    //        else if (tmpp[j] == '7')
    //        {
    //            ans += 7 * i;
    //        }
    //        else if (tmpp[j] == '8')
    //        {
    //            ans += 8 * i;
    //        }
    //        else
    //        {
    //            ans += 9 * i;
    //        }
    //        i = i * 10;
    //    }
    //    if (ans>= -2147483648&&ans<=2147483647)
    //    {
    //        return flat ? ans : ans * -1;
    //    }
    //    else
    //    {
    //        return flat ? 2147483647 : -2147483648;
    //    }
    //}
    //int myAtoi(string s) {
    //    string tmp;
    //    bool flat = true;//true为正，false为假
    //    for (char t : s)//去开头的空格
    //    {
    //        if (tmp.size() == 0)
    //        {
    //            if (t != ' ')
    //            {
    //                tmp += t;
    //            }
    //        }
    //        else
    //        {
    //            tmp += t;
    //        }
    //        if (tmp[0] == '-')
    //        {
    //             flat = false;
    //         }
    //    }
    //    if (tmp[0] == '+' || tmp[0] == '-')
    //    {
    //        tmp = tmp.substr(1, tmp.size() - 1);//起始位置，个数
    //    }
    //    //从处理过后的字符串中读取，一直到非数字结束
    //    string ret;
    //    for (char t : tmp)
    //    {
    //        if (t != '0' && t != '1' && t != '2' && t != '3' && t != '4' && t != '5' && t != '6' && t != '7' && t != '8' && t != '9')
    //        {
    //            break;
    //        }
    //        else
    //        {
    //            ret += t;
    //        }
    //    }
    //    //if (ret.size() > 10)
    //    //{
    //    //    return flat ? 2147483647 : -2147483648;
    //    //}
    //    //去0处理
    //    int k = 0;
    //    for (char t:ret)
    //    {
    //        if (t=='0')
    //        {
    //            k++;
    //        }
    //        else
    //        {
    //            break;
    //        }
    //    }//00123
    //    ret = ret.substr(k,ret.size()-k);
    //    if (ret.size()>11)
    //    {
    //        return flat ? 2147483647 : -2147483648;
    //    }
    //    long long ans = 0;
    //    long long i = 1;
    //    for (int j = ret.size() - 1; j >= 0; j--)
    //    {
    //        if (ret[j] == '0')
    //        {
    //            ans += 0 * i;
    //        }
    //        else if (ret[j] == '1')
    //        {
    //            ans += 1 * i;
    //        }
    //        else if (ret[j] == '2')
    //        {
    //            ans += 2 * i;
    //        }
    //        else if (ret[j] == '3')
    //        {
    //            ans += 3 * i;
    //        }
    //        else if (ret[j] == '4')
    //        {
    //            ans += 4 * i;
    //        }
    //        else if (ret[j] == '5')
    //        {
    //            ans += 5 * i;
    //        }
    //        else if (ret[j] == '6')
    //        {
    //            ans += 6 * i;
    //        }
    //        else if (ret[j] == '7')
    //        {
    //            ans += 7 * i;
    //        }
    //        else if (ret[j] == '8')
    //        {
    //            ans += 8 * i;
    //        }
    //        else
    //        {
    //            ans += 9 * i;
    //        }
    //        i = i * 10;
    //    }
    //    if (ans >= -2147483648 && ans <= 2147483647)
    //    {
    //        return flat ? ans : ans * -1;
    //    }
    //    else
    //    {
    //        return flat ? 2147483647 : -2147483648;
    //    }
    //}
//     int myAtoi(string s)
//     {
//         string tmp;
//         bool flat = true;
//         for (char t:s)
//         {
//             if (tmp.size() == 0)//去开头空格
//             {
//                 if (t!=' ')
//                 {
//                     tmp += t;
//                 }
//             }
//             else
//             {
//                 tmp += t;
//             }
//             if (tmp[0]=='-')
//             {
//                 flat = false;
//             }
//         }
//         if (tmp[0]=='+'||tmp[0]=='-')//去正负号
//         {
//             tmp = tmp.substr(1,tmp.size()-1);
//         }
//         string ret;
//         for (char t:tmp)
//         {
//             if (t=='0'|| t == '1' || t == '2' || t == '3' || t == '4' || t == '5' || t == '6' || t == '7' || t == '8' || t == '9' )
//             {
//                 ret += t;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         //去空白无效0
//         int k = 0;
//         for (char t:ret)
//         {
//             if (t=='0')
//             {
//                 k++;
//             }
//             else
//             {
//                 break;
//             }
//         }
//         ret = ret.substr(k,ret.size()-k);
//         if (ret.size()>10)
//         {
//             return flat ? 2147483647 : -2147483648;
//         }
//         long long ans = 0;
//         long long i = 1;
//         for (int j=ret.size()-1;j>=0;j--)
//         {
//             if (ret[j]=='0')
//             {
//                 ans += 0 * i;
//             }
//             else if (ret[j] == '1')
//             {
//                 ans += 1 * i;
//             }
//             else if (ret[j] == '2')
//             {
//                 ans += 2* i;
//             }
//             else if (ret[j] == '3')
//             {
//                 ans += 3 * i;
//             }
//             else if (ret[j] == '4')
//             {
//                 ans += 4* i;
//             }
//             else if (ret[j] == '5')
//             {
//                 ans += 5* i;
//             }
//             else if (ret[j] == '6')
//             {
//                 ans += 6* i;
//             }
//             else if (ret[j] == '7')
//             {
//                 ans += 7* i;
//             }
//             else if (ret[j] == '8')
//             {
//                 ans += 8 * i;
//             }
//             else
//             {
//                 ans += 9 * i;
//             }
//             i = i * 10;
//         }
//         if (ans >= -2147483648 && ans <= 2147483647)
//         {
//             return ans;
//         }
//         else
//         {
//             return flat ? 2147483647 : -2147483648;
//         }
//     }
//};//"  0000000000012345678"
//int main()
//{
//        Solution s;
//        cout << s.myAtoi("42") << endl;//0 132
//        return 0;
//}
class Solution {
public:
    bool myMatch(string s, string p)
    {
        if (s.size() != p.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != p[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isMatch(string s, string p) {
        if (p.size() == 2 && p[0] == '.' && p[1] == '*')
        {
            return true;
        }
        vector<int> df;
        int wz = 0;
        for (char t:p)
        {
            if (t=='.'||t=='*')
            {
                df.push_back(wz);
            }
            wz++;
        }
        if (df.size()==0)
        {
            return myMatch(s,p);
        }
        int left = 0;
        int right = 0;
    }
};
int main()
{
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
	string longestPalindrome(string s)
	{
		int maxlen = 1;
		int sz = s.size();
		int j = 0;
		vector<vector<bool>> df(sz,vector<bool>(sz,false));
		for (int i=0;i<sz;i++)
		{
			df[i][i] = true;
		}
		for (int len= 2; len<=sz; len++)//枚举长度
		{
			for (int left = 0; left < sz; left++)//左边界
			{
				int right = left + len - 1;
				if (right>=sz)
				{
					break;
				}
				if (s[left]==s[right])
				{
					if (len==2)
					{
						df[left][right] = true;
					}
					else
					{
						if (df[left+1][right-1])
						{
							df[left][right] = true;
						}
						else
						{
							df[left][right] = false;
						}
					}
				}
				else
				{
					df[left][right] =false ;
				}
				if (df[left][right]&&len>maxlen)
				{
					maxlen = right - left + 1;
					j = left;
					cout << maxlen << "  " << j << endl;
				}
			}
		}
		return s.substr(j,maxlen);
	}
	//int reverse(int x) {//123   321
	//	vector<int> tmp;
	//	int ans = 0;
	//	int ss = 1;
	//	int xx = x;
	//	while (xx % 10||xx/10)
	//	{
	//		tmp.push_back(xx % 10);
	//		xx = xx / 10;
	//	}
	//	for (int i = tmp.size() - 1; i >= 0; i--)
	//	{
	//		ans = tmp[i] * ss + ans;
	//		ss = ss * 10;
	//	}
	//	return  ans;
	//}//120  021
	//string convert(string s, int numsRows) {
	//	if (s.size() <= numsRows || numsRows == 1)
	//	{
	//		return s;
	//	}
	//	int lie = 0;
	//	if ((s.size() / numsRows) == 1 && (s.size() % numsRows) <= (numsRows - 2))
	//	{
	//		lie = 1 + s.size() % numsRows;
	//	}
	//	else
	//	{
	//		lie = (s.size() / (numsRows + numsRows - 2)) * (numsRows - 1);//
	//		cout << s.size() / (numsRows + numsRows - 2) << endl;
	//		if (s.size() % (numsRows + numsRows - 2))
	//		{
	//			if (s.size() % (numsRows + numsRows - 2) > numsRows)
	//			{
	//				lie = lie + 1 + (s.size() % (numsRows + numsRows - 2) - numsRows);
	//			}
	//			else
	//			{
	//				lie = lie + 1;
	//			}
	//		}
	//	}
	//	vector<vector<char>> df(numsRows, vector<char>(lie, '0'));
	//	int xb = 0;//字符串s的下表
	//	for (int i = 0; i < lie; i++)//列
	//	{
	//		for (int j = 0; j < numsRows; j++)//行
	//		{
	//			if (xb >= s.size())
	//			{
	//				break;
	//			}//0 3 6   1 2 4 5       4
	//			if (!(i % (numsRows - 1)))
	//			{
	//				df[j][i] = s[xb++];
	//			}
	//			else//1  2   1  2
	//			{//   lie 1 2 4 5       2  1   2 1  //2 3 5 6/2 0 2 0
	//				df[(numsRows - 1) - (i % (numsRows - 1))][i] = s[xb++];
	//				break;
	//			}
	//		}
	//	}
	//	string ans(s.size(), '0');
	//	int ii = 0;
	//	for (int i = 0; i < numsRows; i++)
	//	{
	//		for (int j = 0; j < lie; j++)
	//		{
	//			if (df[i][j] != '0')
	//			{
	//				ans[ii++] = df[i][j];
	//			}
	//		}
	//	}
	//	return ans;
	//}
	string convert1(string s, int numsRows)
	{
		if (s.size() <= numsRows || numsRows == 1)
		{
			return s;
		}
		int sz = (numsRows > s.size()) ? s.size() : numsRows;
		vector<string> df(sz);
		int curRow = 0;
		int x = 0;
		bool flat = false;
		while (x<s.size())
		{
			if (curRow == 0 || curRow ==sz-1)
			{
				flat = !flat;
			}
			df[curRow] += s[x++];
			curRow += flat ? 1 : -1;
		}
		string ans;
	    for (int i=0;i<(numsRows > s.size() ? s.size() : numsRows);i++)
		{
			ans += df[i];
		}
		return ans;
	}
    string convert2(string s, int numsRows)
    {
		if (s.size() <= numsRows||numsRows==1)
		{
			return s;
		}
		int curRow=0;
		bool flat = false;
		int sz = (s.size() > numsRows) ?numsRows :s.size();
		vector<string> df(sz);
		for (char t : s)
		{
			if (curRow == 0 || curRow == (sz-1))
			{
				flat = !flat;
			}
			df[curRow] += t;
			curRow += flat?1:-1;
		}
		string ret;
		for (string cur:df)
		{
			ret += cur;
		}
		return ret;
	}
};
int main()
{
	/*string t = "cabdkac";*/
	/*Solution s;
	string yy = "PAYPALISHIRING";*/
	/*cout<<s.longestPalindrome(t)<<endl;*/
	/*cout <<yy.size()<<" "<< s.convert(yy,5) << endl;*///9646324351
	Solution s;
	string yy = "abcde";
	cout << s.convert1(yy, 4)<<" "<<s.convert2(yy,4) << endl;
	return 0;
}

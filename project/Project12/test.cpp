#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution
{
public:
	string aaa(char* tmp, int n)
	{
		string a(n, '/0');
		for (int i = 0; i < n; i++)
		{
			a[i] = tmp[i];
		}
		return a;
	}
	void test(string s, int i, char* tmp, int n, vector<string>& str)
	{
		if (i == n)
		{
			return;
		}
		if (s[i] == '2')
		{
			tmp[i] = 'a';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'b';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'c';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
		}
		else if (s[i] == '3')
		{
			tmp[i] = 'd';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'e';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'f';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
		}
		else if (s[i] == '4')
		{
			tmp[i] = 'g';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'h';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'i';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
		}
		else if (s[i] == '5')
		{
			tmp[i] = 'j';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'k';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'l';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
		}
		else if (s[i] == '6')
		{
			tmp[i] = 'm';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'n';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'o';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
		}
		else if (s[i] == '7')
		{
			tmp[i] = 'p';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'q';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'r';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 's';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
		}
		else if (s[i] == '8')
		{
			tmp[i] = 't';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'u';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'v';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
		}
		else if (s[i] == '9')
		{
			tmp[i] = 'w';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'x';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'y';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
			tmp[i] = 'z';
			test(s, i + 1, tmp, n, str);
			if (i == n - 1)
			{
				str.push_back(aaa(tmp, n));
			}
		}
		else
		{
			;
		}
	}
	vector<string> letterCombinations(string digits) {
		int sz = digits.size();
		char* tmp = new char[digits.size()];
		vector<string> str;
		test(digits, 0, tmp, sz, str);
		return str;
	}
};
int main()
{
	Solution s;
	string a = "432";
	vector<string> str=s.letterCombinations(a);
	vector<string>::iterator it;
	int i = 0;
	for (it = str.begin(); it != str.end(); it++)
	{
		cout << *it << i<<endl;
		i++;
	}
	return 0;
}

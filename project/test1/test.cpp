//#include<iostream>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//    int check(vector<int>& height, int left, int right)
//    {
//        int k = left;
//        int tmp = 0;
//        int aa = 0;
//        while (k < right)
//        {
//            tmp = height[left] - height[k] + tmp;
//            k++;
//        }
//        return tmp;
//    }
//    int trap(vector<int>& height) {
//        int begin = 0;
//        int end = 0;
//        int n = height.size();
//        int ans = 0;
//        int left = 0;
//        int right = n - 1;
//        int tmp = 0;
//        int ans1 = 0;
//        while (begin < n)
//        {
//            if (height[begin] == 0 && begin == 0)
//            {
//                begin++;
//                end++;
//            }
//            while (end < n)
//            {
//                if (height[begin] <= height[end] && begin != end)
//                {
//                    break;
//                }
//                end++;
//            }
//            if (end == n)
//            {
//                begin++;
//                end = begin;
//            }
//            else
//            {
//                ans = ans + check(height, begin, end);
//                begin = end;
//            }
//        }
//        while (left <= right)
//        {
//            tmp=height[left];
//            height[left] = height[right];
//            height[right] = tmp;
//            left++;
//            right--;
//        }
//        begin = 0;
//        end = 0;
//        while (begin < n)
//        {
//            if (height[begin] == 0 && begin == 0)
//            {
//                begin++;
//                end++;
//            }
//            while (end < n)
//            {
//                if (height[begin] <= height[end] && begin != end)
//                {
//                    break;
//                }
//                end++;
//            }
//            if (end == n)
//            {
//                begin++;
//                end = begin;
//            }
//            else
//            {
//                ans1 = ans1 + check(height, begin, end);
//                begin = end;
//            }
//        }
//        if (ans1 > ans)
//        {
//            return ans1;
//        }
//        return ans;
//    }
//};
//int main()//4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3]
//{
//    Solution s;
//    vector<int> a;
//    int arr[] = { 6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3};
//    int sz = sizeof(arr) / sizeof(int);
//    for (int i = 0; i < sz; i++)
//    {
//        a.push_back(arr[i]);
//    }
//    //a.push_back(6);
//    //a.push_back(4);
//    //a.push_back(2);
//    //a.push_back(0);
//    //a.push_back(3);
//    //a.push_back(2);
//    //a.push_back(0);
//    //a.push_back(3);
//    //a.push_back(1);
//    //a.push_back(4);
//    //a.push_back(6);//,5,3,0,1,2,1,
//    //a.push_back(5);
//    //a.push_back(3);
//    //a.push_back(2);
//    //a.push_back(7);//,5,3,0,1,2,1,
//    //a.push_back(5);
//    //a.push_back(3);
//    //a.push_back(0);
//    //a.push_back(1);
//    //a.push_back(2);
//    //a.push_back(3);
//    //a.push_back(4);
//    //a.push_back(6);
//    //a.push_back(8);
//    //a.push_back(1);
//    //a.push_back(3);
//    int tmp = s.trap(a);
//    cout << tmp << endl;
//	return 0;
//}
#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;
class Solution
{
public:
	int check(vector<int>& height, int left, int right,int i)
    {
		    if (left>=right)
	   	    {
		    	return 0;
		    }
			int tmp = 0;
			int end = 0;
			int begin = left+1; 
			end = i;
	        while (begin< right)
	        {
	            tmp = height[end] - height[begin] + tmp;
				begin++;
	        }
	        return tmp;
    }
	int trap(vector<int>& height)
	{
		int left = 0;
		int right = 0;
		int sz = height.size();
		int l_max = 0;
		int i = 0;
		int ans = 0;
		while (left<sz)
		{
			if (height[left] == 0 && left == 0)
			{
				left++;
				right++;
			}
			while (right<sz)
			{
				if (height[left] <=height[right]&&left!=right)
				{
					l_max =left;
					break;
				}
				right++;
			}
			if (right == sz)
			{
				i = left + 1;
				l_max = i;
				while (i < right)
				{
					if (height[l_max] < height[i])
					{
						l_max = i;
					}
					i++;
				}
				right = l_max;
			}
			if (l_max!=left)
			{
				ans = check(height, left,right ,l_max) + ans;//1,left¼õ
			}
			else
			{
				ans = check(height, left,right, l_max) + ans;//0,max¼õ
			}
			left = right;
		}
		return ans;
	}
};
class Solution1
{
public:
	int lengthOfLongestSubstring(string s)
	{
		unordered_set<char> occ;
		int begin = 0;
		int end = 0;
		int ans = 0;
		while (begin<s.size())
		{
			while (occ.count(s[end])!=1&&end<s.size())
			{
				occ.insert(s[end]);
				end++;
			}
			if ((end - begin) > ans)
			{
				ans = end - begin;
			}
			begin++;
			occ.erase(s[begin-1]);
		}
		return ans;
	}
};
class Solution3
{
public:
	int compare(string s,int left,int right)
	{
		int i = left;
		int j = right;
		while (i<=j)
		{
			if (s[i]!=s[j])
			{
				return 0;
			}
			i++;
			j--;
		}
		return right - left + 1;
	}
	string longespalindrome(string s)
	{
		int sz = s.size();
		int left = 0;
		int right =0;
		int* tmp = new int[2];
		tmp[0] = 0;
		tmp[1] = 0;
		int k = 0;
		int max = 0;
		for (left=0;left<sz;left++)
		{
			for (right = left; right < sz; right++)
			{
				k = compare(s, left, right);
				if (k > max)
				{
					max = k;
					tmp[0] =left;
					tmp[1] = right;
				}
			}
		}
		string a;
		int i=tmp[0];
		int j = tmp[1];
		while (i<=j)
		{
			s.push_back(s[i]);
			i++;
		}
		return a;
	}
};
void test1()
{
	Solution s;
	vector<int> a;
	int arr[] = { 6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3 };
	int sz = sizeof(arr) / sizeof(int);
	for (int i = 0; i < sz; i++)
	{
		a.push_back(arr[i]);
	}
	int tmp = s.trap(a);
	cout << tmp << endl;
}
void test2()
{
	///*Solution1 s;
	//string a = "";
	//int tmp = s.lengthOfLongestSubstring(a);
	//cout << tmp << endl;*/
	//Solution3 s;
	//string a = "bad";
	//string tmp=s.longespalindrome(a);
	//cout << tmp << endl;
	Solution s;
	
}
int main()
{
	test1();
	return 0;
}
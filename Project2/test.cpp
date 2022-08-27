#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<unordered_set>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<map>
using namespace std;
#define INI_MAX 2147483647
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};
struct ListNode
{
	int val;
	ListNode* next;
};
class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int sz = nums.size();
		if (sz== 3)
		{
			return nums[0] + nums[1] + nums[2];
		}
		sort(nums.begin(), nums.end());
		int flat = 1;
		int min =nums[0] + nums[1] + nums[2] - target;
		if (min<0)
		{
			flat = -1;
			min = -min;
		}
		int tmp = 0;
		for (int i = 0; i < sz; i++)
		{
			if (i != 0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			for (int j = i + 1; j < sz; j++)
			{
				int right = sz - 1;
				if (j != i + 1 && nums[j] == nums[j - 1])
				{
					continue;
				}
				while (right>j)
				{
					int t = 1;
					if (right != sz - 1 && nums[right] == nums[right+1])
					{
						right--;
					}
					if (min == 0)
					{
						return target;
					}
					tmp = nums[i] + nums[j] + nums[right] - target;
					if (tmp < 0)
					{
						t = -1;
						tmp = -tmp;
					}
					if (right <= j)
					{
						break;
					}
					min = min > tmp ? t*tmp: flat*min;
					if (min < 0)
					{
						flat = -1;
						min = -min;
					}
					else
					{
						flat = 1;
					}
					right--;
				}
			}
		}
		return min * flat + target;
	}
	//void _letterCombinations(unordered_map<char, string>& uset, vector<string>& ans,string& digits,int t,int stop,string& ret)//0 1
	//{
	//	if (t>=stop)
	//	{
	//		return;
	//	}
	//	int begin = t;
	//	int next = 0;
	//	char tmp;
	//	tmp=uset[digits[begin]][next];
	//	ret.push_back(tmp);
	//	_letterCombinations(uset, ans, digits,t + 1, stop,ret);
	//	if (t==stop-1)
	//	{
	//		ans.push_back(ret);
	//	}
	//	ret =ret.substr(0,t);
	//	tmp = uset[digits[begin]][next+1];
	//	ret.push_back(tmp);
	//	_letterCombinations(uset, ans, digits,t + 1, stop, ret);
	//	if (t == stop - 1)
	//	{
	//		ans.push_back(ret);
	//	}
	//	ret = ret.substr(0,t);
	//	tmp = uset[digits[begin]][next+2];
	//	ret.push_back(tmp);
	//	_letterCombinations(uset, ans, digits,t + 1, stop, ret);
	//	if (t == stop - 1)
	//	{
	//		ans.push_back(ret);
	//	}
	//	if (digits[begin]=='7'||digits[begin]=='9')
	//	{
	//		ret = ret.substr(0, t);
	//		tmp = uset[digits[begin]][next + 3];
	//		ret.push_back(tmp);
	//		_letterCombinations(uset, ans, digits, t + 1, stop, ret);
	//		if (t == stop - 1)
	//		{
	//			ans.push_back(ret);
	//		}
	//	}
	//	ret = ret.substr(0, t-1);
	//}
	//vector<string> letterCombinations(string digits) {
	//	int sz = digits.size();
	//	vector<string> ans;
	//	unordered_map<char, string> uset = { {'2',"abc"},{'3',"def"},{'4', "ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
	//	string ret;
	//	_letterCombinations(uset,ans,digits,0,sz,ret); 
	//	return ans;
	//}
	void _letterCombinations(unordered_map<char, string>& uset, vector<string>& ans, string& digits, string& ret, int t, int stop)
	{
		if (t >= stop)
		{
			return;
		}
		int begin = t;
		char tmp;
		tmp = uset[digits[begin]][0];
		ret.push_back(tmp);
		_letterCombinations(uset, ans, digits, ret, begin + 1, stop);
		if (begin == stop - 1)
		{
			ans.push_back(ret);
		}
		ret = ret.substr(0, begin);
		tmp = uset[digits[begin]][1];
		ret.push_back(tmp);
		_letterCombinations(uset, ans, digits, ret, begin + 1, stop);
		if (begin == stop - 1)
		{
			ans.push_back(ret);
		}
		ret=ret.substr(0, begin);
		tmp = uset[digits[begin]][2];
		ret.push_back(tmp);
		_letterCombinations(uset, ans, digits, ret, begin + 1, stop);
		if (begin == stop - 1)
		{
			ans.push_back(ret);
		}
		ret = ret.substr(0,begin);
		if (digits[begin] == '7' || digits[begin] == '9')
		{
			tmp = uset[digits[begin]][3];
			ret.push_back(tmp);
			_letterCombinations(uset, ans, digits, ret, begin + 1, stop);
			if (begin == stop - 1)
			{
				ans.push_back(ret);
			}
		}
		ret=ret.substr(0,begin-1);
	}
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		int sz = digits.size();
		unordered_map<char, string> uset = { {'2',"abc"},{'3',"def"},{'4', "ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
		string ret;
		_letterCombinations(uset,ans,digits,ret,0,sz);
		return ans;
	}
	vector<int> fraction(vector<int>& cont) {
		int right = cont.size() - 1;
		if (right == 0)
		{
			return cont = {cont[0],1};
		}
		int tmp;
		vector<int> ans = {1,cont[right]};
		while (right>1)
		{
			ans[0] = ans[1] * cont[right - 1]+ans[0];
			tmp = ans[0];
			ans[0] = ans[1];
			ans[1] = tmp;
			right--;
		}
		ans[0] = ans[1] * cont[0] + ans[0];
		return ans;
	}
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		int sz = nums.size();
		if (sz < 4)
		{
			return ans;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < sz; i++)
		{
			if (nums[0] > target&&nums[0]>=0)
			{
				break;
			}
			if (i != 0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			for (int j = i + 1; j < sz; j++)
			{
				if (j != i + 1 && nums[j] == nums[j - 1])
				{
					continue;
				}
				int left = j + 1;
				int right = sz - 1;
				while (left < right)
				{
					while (left > j + 1 && nums[left] == nums[left - 1] && left < right)
					{
						left++;
					}
					while (right != sz - 1 && nums[right] == nums[right + 1] && right > left)
					{
						right--;
					}
					if (left >= right)
					{
						break;
					}
					//if ((long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right]- (long long)target ==0 && left < right)
					//{
					//	ans.push_back({ nums[i],nums[j],nums[left],nums[right] });
					//	left++;
					//	right--;
					//}
					//else if ((long long)nums[i] + (long long)nums[j] + (long long)nums[left] + (long long)nums[right]- (long long)target <0)
					//{
					//	left++;
					//}
					//else
					//{
					//	right--;
					//}
					if (nums[i] + nums[j] + nums[left] +nums[right] - target == 0 && left < right)
					{
						ans.push_back({ nums[i],nums[j],nums[left],nums[right] });
						left++;
						right--;
					}
					else if (nums[i] + nums[j] + nums[left] + nums[right] - target < 0)
					{
						left++;
					}
					else
					{
						right--;
					}
				}
			}
		}
		return ans;
	}
	//ListNode* removeNthFromEnd(ListNode* head, int n) {
	//	if (head == nullptr)
	//	{
	//		return head;
	//	}
	//	int mid= 0;
	//	int sz = 0;
	//	ListNode* fast=head, * slow = head;
	//	ListNode* tmp = nullptr;
	//	ListNode* newhead = nullptr;
	//	while (fast!=nullptr&&fast->next!=nullptr)
	//	{
	//		mid+=1;
	//		fast = fast->next->next;
	//		slow = slow->next;
	//	}
	//	if (fast==nullptr)
	//	{
	//		sz = 2 * mid;
	//	}
	//	else
	//	{
	//		sz = 2 * mid + 1;
	//	}
	//	if (mid< sz - n)
	//	{
	//		while (mid!=sz-n-1)
	//		{
	//			slow = slow->next;
	//			mid++;
	//		}
	//		tmp = slow->next;
	//		slow->next =tmp->next;
	//		newhead = head;
	//	}
	//	else//sz是个数，sz-n代表是删除下标为几的（下标从0开始）
	//	{
	//		if (sz - n == 0)
	//		{
	//			newhead = head->next;
	//		}
	//		else
	//		{
	//			newhead = head;
	//			tmp = head;
	//			for (int i=0;i<sz-n-1;i++)
	//			{
	//				tmp = tmp->next;
	//			}
	//			tmp->next = tmp->next->next;
	//		}
	//	}
	//	return newhead;
	//}
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr)
		{
			return head;
		}
		ListNode* first = head;
		ListNode* slow = head;
		ListNode* newhead = nullptr;
		for (int i = 0; i <n ; i++)
		{
			first = first->next;
		}
		if (first == nullptr)
		{
			newhead = slow->next;
		}
		else
		{
			newhead = head;
			while (first->next != nullptr)
			{
				first = first->next;
				slow = slow->next;
			}
			slow->next = slow->next->next;
		}
		return newhead;
	}
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr)
		{
			return head;
		}
		ListNode* prev = nullptr;
		ListNode* cur = head;
		ListNode* next = cur->next;
		ListNode* newhead=nullptr;
		while (cur!=nullptr&&cur->next != nullptr)
		{
			ListNode* tmp = next->next;
			next->next = cur;
			cur->next = tmp;
			if (newhead == nullptr)
			{
				newhead = next;
			}
			if (prev != nullptr)
			{
				prev->next = next;
			}
			prev = cur;
			cur = prev->next;
			if (cur!=nullptr)
			{
				next = cur->next;
			}
		}
		if (newhead==nullptr)
		{
			newhead = head;
		}
		return newhead;
	}
	//int strStr(string haystack, string needle) {
	//	if ((haystack.size() == 0 && needle.size() == 0)|| (haystack.size() != 0 && needle.size() == 0))
	//	{
	//		return 0;
	//	}
	//	if ((haystack.size() == 0 && needle.size() != 0))
	//	{
	//		return -1;
	//	}
	//	int i = 0;
	//	int j = 0;
	//	while (i <=haystack.size() - 1 && j <= needle.size() - 1)
	//	{
	//		if (haystack[i] == needle[j])
	//		{
	//			i++;
	//			j++;
	//		}
	//		else
	//		{
	//			i = i - j+1;
	//			j = 0;
	//		}
	//	}
	//	if (i== haystack.size()&& j != needle.size())
	//	{
	//		return -1;
	//	}
	//	else
	//	{
	//		return i-j;
	//	}
	//}
	void nextArray(string sub,vector<int>& next)
	{
		next.push_back(0);
 		next.push_back(0);// 0 1 
		int i = 1;
		int k = 0;
 		while (i<sub.size()-1)
		{
			k = next[i];
			if (sub[i]==sub[k])//next[i]==k如果p[i]==p[k],next[i+1]=k+1
			{
				next.push_back(k+1);
				i++;
			}
			else//如果p[i]!=p[k],就一直回退，一直到找到p[i]==p[k]，此时next[i+1]=k+1
			{
				while (k>0)
				{
					if (sub[i]==sub[k])
					{
						next.push_back(k + 1);
						i++;
					}
					else
					{
						k = next[k];
					}
				}
				if (sub[i] == sub[k])
				{
					next.push_back(k + 1);
					i++;
				}
				else
				{
					next.push_back(0);
					i++;
				}
			}
		}
	}
	int kmp(string str,string sub)
	{
		if ((str.size() == 0 && sub.size() == 0)||(str.size() != 0 && sub.size() == 0))
		{
			return 0;
		}
		if (str.size() == 0 && sub.size() != 0)
		{
			return - 1;
		}
		vector<int> next;
		nextArray(sub,next);
		int i = 0;
		int j = 0;
		while (i<str.size()&&j<sub.size())
		{
			if (str[i] == sub[j])
			{
				i++;
				j++;
			}
			else
			{
				if (j== 0)
				{
					i++;
				}
				else
				{
					j = next[j];
				}
			}
		}
		if (j == sub.size())
		{
			return i - j;
		}
		else
		{
			return -1;
		}
	}
	void createNext(string needle,vector<int>& next)
	{
		next.push_back(0);
		next.push_back(0);
		int i = 1;
		int k = 0;
		while (i<needle.size()-1)
		{
			k = next[i];
			if (needle[i] == needle[k])
			{
				next.push_back(k + 1);
				i++;
			}
			else
			{
				while (k>0)
				{
					if (needle[i] == needle[k])
					{
						next.push_back(k + 1);
						i++;
					}
					else
					{
						k = next[k];
					}
				}
				if (needle[i]==needle[k])
				{
					next.push_back(k+1);
					i++;
				}
				else
				{
					next.push_back(k);
					i++;
				}
			}
		}
	}
	int strStr(string haystack, string needle) {
		if ((haystack.size() == 0 && needle.size() == 0) || (haystack.size() != 0 && needle.size() == 0))
		{
			return 0;
		}
		if ((haystack.size() == 0 && needle.size() != 0))
		{
			return -1;
		}
		vector<int> next;
		createNext(needle,next);
		int i = 0;
		int j = 0;
		while (i<haystack.size()&&j<needle.size())
		{
			if (haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				
				if (j==0)
				{
					i++;
				}
				else
				{
					j = next[j];
				}
			}
		}
		if (j==needle.size())
		{
			return i-j;
		}
		else
		{
			return -1;
		}// 2
	}//))((
	//void _generateParenthesis(vector<string>& ans,string& ret,int cur,int& n)
	//{
	//	if (cur>=2*n)
	//	{
	//		return;
	//	}
	//	ret.push_back('(');
	//	_generateParenthesis(ans, ret, cur+1, n);
	//	if (ret.size()==2*n)
	//	{
	//		ans.push_back(ret);
	//	}
	//	ret=ret.substr(0,cur);
	//	ret.push_back(')');
	//	_generateParenthesis(ans, ret, cur + 1, n);
	//	if (ret.size() == 2*n)
	//	{
	//		ans.push_back(ret);
	//	}
	//	ret=ret.substr(0,cur-1);
	//}
	//bool insertAnswer(string& s)
	//{
	//	int left = 0;
	//	int right = 0;
	//	for (int i = 0; i < s.size(); i++)
	//	{//)(
	//		if (left < right)
	//		{
	//			return false;
	//		}
	//		if (s[i] == '(')
	//		{
	//			left++;
	//		}
	//		else
	//		{
	//			right++;
	//		}
	//	}
	//	if (left == right)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}
	//vector<string> generateParenthesis(int n) {
	//	vector<string> ans;
	//	vector<string> reans;
	//	string ret;
	//	_generateParenthesis(ans,ret,0,n);
	//	for (int i = 0; i < ans.size(); i++)
	//	{
	//		if (insertAnswer(ans[i]))
	//		{
	//			reans.push_back(ans[i]);
	//		}
	//	}
	//	return reans;
	//}
	bool valid(string& ret)
	{
		int left = 0;
		int right = 0;
		for (int i = 0; i < ret.size(); i++)
		{
			if (right > left)
			{
				return false;
			}
			if (ret[i] == '(')
			{
				left++;
			}
			else
			{
				right++;
			}
		}
		if (left == right)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void generate_all(vector<string>& result, string& ret, int left, int right, int n)
	{
		if (ret.size() == 2 * n)
		{
			if (valid(ret))
			{
				result.push_back(ret);
			}
			return;
		}
		if (left < n)
		{
			ret += '(';
			generate_all(result, ret, left + 1, right, n);
			ret.pop_back();
		}
		if (left > right)
		{
			ret += ')';
			generate_all(result, ret, left, right + 1, n);
			ret.pop_back();
		}
	}
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		string ret;
		generate_all(result, ret, 0, 0, n);
		return result;
	}
	bool valid(const string& ret)
	{
		int left = 0;
		int right = 0;
		for (char s : ret)
		{
			if (right>left)
			{
				return false;
			}
			if (s == '(')
			{
				left++;
			}
			else
			{
				right++;

			}
		}
		if (left == right)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void _generateParenthesis1(vector < string>& result, string& ret,int& n)
	{
		if (ret.size() == 2 * n)
		{
			if (valid(ret))
			{
				result.push_back(ret);
			}
			return;
		}
		ret.push_back('(');
		_generateParenthesis1(result, ret, n);
		ret.pop_back();
		ret.push_back(')');
		_generateParenthesis1(result, ret, n);
		ret.pop_back();
	}
	vector<string> generateParenthesis1(int n) {
		vector < string> result;
		string ret;
		_generateParenthesis1(result, ret, n);
		return result;
	}
	vector<int> singleNumber(vector<int>& nums) {
		int i = 0;
		int s = 1;
		int s1 = 0;
		int s2 = 0;
		for (int j = 0; j < nums.size(); j++)
		{
			i ^= nums[j];
		}//& 有0全为零，|有1全为1
		while (!(s & i))
		{
			s=s << 1;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if ((s & nums[i])== 0)
			{
				s1 ^= nums[i];
			}
			else
			{
				s2 ^= nums[i];
			}
		}
		return vector<int>{s1,s2};
	}
	//int searchInsert(vector<int>& nums, int target) {
	//	int sz = nums.size();
	//	int left = 0;
	//	int right = sz - 1;
	//	int mid = 0;
	//	while (left<=right)
	//	{
	//		mid = (left + right) >> 1;
	//		if (nums[mid]==target)
	//		{
	//			return mid;
	//		}
	//		else if (nums[mid]<target)
	//		{
	//			left = mid + 1;
	//		}
	//		else
	//		{
	//			right = mid - 1;
	//		}
	//		sz /= 2;
	//	}
	//	if (nums[mid] > target)
	//	{
	//		nums.insert(nums.begin()+mid,target);
	//		return mid;
	//	}
	//	else
	//	{
	//		nums.insert(nums.begin()+mid+1, target);
	//		return mid+1;
	//	}
	//}
	int search(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;
		while (left <= right)
		{
			mid = ((right - left) >> 1)+left;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] > target)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		if (nums[mid] > target)
		{
			nums.insert(nums.begin() + mid, target);
			return mid;
		}
		else
		{
			nums.insert(nums.begin() + mid + 1, target);
			return mid + 1;
		}
	}
	//bool findStr(string& s,int begin,int end,char tmp)
	//{
	//	while (begin<=end)
	//	{
	//		if (s[begin] == tmp)
	//		{
	//			return true;
	//		}
	//		begin++;
	//	}
	//	return false;
	//}
	//string removeDuplicateLetters(string s) {
	//	string result;
	//	int cur = 0;
	//	for (int i = 0; i < s.size(); i++)
	//	{
	//		if (i == 0)
	//		{
	//			result.push_back(s[i]);
	//			cur++;
	//		}
	//		else
	//		{
	//			if (s[i]>result[cur-1])
	//			{
	//				if (cur == 1)
	//				{
	//					result.push_back(s[i]);
	//					cur++;
	//				}
	//				else
	//				{
	//					if (!findStr(result, 0, cur - 2, s[i]))
	//					{
	//						result.push_back(s[i]);
	//						cur++;
	//					}
	//				}
	//			}
	//			else if (s[i] == result[cur - 1])
	//			{
	//				continue;
	//			}
	//			else//比较小
	//			{
	//				if (!findStr(s,i+1,s.size()-1,result[cur-1]))
	//				{
	//					if (!findStr(result, 0, cur - 2, s[i]))
	//					{
	//						result.push_back(s[i]);
	//						cur++;
	//					}
	//				}
	//				else//后面有
	//				{
	//					if (cur==1)
	//					{
	//						result.pop_back();
	//						result.push_back(s[i]);
	//					}
	//					else if (findStr(result, 0, cur - 2, s[i]))
	//					{
	//						;
	//					}
	//					else
	//					{
	//						while (cur > 1)
	//						{
	//							result.pop_back();
	//							cur--;
	//							if (s[i] == result[cur - 1])
	//							{
	//								break;
	//							}
	//							else if (s[i] > result[cur - 1])
	//							{
	//								result.push_back(s[i]);
	//								cur++;
	//								break;
	//							}
	//							else
	//							{//s[i]小
	//								if (!findStr(s,i+1,s.size()-1,result[cur-1]))
	//								{
	//									result.push_back(s[i]);
	//									cur++;
	//									break;
	//								}
	//							}
	//						}
	//						if (s[i] == result[cur - 1])
	//						{
	//							continue;
	//						}
	//						else if (s[i] > result[cur - 1])
	//						{
	//							result.push_back(s[i]);
	//							cur++;
	//						}
	//						else
	//						{
	//							if (!findStr(s, i + 1, s.size() - 1, result[cur - 1]))
	//							{
	//								result.push_back(s[i]);
	//								cur++;
	//							}
	//							else
	//							{
	//								result.pop_back();
	//								result.push_back(s[i]);
	//							}
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}
	//	return result;
	//}
	bool FindStr(string& s,int begin,int end,char sub)
	{
		while (begin<=end)
		{
			if (s[begin] == sub)
			{
				return true;
			}
			begin++;
		}
		return false;
	}
	string removeDuplicateLetters(string s) {
		string result; //acdb c 
		for (int i = 0; i < s.size(); i++)
		{
			if (i == 0)
			{
				result.push_back(s[i]);
			}
			else
			{
				if (result.back() == s[i])
				{
					continue;
				}
				else if (result.back()<s[i])
				{
					if (!result.empty()&&!FindStr(result, 0, result.size() - 2, s[i]))
					{
						result.push_back(s[i]);
					}
				}
				else
				{
					if (FindStr(result,0,result.size()-2,s[i]))
					{
						continue;
					}
					else
					{
						while (!result.empty())
						{
							if (!FindStr(s, i + 1, s.size() - 1, result[result.size() - 1]))
							{
								result.push_back(s[i]);
								break;
							}
							else
							{
								result.pop_back();
							}
							if (!result.empty() && result.back() == s[i])
							{
								break;
							}
							else if (!result.empty() && result.back() < s[i])
							{
								result.push_back(s[i]);
								break;
							}
							else
							{
								;
							}

						}
						if (result.empty())
						{
							result.push_back(s[i]);
						}
					}
				}
			}
		}
		return result;
	}
	bool ValidValue(TreeNode* root,int left,int right)
	{
		if (root == nullptr)
		{
			return true;
		}
		if (root->val<right && root->val>left)
		{
			
			return ValidValue(root->left, left, root->val)&&ValidValue(root->right,root->val,right);
		}
		else
		{
			return false;
		}
	}
	//bool isValidBST(TreeNode* root) {
	//	return ValidValue(root, INT_MIN, INT_MAX);
	//}
 //   bool isValidBST(TreeNode* root) {
	//	stack<TreeNode*> ret;
	//	ret.push(root);
	//	while (!ret.empty())
	//	{
	//		ret.push(tmp->right);
	//		ret.push(tmp->left);
	//		TreeNode* tmp = ret.top();
	//		ret.pop();
	//	}
	//}
	bool isValidBST(TreeNode* root) {
		stack<int> test;
		stack<TreeNode*> ret;
		while (root!=nullptr||!ret.empty())
		{
			while (root!=nullptr)
			{
				ret.push(root);
				root=root->left;
			}
			root = ret.top();
			if (test.empty())
			{
				test.push(root->val);
			}
			else
			{
				if (test.top() >= root->val)
				{
					return false;
				}
				else
				{
					test.push(root->val);
				}
			}
			ret.pop();
			root=root->right;
		}
		return true;
	}
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root == nullptr)
		{
			return result;
		}
		stack<TreeNode*> ret;
		while (root!=nullptr||!ret.empty())
		{
			while (root != nullptr)
			{
				result.push_back(root->val);
				ret.push(root);
				root = root->left;
			}
			root = ret.top();
			ret.pop();
			root = root->right;
		}
		return result;
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;//左根右
		if (root==nullptr)
		{
			return result;
		}
		stack<TreeNode*> ret;
		while (root!=nullptr||!ret.empty())
		{
			while (root!=nullptr)
			{
				ret.push(root);
				root=root->left;
			}
			root = ret.top();
			result.push_back(root->val);
			root = root->right;
			ret.pop();
		}
		return result;
	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		if (root==nullptr)
		{
			return result;
		}
		stack<TreeNode*> ret;
		while (root != nullptr||!ret.empty())
		{
			while (root!=nullptr)
			{
				ret.push(root);
				root = root->left;
			}
			root = ret.top();
			ret.pop();
			result.push_back(root->val);
			root = ret.top(); 
			root=root->right;
		}
		return result;
	}
	char FirstNotRepeatingchar(string s)
	{
		int HastTable[256] = {0};
		for (int i = 0; i < s.size(); i++)
		{
			HastTable[s[i]]++;
		}
		for (char ss : s)
		{
			if (HastTable[ss] == 1)
			{
				return ss;
			}
		}
		return '0';
	}
	//string removeDuplicateLetters1(string s) 
	//{
	//	vector<int> vis(26), num(26);//num代表s还有多少字符，vis代表栈中有什么字符
	//	for (char ch : s) 
	//	{
	//		num[ch - 'a']++;
	//	}//记录每个字符出现的次数
	//	string stk;
	//	for (char ch : s) //遍历
	//	{
	//		if (!vis[ch - 'a']) 
	//		{
	//			while (!stk.empty() && stk.back() > ch) 
	//			{
	//				if (num[stk.back() - 'a'] > 0) 
	//				{
	//					vis[stk.back() - 'a'] = 0;
	//					stk.pop_back();
	//				}
	//				else 
	//				{
	//					break;
	//				}
	//			}
	//			vis[ch - 'a'] = 1;
	//			stk.push_back(ch);
	//		}
	//		num[ch - 'a'] -= 1;
	//	}
	//	return stk;
	//}
	string removeDuplicateLetters1(string s)
	{
		vector<bool> prev(26,false);
		vector<int> next(26,0);
		string sak;
		for (char s1 : s)
		{
			next[s1 - 'a']++;
		}
		for (char s2 : s)
		{
			if (!prev[s2 - 'a'])//前面没有
			{
				while (!sak.empty()&&s2<sak.back())
				{
					if (next[sak.back()-'a']<1)
					{
						break;
					}
					else
					{
						prev[sak.back() - 'a'] = false;
						sak.pop_back();
					}
				}
				sak.push_back(s2);
				prev[s2 - 'a'] = true;
			}
			next[s2 - 'a']--;
		}
		return sak;
	}
	void insert(vector<string>& tmp,int left,int right,string str)
	{
		string s;
		while (left<=right)
		{
			s.push_back(str[left]);
			left++;
		}
		tmp.push_back(s);
	}
	bool compare(string& s,int left,int right)
	{
		int flat =0;
		if (s[left] ==' ')
		{
			return false;
		}
		if (left == right && s[left] == ',')
		{
			return true;
		}
		if (s[left] == ',' || s[left] == '-')
		{
			return false;
		}
		while (left<=right)
		{
			if (left != right&&(s[left] == ','|| s[left] == '.'||s[left]=='!'))
			{
				return false;
			}
			if (left == right && s[left] == '-')
			{
				return false;
			}
			if (s[left] == '0' || s[left] == '1' || s[left] == '2' || s[left] == '3' || s[left] == '4' || s[left] == '5' || s[left] == '6' || s[left] == '7' || s[left] == '8' || s[left] == '9')
			{
				return false;
			}
			left++;
			if (s[left] == '-')
			{
				if ((s[left - 1] <= 'z' && s[left - 1] >= 'a') && (s[left + 1] <= 'z' && s[left + 1] >= 'a'))
				{
					flat++;
				}
				else
				{
					return false;
				}
			}
		}
		if (flat>1)
		{
			return false;
		}
		return true;
	}
	int countValidWords(string sentence) {
		int result = 0;
		int left = 0;//指向每个单词的头部
		int right = 0;//指向每个单词的尾部
		for (int i = 0; i < sentence.size(); i++)
		{
			if (sentence[i] != ' ')
			{
				right = i;
			}
			else
			{
				if (compare(sentence, left, right))
				{
					result++;
				}
				left = right=i+1;
			}
		}
		if (sentence[sentence.size() - 1] != ' ')
		{
			if (compare(sentence, left, right))
			{
				result++;
			}
		}
		return result;
	}
	ListNode* lowreverseBetween(ListNode* head, int left, int right) {
		if (left == right)
		{
			return head;
		}
		ListNode* fast = head, * slow = head,*newhead=nullptr,*prev=nullptr,*cur=nullptr,*next=nullptr;
		int left1 = left;
		while (left1<right)//2 4
		{
			fast = fast->next;
			left1++;
		}
		for (int i = 0; i <left-1 ; i++)
		{
			prev = slow;
			fast=fast->next;
			slow = slow->next;
		}
		if (slow==head)
		{
			newhead = fast;
		}
		else
		{
			newhead = head;
		}
		ListNode* pp = slow;
		cur = slow->next;
		next = cur->next;
		slow->next = fast->next;
		while (pp!=fast)
		{
			cur->next=pp;
			pp = cur;
			cur = next;
			if (next!=nullptr)
			{
				next = next->next;
			}
		}
		if (newhead!=fast)
		{
			prev->next = fast;
		}
		return newhead;
	}
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		ListNode* leftnode =head,*newhead=head, * rightnode = nullptr,*prev=nullptr,*next=nullptr,*cur=nullptr;
		for (int i=0;i<left-1;i++)
		{
			prev = leftnode;
			leftnode=leftnode->next;
		}
		rightnode = leftnode;
		for (int i = 0; i < right-left; i++)
		{
			rightnode = rightnode->next;
		}
		cur = leftnode;
		next = cur->next;
		ListNode* tmp = cur;
		while (tmp!=rightnode)
		{
			cur->next = next->next;
			next->next = tmp;
			tmp = next;
			next = cur->next;
		}
		if (left == 1)
		{
			newhead = tmp;
		}
		else
		{
			prev->next = tmp;
		}
		return newhead;
	}
	ListNode* reverseListNode(ListNode* head)
	{
		if (head==nullptr||head->next == nullptr)
		{
			return head;
		}
		ListNode* newhead = reverseListNode(head->next);
		head->next->next = head;
		head->next = nullptr;
		return newhead;
	}
	void _generateTree(vector<vector<int>>& ans,vector<int>& ret, int cur,int n,int sz)//n代表个数
	{
		if (cur<=0)
		{
			ret.push_back(0);
			return;
		}
		if (cur >= n)
		{
			ret.push_back(0);
			return;
		}
		_generateTree(ans,ret,cur-1,n,sz);
		
	}
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> result;
		if (n<1)
		{
			return result;
		}
		return result;
	}
	void _climb(int& ans,int& ret, int& n)
	{
		if (ret== n)
		{
			ans++;
			return;
		}
		if (ret > n)
		{
			return;
		}
		if (ret<=n)
		{
			ret += 1;
			_climb(ans, ret, n);
			ret -= 1;
		}
		else
		{
			return;
		}
		if (ret<=n)
		{
			ret += 2;
			_climb(ans, ret, n);
			ret -= 2;
		}
		else
		{
			return;
		}
	}
	int climbStairs(int n) {
		if (n == 1)
		{
			return 1;
		}
		int ans = 0;
		int ret = 0;
		_climb(ans,ret,n);
		return ans;
	}
	//int climbStairs(int n) {
	//	if (n == 1)
	//	{
	//		return 1;
	//	}
	//	int prev = 1;//2 11 2
	//	int cur = 1;
	//	int next = 0;
	//	n--;
	//	while (n--)
	//	{
	//		next = prev + cur;
	//		prev = cur;
	//		cur = next;
	//	}
	//	return next;
	//}
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* tmp = head;
		while (tmp != nullptr && tmp->next != nullptr)
		{
			if (tmp->val == tmp->next->val)
			{
				tmp->next = tmp->next->next;
			}
			else
			{
				tmp = tmp->next;
			}
		}
		return head;
	}
	vector<int> plusOne(vector<int>& digits) {
		int sz = digits.size()-1;
		while (sz>=-1)
		{//90
			if (digits[sz] == 9)
			{
				digits[sz--] = 0;
			}
			else
			{
				digits[sz] = digits[sz] + 1;
				return digits;
			}
		}
		digits.push_back(0);
		digits[0] = 1;
		return digits;
	}
	int divide(int dividend, int divisor) {
		int i = 0;
		int cur = 0;
		while (cur <= dividend)
		{
			cur += divisor;//3+3+3+3
			i++;
		}
		if (cur + divisor > dividend)
		{
			return i-1;
		}
		else
		{
			return i;
		}
	}
	//void _coinChange(vector<int>& coins,int& ans,int& cur,int amount,vector<int>& tmp)
	//{
	//	if (cur==amount)
	//	{
	//		tmp.push_back(ans);
	//		return;
	//	}
	//	if (cur > amount)
	//	{
	//		return;
	//	}
	//	for(int i=coins.size()-1;i>=0;i--)
	//	{
	//		if (coins[i] > amount)
	//		{
	//			continue;
	//		}
	//		cur += coins[i];
	//		ans++;
	//		_coinChange(coins,ans,cur,amount,tmp);
	//		if (tmp.size()!=0)
	//		{
	//			return;
	//		}
	//		ans--;
	//		cur -= coins[i];
	//	}
	//}
	//int coinChange(vector<int>& coins, int amount) {
	//	if (amount == 0)
	//	{
	//		return 0;
	//	}
	//	sort(coins.begin(),coins.end());
	//	if (coins[0] > amount)
	//	{
	//		return -1;
	//	}
	//	int ans = 0;
	//	int cur = 0;
	//	vector<int> tmp;
	//	_coinChange(coins, ans, cur, amount, tmp);
	//	if (tmp.size()==0)
	//	{
	//		return -1;
	//	}
	//	else 
	//	{
	//		/*sort(tmp.begin(),tmp.end());*/
	//		return tmp[0];
	//	}
	//}// F(S)=min{F(S-Ci)+1};F(0)==0 
	//	1  2 3
	//	5
	//F(5)=min{F(4)+1,F(3)+1,F(2)+1},F(4)=min{F(3)+1,F(2)+1,F(1)+1},
	//int _coinChange(vector<int>& coins, int amount,vector<int>& ans)
	//{
	//	if (amount == 0)
	//	{
	//		return 0;
	//	}
	//	if (amount < 0)
	//	{
	//		return -1;
	//	}
	//	int min = INI_MAX;
	//	for (int i = 0; i < coins.size(); i++)
	//	{
	//		if (amount - coins[i] >= 0)
	//		{
	//			if (ans[amount - coins[i]] != 0&&amount - coins[i]!=0)
	//			{
	//				min =min>ans[amount - coins[i]]? ans[amount - coins[i]]:min;
	//			}
	//			else
	//			{
	//				int ret=(min > _coinChange(coins, amount - coins[i], ans) + 1 ? _coinChange(coins, amount - coins[i], ans) + 1 : min);
	//				if (ret != 0)
	//				{
	//					min = ret;
	//				}
	//				ans[amount - coins[i]] = min;
	//			}
	//		}
	//	}
	//	if (min == INI_MAX)
	//	{
	//		return min = -1;
	//	}
	//	return min;
	//}
	//int _coinChange(vector<int>& coins, int amount, vector<int>& ans)
	//{
	//	if (amount == 0)
	//	{
	//		return 0;
	//	}
	//	if (ans[amount - 1] != 0)
	//	{
	//		return ans[amount - 1];
	//	}
	//	int min = INI_MAX;
	//	for (int i = 0; i < coins.size(); i++)
	//	{
	//		if (amount - coins[i] >= 0)
	//		{
	//			int ret = _coinChange(coins, amount - coins[i], ans);
	//			if (ret + 1 < min && ret >= 0)
	//			{
	//				min = ret + 1;
	//			}
	//		}
	//	}
	//	if (min == INI_MAX)
	//	{
	//		ans[amount - 1] = -1;
	//	}
	//	else
	//	{
	//		ans[amount - 1] = min;
	//	}
	//	return ans[amount - 1];
	//}
	//int coinChange(vector<int>& coins, int amount) {
	//	if (amount == 0)
	//	{
	//		return 0;
	//	}
	//	vector<int> ans(amount, 0);
	//	int ret = _coinChange(coins, amount, ans);
	//	return ret;
	//} F(n)=F(n-1)+F(n-2)
	int _coinChange(vector<int>& coins,vector<int>& ans, int amount)
	{
		if (amount==0)
		{
			return 0;
		}
		if (ans[amount-1]!=0)
		{
			return ans[amount-1];
		}
		int Min = INI_MAX;
		for (int i=0;i<coins.size();i++)
		{
			if (amount-coins[i]>=0)
			{
				int ret = _coinChange(coins, ans, amount - coins[i]);
				if (Min>ret+1&&ret!=-1)
				{
					Min = ret + 1;
				}
			}
		}
		if (Min== INI_MAX)
		{
			ans[amount-1] = -1;
		}
		else
		{
			ans[amount - 1] = Min;
		}
		return ans[amount-1];
	}
	int coinChange(vector<int>& coins, int amount) {
		if (amount==0)
		{
			return 0;
		}
		vector<int> ans(amount,0);
		return _coinChange(coins,ans,amount);
	}//F(n) = F(n - 1) + F(n - 2)  n-1,n-2,n-3
	int _fbio(int n,vector<int>& ans)
	{
		if (n <= 2)
		{
			return 1;
		}
		if (ans[n-1]!=0)
		{
			return ans[n-1];
		}
		ans[n-2]=_fbio(n-1, ans);
		ans[n - 3] = _fbio(n - 2, ans);
		return ans[n - 2]+ ans[n - 3];
	}
	int fbio(int n)
	{
		vector<int> ans(n,0);
		return _fbio(n,ans);
	}
	int TwoFind_(vector<int>& nums, int begin, int end, int target)
	{
		while (begin <= end)
		{
			int mid = (begin + end) >> 1;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] > target)
			{
				end = mid - 1;
			}
			else
			{
				begin = mid + 1;
			}
		}
		return -1;
	}//0-3,4-6   7
	int search(vector<int>& nums, int target) {
		int sz = nums.size();
		if (sz == 1)
		{
			return -1;
		}
		int ans = TwoFind_(nums, 0, sz - target - 1, target);
		if (ans != -1)
		{
			return ans;
		}
		ans = TwoFind_(nums, sz - target, sz - 1, target);
		return ans;
	}
}; //he bought 2 pencils, 3 erasers, and 1  pencil - sharpener.
//1 3 5 6   2   1
//0 1 2 3
//a b a a b c a c
//0 1 1 2 2 3 1 2
int main(){
	Solution s; //[-1, 2, 1, -4]  1
	//vector<int> nums = { 1, 2, 4, 8, 16, 32, 64, 128 };//0 1 1 1   -100
	//cout <<s.threeSumClosest(nums,82);
	//string digits = "237";
	//vector<string> tmp=s.letterCombinations(digits);
	//vector<string>::iterator iter;
	//for (iter = tmp.begin(); iter < tmp.end(); iter++)
	//{
	//	cout << *iter << endl;
	//}
	/*vector<int> con = {45646};
	vector<int> tt=s.fraction(con);//1刻15分钟，用8刻的钟确定5刻的中       120             75
	cout << tt[0] << " " << tt[1];*/
	//vector<int> tmp = { 91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245 };//{ 1000000000,1000000000,1000000000,1000000000 };//{ 4,-9,-2,-2,-7,9,9,5,10,-10,4,5,2,-4,-2,4,-9,5 };//{ -2,-1,-1,1,1,2,2 };//{ -3,-2,-1,0,0,1,2,3 };//{ 2,2,2,2,2 };// { 1,0,-1,0,-2,2 };
	//vector<int> tmp = { 1000000000,1000000000,1000000000,1000000000 };
	//vector<vector<int>> ret = s.fourSum(tmp, 0);//[[-3,-2,2,3],[-3,-1,1,3],[-3,0,0,3],[-3,0,1,2],[-2,-1,0,3],[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
	//for (int i = 0; i < ret.size(); i++)
	//{
	//	for (int j =0;j<ret[0].size();j++)
	//	{
	//		cout <<ret[i][j]<<" ";
	//	}
	//	cout << endl;
	//}
	//ListNode a1;
	//ListNode a2;
	//ListNode a3;
	//ListNode a4;
	//ListNode a5;
	//a1.val = 1;
	//a2.val = 1;
	//a3.val = 1;
	//a4.val = 1;
	//a5.val = 1;
	//a1.next = &a2;
	//a2.next = &a3;
	//a3.next = &a4;
	//a4.next = &a5;
	//a5.next =nullptr;
	////ListNode a6;
	////ListNode a7;
	////ListNode a8;
	//a1.val = 1;
	//a2.val = 2;
	//a3.val = 3;
	//a4.val = 4;
	//a5.val = 5;
	////a6.val = 6;
	////a7.val = 7;
	////a8.val = 8;
	//a1.next = &a2;
	//a2.next = &a3;
	//a3.next = &a4;
	//a4.next = &a5;
	//a5.next =nullptr;
	//a6.next = &a7;
	//a7.next = &a8;
	//a8.next = nullptr;
	//ListNode* prev = s.removeNthFromEnd(&a1, 5);
	//ListNode b;
	//b.val = 1;
	//b.next = nullptr;
	////ListNode* prev = s.removeNthFromEnd(&b, 1);
	//while (prev)
	//{
	//	cout << prev->val << " ";
	//	prev = prev->next;
	//}
	//ListNode* prev = s.swapPairs(nullptr);
	//while (prev)
 //   {
	//   cout << prev->val << " ";
	//   prev = prev->next;
 //   }
	//string s1 = "aaabaaabbbabaa";
	//string s2 = "babb";//0 0 0 1
	//cout << s.strStr(s1,s2) << endl;
	/*string sub = "abcabcabcabcdabcde";*/
	/*vector<int> next;
	s.nextArray(sub, next);*/
	//string s1 = "mississippi";
	//string s2 = "issip";
	//cout<<s.kmp(s1, s2);
	//vector<int> test = { -1,0 };
	//test=s.singleNumber(test);
	//vector<string> ret = s.generateParenthesis(20);
	//string tt = "cbacdcbc";
	//string ret = s.removeDuplicateLetters(tt);
	//for (int i=0; i < ret.size(); i++)
	//{
	//	cout << ret[i] << endl;
	//}
	//set<char> ss;
	//ss.insert('h');
	//ss.insert('a');
	//ss.insert('c');
	//ss.insert('r');
	//ss.insert('r');
	//set<char>::iterator ii;
	//for (ii=ss.begin();ii!=ss.end();ii++)
	//{
	//	cout << *ii << endl;
	//}
	//vector<int> t = {1,3};
	//cout << s.searchInsert(t,4) << endl;
	//cout << s.search(t,3) << endl;
	//string ss = "cbacdcbc";
	//string ss = "bcabc";
	//cout << s.removeDuplicateLetters(ss) << endl;
	//TreeNode a1 = {5,nullptr,nullptr};
	//TreeNode a2 = { 1,nullptr,nullptr };
	//TreeNode a3 = { 6,nullptr,nullptr };
	//TreeNode a4 = { 5,nullptr,nullptr };
	//TreeNode a5 = { 4,nullptr,nullptr };
	//TreeNode a6 = { 9,nullptr,nullptr };
	//TreeNode a7 = { 7,nullptr,nullptr };
	//a1.left = &a2;
	//a1.right = &a3;
	//a2.left = nullptr;
	//a2.right =nullptr;
	//a3.left = &a4;
	//a3.right = &a7;
	//a4.left = &a5;
	//a4.right = &a6;
	//a5.left = nullptr;
	//a5.right = nullptr;
	//a6.left = nullptr;
	//a6.right = nullptr;
	//a7.left = nullptr;
	//a7.right = nullptr;
	//vector<int> tmp=s.postorderTraversal(&a1);
	//cout << s.isValidBST(&a1) << endl;
   /* string t ="cbacdcbc";
	cout << s.removeDuplicateLetters1(t) << endl;*/
    //string tmp = "bddbccdhrtsjywghsehjrtrt";
    //cout << s.FirstNotRepeatingchar(tmp) << endl;
 //   string ss = " 62   nvtk0wr4f  8 qt3r! w1ph 1l ,e0d 0n 2v 7c.  n06huu2n9 s9   ui4 nsr!d7olr  q-, vqdo!btpmtmui.bb83lf g .!v9-lg 2fyoykex uy5a 8v whvu8 .y sc5 -0n4 zo pfgju 5u 4 3x,3!wl  fv4   s  aig cf j1 a i  8m5o1  !u n!.1tz87d3 .9    n a3  .xb1p9f  b1i a j8s2 cugf l494cx1! hisceovf3 8d93 sg 4r.f1z9w   4- cb r97jo hln3s h2 o .  8dx08as7l!mcmc isa49afk i1 fk,s e !1 ln rt2vhu 4ks4zq c w  o- 6  5!.n8ten0 6mk 2k2y3e335,yj  h p3 5 -0  5g1c  tr49, ,qp9 -v p  7p4v110926wwr h x wklq u zo 16. !8  u63n0c l3 yckifu 1cgz t.i   lh w xa l,jt   hpi ng-gvtk8 9 j u9qfcd!2  kyu42v dmv.cst6i5fo rxhw4wvp2 1 okc8!  z aribcam0  cp-zp,!e x  agj-gb3 !om3934 k vnuo056h g7 t-6j! 8w8fncebuj-lq    inzqhw v39,  f e 9. 50 , ru3r  mbuab  6  wz dw79.av2xp . gbmy gc s6pi pra4fo9fwq k   j-ppy -3vpf   o k4hy3 -!..5s ,2 k5 j p38dtd   !i   b!fgj,nx qgif ";
	//cout << s.countValidWords(ss) << endl;
	//ListNode* tmp = s.reverseBetween(&a1, 2, 4);
	//while (tmp!=nullptr)
	//{
	//	cout << tmp->val << "->";
	//	tmp = tmp->next;
	//}
	//cout << "null";
	//ListNode* tmp = s.reverseListNode(&a1);
	//while (tmp!=nullptr)
	//{
	//	cout << tmp->val << "->";
	//	tmp = tmp->next;
	//}
	//cout << "null";
	//vector<TreeNode*> tmp = s.generateTrees(3);// 111 12 21
//cout << s.climbStairs(8);//1 2 3 5 8 13 21 34
	//ListNode* tmp=s.deleteDuplicates(&a1);
	//while (tmp!=nullptr)
	//{
	//	cout << tmp->val << "->";
	//	tmp = tmp->next;
//	//}
////cout << s.divide(2949639,-1) << endl;[186,419,83,408]
	//vector<int> ret = { 186,419,83,408 };//83 186 408 416
	//cout << s.coinChange(ret, 6249) << endl;
	//cout << s.coinChange(ret, 6249) << endl;
	//vector<int> ret = {1,2,5};//83 186 408 416
	//cout << s.coinChange(ret,6) << endl;
	//cout << s.fbio(45) << endl;//1 1 2 3 5 8 13
	vector<int> tmp = {4,5,6,7,0,1,2};
	cout << s.search(tmp,0) << endl;
	return 0;
}
//    3+3+3+4=13,
// [1,2147483647]
// 2
// [186,419,83,408]
// 
//4 5 6 7 8
//5 4 7 6 8
// 
// [-2,-1,-1,1,1,2,2] 0
// 
// [4,-9,-2,-2,-7,9,9,5,10,-10,4,5,2,-4,-2,4,-9,5] -13
// 
// [1000000000,1000000000,1000000000,1000000000] 0
// [1,-2,-5,-4,-3,3,3,5] -11
// 
// [0,0,0,1000000000,1000000000,1000000000,1000000000]   1000000000
// 
// "mississippi" "issip"
// 
// 
// 
// "aaabaaabbbabaa"  "babb"        ))))))
// () ( ( ) )
//  1  2   3  )
//( ( ( 
//()()()            ()(())          
//(())()            (()())     
//((())) 
// 
// 1   2   3
// 2   2   1
//@Lin071411
//   (((((((((
// 
// 
// 
// 
// 
// 
//
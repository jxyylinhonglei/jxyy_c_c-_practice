#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Sloution
{
public:
	bool compare(string s,int i,int j)
	{
		int left = i;
		int right = j;
		while (left<=right)
		{
			if (s[left] != s[right])
			{
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
	string longestPalindrome(string s)
	{
		int sz = s.size();
		if (sz == 1)
		{
			return s;
		}
		int* tmp = new int[2];
		int ans = 0;
		int flat = 0;
		int k = 0;
		for (int i = 0; i < sz; i++)
		{
			for (int j = i+1; j < sz; j++)
			{
				if (compare(s, i, j))
				{
					if (ans<j-i+1)
					{
						ans = j - i + 1;
						tmp[0] = i;
						tmp[1] = j;
					}
					if (ans>=sz-i)
					{
						flat = 1;
						break;
					}
				}
			}
			if (flat == 1)
			{
				break;
			}
		}
		if (ans == 0)
		{
			string tt(1,'/0');
			tt[0] = s[0];
			return tt;
		}
		string yy(ans,'/0');
		for (int i = tmp[0]; i <= tmp[1]; i++)
		{
			yy[k] = s[i];
			k++;
		}
		delete tmp;
		return yy;
	}
};
struct ListNode
{
	int val;
	ListNode* next;
};
int main()
{
	/*Sloution s;
	string aa = "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
	string tmp=s.longestPalindrome(aa);
	cout << tmp << endl;*/
	//vector<int> a(3,1);
	//ListNode l1;
	//l1.val = 1;
	//l1.next = nullptr;
	//vector<ListNode> aa;
	//cout << aa.size() << endl;
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	/*vector<int> iterator*/
	cout<<a[0]<<endl;
	cout << a[1] << endl;
	return 0;
}
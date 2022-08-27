//#include<iostream>
//#include<vector>
//using namespace std;
//struct ListNode
//{
//    int val;
//    ListNode* next;
//};
//class Solution {
//public:
//    void getValue(ListNode* head,vector<int>& arr)
//    {
//        ListNode* list = head;
//        while (list)
//        {
//            arr.push_back(list->val);
//            list = list->next;
//        }
//    }
//    ListNode* insertVal(ListNode* head,vector<int>& listt)
//    {
//        ListNode* kk = head;
//        int i = 0;
//        while (kk)
//        {
//            kk->val = listt[i++];
//            kk = kk->next;
//        }
//        return kk;
//    }
//    void reverseval(vector<int>& arr,int left,int right)
//    {
//        while (left<=right)
//        {
//            int tmp = arr[left];
//            arr[left] = arr[right];
//            arr[right] = tmp;
//            left++;
//            right--;
//        }
//    }
//    ListNode* reverseKGroup(ListNode* head, int k)
//    {
//        vector<int> val;
//        getValue(head, val);
//        int sz = val.size()/k,i=0;
//        while (sz--)
//        {
//            reverseval(val,i,i+k-1);
//            i = i + k;
//        }
//        insertVal(head, val);
//        return head;
//    }
//};
//void test()
//{
//    Solution s;
//    ListNode a;
//    ListNode b;
//    ListNode c;
//    ListNode d;
//    ListNode e;
//    a.val = 1;
//    b.val = 2;
//    c.val = 3;
//    d.val = 4;
//    e.val = 5;
//    a.next = &b;
//    b.next = &c;
//    c.next = &d;
//    d.next = &e;
//    e.next =nullptr;
//    s.reverseKGroup(&a,2);
//}
//int main()
//{
//    test();
//	return 0;
//}
#include<iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
};
class Solution
{
public:
	ListNode* myReverse(ListNode* head, ListNode* tail)
	{
		ListNode* prev = tail->next, * nex = head->next,*cur=head;
		while (cur!=tail)
		{
			cur->next = prev;

			prev = cur;
			cur = nex;
			nex = nex->next;
		}
		cur->next = prev;
		return cur;
	}
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		ListNode* next=head,*prev=nullptr,*newhead=head,*pprev=head,*nnext=nullptr;
		while (next)
		{
			prev = next;
			for (int i = 0; i < k-1; i++)
			{
				next= next->next;
				if (!next)
				{
					return newhead;
				}
				nnext = next->next;
			}
			if (newhead==head)
			{
				newhead = myReverse(prev,next);
			} 
			else
			{
				ListNode* tt = myReverse(prev, next);
				pprev->next = tt;
				pprev = prev;
			}
			next = nnext;
		}
		return newhead;
	}
};
void test()
{
	Solution s;
    ListNode a;
    ListNode b;
    ListNode c;
    ListNode d;
    ListNode e;
    a.val = 1;
    b.val = 2;
    c.val = 3;
    d.val = 4;
    e.val = 5;
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next =nullptr;
	/*ListNode *tt=s.myReverse(&a,&c);*/
	ListNode* tt = s.reverseKGroup(&a,2);
	while (tt)
	{
		cout << tt->val << "->";
		tt = tt->next;
	}
	cout << "null" << endl;
}
int BF(const char* sub,const char* str)
{
	int i = 0,j = 0;
	while (sub[i]!='\0'&&str[j]!='\0')//sub目标串，str模式串
	{
		if (sub[i] == str[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (str[j]=='\0')
	{
		return i-j+1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	//test();
	const char* sub = "abcdefg";
	const char* str = "def";
	cout << BF(sub,str) << endl;
	return 0;
}

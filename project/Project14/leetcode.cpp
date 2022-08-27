//#include<iostream>
//#include<vector>
//using namespace std;
//struct ListNode
//{
//	int val;
//	ListNode* next;
//};
//class Solution
//{
//public:
//	ListNode* mergedoublelists(ListNode* L1, ListNode* L2)
//	{
//		ListNode** begin = new ListNode*;
//		ListNode** end = new ListNode*;
//		*begin = nullptr;
//		*end = nullptr;
//		while (L1 != nullptr && L2 != nullptr)
//		{
//			if (L1->val < L2->val)
//			{
//				if (*begin== nullptr)
//				{
//					ListNode* tmp=new ListNode;
//					tmp->next = nullptr;
//					*begin = *end = tmp;
//					tmp->val = L1->val;
//				}
//				else
//				{
//					ListNode* tmp = new ListNode;
//					tmp->next = nullptr;
//					tmp->val = L1->val;
//					(*end)->next = tmp;
//					(*end) = (*end)->next;
//				}
//				L1 = L1->next;
//			}
//			else
//			{
//				if ((*begin) == nullptr)
//				{
//					ListNode* tmp = new ListNode;
//					tmp->next = nullptr;
//					tmp->val = L2->val;
//					(*begin) = (*end) = tmp;
//				}
//				else
//				{
//					ListNode* tmp = new ListNode;
//					tmp->next = nullptr;
//					tmp->val = L2->val;
//					(*end)->next = tmp;
//					(*end) = (*end)->next;
//				}
//				L2 = L2->next;
//			}
//		}
//		while (L1)
//		{
//			if (*begin == nullptr && *end == nullptr)
//			{
//				*begin=(*end) = L1;
//			}
//			else
//			{
//				(*end)->next = L1;
//				(*end) = (*end)->next;
//			}
//			L1 = L1->next;
//		}
//		while (L2)
//		{
//			if (*begin == nullptr&& *end == nullptr)
//			{
//				*begin = (*end) = L2;
//			}
//			else
//			{
//				(*end)->next = L2;
//				(*end) = (*end)->next;
//			}
//			L2 = L2->next;
//		}
//		return *begin;
//	}
//	ListNode* mergeKLists(vector<ListNode*>& lists)
//	{
//		int sz = lists.size();
//		if (sz == 0)
//		{
//			return nullptr;
//		}
//		if (sz == 1)
//		{
//			return lists[0];
//		}
//		ListNode** tmp = new ListNode*;
//		for (int i = 1; i < sz; i++)
//		{
// 			if (i == 1)
//			{
//				*tmp = mergedoublelists(lists[0], lists[1]);
//			}
//			else
//			{
//				*tmp = mergedoublelists(*tmp, lists[i]);
//			}
//		}
//		return *tmp;
//	}
//};
//void test()
//{
//	////Á´±í1
//	//ListNode a;
//	//a.val = 1;
//	//ListNode b;
//	//b.val = 4;
//	//ListNode c;
//	//c.val = 5;
//	//a.next = &b;
//	//b.next = &c;
//	//c.next = nullptr;
//	////Á´±í2
//	//ListNode a1;
//	//a1.val = 1;
//	//ListNode b1;
//	//b1.val = 3;
//	//ListNode c1;
//	//c1.val = 4;
//	//a1.next = &b1;
//	//b1.next = &c1;
//	//c1.next = nullptr;
//	////Á´±í3
//	//ListNode a3;
//	//a3.val = 2;
//	//ListNode b3;
//	//b3.val = 6;
//	//a3.next = &b3;
//	//b3.next = nullptr;
//	//vector<ListNode*> push1;
//	//push1.push_back(&a);
//	//push1.push_back(&a1);
//	//push1.push_back(&a3);
//	//Solution s;
//	//ListNode* begin=s.mergeKLists(push1);
//	//while (begin)
//	//{
//	//	cout << begin->val << endl;
//	//	begin = begin->next;
//	//}
//	//ListNode* tmp=nullptr;
//	//while (begin)
//	//{
//	//	tmp = begin;
//	//	begin = begin->next;
//	//	delete tmp;
//	//}
//	Solution s;
//	ListNode a;
//	a.val = 2;
//	a.next = nullptr;
//	vector<ListNode*> push1;
//	push1.push_back(nullptr);
//    push1.push_back(&a);
//	ListNode* begin=s.mergeKLists(push1);
//while (begin)
//{
//	cout << begin->val << endl;
//	begin = begin->next;
//}
//}
//int main()
//{
//	test();
//	return 0;
//}

//#include<iostream>
//#include<vector>
//using namespace std;
//struct ListNode
//{
//	int val;
//	ListNode* next;
//};
//class Solution
//{
//public:
//	ListNode* mergeDoubleListNode(ListNode* ans1,ListNode* ans2)
//	{
//		ListNode* head = nullptr,*tail = nullptr;
//		if ((!ans1)||(!ans2))
//		{
//			return ans1 ? ans1 : ans2;
//		}
//		else
//		{
//			while (ans1&&ans2)
//			{
//				if (ans1->val < ans2->val)
//				{
//					if (!head)
//					{
//						head = tail = ans1;
//					}
//					else
//					{
//						tail->next = ans1;
//						tail = ans1;
//					}
//					ans1 = ans1->next;
//				}
//				else
//				{
//					if (!head)
//					{
//						head = tail = ans2;
//					}
//					else
//					{
//						tail->next = ans2;
//						tail = ans2;
//					}
//					ans2 = ans2->next;
//				}
//			}
//			//if (ans1)
//			//{
//			//	tail->next = ans1;
//			//}
//			//else
//			//{
//			//	tail->next = ans2;
//			//}
//			tail->next =(ans1?ans1:ans2);
//		}
//		return head;
//	}
//	ListNode* mergeKLists(vector<ListNode*>& lists)
//	{
//		if (lists.size()==0) 
//		{
//			return nullptr;
//		}
//		ListNode* tmp = lists[0];
//		for(int i=1;i< lists.size();i++)
//		{
//			tmp= mergeDoubleListNode(tmp, lists[i]);
//		}
//		return tmp;
//	}
//};
//void test()
//{
//	Solution s;
//	ListNode a;
//	ListNode b;
//	ListNode c;
//	ListNode a1;
//	ListNode b1;
//	ListNode c1;
//	ListNode a2;
//	ListNode b2;
//	ListNode c2;
//	a.val = 1;
//	b.val = 4;
//	c.val = 5;
//	a1.val = 1;
//	b1.val = 3;
//	c1.val = 4;
//	a2.val = 2;
//	b2.val = 6;
//	a.next = &b;
//	b.next = &c;
//	c.next = nullptr;
//	a1.next = &b1;
//	b1.next = &c1;
//	c1.next = nullptr;
//	a2.next = &b2;
//	b2.next = nullptr;
//	vector<ListNode*>tt;
//	tt.push_back(&a);
//	tt.push_back(&a1);
//	tt.push_back(&a2);
//	ListNode* tmp=s.mergeKLists(tt);
//	while (tmp)
//	{
//		cout << tmp->val<<"->";
//		tmp = tmp->next;
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}
//#include<iostream>
//#include<vector>
//using namespace std;
//struct ListNode
//{
//	int val;
//	ListNode* next;
//};
//class Solution
//{
//public:
//	ListNode* mergeTowListNode(ListNode* ans1,ListNode* ans2)
//	{
//		if ((!ans1)||(!ans2))
//		{
//			return ans1 ? ans1 : ans2;
//		}
//		ListNode* head=nullptr,*tail=nullptr;
//		while (ans1&&ans2)
//		{
//			if (ans1->val < ans2->val)
//			{
//				if (!head)
//				{
//					head = tail =ans1;
//				}
//				else
//				{
//					tail->next=ans1;
//					tail = tail->next;
//				}
//				ans1 = ans1->next;
//			}
//			else
//			{
//				if (!head)
//				{
//					head = tail = ans2;
//				}
//				else
//				{
//					tail->next = ans2;
//					tail=tail->next;
//				}
//				ans2 = ans2->next;
//			}
//		}
//		tail->next =(ans1?ans1:ans2);
//		return head;
//	}
//	ListNode* merge(vector<ListNode*> &list,int left,int right)
//	{
//		if (left == right)
//		{
//			return list[left];
//		}
//		if (left > right)
//		{
//			return nullptr;
//		}
//		int mid = (left + right) >> 1;
//		return mergeTowListNode(merge(list,left,mid),merge(list,mid+1,right));
//	}
//	ListNode* mergeKLists(vector<ListNode*>& Lists)
//	{
//		return merge(Lists,0,Lists.size()-1);//0 3
//	}
//};
//void test()
//{
//	Solution s;
//	ListNode a;
//	ListNode b;
//	ListNode c;
//	ListNode a1;
//	ListNode b1;
//	ListNode c1;
//	ListNode a2;
//	ListNode b2;
//	ListNode c2;
//	a.val = 1;
//	b.val = 4;
//	c.val = 5;
//	a1.val = 1;
//	b1.val = 3;
//	c1.val = 4;
//	a2.val = 2;
//	b2.val = 6;
//	a.next = &b;
//	b.next = &c;
//	c.next = nullptr;
//	a1.next = &b1;
//	b1.next = &c1;
//	c1.next = nullptr;
//	a2.next = &b2;
//	b2.next = nullptr;
//	vector<ListNode*>tt;
//	tt.push_back(&a);
//	tt.push_back(&a1);
//	tt.push_back(&a2);
//	ListNode* tmp=s.mergeKLists(tt);
//	while (tmp)
//	{
//		cout << tmp->val<<"->";
//		tmp = tmp->next;
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
};
class Solution
{
public:
	ListNode* mergeDoubleListNode(ListNode* ans1,ListNode* ans2)
	{
		if ((!ans1)||(!ans2))
		{
			return ans1 ? ans1 : ans2;
		}
		ListNode* head=nullptr, * tail=nullptr;
		while (ans1&&ans2)
		{
			if (ans1->val<ans2->val)
			{
				if (head==nullptr)
				{
					head = tail = ans1;
				}
				else
				{
					tail->next =ans1;
					tail = tail->next;
				}
				ans1 = ans1->next;
			}
			else
			{
				if (head == nullptr)
				{
					head = tail = ans2;
				}
				else
				{
					tail->next = ans2;
					tail = tail->next;
				}
				ans2 = ans2->next;
			}
		}
		tail->next = ans1 ? ans1 : ans2;
		return head;
	}
	ListNode* merge(vector<ListNode*> &tt,int left,int right)
	{
		if (left>right)
		{
			return nullptr;
		}
		if (left==right)
		{
			return tt[left];
		}
		int mid = (left + right) >> 1;
		return mergeDoubleListNode(merge(tt,left,mid),merge(tt,mid+1,right));
	}
	ListNode* mergeKLists(vector<ListNode*> &lists)
	{
		return merge(lists,0,lists.size()-1);
	}
};
void test()
{
	Solution s;
	ListNode a;
	ListNode b;
	ListNode c;
	ListNode a1;
	ListNode b1;
	ListNode c1;
	ListNode a2;
	ListNode b2;
	ListNode c2;
	a.val = 1;
	b.val = 4;
	c.val = 5;
	a1.val = 1;
	b1.val = 3;
	c1.val = 4;
	a2.val = 2;
	b2.val = 6;
	a.next = &b;
	b.next = &c;
	c.next = nullptr;
	a1.next = &b1;
	b1.next = &c1;
	c1.next = nullptr;
	a2.next = &b2;
	b2.next = nullptr;
	vector<ListNode*>tt;
	tt.push_back(&a);
	tt.push_back(&a1);
	tt.push_back(&a2);
	ListNode* tmp=s.mergeKLists(tt);
	while (tmp)
	{
		cout << tmp->val<<"->";
		tmp = tmp->next;
	}
}
int main()
{
	test();
	return 0;
}
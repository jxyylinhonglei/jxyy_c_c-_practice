#include<iostream>
using namespace std;
#include<vector>
struct ListNode
{
	int val;
     ListNode* next;
};
class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1,ListNode* l2)
	{
		ListNode* begin = nullptr;
		ListNode* end = nullptr;
		ListNode* tmp = nullptr;
		int j = 0; int tmp1 = 0;
		while (l1!=nullptr&&l2!=nullptr)
		{
		    tmp=new ListNode;
			tmp->next = nullptr;
			 tmp1 = l1->val + l2->val+j;
			if (tmp1 > 9)
			{
				tmp->val = tmp1%10;
				j = 1;
			}
			else
			{
				tmp->val = tmp1;
				j = 0;
			}
			if (begin == nullptr)
			{
				begin = end = tmp;
			}
			else
			{
				end->next = tmp;
				end = tmp;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1)//l1²»¿ÕÊ±
		{
			if (begin == nullptr)
			{
				while (l1)
				{
					tmp = new ListNode;
					tmp->val = l1->val;
					if (begin == nullptr)
					{
						begin = end = tmp;
					}
					else
					{
						end->next = tmp;
					}
					l1 = l1->next;
				}
				break;
			}
			else
			{
				/*tmp1 = l1->val + j;
				end->next = l1;
				if (tmp1 > 9)
				{
					j = 1;
					end->val = tmp1 % 10;
				}
				else
				{

				}*/
				end->next = l1;
				end = l1;
				if (j == 1)
				{
					tmp1 = end->val + j;
					if (tmp1 > 9)
					{
						j = 1;
						end->val = tmp1 % 10;
					}
					else
					{
						j = 0;
						end->val = tmp1;
					}
				}
				else
				{
					while (end->next)
					{
						end = end->next;
					}
					break;
				}
			}
			l1 = l1->next;
		}
		while (l2)
		{
			if (begin == nullptr)
			{
				begin = end = l2;
				break;
			}
			else
			{
				end->next = l2;
				end = l2;
				if (j == 1)
				{
					tmp1 = j + end->val;
					if (tmp1 > 9)
					{
						end->val = tmp1%10;
						j = 1;
					}
					else
					{
						j = 0;
						end->val = tmp1;
						while (end->next)
						{
							end = end->next;
						}
						break;
					}
				}
			}
			l2 = l2->next;
		}
		if (j == 1)
		{
			tmp = new ListNode;
			tmp->next = nullptr;
			tmp->val = 1;
			end->next= tmp;
		}
		return begin;
	}
};
int main()
{
	/*ListNode a;
	a.val = 2;
	ListNode b;
	b.val = 4;
	ListNode c;
	ListNode d;
	d.val = 5;
	c.val = 3;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = nullptr;*/

	//ListNode e;
	//e.val = 5;
	//ListNode f;
	//f.val = 6;
	//ListNode g;
	//g.val = 4;
	//e.next = &f;
	//f.next = &g;
	//g.next = nullptr;
	/*ListNode a;
	a.val = 0;
	a.next = nullptr;
	ListNode e;
	e.val = 0;
	e.next = nullptr;*/
	//Solution s;
	//ListNode* tmp=s.addTwoNumbers(nullptr,&e);

	//while (tmp)
	//{
	//	cout << tmp->val << endl;
	//	ListNode* a = tmp;
	//	tmp = tmp->next;
	//	/*delete a;*/
	//}
	/*vector<int [2]> a;*/
	/*a.push_back();*/

	return 0;
}

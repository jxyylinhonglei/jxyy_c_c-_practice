
//void merge1(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//    int i1 = 0, i2 = 0, ai = 0;
//    if (m == 1 && n == 0)
//    {
//        return;
//    }
//    else if (m == 0 && n == 1)
//    {
//        nums1[i1] = nums2[i2];
//    }
//    else
//    {
//        int* arr = (int*)malloc(sizeof(int) * (m + n));
//        while ((i1 < m) && (i2 < n))
//        {
//            if (nums1[i1] < nums2[i2])
//            {
//                arr[ai] = nums1[i1];
//                i1++;
//                ai++;
//            }
//            else
//            {
//                arr[ai] = nums2[i2];
//                i2++;
//                ai++;
//            }
//        }
//        if (i1 == m)
//        {
//            while (i2 < n)
//            {
//                arr[ai] = nums2[i2];
//                i2++;
//                ai++;
//            }
//            for (int i = 0; i < m + n; i++)
//            {
//                nums1[i] = arr[i];
//            }
//            free(arr);
//            arr = NULL;
//        }
//        else if (i2 == n)
//        {
//            while (i1 < m)
//            {
//                arr[ai] = nums1[i1];
//                i1++;
//                ai++;
//            }
//            for (int i = 0; i < m + n; i++)
//            {
//                nums1[i] = arr[i];
//            }
//            free(arr);
//            arr = NULL;
//        }
//        else
//        {
//            for (int i = 0; i < m + n; i++)
//            {
//                nums1[i] = arr[i];
//            }
//            free(arr);
//            arr = NULL;
//        }
//    }
//}
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
//    int p1 = 0, p2 = 0, i = m - 1;
//    if (m == 0)
//    {
//        while (p2 < n)
//        {
//            nums1[p1] = nums2[p2];
//            p1++;
//            p2++;
//        }
//    }
//    else if (m == 1 && n == 1)
//    {
//        if (nums1[p1] > nums2[p2])
//        {
//            nums1[p1 + 1] = nums1[p1];
//            nums1[p1] = nums2[p2];
//        }
//        else if (nums1[p1] == nums2[p2])
//        {
//            nums1[p1 + 1] = nums1[p2];
//        }
//        else
//        {
//            nums1[p1 + 1] = nums2[p2];
//        }
//    }
//    else
//    {
//        while (p2 < n)
//        {
//            if (nums1[p1] > nums2[p2])
//            {
//                for (int j = i; j >= p1; j--)
//                {
//                    nums1[j + 1] = nums1[j];
//                }
//                nums1[p1] = nums2[p2];
//                p1 += 1;
//                p2++;
//                i++;
//            }
//            else if (nums1[p1] == nums2[p2])
//            {
//                for (int j = i; j > p1; j--)
//                {
//                    nums1[j + 1] = nums1[j];
//                }
//                nums1[p1 + 1] = nums2[p2];
//                p1 += 1;
//                p2++;
//                i++;
//            }
//            else
//            {
//                if (p1 < i)
//                {
//                    p1++;
//                }
//                else
//                {
//                    while (p2 < n)
//                    {
//                        nums1[p1 + 1] = nums2[p2];
//                        p1++;
//                        p2++;
//                    }
//                }
//            }
//        }
//    }
//}
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* newhead = NULL, * cur = NULL, * prev = NULL, * tail = head,*ps=head;
//    int i = 0;
//    while (ps)
//    {
//        ps = ps->next;
//        i++;
//    }
//    while (i--)//(prev!=tail)&&(prev==NULL)½áÊøÌõ¼þ
//    {
//        prev = cur = head;
//        while (cur->next)
//        {
//            prev = cur;
//            cur = cur->next;
//        }
//        prev->next = NULL;
//        if (newhead == NULL)
//        {
//            newhead = tail = cur;
//        }
//        else
//        {
//            tail->next = cur;
//            tail = cur;
//        }
//    }
//    return newhead;
//}
//struct ListNode* reverseList(struct ListNode* head) {
//    struct ListNode* prev = NULL, * cur = head;
//    while (cur)
//    {
//        struct ListNode* tmp = cur->next;
//        cur->next = prev;
//        prev = cur;
//        cur = tmp;
//    }
//    return prev;
//}
//void test()
//{
//   /* int nums1[] = { 0,2,0,0,0,0,0,0 };
//    int nums2[]= { -1, 1, 1, 2, 2, 3 };
//    merge(nums1, 8, 2, nums2,6,6);*/
//    struct ListNode a;
//    a.val = 1;
//    struct ListNode b;
//    b.val = 2;
//    a.next = &b;
//    struct ListNode c;
//    c.val = 3;
//    b.next = &c;
//    struct ListNode d;
//    d.val = 4;
//    c.next = &d;
//
//    struct ListNode e;
//    e.val = 5;
//    d.next = &e;
//    e.next=NULL;
//    reverseList(&a);
//}
//int main()
//{
//    test();
//    return 0;
//}
//struct ListNode {
//    int val;
//    struct ListNode* next;
//};
//ListNode* partition(ListNode* pHead, int x) {
//
//    ListNode* cur = pHead, * newhead1 = NULL, * newhead2 = NULL, * tail1 = NULL, * tail2 = NULL;
//    if (cur == NULL || cur->next == NULL)
//    {
//        return cur;
//    }
//    while (cur)
//    {
//        if (cur->val < x)
//        {
//            if (newhead1 == NULL)
//            {
//                newhead1 = tail1 = cur;
//                cur = cur->next;
//                tail1->next = NULL;
//            }
//            else
//            {
//                tail1->next = cur;
//                tail1 = cur;
//                cur = cur->next;
//                tail1->next = NULL;
//            }
//        }
//        else
//        {
//            if (newhead2 == NULL)
//            {
//                newhead2 = tail2 = cur;
//                cur = cur->next;
//                tail2->next = NULL;
//            }
//            else
//            {
//                tail2->next = cur;
//                tail2 = cur;
//                cur = cur->next;
//                tail2->next = NULL;
//            }
//        }
//    }
//    tail1->next = newhead2;
//    return newhead1;
//    // write code here
//}
//void test()
//{
//    struct ListNode a;
//    a.val = 1;
//    struct ListNode b;
//    b.val = 4;
//    a.next = &b;
//    struct ListNode c;
//    c.val=3;
//    b.next = &c;
//    struct ListNode d;
//    d.val = 2;
//    c.next = &d;
//    struct ListNode e;
//    e.val = 5;
//    d.next = &e;
//    struct ListNode f;
//    f.val = 1;
//    e.next = &f;
//    f.next = NULL;
//    struct ListNode *ps=partition(&a,4);
//}
//int main()
//{
//    test();
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//struct ListNode {
//	int val;
//	struct ListNode* next;
//};
//ListNode* deleteDuplication(ListNode* pHead) {
//    if (pHead == NULL || pHead->next == NULL)
//    {
//        return pHead;
//    }
//    ListNode* prev = NULL, * cur = pHead, * next = pHead->next, * newhead = NULL;
//    while (next)
//    {
//        if (cur->val == next->val)
//        {
//            while (cur->val == next->val && next != NULL)
//            {
//                next = next->next;
//            }
//            if (next == NULL)
//            {
//                if (prev == NULL)
//                {
//                    return NULL;
//                }
//                else
//                {
//                    prev->next = NULL;
//                }
//            }
//            if (newhead == NULL)
//            {
//                newhead = prev = cur = next;
//                next = next->next;
//            }
//            else
//            {
//                prev->next = next;
//                cur = next;
//                if (next != NULL)
//                    next = next->next;
//            }
//        }
//        else
//        {
//            if (newhead == NULL)
//            {
//                newhead = cur;
//            }
//            prev = cur;
//            cur = next;
//            next = next->next;
//        }
//    }
//    return newhead;
//}
//void test()
//{
//	struct ListNode a;
//	a.val = 1;
//	struct ListNode b;
//	b.val = 2;
//	a.next = &b;
//	struct ListNode c;
//	c.val = 3;
//	b.next = &c;
//	struct ListNode d;
//	d.val = 3;
//	c.next = &d;
//	struct ListNode e;
//	e.val = 4;
//	d.next = &e;
//	struct ListNode f;
//	f.val = 4;
//	e.next = &f;
//	struct ListNode g;
//	g.val=5;
//    f.next = &g;
//	g.next = NULL;
//    struct ListNode* tmp=deleteDuplication(&a);
//}
//
//int main()
//{
//	test();
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef char DataType;
struct Stack
{
    DataType data;
    struct Stack* next;
};
void InsertStack(struct Stack* *ps, DataType x)
{
    struct Stack* tmp = (struct Stack*)malloc(sizeof(struct Stack));
    tmp->next = NULL;
    tmp->data = x;
    if (*ps == NULL)
    {
        *ps= tmp;
    }
    else
    {
        struct Stack* cur = *ps;
        while (cur->next)
        {
            cur= cur->next;
        }
        cur->next = tmp;
    }
}
DataType PopStack(struct Stack** ps)
{
    struct Stack* pp = NULL;
    if ((*ps)->next == NULL)
    {
        DataType tmp = (*ps)->data;
        free(*ps);
        *ps = NULL;
        return tmp;
    }
    else
    {
        struct Stack* cur = *ps;
        while (cur->next)
        {
            pp = cur;
            cur = cur->next;
        }
        DataType tmp = cur->data;
        pp->next = NULL;
        free(cur);
        cur = NULL;
        return tmp;
    }
}
void StackDestory(struct Stack** ps)
{
    struct Stack* pp = NULL;
    struct Stack* cur =*ps;
    while (cur)
    {
        pp = cur;
        cur=cur->next;
        free(pp);
        pp = NULL;
    }
}
bool isValid(char* s) {//(,)[,]
    struct Stack* cur= NULL;
    char tmp;
    while (*s)
    {
        tmp = *s;
        if (tmp == '(' || tmp == '[' || tmp == '{')
        {
            InsertStack(&cur,tmp);
        }
        else
        {
            if (cur == NULL)
            {
                return false;
            }
            else
            {
                char res = PopStack(&cur);
                if (tmp == ')' && res == '(')
                {
                    s++;
                    continue;
                }
                else if (tmp == ']' && res == '[')
                {
                    s++;
                    continue;
                }
                else if (tmp == '}' && res == '{')
                {
                    s++;
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        s++;
    }
    if (tmp == '(' || tmp == '[' || tmp == '{')
    {
        return false;
    }
    else if (cur)
    {
        return false;
    }
    else
    {
        return true;
    }
}//(,)[,]
int main()
{
    char s[] = "(([]){})";
    if (!isValid(s))
    {
        printf("false");
    }
    return 0;
}

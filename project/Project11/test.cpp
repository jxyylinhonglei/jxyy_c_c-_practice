//#include <map> 
//#include <iostream>
//using namespace std;
//int main()
//{
//    map < int, int > m1, m2, m3;
//    map < int, int >::iterator m1_Iter;
//    m1.insert(pair < int, int >(1, 10));
//    m1.insert(pair < int, int >(2, 20));
//    m1.insert(pair < int, int >(3, 30));
//    m2.insert(pair < int, int >(10, 100));
//    m2.insert(pair < int, int >(20, 200));
//    m3.insert(pair < int, int >(30, 300));
//    cout << "The original map m1 is:";
//    for (m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
//        cout << " " << m1_Iter->second;
//    cout << "." << endl;
//    // This is the member function version of swap
//    //m2 is said to be the argument map; m1 the target map
//    m1.swap(m2);
//    cout << "After swapping with m2, map m1 is:";
//    for (m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
//        cout << " " << m1_Iter->second;
//    cout << "." << endl;
//    cout << "After swapping with m2, map m2 is:";
//    for (m1_Iter = m2.begin(); m1_Iter != m2.end(); m1_Iter++)
//        cout << " " << m1_Iter->second;
//    cout << "." << endl;
//    // This is the specialized template version of swap
//    swap(m1, m3);
//    cout << "After swapping with m3, map m1 is:";
//    for (m1_Iter = m1.begin(); m1_Iter != m1.end(); m1_Iter++)
//        cout << " " << m1_Iter->second;
//    cout << "." << endl;
//}             //  É¾³ıËùÓĞÔªËØ
//#include<iostream>
//#include<unordered_set>
//using namespace std;
//int main()
//{
//	unordered_set<char> s;
//	s.insert('a');
//	s.insert('b');
//	s.insert('a');
//	cout << "a" << endl;
//	cout <<s.count('a')<< endl;
//	return 0;
//}
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int left = 0;
        int right = 0;
        int ans = 0;
        int ans1 = 0;
        int k = l1 + l2;
        int check = 0;
        if (l1 == 0 && l2 == 0)
        {
            return (double)0;
        }
        if (l1 == 0 && l2 == 1)
        {
            return (double)nums2[0];
        }
        if (l1 == 1 && l2 == 0)
        {
            return (double)nums1[0];
        }
        if ((l1+l2)%2==0)
        {
            k = (l1 + l2) / 2;
            check = 1;
        }
        else
        {
            k= (l1 + l2) / 2+1;
        }
        while (left+right<k)
        {
            if (left<l1&&right<l2)
            {
                if (nums1[left] < nums2[right])
                {
                    ans = nums1[left];
                    left++;
                }
                else
                {
                    ans = nums2[right];
                    right++;
                }
            }
            else if (left < l1&&l2==right)
            {
                ans = nums1[left];
                left++;
            }
            else
            {
                ans = nums2[right];
                right++;
            }
        }
        if (check==0)
        {
            return (double)ans;
        }
        else
        {
            if (left<l1&&right<l2)
            {
                if (nums1[left]<nums2[right])
                {
                    ans1 = nums1[left];
                }
                else
                {
                    ans1 = nums2[right];
                }
            }
            else if (left==l1&&right<l2)
            {
                ans1 = nums2[right];
            }
            else
            {
                ans1 = nums1[left];
            }
        }
        return (double)(ans + ans1) / (double)2;
    }
};
int main()
{
	/*vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);*/
   /* int  a= 3;
    int b = 2;
	cout << (double)a/(double)2 << endl;*/
    vector<int> a;
    vector<int> b;
    a.push_back(1);
    a.push_back(2);
   /* b.push_back(3);*/
    b.push_back(4);
    class Solution s;
    cout << s.findMedianSortedArrays(a,b) << endl;
	return 0;
}
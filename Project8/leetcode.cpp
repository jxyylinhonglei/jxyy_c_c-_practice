//////#include<iostream>
//////#include<vector>
//////using namespace std;
//////class Solution {
//////public:
//////	void _combine(int n,int k,int cur,int prev) {//cur代表有几位数了
//////		if (cur==k) {
//////			ans.push_back(ret);
//////			return;
//////		}
//////		for (int i = prev; i <= n;i++) {
//////			ret.push_back(i);
//////			_combine(n,k,cur+1,i+1);
//////			ret.pop_back();
//////		}
//////	}
//////	vector<vector<int>> combine(int n, int k) {
//////		_combine(n,k,0,1);
//////		return ans;
//////	}
//////private:
//////	vector<vector<int>> ans;
//////	vector<int> ret;
//////};
//////void test() {
//////	//Solution s;
//////	//vector<vector<int>> ans=s.combine(1,1);
//////	//for (int i = 0; i < ans.size();i++) {
//////	//	for (int j = 0; j < ans[i].size();j++) {
//////	//		cout << ans[i][j];
//////	//	}
//////	//	cout << endl;
//////	//}
//////	float sum = 0;
//////	float sum1 = 0.01;
//////	for (int i = 0; i < 100;i++) {
//////		sum += sum1;
//////	}
//////	printf("%f\n", sum);
//////	//char arrr[] = {1,4,9999};
//////	//const int a = 10;
//////	//int arr[a];
//////	//cout << "tamade"    "caonilaomu" << endl;//下面击中方式等价
//////	//cout << "tamadecaonilaomu" << endl;
//////	//cout << "tamade"
//////	//	"caonilaomu" << endl;
//////
//////	//cin输入遇到空格或者回车键就结束，剩下的存放在内存中
//////	//char name1[10];
//////	//char name2[10];
//////	//cout << "tamade" << endl;
//////	//cin >> name1;
//////	//cout << "hahah" << endl;
//////	//cin >> name2;
//////	//cout << name1 << endl;
//////	//cout << name2 << endl;
//////
//////	//而cin中getline()与get()是获取行，遇到回车键就结束，两者的区别是getline会将回车键丢弃，而get()时报存在内存中
//////	//char name1[10];
//////	//char name2[10];
//////	//cin.get(name1,20);
//////	//cin.get();
//////	//cin.get(name2,20);
//////	//等价于
//////	//cin.get(name1,20).get();
//////	//或者是
//////	//cin.getline(name1, 20).getline(name2,20);
//////	//cout << name1 << endl;
//////	//cout << name2 << endl;
//////	//cout << "66" << endl;
//////}
//////int main() {
//////	test();
//////	return 0;
//////}
////#include<iostream>
////#include<string>
////#include<cstring>
////using namespace std;
////struct name {
////	unsigned int age:2;
////	int tmp : 1;
////};
////int main() {
////	name ret = {-1,-1};
////	cout << ret.age << endl;
////	cout << ret.tmp << endl;
////	//name ret{
////	//	"qwertty",
////	//	19,
////	//	"tgbb"
////	//};
////	//cout << ret.age << endl;
////	//cout << ret.str << endl;
////	//cout << ret.tmp << endl;
////	//char name1[10] = "asdfgh";
////	//char name2[10];
////	//name2 = name1;
////	//cout << name2 << endl;
////	//string name1 = "haha";
////	//string name2="heihei";
////	//string name3 = name1 + name2;
////	return 0;
////}
//#include<iostream>
//#include<array>
//#include<vector>
//using namespace std;
//int main() {
//	//int tmp3[5] = {1,2,3,4,5};
//	//vector<int> tmp1={1,2,3,4,5};
//	//array<int, 5> tmp2{1,2,3,4,5};
//	//cout << tmp1[0] << " " << &tmp1[0] << "   " << tmp2[0] << " " << &tmp2[0] << "   " << tmp3[0] << " " << &tmp3[0] << endl;
//	//cout << tmp1[1] << " " << &tmp1[1] << "   " << tmp2[1] << " " << &tmp2[1] << "   " << tmp3[1] << " " << &tmp3[1] << endl;
//	//cout << tmp1[2] << " " << &tmp1[2] << "   " << tmp2[2] << " " << &tmp2[2] << "   " << tmp3[2] << " " << &tmp3[2] << endl;
//	//cout << tmp1[3] << " " << &tmp1[3] << "   " << tmp2[3] << " " << &tmp2[3] << "   " << tmp3[3] << " " << &tmp3[3] << endl;
//	//cout << tmp1[4] << " " << &tmp1[4] << "   " << tmp2[4] << " " << &tmp2[4] << "   " << tmp3[4] << " " << &tmp3[4] << endl;
//	//for (int i = 0; i < 10;i=i+4) {
//	//	cout << "6666" << endl;
//	//}
//	//int i = 0;
//	//i++;
//	//{
//	//	int b = 10;
//	//	cout<<b<<endl;
//	//	cout << i << endl;
//	//}
//	//string word = "123456";
//	//cout << word << endl;
//	//for (int i = word.size() - 1, j = 0; i != 0; i--, j++) {
//	//	char tmp = word[i];
//	//	word[i] = word[j];
//	//	word[j] = tmp;
//	//}
//	//cout<<word<<endl;
//	//char tmp;
//	//cin.get(tmp);
//	//cout<<tmp<<endl;
//	//int a,b;
//	//cin >> a >> b;
//	//cout << a << " " << b;
//	int ret=0;
//	int sum = 0;
//	if (cin>>ret) {
//		sum += ret;
//	}
//	cout << sum;
//	return 0;
//}
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//class Solution {
//public:
//    //string simplifyPath(string path) {
//    //    string ans = "/";
//    //    int i = 1;///a/./b/../../c/
//    //    while (i < path.size() ) {
//    //        if (ans.size() != 1 && ans[ans.size() - 1] == '/' && ans[ans.size() - 1] == ans[ans.size() - 2]) {
//    //            ans.pop_back();
//    //        }
//    //        if (path[i] == path[i + 1] && path[i] == '/') {
//    //            while (i < path.size() - 1 && path[i] == path[i + 1] && path[i] == '/') {
//    //                i += 2;
//    //            }
//    //            ans.push_back('/');
//    //            continue;
//    //        }
//    //        else if (path[i] == path[i + 1] && path[i] == '.') {
//    //            if (i + 2 == path.size() || path[i + 2] == '/') {
//    //                if (ans[ans.size() - 1] == '/' && ans.size() != 1) {
//    //                    ans.pop_back();
//    //                }
//    //                while (ans.size() != 1 && ans[ans.size() - 1] != '/') {
//    //                    ans.pop_back();
//    //                }
//    //                i += 2;
//    //            }
//    //            else
//    //            {
//    //                while (i < path.size() && path[i] != '/') {
//    //                    ans.push_back(path[i++]);
//    //                }
//    //                continue;
//    //            }
//    //        }
//    //        else {// /...
//    //            if (i+1<=path.size()&&path[i] == '.'&&path[i+1]=='/') {
//    //                i += 2;
//    //                continue;
//    //            }
//    //            else {
//    //                ans.push_back(path[i]);
//    //            }
//    //        }
//    //        i++;
//    //    }
//    //    while (ans.size() != 1 && ans[ans.size() - 1] == '/') {
//    //        ans.pop_back();
//    //    }
//    //    return ans;
//    //}
//    //
//    //  /./  /..a/ ///  /aaa.
//    //   /..  /
//    string simplifyPath(string path) {
//        string ans = "/";
//        int i = 1;
//        while (i < path.size()) {
//            if (ans[ans.size() - 1] == '/' && path[i] == '/') {
//                i++;
//                continue;
//            }
//            if (path[i] == '.' && path[i] == path[i + 1] && path[i - 1] == '/' && (i == path.size() - 2 || path[i + 2] == '/')) {//    /ff..  /..
//                if (ans.size() != 1) {
//                    if (ans[ans.size() - 1] == '/') {
//                        ans.pop_back();
//                    }
//                    while (ans.size() > 1 && ans[ans.size() - 1] != '/') {
//                        ans.pop_back();
//                    }
//                }
//                i += 2;
//                continue;
//            }
//            else if (path[i] == '.' && path[i - 1] == '/' && (i == path.size() - 1 || path[i + 1] == '/')) {
//                i++;
//                continue;
//            }
//            else {
//                while (path[i] == '/' && i < path.size() - 1 && path[i] == path[i + 1]) {
//                    i++;
//                    continue;
//                }
//                ans.push_back(path[i]);
//            }
//            i++;
//        }
//        while (ans.size() != 1 && ans[ans.size() - 1] == '/') {
//            ans.pop_back();
//        }
//        return ans;
//    }
//    vector<string> restoreIpAddresses(string s) {
//        vector<string> ans;
//        return ans;
//    }
//};
//int main() {
//    Solution s;
//    //string ret = s.simplifyPath("/home");
//    //cout << ret << endl;
//    //ret = s.simplifyPath("/home/");
//    ////cout << ret << endl;
//    //string ret = s.simplifyPath("/a//b////c/d//././/..");
//    //cout << ret<< endl;
//    //ret = s.simplifyPath("/home//foo/");
//    //cout << ret << endl;
//    //    ret = s.simplifyPath("/a/./b/../../c/");
//    //cout << ret << endl;
//    //ret = s.simplifyPath("/hello./world/");
//    //cout << ret << endl;
//    //ret = s.simplifyPath("/hello../world");
//    //cout << ret << endl;
//    //ret = s.simplifyPath("/..aa/...hidden/");
//    //cout << ret << endl;
//    //ret = s.simplifyPath("/.");
//    //cout << ret << endl;
//    //ret = s.simplifyPath("/.aaaa");
//    //cout << ret << endl;
//    vector<string> ret = s.restoreIpAddresses("2552552550");
//    for (vector<string>::iterator str = ret.begin(); str != ret.end(); str++) {
//        cout << *str << endl;
//    }
//    return 0;
//}
#include<iostream>
using namespace std;
class A {
private:
	int n1;
	int n2;
public:
	A():n2(0),n1(n2+2)
	{
	
	}
	void print() {
		cout << "n1=" << this->n1 << " " << "n2=" << this->n2 << endl;
	}
};
int main() {
	A a;
	a.print();
	return 0;
}
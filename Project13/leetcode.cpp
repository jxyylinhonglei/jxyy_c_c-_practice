//#include<iostream>
//#include<map>
//#include<string>
//using namespace std;
//class Slution {
//public:
//    int romanToInt(string s) {
//        int ans = 0;//M C M //1000 100 1000
//        for (int i = 0; i < s.size(); i++) {
//            ans += table[s[i]];
//            if (i!=0&& table[s[i-1]]< table[s[i]]) {
//                ans -= 2 * table[s[i - 1]];
//            }
//        }
//        return ans;
//    }
//private:
//    map<char, int> table{
//        {'I',1},
//        {'V',5},
//        {'X',10},
//        {'L',50},
//        {'C',100},
//        {'D',500},
//        {'M',1000}
//    };
//};
//int main() {
//	return 0;
//}
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class test {
public:
	test() {
		cout<<"默认构造函数" << endl;
	}
	int tmp;
};
struct person {
	int age;
	string name;
	//test t;

};
int main() {
	person* ps=(person*)malloc(sizeof(person));
	memset(ps,0x00,sizeof(*ps));
	ps->age = 100;
	ps->name = "aaaa";
	cout<<ps->name<<endl;
	return 0;
}
//string空间是动态变化的，也就是内存空间是不确定的。
//而malloc的参数是字节，意味着会开辟确定空间的大小。而string是动态的，这就很尬尴了，才会导致赋值不成功。
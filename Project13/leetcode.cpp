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
		cout<<"Ĭ�Ϲ��캯��" << endl;
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
//string�ռ��Ƕ�̬�仯�ģ�Ҳ�����ڴ�ռ��ǲ�ȷ���ġ�
//��malloc�Ĳ������ֽڣ���ζ�ŻῪ��ȷ���ռ�Ĵ�С����string�Ƕ�̬�ģ���ͺ������ˣ��Żᵼ�¸�ֵ���ɹ���
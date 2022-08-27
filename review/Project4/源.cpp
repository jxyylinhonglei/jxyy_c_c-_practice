#include<iostream>
using namespace std;
class person {
public:
	const static int a=10;
};
int main() {
	person aa;
	cout << aa.a << endl;
	const int b = 10;
	double arr[aa.a +1];
	return 0;
}
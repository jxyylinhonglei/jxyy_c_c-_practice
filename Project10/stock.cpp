#include"stock.h"
Stock::Stock() {
	std::cout << "空参构造器\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
}
Stock::Stock(const std::string& co, long n, double pr) {
	std::cout << "有参构造器\n";
	company = co;
	shares = n;
	share_val = pr;
}
Stock::~Stock() {
	std::cout<<"析构函数" << std::endl;
}
//void Stock::buy(long num, double price) {
//	
//}
//void Stock::sell(long num, double price) {
//
//}
//void Stock::update(double price) {
//
//}
//void Stock::show() {
//
//}
#include"stock.h"
Stock::Stock() {
	std::cout << "�ղι�����\n";
	company = "no name";
	shares = 0;
	share_val = 0.0;
}
Stock::Stock(const std::string& co, long n, double pr) {
	std::cout << "�вι�����\n";
	company = co;
	shares = n;
	share_val = pr;
}
Stock::~Stock() {
	std::cout<<"��������" << std::endl;
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
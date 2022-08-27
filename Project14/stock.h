#ifndef STOCK_H_
#define STOCK_H_
#include<string>
#include<iostream>
//test
class Stock {
public:
	std::string company;
	long shares;
	double share_val;
	Stock();
	Stock(const std::string& co,long n=0,double pr=0.0);
	~Stock();
	//void buy(long num,double price);
	//void sell(long num,double price);
	//void update(double price);
	//void show();
};
#endif

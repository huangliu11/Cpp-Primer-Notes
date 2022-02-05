#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
//using namespace std;    //在头文件中尽量不要使用using
struct Sales_data {
	std::string bookNo;
	std::string bookName;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
#endif

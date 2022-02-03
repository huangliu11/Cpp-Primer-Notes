#ifndef SALES_DATA_H
#define SALES_DATA_H
#include<iostream>
using namespace std;
struct Sales_data {
	string bookNo;
	string bookName;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
#endif

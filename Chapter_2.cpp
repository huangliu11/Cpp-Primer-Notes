#include<iostream>
#include"Sales_data.h"
using namespace std;
//struct Foo {};

int main() {
	/*2.1.2节练习2.4*/
	unsigned u = 10, u2 = 42;
	int i = 10, i2 = 42;

	cout << u2 - u << endl;
	cout << u - u2 << endl;

	cout << i2 - i << endl;
	cout << i - i2 << endl;
	cout << i - u << endl;
	cout << u - i << endl;

	/*2.1.3节练习2.8*/
	cout << "2\115\n" << endl;
	cout << "2\t\115\n" << endl;

	/*2.2.4节练习2.14*/
	int i = 100, sum = 0;
	for (int i = 0; i != 10; ++i) {
		sum += i;		//此时i作用域为for循环内
	}
	cout << i << " " << sum << endl;

	/*2.3.1节练习2.17*/
	int i, & ri = i;	//i申请了内存，引用可以绑定
	i = 5;
	ri = 10;
	cout << i << " " << ri << endl;

	/*2.3.2节练习2.18*/
	int i = 0, j = 1, * pi = &i;
	cout << *pi << endl;
	//更改指针的值
	pi = &j;
	cout << *pi << endl;
	//更改指针所指对象的值
	*pi = 2;
	cout << j << endl;

	/*2.4.4节练习2.32*/
	//int null = 0, * p = null;	//错误，不能将int型赋值给int型指针
	constexpr int null = 0;	//正确，此时null为常量表达式
	const int null = 0;		//正确，此时null为常量，0表示将p指针初始化为空；如果是0以外的常量则不可以
	int *p = null;

	/*2.5.2节练习2.34*/
	int i = 0, & r = i;
	auto a = r;		//a是int型，a=0
	const int ci = i, & cr = ci;	//cr是ci的别名
	auto b = ci;	//b是int，忽略顶层const
	auto c = cr;	//c是int，忽略顶层const
	auto d = &i;	//d是int型指针
	auto e = &ci;	//e是一个指向常量int型的指针
	const auto f = ci;	//ci推出f是int，加上前缀const是const int
	auto& g = ci;	//g是整型常量引用
	
	cout << "a before:" << a << endl;
	a = 42;
	cout << "a after" << a << endl;

	cout << "b before:" << b << endl;
	b = 42;
	cout << "b after" << b << endl;

	cout << "c before:" << c << endl;
	c = 42;
	cout << "c after" << c << endl;
	//错误
	//d = 42;
	//e = 42;
	//g = 42;

	/*练习2.35*/
	const int i = 42;
	auto j = i;		//j是int
	const auto& k = i;	//k是int常量引用，其引用的对象不可变
	auto* p = &i;	//p是指向int常量的指针
	const auto j2 = i, & k2 = i;	//j2是int常量，k2是int常量的常量引用

	cout << "before j" << j << endl;
	j = 0;
	cout << "after j" << j << endl;
	//k = 0;	//错误
	cout << "before *p" << *p << endl;
	p = &j;
	//*p = 0; //错误
	cout << "after *p" << *p << endl;
	//k2 = j2;	//错误

	/*2.6.1节练习2.40*/

	/*2.6.2节练习2.41*/
	/*1.21*/
	Sales_data data1, data2;
	double price = 0.0;
	cin >> data1.bookNo >> data1.units_sold >> price;
	data1.revenue = data1.units_sold * price;
	cin >> data2.bookNo >> data2.units_sold >> price;
	data2.revenue = data2.units_sold * price;

	if (data1.bookNo == data2.bookNo) {
		unsigned totalCnt = data1.units_sold + data2.units_sold;
		double totalRevenue = data1.revenue + data2.revenue;
		cout << data1.bookNo << " " << totalCnt
			<< " " << totalRevenue << " ";
		if (totalCnt != 0)
			cout << totalRevenue / totalCnt << endl;
	}
	else {
		cerr << "not the same ISBN" << endl;
		return -1;
	}
	/*1.22*/
	Sales_data currData, total;
	while (cin >> currData.bookNo) {
		double price;
		cin >> currData.units_sold >> price;
		currData.revenue = currData.units_sold * price;
		total.bookNo = currData.bookNo;
		total.units_sold += currData.units_sold;
		total.revenue += currData.revenue;
	}
	cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
	
	/*1.24*/
	Sales_data currData, data;
	while (cin >> currData.bookNo) {
		double price;
		cin >> currData.units_sold >> price;
		int cnt = 1;
		while (cin >> data.bookNo) {
			cin >> data.units_sold >> price;
			if (currData.bookNo == data.bookNo) {
				++cnt;
			}
			else {
				cout << currData.bookNo << " " << cnt << endl;
				cnt = 1;
				currData.bookNo = data.bookNo;
			}
		}
		cout << currData.bookNo << " " << cnt << endl;
	}

	/*1.25*/
	Sales_data total;
	if (cin >> total.bookNo) {
		double price;
		cin >> total.units_sold >> price;
		total.revenue = total.units_sold * price;
		Sales_data trans;
		while (cin >> trans.bookNo) {
			cin >> trans.units_sold >> price;
			trans.revenue = trans.units_sold * price;
			if (total.bookNo == trans.bookNo) {
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
			}
			else {
				cout << total.bookNo << " " << total.units_sold
					<< " " << total.revenue << " "
					<< total.revenue / total.units_sold << endl;

				total.bookNo = trans.bookNo;
				total.units_sold = trans.units_sold;
				total.revenue = trans.revenue;
			}
		}
		cout << total.bookNo << " " << total.units_sold
			<< " " << total.revenue << " "
			<< total.revenue / total.units_sold << endl;
	}
	
	return 0;	
}

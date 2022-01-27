#include<iostream>
#include"Sales_item.h"
using namespace std;

int main()
{
	//1.5.1节练习1.22
	Sales_item item, total;
	while (cin >> item) {
		total = item + total;	//为什么不写成total += item？
								//因为+=会先将total进行类定义的初始化，而非赋值初始化，输出的结果与期望的不一样
		//total += item;
	}
	cout << total << endl;

	//1.5.2节练习1.24
	Sales_item item, currItem;
	while (cin >> currItem) {
		int cnt = 1;
		while (cin >> item) {
			if (item.isbn() == currItem.isbn())
				++cnt;
			else {
				cout << currItem.isbn() << "occurs"
					<< cnt << "times" << endl;
				currItem = item;
				cnt = 1;
			}
		}
		cout << currItem.isbn() << "occurs"
			<< cnt << "times" << endl;
	}

	//1.6节练习1.25
	Sales_item total;
	if (cin >> total) {
		Sales_item trans;
		while (cin >> trans) {
			if (trans.isbn() == total.isbn()) {
				total += trans;
			}
			else {
				cout << total << endl;
				total = trans;
			}
		}
		cout << total << endl;
	}
	else {
		//没有输入
		cerr << "no data!" << endl;
		return -1;	//要返回错误
	}

	return 0;
}

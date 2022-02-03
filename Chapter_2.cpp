#include<iostream>
using namespace std;

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
	int null = 0, * p = null;	//错误，不能将int型赋值给int型指针
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
	错误
	d = 42;
	e = 42;
	g = 42;

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



	return 0;	
}

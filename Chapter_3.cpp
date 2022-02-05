#include<iostream>
#include<string>
using namespace std;
int main() {
	/*3.2.2节练习3.2*/
	string s;
	while (getline(cin, s)) { //读一行
	//while(cin >> s) {	//读一个单词
		cout << s << endl;
	}

	/*练习3.4*/
	string s1, s2;
	cin >> s1 >> s2;
	if (s1 == s2)		//比较大小
	//if (s1.size() == s2.size())  //比较长短
		cout << "=" << endl;
	else {
		if (s1 > s2)
	//	if (s1.size() > s2.size())
			cout << s1 << endl;
		else
			cout << s2 << endl;
	}

	/*练习3.4*/
	string s0, s1;
	while (cin >> s0) {
		s1 += s0;
		//s1 += " ";	//分隔
	}
	cout << s1 << endl;

	/*3.2.3节练习3.6*/
	string s;
	cin >> s;
	for (auto& c : s) {
	/*练习3.7*/
	for(char c : s) {
		c = 'X';
	}

	/*练习3.8*/
	//while写循环
	decltype(s.size()) index = 0;
	while (index < s.size()) {
		s[index] = 'X';
		++index;
	}

	/*练习3.10*/
	string s1;
	if (!s.empty()) {
		for (decltype(s.size()) index = 0; index < s.size(); ++index) {
			if (!ispunct(s[index]))
				s1 += s[index];
		}
	}
	cout << s1 << endl;

	/*练习3.11*/
	const string s = "keep out!";
	for(auto &c:s) {
		//当auto引用时，顶层常量属性保留，c为const char &
	}
	return 0;
}

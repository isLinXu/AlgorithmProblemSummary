// 表示数字

#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	while (cin >> s) {
		for (int i = 0; i < s.length(); i++) {
			if (isdigit(s[i])) { // 每次第一个遇到的数字前加*
				s.insert(i, "*");
				i++;
				while (isdigit(s[i])) //遍历连续的数字找到这一段的最后一个数字
					i++;
				s.insert(i, "*"); //最后加*
			}
		}
		cout << s << endl;
	}
	return 0;
}


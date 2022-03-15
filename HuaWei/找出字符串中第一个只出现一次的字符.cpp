// 找出字符串第一个只出现一次的字符

#include <bits/stdc++.h>
using namespace std;
int main() {
	string str;
	while (cin >> str) {
		bool flag = false;//flag用来判断是否存在只出现一次的字符
		for (int i = 0; i < str.size(); i++) { //遍历一遍字符串
			if (str.find_first_of(str[i]) == str.find_last_of(str[i])) { //判断当前字符是否是只出现了一次
				cout << str[i] << endl;//若是，则输出这个字符
				flag = true;
				break;//找到了第一次出现的字符，跳出循环
			}
		}
		if (!flag) cout << "-1" << endl; //如果没有找到第一次出现的字符，则输出-1
	}
	return 0;
}



#include<iostream>
#include<cstdio>
#include<string.h>


using namespace std;

int main() {
	
	string str;

	while (getline(cin, str)) {
		// 循环：输出前8个，截取9...最后的
		while (str.size() > 0) {
			cout << str.substr(0, 8) << endl;
			str = str.substr(8);
		}
		cout << str.append(8 - str.size(), '0') << endl;
	}
	return 0;

}

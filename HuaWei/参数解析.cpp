// 参数解析

#include <iostream>
#include <string>
using namespace std;
int main() {
	string input;
	while (getline(cin, input)) {
		//统计个数
		int length = input.length();
		int num = 0;
		for (int i = 0; i < length; i++) {
			if (input[i] == '"') {
				i++;
				while (input[i] != '"') {
					i++;
				}
			} else if (input[i] == ' ') {
				num++;
			}
		}
		cout << num + 1 << endl;
		//输出
		for (int i = 0; i < length; i++) {
			if (input[i] == '"') {
				i++;
				while (input[i] != '"') {
					cout << input[i];
					i++;
				}
			} else if (input[i] == ' ') {
				cout << endl;
			} else {
				cout << input[i];
			}
		}
		cout << endl;
	}
	return 0;
}

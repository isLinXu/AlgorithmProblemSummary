// 求最小公倍数

#include<iostream>
using namespace std;

int main() {
	int a, b;
	while (cin >> a >> b) {
		for (int i = a; ; i++) { //从a开始往后找
			if (i % a == 0 && i % b == 0) { //直到遇到第一个两个数的公倍数
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}


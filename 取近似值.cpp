#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	// 浮点数 尽量用double
	double num;
	cin >> num;

	int a = (int)num;
	if ((num - a) * 10 >= 5) {
		cout << a + 1 << endl;
	} else {
		cout << a << endl;
	}

	return 0;
}

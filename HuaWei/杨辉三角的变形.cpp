// 杨辉三角的变形

#include<iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		if (n == 1 || n == 2) {
			cout << -1 << endl;
		} else if (n % 4 == 3 || n % 4 == 1) {
			cout << 2 << endl;
		} else if (n % 4 == 0) {
			cout << 3 << endl;
		} else {
			cout << 4 << endl;
		}
	}
	return 0;
}

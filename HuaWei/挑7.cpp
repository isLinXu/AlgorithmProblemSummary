// 挑7

#include<iostream>
using namespace std;

bool ifSev(int num) {
	while (num > 0) {
		if (num % 10 == 7) {
			return true;
		}
		num /= 10;
	}
	return false;
}

int main() {
	int n;
	while (cin >> n) {
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (i % 7 == 0) {
				ans++;
				continue;
			}
			if (ifSev(i)) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}


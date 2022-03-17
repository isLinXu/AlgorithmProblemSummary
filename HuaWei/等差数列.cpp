// 等差数列

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int sum = n * 2 + n * (n - 1) / 2 * 3; //等差数列求和公式Sn = n·a1 + n(n-1)/2 * d，忘记的同学也可以自行百度回忆一下
		cout << sum << endl; //输出等差数列前N项的和
	}
	return 0;
}


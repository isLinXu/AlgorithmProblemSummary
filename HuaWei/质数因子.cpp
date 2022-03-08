#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	
	long num;

	while (cin >> num) {
		// for循环从小到大输出质数因子
		// 2 3 5 7 11 13 17 19
		for (int i = 2; i * i < num; i++) {
			while (num % i == 0) {
				cout << i << ' ';
				num /= i;
			}
		}
		// 很大的质数
		if (num > 1) {
			cout << num << ' ';
		}
	}



	return 0;
}

// 查找组成一个偶数最接近的两个素数

#include<iostream>
using namespace std;

bool isPrime(int n) { //判断数字n是否是素数
	for (int i = 2; i < n; i++) { //遍历到n-1
		if (n % i == 0) //如果由因子就不是素数
			return false;
	}
	return true; //遍历完都没有就是素数
}

int main() {
	int n;
	while (cin >> n) {
		int mindis = n;
		pair<int, int> res; //记录两个素数
		for (int i = 2; i < n; i++) { //遍历2到n找到两个素数
			if (isPrime(i) && isPrime(n - i)) { //两个数都是素数的时候
				if (abs(n - i - i) < mindis) { //找距离最小
					res = {i, n - i}; //更新最小
					mindis = abs(n - i - i);
				}
			}
		}
		cout << res.first << endl << res.second << endl;
	}
	return 0;
}


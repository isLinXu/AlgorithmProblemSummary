// 尼科彻斯定理


#include<iostream>
#include<string>
using namespace std;

int main() {
	int m;
	while (cin >> m) {
		int pow = m * m * m; //先获取三次方的值
		for (int i = 1; i < pow; i += 2) { //从1开始找到pow
			if (m * i + m * (m - 1) == pow) { //比较等差数列和与三次幂是否相等
				cout << i; //相等开始输出连续m个数字
				for (int j = 1; j < m; j++)
					cout << '+' << i + 2 * j;
				cout << endl;
				break;
			}
		}
	}
	return 0;
}


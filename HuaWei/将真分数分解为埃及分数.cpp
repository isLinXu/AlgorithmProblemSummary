// 将真分数分解为埃及分数

#include<iostream>
#include<string>
using namespace std;

void recursion(int a, int b) {
	if (a == 1) {
		cout << 1 << "/" << b << endl;
		return;
	}
	if (b % a == 0) { //去掉公因子
		recursion(1, b / a);
		return;
	}
	if (b % (a - 1) == 0) { //整除a-1的情况
		cout << 1 << "/" << b / (a - 1) << "+";
		recursion(1, b);
		return;
	}
	cout << 1 << "/" << b / a + 1 << "+";
	recursion(a - b % a, b * (b / a + 1)); //根据公式更新分子分母送入递归
}

int main() {
	int a, b; //分别是分子分母
	char op; //除号
	while (cin >> a >> op >> b) {
		recursion(a, b);
	}
}


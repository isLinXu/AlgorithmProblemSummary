// 走方格的方案数


#include<iostream>
#include<vector>
using namespace std;

int recursion(int i, int j, int m, int n) { //递归计算方案数
	if (n == i || m == j) //到边界只有一种走法
		return 1;
	return recursion(i + 1, j, m, n) + recursion(i, j + 1, m, n); //进入子问题
}
int main() {
	int m, n;
	while (cin >> n >> m) {
		cout << recursion(0, 0, m, n) << endl;
	}
	return 0;
}



// 求最大连续bit数

#include<iostream>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int count = 0; //记录每次统计的连续1的个数
		int max_count = 0; //记录最大连续1的个数
		while (n) {
			if (n % 2 == 1) //最后一位为1
				count++;
			else { //遇到不为1
				max_count = max(max_count, count); //更新最大值
				count = 0; //从0开始
			}
			n /= 2; //去掉最后一位
		}
		max_count = max(max_count, count); //最后一次更新最大值
		cout << max_count << endl;
	}
	return 0;
}


// 24点游戏算法

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double cal(double a, double b, char c) { //根据运算符运算结果
	switch (c) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
	}
	return 0;
}

bool check(vector<double>& nums) {
	char op[4] = {'+', '-', '*', '/'};
	sort(nums.begin(), nums.end()); //先按照从小到大排
	do {
		for (int i = 0; i < 4; i++) //遍历三个位置的所有可能运算符
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++) {
					double first = cal(nums[0], nums[1], op[i]); //依次运算
					double second = cal(first, nums[2], op[j]);
					if (cal(second, nums[3], op[k]) == 24) //判断是否等于24
						return true;
				}
	} while (next_permutation(nums.begin(), nums.end())); //依次找到其他排列
	return false;
}

int main() {
	vector<double> nums(4);
	while (cin >> nums[0] >> nums[1] >> nums[2] >> nums[3]) { //输入4个数字
		if (check(nums))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}


// Redraiment的走法

#include<iostream>
#include<vector>
using namespace std;

int lis(vector<int>& arr) {
	vector<int> dp(arr.size(), 1); //设置数组长度大小的动态规划辅助数组
	int max = 1;
	for (int i = 1; i < arr.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1; //i点比j点大，理论上dp要加1
				//但是可能j不是所需要的最大的，因此需要dp[i] < dp[j] + 1
				max = max > dp[i] ? max : dp[i]; //找到最大长度
			}
		}
	}
	return max;
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> arr(n);
		for (int i = 0; i < n; i++) //输入
			cin >> arr[i];
		cout << lis(arr) << endl; //计算最长递增子序列长度
	}
	return 0;
}


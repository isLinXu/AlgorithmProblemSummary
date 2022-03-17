// 数组分组

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool dp(vector<int> &num, int t, int k) {
	if (t == 0 && k == num.size()) return true;
	if (k == num.size()) return false;
	//如果只是3的倍数，不能加到该集合中。
	if (!(num[k] % 3)) return (dp(num, t, k + 1));
	if (num[k] == t) return true;
	//对于一个数有两种选择，加或者不加到该集合中
	return (dp(num, t - num[k], k + 1) | dp(num, t, k + 1));
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> num;
		int x, sum = 0, part = 0; //只要找到总和的一半即可，剩下的数字之和自然为总和的一半。
		for (int i = 0; i < n; i++) {
			cin >> x;
			//如果是5的倍数，不放入数组num
			if (x % 5)
				num.push_back(x);
			else
				part += x;
			sum += x;
		}
		//如果所有数之和不是偶数，则肯定是false
		if (sum % 2) {
			cout << "false" << endl;
		} else {
			sum = sum / 2;
			if (dp(num, sum - part, 0))
				cout << "true" << endl;
			else cout << "false" << endl;
		}

		num.clear();
	}
}


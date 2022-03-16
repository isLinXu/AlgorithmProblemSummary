// 火车进站

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfs(const vector<int>& in, int index, stack<int>& st, vector<int>& out, vector<vector<int>>& res) {
	if (index >= in.size() && st.empty()) {
		res.push_back(out);
		return;
	}
	// 进
	if (index < in.size()) {
		st.push(in[index]);
		dfs(in, index + 1, st, out, res);
		st.pop();
	}
	// 出
	if (!st.empty()) {
		out.push_back(st.top());
		st.pop();
		dfs(in, index, st, out, res);
		st.push(out.back());
		out.pop_back();
	}
}

int main() {
	int n;
	while (cin >> n) {
		vector<int> nums(n);
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}
		stack<int> st;
		vector<int> path;
		vector<vector<int>> res;
		dfs(nums, 0, st, path, res);
		sort(res.begin(), res.end());
		for (auto p : res) {
			for (int a : p) {
				cout << a << " ";
			}
			cout << endl;
		}
	}
	return 0;
}


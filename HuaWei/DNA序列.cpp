// DNA序列

#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s; // 输入我们的字符串
	int n, ans = -1; // 把我们最大值置为-1，这样可以保证后续答案可以正常更新
	cin >> n; // 这个n就是我们要截取的一个子串的长度
	string res = ""; // 这个是我们最后的一个答案字符串
	for (int i = 0; i < s.size(); i++) {
		int cnt = 0; // 这个是判断每一次的截取出来的子串有多少个CG
		string tmp = ""; // 这个是我们每一次截取出来的子串
		for (int j = i; j < s.size() && j < i + n; j++) { // 这个是截取子串的操作，要保证子串也要在我们的子串范围内
			tmp += s[j]; // 每次把原字符串的一位加到我们的子串之中
			if (s[j] == 'G' || s[j] == 'C') cnt++; // 这个记录这个子串有多少个CG
		}
		if (cnt > ans) res = tmp, ans = cnt; // 如果当前的子串中的CG的数量要是比我们的之前记录的大，我们更新答案字符串和最大的CG数量
	}
	cout << res << '\n'; // 输出我们最后的答案字符串
}
signed main()
{
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	solve();
	return 0;
}


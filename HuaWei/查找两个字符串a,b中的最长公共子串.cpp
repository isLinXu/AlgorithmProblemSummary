// 查找两个字符串a,b中的最长公共子串

#include <bits/stdc++.h>
using namespace std;
string LCS(string str1, string str2) {
	// write code here
	if (str1.size() > str2.size())
		swap(str1, str2);
	int m = str1.size();
	int n = str2.size();
	// dp[i][j] str1前i个字符和str2前j个字符（以其为尾字符）的最长公共子串长度
	int dp[m + 1][n + 1];
	int maxlen = 0, end = 0;
	//base case
	for (int i = 0; i <= m; ++i) dp[i][0] = 0;
	for (int j = 0; j <= n; ++j) dp[0][j] = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = 0;
			if (dp[i][j] > maxlen) {
				maxlen = dp[i][j];
				end = i - 1;
			}
		}
	}
	if (maxlen == 0) return "-1";
	else return str1.substr(end - maxlen + 1, maxlen);
}
int main() {
	string s1, s2;
	while (cin >> s1 >> s2)
		cout << LCS(s1, s2) << endl;
}


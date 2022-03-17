// 合法IP

#include<bits/stdc++.h>
#include<arpa/inet.h>
using namespace std;
bool valids(const char *s, int n) {
	if (n == 0)return false;
	if (s[0] == '0' && n > 1)return false; // 前导零
	int v = 0;
	for (int i = 0; i < n; i++) {
		if (!isdigit(s[i]))return false;
		v *= 10;
		v += s[i] - '0';
	}
	return v >= 0 && v <= 255;
}
void work(string &s) {
	int n = s.length();
	int p = 0; // 字符串 起始位置
	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		if (s[i] == '.' || s[i] == '\0') {
			if (!valids(s.c_str() + p, i - p)) {
				printf("NO\n");
				return ;
			}
			p = i + 1; // 下一个开始位置
			cnt ++;
		}
	}
	printf("%s\n", cnt == 4 ? "YES" : "NO"); // 4位
}

int main() {
	string s;
	while (getline(cin, s)) {
		work(s);
	}
	return 0;
}


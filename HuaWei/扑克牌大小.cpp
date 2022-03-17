// 扑克牌大小

#include<bits/stdc++.h>
using namespace std;

// 3 4 5 6 7 8 9 10 J Q  K  A  2 joker JOKER
// 0 1 2 3 4 5 6 7  8 9 10 11 12 13  14
int s2int(const char * s, int n) { // 字符串转值
	if (n == 2)return 7; // 10
	if (n == 5) {
		if (s[0] == 'j')return 13; // joker
		else return 14; // JOKER
	}
	if (s[0] == '2')return 12;
	if (s[0] == 'A')return 11;
	if (s[0] == 'K')return 10;
	if (s[0] == 'Q')return 9;
	if (s[0] == 'J')return 8;
	return s[0] - '3';
}

// 数组 转 类型 和 值
// 炸弹 个子 对子 三个 顺子
// -1   0   1    2   3,4,5,6
pair<int, int> a2tv(const vector<int>&arr) {
	if (arr.size() == 1)return {0, arr[0]}; // 个
	if (arr.size() == 2) {
		if (arr[0] == arr[1])return {1, arr[0]}; // 对
		else return {-1, arr[0]}; // 王炸
	}
	if (arr.size() == 3) {
		if (arr[0] == arr[1])return {2, arr[0]}; // 三
		else return {3, arr[0]}; // 顺
	}
	if (arr.size() == 4) {
		if (arr[0] == arr[1]) return {-1, arr[0]}; // 炸
		else return {4, arr[0]}; // 顺
	}
	return {arr.size(), arr[0]}; // 顺
}

int main() {
	string s;
	while (getline(cin, s)) {
		int n = s.length();
		vector<int>arr[2] = {};
		int itr = 0;
		int dpos = 0; // - 的下标
		for (int i = 0; i <= n; i++) {
			if (s[i] == ' ' || s[i] == '-' || s[i] == '\0') { // 分割字符
				arr[!!dpos].push_back(s2int(s.c_str() + itr, i - itr));
				if (s[i] == '-') dpos = i;
				itr = i + 1;
			}
		}
		s[dpos] = '\0';

		auto ltv = a2tv(arr[0]);
		auto rtv = a2tv(arr[1]);
		if (ltv.first == rtv.first) { // 同类型
			if (ltv.second < rtv.second) {
				printf("%s\n", s.c_str() + dpos + 1);
			} else {
				printf("%s\n", s.c_str());
			}
		} else if (ltv.first == -1 || rtv.first == -1) { // 至少一个是炸弹
			if (rtv.first == -1) {
				printf("%s\n", s.c_str() + dpos + 1);
			} else {
				printf("%s\n", s.c_str());
			}
		} else { // 非同类型无法比较
			printf("ERROR\n");
		}
	}
	return 0;
}


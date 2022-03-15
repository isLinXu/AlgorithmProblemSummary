// 高精度整数加法

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		string ans;
		int m = s1.size(), n = s2.size();
		int ptr1 = m - 1, ptr2 = n - 1;
		int carry = 0;
		while (ptr1 >= 0 || ptr2 >= 0 || carry != 0) {
			int a = ptr1 < 0 ? 0 : s1[ptr1--] - '0';
			int b = ptr2 < 0 ? 0 : s2[ptr2--] - '0';
			int sum = a + b + carry;
			carry = sum / 10;
			ans += (sum % 10) + '0';
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
}

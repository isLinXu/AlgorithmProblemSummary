// 字符逆序

#include<bits/stdc++.h>
using namespace std;
int main() {
	string str;
	while (getline(cin, str)) {
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
	return 0;
}


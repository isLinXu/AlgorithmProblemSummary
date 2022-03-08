#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	
	string str;

	while (getline(cin, str)) {
		if (str.size() < 0) {
			break;
		}
		// 超出int范围
		long long num = 0;
		for (int i = 2; i < str.size(); i++) {
			if (str[i] >= '0' && str[i] <= '9') {
				num = num * 16 + str[i] - '0';
			} else {
				num = num * 16 + str[i] - 'A' + 10;
			}
		}
		cout << num << endl;
	}


	return 0;
}

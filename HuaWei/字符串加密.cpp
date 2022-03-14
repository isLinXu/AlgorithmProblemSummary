// 字符串加密

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

int main () {
	string sKey, sStr;
	while(getline(cin, sKey) && getline(cin, sStr)) {
		// 先把key中的大写字符全变为小写
		for (int i = 0; i < sKey.size(); ++i) {
			if (isupper(sKey[i]))
				sKey[i] += 32;
		}
		// 用set记录有多少个元素
		unordered_set<char> set;
		for (int i = 0; i < sKey.size(); ++i) {
			set.insert(sKey[i]);
		}
		// 输入不重样字符的key
		vector<char> arr(26);
		int j = 0;
		for(int i = 0; i < sKey.size(); ++i) {
			int flag = 0;
			for (char c : arr) {
				if (c == sKey[i])
					flag = 1;
			}
			if (flag == 0)
				arr[j++] = sKey[i];
		}
		// 输入剩余的字符
		for(int i = 0; i < 26; ++i) {
			if (set.count('a' + i) == 0) {
				arr[j++] = 'a' + i;
			}
		}
		// 输出
		string ans;
		for (int i = 0; i < sStr.size(); ++i) {
			if (isupper(sStr[i])) {
				ans += (arr[sStr[i] - 'A'] - 'a' + 'A');
				continue;
			} else if (islower(sStr[i])) {
				ans += arr[sStr[i] - 'a'];
				continue;
			} else {
				ans += sStr[i];
			}
			
		}
		cout << ans << endl;
	}
	
	
}


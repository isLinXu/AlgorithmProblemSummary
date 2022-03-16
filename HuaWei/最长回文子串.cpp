// 最长回文子串

#include<bits/stdc++.h>
using namespace std;
int getLen(string str, int low, int high) {    //中心扩展法
	while (low >= 0 && high < str.length() && str[low] == str[high]) {
		low--;
		high++;
	}
	return high - low - 1;
}
int main() {
	string str;    //存放输入的字符串
	while (getline(cin, str)) {   //获取输入的一行字符串
		int length = str.length();    //length为字符串的长度
		if (length == 0 || length == 1) { //如果字符串长度为小于等于1，直接输出字符串的长度
			cout << length << endl;
			continue;
		} else {  //如果字符串的长度大于1
			int len = 0;  //len为最长回文子串的长度
			for (int i = 0; i < length - 1; i++) { //循环计算每个中心点下的最长回文子串
				int x = getLen(str, i, i);    //单中心回文子串长度
				int y = getLen(str, i, i + 1);  //双中心回文子串的长度
				len = max( max(x, y), len);
			}
			cout << len << endl;
		}
	}
	return 0;
}


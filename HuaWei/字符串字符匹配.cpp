// 字符串字符匹配

#include <iostream>
using namespace std;
//字符串匹配的函数接口
//判断短字符串中的所有字符是否在长字符串中全部出现，区别于短字符串是否为长字符串的子字符串。
int String_Matching(string str1, string str2) {
	int short_str[128] = {0}; //记录短字符串中各种字符的出现情况
	int long_str[128] = {0}; //记录短字符串中各种字符的出现情况
	int count = 0; //短字符串和长字符串具有相同字符的个数
	int sum = 0; //短字符串具有不同字符的总数
	//字符记录：若某字符出现在（短、长）字符串中，则置该字符的 ASCII 码作为下标对应的数组元素为 1
	for (int i = 0; i < str1.size(); i++) {
		short_str[str1[i]] = 1;
	}
	for (int i = 0; i < str2.size(); i++) {
		long_str[str2[i]] = 1;
	}
	//计数：第一个 if 语句：得到短字符串和长字符串具有相同字符的个数，第二个 if 语句：得到短字符串具有不同字符的总数
	for (int i = 0; i < 128; i++) {
		if ((short_str[i] == 1) && (long_str[i] == 1)) {
			count++;
		}
		sum += short_str[i];
	}
	//若短字符串和长字符串具有相同字符的个数 和 短字符串具有不同字符的总数 相等，则满足要求
	if (count == sum) {
		cout << "true" << endl;
	} else if (count != sum) {
		cout << "false" << endl;
	}
	return 0;
}
//主函数
int main() {
	string ShortString, LongString;
	while (cin >> ShortString >> LongString) {
		String_Matching(ShortString, LongString);
	}
	return 0;
}

#include<iostream>
using namespace std;
//删除字符串中出现次数最少的字符的函数接口
string Del_Str(string str) {
	string Del_str; //删除字符串中出现次数最少的字符后的字符串
	int a[26] = {0}; //初始化一个数组，记录输入的字符串中每个小写字母出现的次数
	int len = str.size(); //获取字符串的长度
	int min = 1000; //出现次数最少的字符的出现次数，自然不能为 0
	//采用小写字母的 ASCII 码作为数组的下标，对应地记录字符串中每个小写字母字符出现的次数
	for (int i = 0; i < len; i++) {
		a[str[i] - 'a'] += 1;
	}
	//获取字符串中出现次数最少的字符的次数
	for (int i = 0; i < 26; i++) {
		if ((a[i] <= min) && (a[i] != 0)) {
			min = a[i];
		}
	}
	//得到不包含字符串中出现次数最少的字符的字符串
	for (int i = 0; i < len; i++) {
		if (a[str[i] - 'a'] > min) {
			Del_str += str[i];
		}
	}
	return Del_str; //返回删除字符串中出现次数最少的字符后的字符串
}
//主函数
int main() {
	string str;
	while (cin >> str) {
		cout << Del_Str(str) << endl;
	}
	return 0;
}

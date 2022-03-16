// 统计大写字母个数

#include<bits/stdc++.h>
using namespace std;
int main() {
	string str;    //存放输入的字符串
	while (getline(cin, str)) {   //获取输入的一行字符串
		int count = 0;  //计数器，统计大写字母的个数
		for (int i = 0; i < str.length(); i++) { //判断字符串中每个字符是否为大写字母
			if (isupper(str[i]))
				count++;
		}
		cout << count << endl; //输出字符串中大写字母的个数
	}
	return 0;
}


// 在字符串中找出连续最长的数字串

#include<bits/stdc++.h>
using namespace std;
int main() {
	string str;    //存放输入的字符串
	while (getline(cin, str)) {   //获取输入的一行字符串
		vector<string> digitalstr;    //容器digitalstr用来存放最长的数字子串
		int length = str.length();    //length为输入字符串的长度
		int maxlen = 0;    //maxlen记录最长数字子串的长度
		for (int i = 0; i < length; i++) { //查找字符串中以每个字符为首的最长数字串
			int j = i;  //记录当前起始位置
			string tmp;    //存放以当前字符为首的最长数字串
			while (isdigit(str[j]) && j < length) { //如果当前字符是数字0~9，则添加该字符到字符串tmp的末尾
				tmp.push_back(str[j]);
				j++;
			}
			int count = tmp.length();    //count表示当前最长数字串的长度
			if (count > maxlen) { //如果当前最长数字串的长度大于已有最长数字串的长度
				digitalstr.clear();    //将容器digitalstr清空
				digitalstr.push_back(tmp);    //将当前最长数字串添加到容器digitalstr的末尾
				maxlen = count;    //更新已有最长数字串的长度
			} else if (count == maxlen) {   //长度相等的数字串添加到容器digitalstr之后
				digitalstr.push_back(tmp);
			}
		}
		for (int i = 0; i < digitalstr.size(); i++) //输出最长数字串
			cout << digitalstr[i];
		cout << ",";
		cout << digitalstr[0].length() << endl;
	}
	return 0;
}


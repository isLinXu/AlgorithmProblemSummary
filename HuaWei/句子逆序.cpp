/*
句子逆序

输入：I am a boy
输出：boy a an I
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	
	string str;
	
	getline(cin, str);
	// 翻转句子所有字符
	reverse(str.begin(), str.end());
	// 翻转单个单词
	for (int i = 0; i < str.size(); i++){
		int j = i;
		while(j < str.size() && str[j] != ' ') j++;
		reverse(str.begin()+i, str.begin() +j);
		i = j;
	}
	
	cout << str << endl;
	return 0;
}

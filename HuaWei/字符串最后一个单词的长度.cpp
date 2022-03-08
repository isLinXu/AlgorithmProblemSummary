#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main() {
	char str[5001];
	//输入字符串
//	cin >> str; 这样做会出错，遇到空格读不了
	// cin不接受空格,TAB等键的输入，遇到这些会终止
	// 而gets()则接受连续的输入
//	gets(str); error: ‘gets’ was not declared in this scope gets(s)
	// 改为下面这个
	cin.getline(str,5001);
	cout << str << endl;
	int len = 0;
	for (int i = strlen(str)-1; str[i] != ' ' && i != 0; i--){
		len++;
	}
	cout << len << endl;

	return 0;
}


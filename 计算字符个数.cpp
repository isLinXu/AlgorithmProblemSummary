#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

const int N = 100010;
char str[N];

int main(){
	// 输入字符串
	cin.getline(str,N);
	
	char x;
	
	cin >> x;
	
	int count = 0;
	for (int i = 0; str[i] != '\0'; i++){
		// 处理大小写
		if (str[i] == x || str[i] == x + 32 || str[i] == x - 32){
			count ++;	
		}
	}
	cout << count << endl;
	
	return 0;
}

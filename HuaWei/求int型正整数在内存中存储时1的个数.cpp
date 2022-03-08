/*
求int型正整数在内存中存储时1的个数
输入：5
输出：2

5
101
2
*/

#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	
	int num;
	cin >> num;
	
	int count = 0;

	while(num){
		if(num & 1){
			count ++;
		}
		num = num >> 1;	
	}
	cout << count << endl;
	
	return 0;
}

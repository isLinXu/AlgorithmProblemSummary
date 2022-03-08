// 11.数字颠倒
/*输入：1516000
输出：006151*/

#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	
	string str;
	int num;
	
	cin >> num;
	
	while(num != 0){
		char c = num % 10 + '0';
		num /= 10;
		str += c;
	}
	cout << str << endl;
	
	return 0;
}

// 计算某字符出现次数

#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
	char target;
	unordered_map<char, int> mp;
	char c;
	while((c = getchar()) != '\n'){ //按字符输入字符串
		if(c >= 'A' && c <= 'Z') //大写转小写
			c = c - 'A' + 'a';
		mp[c]++; //统计频率
	}
	cin >> target; //输入目标字符
	if(target >= 'A' && target <= 'Z') //大写转小写
		target = target - 'A' + 'a';
	cout << mp[target] << endl;
	return 0;
}


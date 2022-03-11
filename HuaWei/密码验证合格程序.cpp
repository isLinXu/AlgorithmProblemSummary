// 密码验证合格程序

#include<iostream>
using namespace std;
//密码合格验证的函数接口
string Password_Verification(string str) {
	int len = str.size(); //获取字符串长度
	int a[4] = {0}; //初始化一个数组，用 0 1 记录每一种类型字符出现与否的情况
	int count = 0; //计数器，记录字符串包含多少种字符（大小写字母，数字，其他符号等）
	int num = 0; //有相同长度超 2 的子串重复的字符串对数
	//记录字符串是否包含四种字符的情况
	for (int i = 0; i < len; i++) {
		if ((str[i] >= 'A') && (str[i] <= 'Z')) {
			a[0] = 1;
		} else if ((str[i] >= 'a') && (str[i] <= 'z')) {
			a[1] = 1;
		} else if ((str[i] >= '0') && (str[i] <= '9')) {
			a[2] = 1;
		} else {
			a[3] = 1;
	
	//计算字符串包含的字符种类总数
	for (int i = 0; i < 4; i++) {
		if (a[i] == 1) {
			count++;
			
		}
	}
	//判断字符串是否包含长度超 2 的两个以上相同子串，故考虑长度为 3 的子字符串是否有重复即可，从而子字符串有（len - 2）种可能，但作为基准子字符串的只需要（len - 3）个即可
	//因为最后一个子字符串被反复判断的次数最多，并且在它之后没有可以比较的子字符串了，所以 i <= len - 6，即最后一个基准子字符串是倒数第二个子字符串
	for (int i = 0; i <= len - 6; i++) {
		for (int j = i + 3; j <= len - 3; j++) {
			if ((str[i] == str[j]) && (str[i + 1] == str[j + 1]) && (str[i + 2] == str[j + 2])) {
				num++;
			}
			//一旦出现重复的子字符串（长度为 3 ），就及时跳出 for 循环，避免做无用功
			if (num != 0) {
				break;
			}
		}
		//一旦出现重复的子字符串（长度为 3 ），就及时跳出 for 循环，避免做无用功
		if (num != 0) {
			break;
		}
	}
	//验证密码是否合格，并输出验证结果
	if ((len >= 9) && (count >= 3) && (num == 0)) {
		return "OK";
	}
	//验证不通过的条件也可以放在不同位置，比如先判断字符串的长度是否超过 8，若不满足，其他条件也就不用验证了。
	else if ((len <= 8) || (count <= 2) || (num >= 1)) {
		return "NG";
	}
}
//主函数
int main() {
	string str;
	while (getline(cin, str)) {
		cout << Password_Verification(str) << endl;
	}
	return 0;
}


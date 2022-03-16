// 密码强度等级

#include <iostream>
using namespace std;
//接口一、密码长度：5 分: 小于等于4 个字符；10 分: 5 到7 字符；25 分: 大于等于8 个字符
int Password_Length_Score(int len) {
	int score = 0;
	if ((len >= 0) && (len <= 4)) {
		score = 5;
	} else if ((len >= 5) && (len <= 7)) {
		score = 10;
	} else if (len >= 8) {
		score = 25;
	}
	return score;
}
//接口二、字母: 0 分: 没有字母；10 分: 全都是小（大）写字母；20 分: 大小写混合字母
int Alphabet_Score(int Array[]) {
	//大写字母：65~90；小写字母：97~122
	int score = 0;
	int num1 = 0; //大写字母个数
	int num2 = 0; //小写字母个数
	for (int i = 65; i <= 90; i++) {
		num1 += Array[i];
	}
	for (int i = 97; i <= 122; i++) {
		num2 += Array[i];
	}
	if ((num1 == 0) && (num2 == 0)) {
		score = 0;
	} else if (((num1 > 0) && (num2 == 0)) || ((num1 == 0) && (num2 > 0))) {
		score = 10;
	} else if ((num1 > 0) && (num2 > 0)) {
		score = 20;
	}
	return score;
}
//接口三、数字：0 分: 没有数字；10 分: 1 个数字；20 分: 大于1 个数字
int Number_Score(int Array[]) {
	//数字：48~57
	int score = 0;
	int num = 0; //数字个数
	for (int i = 48; i <= 57; i++) {
		num += Array[i];
	}
	if (num == 0) {
		score = 0;
	} else if (num == 1) {
		score = 10;
	} else if (num > 1) {
		score = 20;
	}
	return score;
}
//接口四、符号：0 分: 没有符号；10 分: 1 个符号；25 分: 大于1 个符号
int Symbol_Score(int Array[]) {
	int score = 0;
	int num = 0; //符号个数
	for (int i = 0; i <= 47; i++) {
		num += Array[i];
	}
	for (int i = 58; i <= 64; i++) {
		num += Array[i];
	}
	for (int i = 91; i <= 96; i++) {
		num += Array[i];
	}
	for (int i = 123; i <= 127; i++) {
		num += Array[i];
	}
	if (num == 0) {
		score = 0;
	} else if (num == 1) {
		score = 10;
	} else if (num > 1) {
		score = 25;
	}
	return score;
}
//接口五、奖励：2 分: 字母和数字；3 分: 字母、数字和符号；5 分: 大小写字母、数字和符号
int Reward_Score(int score1, int score2, int score3) {
	int score = 0;
	if ((score1 != 0) && (score2 != 0) && (score3 == 0)) {
		score = 2;
	} else if ((score1 != 0) && (score2 != 0) && (score3 != 0)) {
		score = 3;
	} else if ((score1 == 20) && (score2 != 0) && (score3 != 0)) {
		score = 5;
	}
	return score;
}
//获取密码强度等级的函数接口
int Get_Password_Security_Level(string PasswordStr) {
	int score = 0; //密码得分
	int len = PasswordStr.size();
	int Array[128] = {0}; //字符记录数组
	for (int i = 0; i < len; i++) {
		Array[PasswordStr[i]] = 1;
	}
	//累计各项得分
	score += Password_Length_Score(len);
	score += Alphabet_Score(Array);
	score += Number_Score(Array);
	score += Symbol_Score(Array);
	score += Reward_Score(Alphabet_Score(Array), Number_Score(Array), Symbol_Score(Array));
	if ((score >= 90) && (score <= 100)) {
		cout << "VERY_SECURE" << endl;
	} else if ((score >= 80) && (score < 90)) {
		cout << "SECURE" << endl;
	} else if ((score >= 70) && (score < 80)) {
		cout << "VERY_STRONG" << endl;
	} else if ((score >= 60) && (score < 70)) {
		cout << "STRONG" << endl;
	} else if ((score >= 50) && (score < 60)) {
		cout << "AVERAGE" << endl;
	} else if ((score >= 25) && (score < 50)) {
		cout << "WEAK" << endl;
	} else if ((score >= 0) && (score < 25)) {
		cout << "VERY_WEAK" << endl;
	}
	return 0;
}
//主函数
int main() {
	string PasswordStr;
	while (getline(cin, PasswordStr)) {
		Get_Password_Security_Level(PasswordStr);
	}
	return 0;
}

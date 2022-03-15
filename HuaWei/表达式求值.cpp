// 表达式求值

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int compute(string& s, int left, int right) {
	char op = '+'; //默认加开始
	int num = 0;
	vector<int> st;
	for (int i = left; i <= right; i++) {
		if (isdigit(s[i])) //数字
			num = num * 10 + s[i] - '0'; //计算该部分数字总和
		if (s[i] == '(') { //进入左括号
			int layer = 0; //统计左括号层数
			int j = i;
			while (j <= right) { //遍历到右边
				if (s[j] == '(')
					layer++; //遇到左括号，层数累加
				else if (s[j] == ')') {
					layer--; //遇到右括号层数递减
					if (layer == 0) //直到层数为0
						break;
				}
				j++;
			}
			num = compute(s, i + 1, j - 1); //递归计算括号中的部分
			i = j + 1;
		}
		if (!isdigit(s[i]) || i == right) { //遇到运算符或者结尾
			switch (op) { //根据运算符开始计算
				case '+':
					st.push_back(num);
					break; //加减法加入到末尾
				case '-':
					st.push_back(-num);
					break;
				case '*':
					st.back() *= num;
					break; //乘除法与末尾计算
				case '/':
					st.back() /= num;
					break;
			}
			op = s[i]; //修改为下一次的运算符
			num = 0;
		}
	}
	int res = 0;
	for (int x : st) //累加和
		res += x;
	return res;
}
int main() {
	string s;
	while (cin >> s) {
		cout << compute(s, 0, s.length() - 1) << endl;
	}
	return 0;
}


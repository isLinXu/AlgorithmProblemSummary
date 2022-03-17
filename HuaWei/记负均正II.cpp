// 记负均正II

#include <iostream>
#include<iomanip> //包含格式控制函数 setiosflags() 和输出数的位数控制函数 setprecision() 的头文件
using namespace std;
//主函数
int main() {
	int num; //输入整数
	int count1 = 0; //计数器，记录负数的个数
	int count2 = 0; //计数器，记录正数的个数
	float sum = 0.0; //记录正数之和
	float mean = 0.0; //均值
	while (cin >> num) {
		if (num < 0) {
			count1++;
		} else if (num > 0) {
			count2++;
			sum += num;
		}
	}
	//避免 0 做除数
	if (count2 > 0) {
		mean = sum / count2;
	}
	//setiosflags(ios::fixed|ios::showpoint) 控制输出格式；setprecision() 设置精度，控制输出数的位数；
	//对应的，本题需要实现“若出现小数，则保留一位小数”，即控制小数部分有且仅有一位输出，故有如下代码。
	cout << count1 << '\n' << setiosflags(ios::fixed | ios::showpoint) << setprecision(1) << mean << endl;
	return 0;
}

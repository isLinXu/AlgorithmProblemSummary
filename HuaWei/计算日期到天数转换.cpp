// 计算日期到天数转换

#include <iostream>
using namespace std;
int main() {
	int year, mon, day;
	int data[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	while (cin >> year >> mon >> day) {
		int sum;
		for (int i = 0; i < mon - 1; i++) {
			sum = sum + data[i];
		}
		if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && mon > 2)
			sum = sum + 1 + day;
		else
			sum = sum + day;
		cout << sum << endl;

	}
	return 0;
}

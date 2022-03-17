// 求解立方根

#include<iostream>
#include<iomanip>
using namespace std;

double cal(double x) { //二分查找
	double left = min(-1.0, x); //正负数都有
	double right = max(1.0, x);
	double y;
	while (abs(right - left) > 0.01) { //立方根的精度值
		y = (left + right) / 2; //二分中值
		if (y * y * y > x) //比较选取二分哪一边
			right = y;
		else
			left = y;
	}
	return y;
}

int main() {
	double val;
	while (cin >> val) {
		cout << setprecision(1) << fixed << cal(val) << endl; //控制小数位输出
	}
	return 0;
}


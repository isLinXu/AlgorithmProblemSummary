// 坐标移动
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//坐标移动的函数接口
int Coordinate_Movement(string str) {
	int x = 0, y = 0; //初始化横纵坐标
	int len = str.size(); //获取字符串的总长度
	vector <string> vec; //用一个向量来存储分割后的多个子字符串
	//将字符串 str 按 ';' 分割成多个子字符串 substr，然后依次写入向量 vec 中
	int sublen = 0; //记录每个子字符串的长度
	for (int i = 0; i < len; i++) {
		if (str[i] != ';') {
			sublen++;
			continue;
		}
		vec.push_back(str.substr(i - sublen, sublen));
		sublen = 0;
	}

	//坐标移动，方向（左右上下） + 大小（-99~99）
	for (int i = 0; i < vec.size(); i++) {
		//确定坐标移动的大小，[-99,99]
		int num = 0; //（横或纵）坐标移动的大小
		//若字符串为三位有效位，则第二和第三位是坐标移动的大小
		if ((vec[i].size() == 3) && (vec[i][1] >= '0') && (vec[i][1] <= '9') && (vec[i][2] >= '0') && (vec[i][2] <= '9')) {
			num = (vec[i][1] - '0') * 10 + (vec[i][2] - '0');
		}
		//若字符串为两位有效位，则第二位是坐标移动的大小
		if ((vec[i].size() == 2) && (vec[i][1] <= '9') && (vec[i][1] >= '0')) {
			num = (vec[i][1] - '0');
		}
		//若字符串为一位有效位，则无坐标移动
		if (vec[i].size() == 1) {
			num = 0;
		}
		//确定坐标移动的方向，左右上下
		switch (vec[i][0]) {
			case 'A':
				x -= num;
				break;
			case 'D':
				x += num;
				break;
			case 'S':
				y -= num;
				break;
			case 'W':
				y += num;
				break;
			default:
				break;
		}
	}
	cout << x << "," << y << endl;
	return 0;
}

//主函数
int main() {
	string str;
	while (cin >> str) {
		Coordinate_Movement(str);
	}
	return 0;
}

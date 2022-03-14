// 求小球落地5次后所经历的路程和第5次反弹的高度

#include <iostream>
#include <iomanip> //包含输出数的位数控制函数 setprecision() 的头文件
//#include <algorithm>，采用方法二“幂函数直接求解反弹高度”时使用
using namespace std;
//球落地反弹的函数接口
int Ball_Bounce(int num)
{
	int bounce_time = 5; //设置反弹次数
	int drop_time = 5; //设置落地次数
	double path_length = 0.0; //经过的路径总长度
	double bounce_height = 0.0; //单次反弹高度
	//方法一：可以用递归来依次求解反弹高度
	bounce_height = double(num) / 2; //第一次反弹的高度
	for (int i = 2; i <= bounce_time; i++)
	{
		bounce_height = bounce_height / 2;
	}
	//方法二：可以用幂函数来直接求解反弹高度，但好像不是很稳定，耗时稍长：bounce_height = double(num) / pow(2, bounce_time);
	double length = double(num); //第一次落地的路径长度
	path_length += length; //累计经过的路径总长度，从第一次落地开始记录
	for (int i = 2; i <= drop_time; i++)
	{
		//每次落地的路径长度为上一次落地的路径长度的一半
		length = length / 2;
		//从第二次落地开始，每次落地的路径长度和当前反弹高度相等，故该往返（反弹-落地）经过的路径长度为该次落地的路径长度的两倍
		path_length += 2 * length;
	}
	//保留六位有效数字
	cout << setprecision(6) << path_length << '\n' << bounce_height << endl;
	return 0;
}
//主函数
int main()
{
	int starting_height; //输入起始高度
	while (cin >> starting_height)
	{
		Ball_Bounce(starting_height); //调用球落地反弹的函数接口
	}
	return 0;
}

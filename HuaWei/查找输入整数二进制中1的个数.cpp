// 查找输入整数二进制中1的个数

#include <iostream>
using namespace std;
//查找输入整数二进制中 1 的个数的函数接口
int Find_Number_Of_1(int num)
{
	int count = 0; //计数器，记录 1 的个数
	//整数转为二进制形式，但只计数 1，无需输出二进制
	while (double (num) / 2 > 0)
	{
		if (num % 2 == 1)
		{
			count++;
			num = num / 2;
		}
		else if (num % 2 == 0)
		{
			num = num / 2;
		}
	}
	cout << count << endl;
	return 0;
}
//主函数
int main()
{
	int num;
	while (cin >> num)
	{
		Find_Number_Of_1(num);
	}
	return 0;
}

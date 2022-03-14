// 图片整理

#include <iostream>
#include <algorithm>
using namespace std;
//字符排序的函数接口
string String_Sorting(string str)
{
	//按字符的 ASCII 码排序
	sort(str.begin(), str.end());
	//返回排序后的字符串
	return str;
}
//主函数
int main()
{
	string str;
	while (getline(cin, str))
	{
		cout << String_Sorting(str) << endl;
	}
	return 0;
}

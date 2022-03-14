// 统计字符

#include <iostream>
using namespace std;
/*
函数接口1：统计出英文字母字符的个数。
@param str 需要输入的字符串
@return 英文字母字符的个数
 */
int getEnglishCharCount(string str)
{
	int count = 0; //计数器，记录英文字符的个数
	for (int i = 0; i < str.size(); i++)
	{
		if (((str[i] >= 'A') && (str[i] <= 'Z')) || ((str[i] >= 'a') && (str[i] <= 'z')))
		{
			count++;
		}
	}
	return count;
}
/*
函数接口2：统计出空格字符的个数。
@param str 需要输入的字符串
@return 空格字符的个数
 */
int getBlankCharCount(string str)
{
	int count = 0; //计数器，记录空格字符的个数
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}
	return count;
}
/*
函数接口3：统计出数字字符的个数。
@param str 需要输入的字符串
@return 数字字符的个数
 */
int getNumberCharCount(string str)
{
	int count = 0; //计数器，记录数字字符的个数
	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
		{
			count++;
		}
	}
	return count;
}
/*
函数接口4：统计出其它字符的个数。
@param str 需要输入的字符串
@return 其他字符的个数
 */
int getOtherCharCount(string str)
{
	//ASCII 码：最小边界值 0；空格：32；数字：48~57；英文字母：大写 65~90，小写 97~122；最大边界值 127。故对应写出五个区间即可判断其他字符
	int count = 0; //计数器，记录其他字符的个数
	for (int i = 0; i < str.size(); i++)
	{
		if (((str[i] >= 0) && (str[i] < ' ')) || ((str[i] > ' ') && (str[i] < '0')) || ((str[i] > '9') && (str[i] < 'A')) || 
			((str[i] > 'Z') && (str[i] < 'a')) || ((str[i] > 'z') && (str[i] <= 127)))
		{
			count++;
		}
	}
	return count;
}
//主函数
int main()
{
	string str;
	while (getline(cin, str))
	{
		cout << getEnglishCharCount(str) << '\n' << getBlankCharCount(str) << '\n' 
		<< getNumberCharCount(str) << '\n' << getOtherCharCount(str) << endl;
	}
	return 0;
}

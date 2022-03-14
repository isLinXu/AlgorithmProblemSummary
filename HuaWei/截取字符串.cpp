// 截取字符串

#include <iostream>
using namespace std;
//按按字符截取字符串的函数接口
int Intercept_String_by_Character(string str, int length)
{
	//截取子字符串
	string substr = str.substr(0, length);
	cout << substr << endl;
	return 0;
}
//主函数
int main()
{
	string str;
	int length;
	while (cin >> str >> length)
	{
		Intercept_String_by_Character(str, length);
	}
	return 0;
}

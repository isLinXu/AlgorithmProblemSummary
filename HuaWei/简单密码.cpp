// 简单密码

#include<iostream>
using namespace std;
//密码（口令）变换的函数接口
string Password_Transformation(string str)
{
	//字典法：考虑两个字典，一个是明文字典 a[]，另一个是明文对应的加密字典 b[]。
	//然后采用字典元素对应的方法，做加密或解密，实现方法为“字典下标对应索引以及元素匹配”。
	char a[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"}; //非必要的参照字典
	char b[] = {"bcdefghijklmnopqrstuvwxyza222333444555666777788899990123456789"}; //字符输出对应字典
	int len = str.size();
	for (int i = 0; i < len; i++)
	{
		//小写字母转数字
		if ((str[i] >= 'a') && (str[i] <= 'z'))
		{
			str[i] = b[str[i] - 'a' + 26];
		}
		//大写字母转小写
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			str[i] = b[str[i] - 'A'];
		}
		//数字不用转换，保持原样
	}
	return  str;
}


//主函数
int main()
{
	string str;
	while (getline(cin,str))
	{
		cout << Password_Transformation(str) << endl;
	}
	return 0;
}

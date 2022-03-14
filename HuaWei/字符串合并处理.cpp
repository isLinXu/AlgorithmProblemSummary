/*
字符串合并处理
 */
#include <iostream>
#include <algorithm>
using namespace std;
//字符串合并处理的函数接口
void Process_String(string str1, string str2, string strOutput)
{
	//字典法：只考虑 '0' 到 '9' ，'a' 到 'f'，'A' 到 'F' 的字符即可，其余字符不做改变，照原输出
	char Intput[] = {"0123456789abcdefABCDEF"}; //输入参照字典（数字 + 大小写字母）
	//    int Output[] = "084c2a6e195d3b7f5d3b7f"; //输出参照字典（小写）
	char Output[] = {"084C2A6E195D3B7F5D3B7F"}; //输出参照字典（数字 + 大写字母）
	strOutput = str1 + str2; //合并两个字符串
	string odd_str; //下标为奇数的字符组成的字符串，奇数位字符串
	string even_str; //下标为偶数的字符串组成的字符串，偶数位字符串
	//根据字符在合并字符串中的次序，按字典序分奇数位、偶数位独立来排，但次序的奇偶性不变，即原来是奇数位，排序后还是奇数位
	for (int i = 0; i < strOutput.size(); i++)
	{
		if (i % 2 == 0)
		{
			odd_str += strOutput[i];
		}
		else if (i % 2 == 1)
		{
			even_str += strOutput[i];
		}
	}
	sort(odd_str.begin(), odd_str.end()); //奇排序
	sort(even_str.begin(), even_str.end()); //偶排序
	//将按奇数位、偶数位排序后的字符再填回合并字符串 strOutput
	int j = 0; //奇数位字符串的下标
	int k = 0; //偶数位字符串的下标
	for (int i = 0; i < strOutput.size(); i++)
	{
		if (i % 2 == 0)
		{
			strOutput[i] = odd_str[j];
			j++;
		}
		else if (i % 2 == 1)
		{
			strOutput[i] = even_str[k];
			k++;
		}
	}
	//对字符（符合字典 Input[]）所代表的 16 进制的数进行 BIT 倒序的操作，并转换为相应的大写字符
	for (int i = 0; i < strOutput.size(); i++)
	{
		if ((strOutput[i] >= '0') && (strOutput[i] <= '9'))
		{
			strOutput[i] = Output[strOutput[i] - '0'];
		}
		else if ((strOutput[i] >= 'a') && (strOutput[i] <= 'f'))
		{
			strOutput[i] = Output[strOutput[i] - 'a' + 10];
		}
		else if ((strOutput[i] >= 'A') && (strOutput[i] <= 'F'))
		{
			strOutput[i] = Output[strOutput[i] - 'A' + 16];
		}
	}
	cout << strOutput << endl;
	return;
}
//主函数
int main()
{
	string str1, str2, strOutput;
	while (cin >> str1 >>str2)
	{
		Process_String(str1, str2, strOutput);
	}
	return 0;
}

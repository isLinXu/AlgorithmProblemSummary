// 输入整型数组和排序标识，对其元素按照升序或降序进行排序


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//数组法
//升序排序或降序排序的函数接口
void Ascending_Descending_Sorting(int num)
{
	int number; //输入整数
	int pIntegerArray[num]; //存储整数的数组
	int iSortFlag; //排序标识
	for (int i = 0; i < num; i++)
	{
		cin >> number;
		pIntegerArray[i] = number;
	}
	cin >> iSortFlag;
	//数组的元素排序（从小到大）
	sort(pIntegerArray, pIntegerArray + num);
	//排序标识为 0，顺序输出
	if (iSortFlag == 0)
	{
		for (int i = 0; i < num; i++)
		{
			cout << pIntegerArray[i] << ' ';
		}
		cout << endl;
	}
	//排序标识为 1，逆序输出
	else if (iSortFlag == 1)
	{
		for (int i = num - 1; i >= 0; i--)
		{
			cout << pIntegerArray[i] << ' ';
		}
		cout << endl;
	}
	return;
}
//主函数
int main()
{
	int num;
	while (cin >> num)
	{
		Ascending_Descending_Sorting(num);
	}
	return 0;
}
/*
//向量法
//升序排序或降序排序的函数接口
void Ascending_Descending_Sorting(int num)
{
int number; //输入整数
vector <int> vec; //存储整数的向量
int iSortFlag; //排序标识：0 表示按升序，1 表示按降序
for (int i = 0; i < num; i++)
{
cin >> number;
vec.push_back(number);
}
cin >> iSortFlag;
//向量的元素排序（从小到大）
sort(vec.begin(), vec.end());
//排序标识为 0，顺序输出
if (iSortFlag == 0)
{
for (int i = 0; i < num; i++)
{
cout << vec[i] << ' ';
}
cout << endl;
}
//排序标识为 1，逆序输出
else if (iSortFlag == 1)
{
for (int i = num - 1; i >= 0; i--)
{
cout << vec[i] << ' ';
}
cout << endl;
}
return;
}
//主函数
int main()
{
int num;
while (cin >> num)
{
Ascending_Descending_Sorting(num);
}
return 0;
}
 */

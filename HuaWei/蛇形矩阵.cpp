/*
2020-05-05
蛇形矩阵
 */
//解题思路：笨方法
//蛇形矩阵，顾名思义像蛇摆一样，具有弯曲但连续这个特点；
//从矩阵特点来看，就是沿着方阵的主对角线斜向下方向，以及沿着副对角线斜向上，依次递增 1；
//从输出矩阵元素的个数来看，总数是一个首项为 1 且公差为 1 的等差数列前 N 项和；
//利用等差数列的规律，可以得知，每一行或每一列的数列是一个阶梯级数（相邻两项的差逐渐递增）。
#include <iostream>
using namespace std;
//输出蛇形矩阵的函数接口
int SerpentineMatrix (int N) {
	int Column_d = 1; //初始化列间相邻两项的第一个差
	int ColumnFirstItem = 1; //列首项
	int RowFirstItem = 1; //行首项
	//按行顺序输出矩阵元素
	for (int i = 1; i <= N; i++) {
		RowFirstItem = ColumnFirstItem; //将第 1 列的第 i 个元素按顺序拷贝作为第 i 行的首个元素
		cout << ColumnFirstItem << ' '; //输出第 i 行的首个元素
		ColumnFirstItem += Column_d;
		Column_d++;  //相邻两项的差递增 1
		int Row_d = i + 1; //初始化第 i 行元素的行间相邻两项的第一个差
		//按列顺序输出第 i 行的矩阵元素
		for (int j = i + 1; j <= N; j++) {
			RowFirstItem += Row_d;
			cout << RowFirstItem << ' '; //输出第 i 行除首个元素之外的其余元素
			Row_d++; //相邻两项的差递增 1
		}
		cout << endl; //第 i 行元素输出结束，换行。
	}
	return 0;
}
//主函数
int main (){
	int N; //矩阵的阶数 N，由于是正整数，故大于或等于 1。
	while (cin >> N) {
		SerpentineMatrix (N);
	}
	return 0;
}

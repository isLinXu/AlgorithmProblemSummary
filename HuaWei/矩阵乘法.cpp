// 矩阵乘法

#include <iostream>
using namespace std;
//矩阵乘法的函数接口
int MatrixMultiplication (int x, int y, int z) {
	int number; //矩阵元素
	//用数组来存储矩阵
	int A[x][y]; //矩阵 A
	int B[y][z]; //矩阵 B
	int C[x][z]; //矩阵 C
	//输入矩阵 A
	for (int i = 0; i < x; i++) {
		for (int k = 0; k < y; k++) {
			cin >> number;
			A[i][k] = number;
		}
	}
	//输入矩阵 B
	for (int k = 0; k < y; k++) {
		for (int j = 0; j < z; j++) {
			cin >> number;
			B[k][j] = number;
		}
	}
	//计算矩阵 C
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < z; j++) {
			C[i][j] = 0; //初始化矩阵 C 的每个元素，置为 0。若缺少这个，有些测试示例不通过。
			for (int k = 0; k < y; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	//输出矩阵 C
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < z; j++) {
			cout << C[i][j] << ' ';
		}
		cout << endl; //换行，输出矩阵的下一行元素
	}
	return 0;
}
//主函数
int main() {
	int x;
	int y;
	int z;
	while (cin >> x >> y >> z) {
		MatrixMultiplication(x, y, z);
	}
	return 0;
}

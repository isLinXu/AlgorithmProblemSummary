// 自守数

/*
求自守数的解题思路
规律：个位数为 0、1、5、6 的数才可能是自守数，故采用筛选法，只判断符合该条件的数
思路1：可以把整数（数及其平方）转换为字符串，通过比较长字符串的末尾是否与短字符串相同即可
如：25 * 25 = 625，字符串'625'的末尾'25'与字符串'25'的相同
思路2：若该数的平方与该数的差，去模该数对应的各个进制位均等于零，则该数为自守数
如：25 * 25 = 625，625 - 25 = 600，600 % (10*1) = 0，600 % （10 * 2） = 0
 */
#include <iostream>
#include <string>
using namespace std;
//求整数 n 以内自守数的接口
int CalcAutomorphicNumbers(int n) {
	int count = 0;
	for (int i = 0; i <= n; i++) {
		//仅对个位数符合条件的数执行自守数的判断
		if ((i % 10 == 0) || (i % 10 == 1) || (i % 10 == 5) || (i % 10 == 6)) {
			long j = i * i;
			string s1 = to_string(i);
			string s2 = to_string(j);
			int pos = s2.size() - s1.size();
			if (s2.find(s1, pos) != -1) {
				count++;
			}
		}
	}
	return count;
}
int main() {
	int n;
	while (cin >> n) {
		cout << CalcAutomorphicNumbers(n) << endl;
	}
	return 0;
}

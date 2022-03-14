/*
2020-03-16
字符串运用-密码截取
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//思路：基于对称字符串的特点，考虑原始字符串和反转后的字符串之间的最大重合对称子字符串即可
//如 1232100 与0012321，互为相反的字符串，二者的最大重合对称子字符串为 12321，长度为 5 获取最长有效密码长度的函数接口
//方法：动态规划
int Get_Ciphertext_Max_Len(string str) {
	string str1 = str; //原始字符串
	reverse(str.begin(), str.end());
	string str2 = str; //反转后的字符串
	int len1 = str1.size(); //获取原始字符串长度
	int len2 = str2.size(); //获取反转后的字符串的长度
	int max = 0; //字符串 str 1 和 字符串 str2 的最大重合对称子字符串的长度
	int** dp = new int* [len2];
	//当字符串为空时，返回 0
	if (len1 == 0) {
		return 0;
	}
	//当字符串仅有一个字符时，返回 1
	if (len1 == 1) {
		return 1;
	}
	for (int i = 0; i < len2; i++) {
		dp[i] = new int [len1];
	}
	for (int i = 0; i < len2; i++) {
		if (str1[0] == str2[i]) {
			dp[i][0] = 1;
		} else {
			dp[i][0] = 0;
		}
	}
	for (int i = 0; i < len1; i++) {
		if (str1[i] == str2[0]) {
			dp[0][i] = 1;
		} else {
			dp[0][i] = 0;
		}
	}
	for (int i = 1; i < len2; i++) {
		for (int j = 1; j < len1; j++) {
			if (str2[i] == str1[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = 0;
			}
			if (dp[i][j] > max) {
				max = dp[i][j];
			}
		}
	}
	return max;
}
//主函数
int main () {
	string str;
	while (cin >> str) {
		cout << Get_Ciphertext_Max_Len(str) << endl;
	}
	return 0;
}



//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//const int N = 3e3 + 10;
//
//int main()
//{
//	string a;
//	cin >> a;
//	int ans = 1;
//	/*遍历每一个元素*/
//	for (int i = 0; i < a.size(); i ++ ) {
//		/*扩展计算最长AA型的回文串*/
//		int l = i - 1, r = i + 1;
//		while (l >= 0 && r < a.size() && a[l] == a[r]) {
//			ans = max(ans, r - l + 1);    //更新答案
//			l -- , r ++ ;
//		}
//		/*扩展计算最长ABA型的回文串*/
//		l = i, r = i + 1;
//		while (l >= 0 && r < a.size() && a[l] == a[r]) {
//			ans = max(ans, r - l + 1);    //更新答案
//			l -- , r ++ ;
//		}
//	}	
//	cout << ans << "\n";
//	return 0;
//}


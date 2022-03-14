// 统计每个月兔子的总数

#include<iostream>
using namespace std;

int getSum(int n) { //求每个月兔子数
	if(n == 1 || n == 2) //n=1或2跳出递归
		return 1;
	return getSum(n - 1) + getSum(n - 2); //返回前两个月相加
}

int main(){
	int n;
	while(cin >> n){ //每次输入n
		cout << getSum(n) << endl;
	}
	return 0;
}

// 动态规划
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main(){
//	int n;
//	while(cin >> n){ //每次输入n
//		vector<int> dp(n + 1);
//		dp[1] = 1; //初始第一个月
//		dp[2] = 1; //第二个月
//		for(int i = 3; i <= n; i++) //后面的每个月由前面的累加
//			dp[i] = dp[i - 1] + dp[i - 2];
//		cout << dp[n] << endl;
//	}
//	return 0;
//}


// 迭代
//#include<iostream>
//using namespace std;
//
//int main(){
//	int n;
//	while(cin >> n){ //每次输入n
//		if(n <= 2) //前两个月直接输出
//			cout << 1 << endl;
//		else{
//			int dpi_2 = 1; //初始化第1个月
//			int dpi_1 = 1; //初始化第2个月
//			int output = 0;
//			for(int i = 3; i <= n; i++){
//				output = dpi_1 + dpi_2; //公式相加
//				dpi_2 = dpi_1; //变量更新
//				dpi_1 = output;
//			}
//			cout << output << endl;
//		}
//	}
//	return 0;
//}


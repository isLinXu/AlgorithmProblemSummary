// 合唱队

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	while(cin >> n){
		// 输入的数组
		int tmp;
		vector<int> v;
		for (int i = 0; i < n; ++i){
			cin >>tmp;
			v.push_back(tmp);
		}
		
		// 最长递增子序列
		if (v.empty()) return 0;
		vector<int> dp1(n, 0);
		for (int i = 0; i < n; ++i){
			dp1[i] = 1;
			for(int j = 0; j <  i ; ++j){
				if (v[i] > v[j]){
					dp1[i] = max(dp1[i], dp1[j]+1);
				}
			}
		}
		
		// 最长递减子序列
		vector<int> dp2(n, 0);
		for (int i = n - 1; i >= 0; --i){
			dp2[i] = 1;
			for (int j = n -1; j > i; --j){
				if (v[i] > v[j]){
					dp2[i] = max(dp2[i], dp2[j]+1);
				}
			}
		}
		
		
		int maxLength = 0;
		for (int  i = 0; i < n; ++i){
			if (maxLength < dp1[i] + dp2[i] - 1){
				maxLength = dp1[i] + dp2[i] - 1;
				//这里的i就是划分中点
			}
		}
		cout << n - maxLength << endl;
	}
	return 0;
}

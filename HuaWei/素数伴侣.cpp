// 素数伴侣

#include<iostream>
#include<vector>
using namespace std;

bool isprime(int num){ //判断一个数是否是素数
	for(int i = 2; i * i <= num; i++){ //遍历到根号num
		if(num % i == 0) //检查有无余数
			return false;
	}
	return true;
}

bool find(int num, vector<int>& evens, vector<bool>& used, vector<int>& match){
	for(int i = 0; i < evens.size(); i++){ //遍历每个偶数与奇数比较
		if(isprime(num + evens[i]) && !used[i]){
			used[i] = true;
			if(match[i] == 0 || find(match[i], evens, used, match)){ //如果第i个偶数还未配对，或者跟它配对的奇数还有别的选择
				match[i] = num; //则配对该数
				return true;
			}
		}
	}
	return false;
}
int main(){
	int n;
	while(cin >> n){
		vector<int> odds;
		vector<int> evens;
		vector<int> nums(n);
		for(int i = 0; i < n; i++){ //输入n个数
			cin >> nums[i];
			if(nums[i] % 2) //奇数
				odds.push_back(nums[i]);
			else //偶数
				evens.push_back(nums[i]);
		}
		int count = 0;
		if(odds.size() == 0 || evens.size() == 0){ //缺少奇数或者偶数无法构成素数
			cout << count << endl;
			continue;
		}
		vector<int> match(evens.size(), 0); //统计每个偶数的配对是哪个奇数
		for(int i = 0; i < odds.size(); i++){ //遍历每个奇数
			vector<bool> used(evens.size(), false); //每一轮偶数都没用过
			if(find(odds[i], evens, used, match)) //能否找到配对的偶数，且要最优
				count++;
		}
		cout << count << endl;
	}
	return 0;
}

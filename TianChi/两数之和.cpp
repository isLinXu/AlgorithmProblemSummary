// 两数之和

#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target){
		map<int, int> a;
		vector<int> b(2,-1);

		for (int i = 0; i < nums.size(); i++){
			if (a.count(target-nums[i]>0)){
				b[0] = a[target-nums[i]];
				b[1] = i;
				break;
			}
			a[nums[i]] = i;
		}
		return b;
	}

};



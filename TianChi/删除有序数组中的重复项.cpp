// 删除有序数组中的重复项

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		// 双指针法
		int n = nums.size();
		if (n == 0) return 0;
		// i指向目前有序不重复的最后一个下标
		// j指向大于left的下一个元素
		int i = 0;
		for (int j = 1; j < n; j++) {
			// j对应值赋予在i后
			if (nums[j] != nums[i]) {
				i++;
				nums[i] = nums[j];
			}
		}
		return i+1;   
	}
};

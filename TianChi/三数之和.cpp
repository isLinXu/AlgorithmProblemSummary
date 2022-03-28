// 三数之和

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		set<vector<int>> res;
		sort(nums.begin(), nums.end());
		if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
		for (int k = 0; k < (int)nums.size() - 2; ++k) {
			if (nums[k] > 0) break;
			int target = 0 - nums[k];
			int i = k + 1;
			int j = (int)nums.size() - 1;
			while (i < j) {
				if (nums[i] + nums[j] == target) {
					res.insert({nums[k], nums[i], nums[j]});
					while (i < j && nums[i] == nums[i + 1]) ++i;
					while (i < j && nums[j] == nums[j - 1]) --j;
					++i; --j;
				} else if (nums[i] + nums[j] < target) ++i;
				else --j;
			}
		}
		return vector<vector<int>>(res.begin(), res.end());
	}
};

// 字符统计

#include <map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main() {
	string s;
	map<char, int> mp;
	while (cin >> s) {
		//每次循环都要清一下map
		mp.clear();
		for (char c : s) {
			++mp[c];
		}
		//用迭代器范围初始化一个vector
		vector<pair<char, int>> vec(mp.begin(), mp.end());
		//因为map已经依照键排序了，所以用稳定排序当次数一样时，会保持原来的先后关系，即ASCII码的升序
		stable_sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
			//用Lambda来写配合算法使用的小函数是非常方便的
			return a.second > b.second;
		});
		for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
			cout << iter->first;
		}
		cout << endl;
	}
}


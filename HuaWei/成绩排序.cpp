// 成绩排序

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, flag;
	while (cin >> n >> flag) {
		vector<pair<string, int>> res(n);
		for (int i = 0; i < n; i++) {
			cin >> res[i].first >> res[i].second;
		}
		if (flag == 0) {
			stable_sort(res.begin(), res.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
				return a.second > b.second;
			});
		} else if (flag == 1) {
			stable_sort(res.begin(), res.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
				return a.second < b.second;
			});
		}
		for (int i = 0; i < n; i++)
			cout << res.at(i).first << " " << res.at(i).second << endl;
	}
	return 0;
}


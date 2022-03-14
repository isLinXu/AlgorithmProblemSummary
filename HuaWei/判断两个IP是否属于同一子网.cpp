// 判断两个IP是否属于同一子网

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> getnumber(string &s) {
	vector<int> v;
	int i = 0;
	string str = "";
	while (i < s.length()) {
		if (s[i] != '.') {
			while (i < s.length() && s[i] != '.') {
				str += s[i];
				i++;
			}
			v.push_back(stoi(str));
			str = "";
		} else i++;
	}
	return v;
}

bool judge1(vector<int> &v) {
	long long sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i] * pow(256, v.size() - 1 - i);
	}

	return (sum | (sum - 1)) == 0xFFFFFFFF;
}

bool judge(vector<int> &v, int t) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < 0 || v[i] > 255) return false;
	}
	if (t == 1) return judge1(v);
	return true;
}

int helper(string &s, string &s1, string &s2) {
	vector<int> v = getnumber(s);
	vector<int> v1 = getnumber(s1);
	vector<int> v2 = getnumber(s2);
	if (!judge(v, 1)) return 1;
	if (!judge(v1, 0)) return 1;
	if (!judge(v2, 0)) return 1;

	for (int i = 0; i < v.size(); i++) {
		if ((v1[i]&v[i]) != (v2[i]&v[i])) return 2;
	}
	return 0;
}
int main() {
	string s, s1, s2;
	while (cin >> s) {
		cin >> s1;
		cin >> s2;
		cout << helper(s, s1, s2) << endl;
	}
	return 0;
}

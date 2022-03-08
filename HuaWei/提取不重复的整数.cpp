// 提取不重复的整数

#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<bits/stdc++.h>

using namespace std;

//int main() {
//	
//	unordered_map<int, int>hash;
//	int num, out;
//
//	cin >> num;
//	while (num) {
//		if (hash[num % 10] == 0) {
//			hash[num % 10]++;
//			out = out * 10 + num % 10;
//		}
//		num /= 10;
//	}
//	cout << out << endl;
//
//
//	return 0;
//}

int main() {
	int nums; 
	cin >> nums;
	string str = to_string(nums);
	unordered_set<char> set;
	reverse(str.begin(), str.end());
	string res;
	for(char c : str)
		if(set.count(c) != 1) {
		res += c;
		set.insert(c);
	}
	cout << stoi(res) << endl;
	
	
}


// 10.字符个数的统计

#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<bits/stdc++.h>

using namespace std;

int main() {
//	int sum = 0;
//
//	unordered_map<char, int>hash;
//	char c;
//	while(cin >> c)	hash[c] = 1;
//
//
//	for (int i = 0; i < hash.size(); i++){
//		// ascii 0 ''
//		if (hash[' ' + i] == 1){
//			sum ++;
//		}
//	}
//	cout << sum << endl;
//
//
//	return 0;

	string str;
	cin >> str;
	unordered_set<char> set;
	for (char c : str)
		if (c >= 0 && c <= 127) set.insert(c);
	cout << set.size() << endl;
	return 0;
}


/*
字符串排序

输入:
9
cap
to
cat
card
two
too
up
boat
boot
输出：
boat
boot
cap
card
cat
to
too
two
up
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(const string &s1, const string &s2){
	return s1 < s2;
}



int main(){
	
	int n;
	cin >> n;
	vector<string> res;
	while(n--){
		string word;
		cin >> word;
		res.push_back(word);
	}
	sort(res.begin(),res.end(), cmp);
	
	for(auto x:res){
		cout << x << endl;
	}
	
	
	
	return 0;
}

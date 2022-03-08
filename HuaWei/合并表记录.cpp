#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	
//	int n;
//	cin >> n;
//	unordered_map<int, int> hash;
//	while(n--){
//		int k,v;
//		cin >> k >> v;
//		hash[k] += v;
//	}
//	for (int i =0; i < hash.size(); i++){
//		if (hash[i] != 0){
//			cout << i << ' ' << hash[i] << endl;
//		}
//	}
	int n;
	cin >> n;
	unordered_map<int, int> hash;
	vector<int> key;
	
	while(n--){
		int k,v;
		cin >> k >> v;
		key.push_back(k);
		hash[k] += v;
	}
	
	// key去重
	sort(key.begin(), key.end());
	key.erase(unique(key.begin(),key.end()), key.end());
	
	for (auto x:key){
		cout << x << " " << hash[x] << endl;
	}


	
	return 0;
}

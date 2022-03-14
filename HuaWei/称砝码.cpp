// 称砝码

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		vector<int> weight(n);
		vector<int> num(n);
		for(int i = 0; i < n; i++) //输入n种砝码重量
			cin >> weight[i];
		for(int i = 0; i < n; i++) //输入n种砝码的数量
			cin >> num[i];
		unordered_set<int> s; //集合用于去重
		s.insert(0); //0也是一种
		for(int i = 0; i < n; i++){ //对于每一种砝码
			for(int j = 1; j <= num[i]; j++){ //用完之前数量之前
				unordered_set<int> temp(s);
				for(auto iter = temp.begin(); iter != temp.end(); iter++) //当前集合每个都可以加一次
					s.insert(*iter + weight[i]);
			}
		}
		cout << s.size() << endl; //最后集合的大小就是种类
	}
	return 0;
}


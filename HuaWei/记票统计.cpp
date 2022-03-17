// 记票统计


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
	int num_name,num_choice;
	while(cin>>num_name){
		vector<string> name;//保存有哪些名字（vector可以保留顺序）
		unordered_map<string,bool> flag;//用来后面判断输入的名字是否合法
		unordered_map<string,int> num;//统计每个人的得票
		int wrong=0;
		while(num_name--){
			string s;
			cin>>s;
			name.push_back(s);
			flag[s]=true;
		}
		cin>>num_choice;
		while(num_choice--){
			string s;
			cin>>s;
			if(flag[s]==true)
				num[s]++;
			else wrong++;
		}

		for(string i:name)
			cout<<i<<" : "<<num[i]<<endl;
		cout<<"Invalid : "<<wrong<<endl;
	}
}


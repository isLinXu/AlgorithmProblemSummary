// 名字的漂亮度

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int d;
	while(cin>>d)
	{
		while(d--)
		{
			string s;
			cin>>s;
			vector<int>arr(26,0);
			for(int i=0;i<s.size();i++)
			{
				if(s[i]>='a'&&s[i]<='z')
				{
					arr[s[i]-'a']++;
				}
				else if(s[i]>='A'&&s[i]<='Z')
				{
					arr[s[i]-'A']++;
				}
			}
			sort(arr.begin(),arr.end());
			int res=0;
			int k=26;
			for(int i=25;i>=0;i--)
			{
				res+=arr[i]*k;
				k--;
			}
			cout<<res<<endl;
		}
	}
	return 0;
}


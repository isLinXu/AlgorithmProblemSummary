// 二维数组操作

#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,n,x,y;
	int x1,y1,x2,y2;
	int l,r;
	
	
	while(cin>>m>>n){
		//bool f=false;//无错误
		if(m<=9&&n<=9) cout<<0<<endl;
		else cout<<-1<<endl;
		
		cin>>x1>>y1>>x2>>y2;
		if(x1>=m||x2>=m||y1>=n||y2>=n) cout<<-1<<endl;
		else cout<<0<<endl;
		
		cin>>l;
		if(m==9||l>m-1) { 
			cout<<-1<<endl;
			// f=true;
		}else cout<<0<<endl;
		
		cin>>r;
		if(n==9||r>n-1) { 
			cout<<-1<<endl;
			//f=true;
		}else cout<<0<<endl;
		
		cin>>x>>y;
		if(x<m&&y<n) cout<<0<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}



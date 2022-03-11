// 购物单
/*
动态规划
本题的基本思想是动态规划，和背包问题一致。
理解本题的题意很关键，买了附件就要买主件，因此刚开始是以附件的角度入手，
但是如果主件买了，遇见附件也买再加上主件，这样就重复了，
我们可以从主件入手，把所有的商品都归到主件门下，不要单独把附件丢出来。
买了主件一定要买附件吗，不一定，可以比较后选择。
我们对每个主件都设定有两个附件，没有的话值就为0，有的话，
根据容量分别对是否加附件1，附件2，或者都加就可以做出选择。
而且很重要的一点是这种做法保证了如果选择了附件，
肯定也就选择了相应的主件，因为我们是以主件为前提的。
*/


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// 总线数 < 32000

int main() {
	
	int N,m;
	cin>>N>>m;
	N/=10;    //价格都是10的整数倍，这样处理可以有效的节省空间
	vector<vector<int>> price(m+1,vector<int>(3,0));  //表示主件的价格以及附件的价格，没有则为0
	vector<vector<int>> value(m+1,vector<int>(3,0));
	vector<vector<int>> re(m+1,vector<int>(N+1,0));
	int v,p,q;
	for(int i=1;i<=m;i++){
		cin>>v>>p>>q;
		v/=10;    
		if(q==0){    //物品是主件
			price[i][0]=v;
			value[i][0]=p*v;
		}else{      //此物品是编号为q的主件的附件
			if(price[q][1]==0){  //是主件q的第一个附件
				price[q][1]=v;
				value[q][1]=p*v;
			}else{    //是主件q的第二个附件
				price[q][2]=v;
				value[q][2]=p*v;
			}
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=N;j>0;j--)
	{
		if(j>=price[i][0]){//可以容纳主件
			re[i][j]=max(re[i-1][j],re[i-1][j-price[i][0]]+value[i][0]);
		}else if(j>=price[i][0]+price[i][1]){//可以容纳主件及主件的第一个附件
			re[i][j]=max(re[i-1][j],re[i-1][j-price[i][0]-price[i][1]]+value[i][0]+value[i][1]);
		}else if(j>=price[i][0]+price[i][2]){//可以容纳主件及主件的第二个附件
			re[i][j]=max(re[i-1][j],re[i-1][j-price[i][0]-price[i][2]]+value[i][0]+value[i][2]);
		}else if(j>=price[i][0]+price[i][1]+price[i][2]){//可以容纳主件及主件的第一和二个附件
			re[i][j]=max(re[i-1][j],re[i-1][j-price[i][0]-price[i][1]-price[i][2]]+value[i][0]+value[i][1]+value[i][2]);
		}
	}
	cout<<10*re[m][N]<<endl;


	return 0;
}

// 迷宫问题

#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<vector<int>> maze;
//当从（0，0）到（n-1，m-1）有多条通路时，best_path记录最小的temp_path
//本题只有一条通路，所以当到达（n-1，m-1）时，让 best_path=temp_path即可
vector<vector<int>> best_path;
vector<vector<int>> temp_path;

void dfs(int i,int j)
{
	//边界条件：（1）数组越界（2）“墙壁”或已走过
	if(i<0||i>=n||j<0||j>=m||maze[i][j]==1)
	{
		return;
	}
	maze[i][j]=1;//该位置已走过标记为1
	temp_path.push_back({i,j});//将该位置加入路径
	if(i==n-1&&j==m-1)//走到终点
	{
		//多条路径时best_path记录最小的temp_path
		//if(temp_path.size()<best_path.size()||best_path.empty())
		//{
		//    best_path=temp_path;
		//}
		//本题只有一条通路，所以当到达（n-1，m-1）时，让 best_path=temp_path即可
		best_path=temp_path;
	}
	dfs(i-1,j);//上
	dfs(i+1,j);//下
	dfs(i,j-1);//左
	dfs(i,j+1);//右
	maze[i][j]=0;//该结点走不通时，恢复原场面
	temp_path.pop_back();//从路径中删除该节点
}

int main()
{
	while(cin>>n>>m)//一次测试中多个案例依次输入
	{
		maze=vector<vector<int>>(n,vector<int>(m,0));//设置地图的大小并初始化
		//一次测试中多个案例依次输入时，每个案例执行完后将路径容器清空
		best_path.clear();
		temp_path.clear();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin>>maze[i][j];
			}
		}
		dfs(0,0);
		for(vector<vector<int>>::iterator 
			it=best_path.begin();it!=best_path.end();it++)
		{
			cout<<'('<<(*it)[0]<<','<<(*it)[1]<<')'<<endl;
		}
	}
	return 0;
}

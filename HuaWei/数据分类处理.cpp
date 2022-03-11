// 数据分类处理

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool IsContain(const int &Ri,const int &I)//判断是否含有字符串，string.find
{
	//把I变成字符串,C11新特性
	string str_I = to_string(I);
	string str_R = to_string(Ri);
	if(int(str_I.find(str_R)) != -1 )
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	int numI,temI,numR,temR;
	while(cin>>numI)
	{
		//读取并存储
		vector<int> vecI,vecR;//用于存储读进来的数据
		for(int i = 0;i<numI;i++)
		{
			cin>>temI;
			vecI.push_back(temI);
		}
		cin>>numR;
		for(int i = 0;i<numR;i++)
		{
			cin>>temR;
			vecR.push_back(temR);
		}
		
		//对R排序去重
		sort(vecR.begin(),vecR.end());//排序
		vecR.erase(unique(vecR.begin(),vecR.end()),vecR.end());//unique 不改变长度，需要搭配erase
		
		//循环I，R进行挑选
		vector<int>::iterator pr_I;//定义两个迭代器
		vector<int>::iterator pr_R;
		vector<vector<int>> sum_index;//用于存储所有挑选出来的索引
		vector<int> tem_index;//暂时存储对应Ri挑选出来的I索引
		vector<int> sum_Ri;//计算总的整数个数
		int sum_num = 0;
		for(pr_R = vecR.begin();pr_R != vecR.end();++pr_R)//循环R
		{
			//         cout<<*pr_R<<endl;
			int i = 0;
			for(pr_I = vecI.begin();pr_I != vecI.end();++pr_I)//循环I
			{
				if(IsContain(*pr_R,*pr_I))// !=0
				{
					tem_index.push_back(i);
				}
				i++;
			}
			if(tem_index.size() != 0)
			{
				sum_index.push_back(tem_index);
				sum_Ri.push_back(*pr_R);
				sum_num += tem_index.size()*2 +2;
				//             cout<<*pr_R<<" "<<tem_index.size()<<endl;
			}
			
			tem_index.clear();
		}
		
		//输出
		cout<<sum_num<<" ";
		for(int i=0;i<sum_index.size();i++)
		{
			cout<<sum_Ri[i]<<" "<<sum_index[i].size()<<" ";
			for(int j = 0;j<sum_index[i].size();j++)
			{
				cout<<sum_index[i][j]<<" "<<vecI.at(sum_index[i][j])<<" ";
			}
		}
		cout<<endl;
	}
	
	
	return 0;
}


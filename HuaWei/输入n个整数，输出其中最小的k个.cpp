// 输入n个整数，输出其中最小的k个

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <iterator>
//using namespace std;
//int main() {
//	int n, k;
//	while (cin >> n >> k) {
//		vector<int> vec(n);
//		for (int i = 0; i < n; ++i)
//			cin >> vec[i];
//		partial_sort(vec.begin(), vec.begin() + k, vec.end());
//		copy(vec.begin(), vec.begin() + k, ostream_iterator<int>(cout, " "));
//		cout << endl;
//	}
//}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	while(cin>>n>>k)
	{   //输入n和k
		vector<int> num;
		for(int i=0;i<n;i++)
		{   //逐个储存n个整数
			int temp;
			cin>>temp;
			num.push_back(temp);
		}
		sort(num.begin(),num.end());//对n个数进行升序排序
		for(int i=0;i<k-1;i++)
		{   //输出前k个数字
			cout<<num[i]<<' ';
		}
		cout<<num[k-1]<<endl;//最后一个数字输出后不要输出空格了
	}
	return 0;
}


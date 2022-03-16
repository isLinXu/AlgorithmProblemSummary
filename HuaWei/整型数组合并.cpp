// 整型数组合并

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n1;    //第一个数组的长度
	while (cin >> n1) { //输入第一个数组的长度
		vector<int> vec1;    //容器vec1存放第一个数组中的元素
		for (int i = 0; i < n1; i++) { //依次输入容器vec1中的n1个元素
			int tmp;
			cin >> tmp;
			vec1.push_back(tmp);
		}
		int n2;    //第二个数组的长度
		cin >> n2;  //输入第一个数组的长度
		vector<int> vec2;    //容器vec2存放第一个数组中的元素
		for (int i = 0; i < n2; i++) { //依次输入容器vec2中的n2个元素
			int tmp;
			cin >> tmp;
			vec2.push_back(tmp);
		}
		vector<int> vec;    //容器vec存放合并后的数组元素
		vec.insert(vec.end(), vec1.begin(), vec1.end());    //将第一个数组插入在容器vec后
		vec.insert(vec.end(), vec2.begin(), vec2.end());    //将第二个数组插入到容器vec后
		sort(vec.begin(), vec.end());   //将容器vec中的元素，按升序排序
		vec.erase(unique(vec.begin(), vec.end()), vec.end());    //去除容器vec中的重复元素
		for (int i = 0; i < vec.size(); i++) //输出容器vec中的元素
			cout << vec[i];
		cout << endl;
	}
	return 0;
}


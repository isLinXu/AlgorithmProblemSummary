// 从单向链表中删除指定值的节点

#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,head;
	cin>>n>>head;    //输入结点数和头结点的值
	forward_list<int> linklist;    //创建一个单向链表
	linklist.push_front(head);    //初始化头结点
	for(int i=1;i<n;i++) {
		int front,back;
		cin>>back>>front;
		auto it=find(linklist.begin(), linklist.end(), front);
		linklist.insert_after(it, back);    //逐个插入结点
	}
	int last;
	cin>>last;    //输入要删除的结点值
	linklist.remove(last);    //移除具有该值的节点
	for(auto it=linklist.begin();it!=linklist.end();it++) {
		cout<<*it<<" ";    //从头到尾输出链表的值
	}
	cout<<endl;
	return 0;
}

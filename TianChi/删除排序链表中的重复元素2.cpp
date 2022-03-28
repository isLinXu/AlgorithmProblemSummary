// 删除排序链表中的重复元素II

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if(nullptr == head || nullptr == head->next)
			return head;
		ListNode *tmpNode = new ListNode(0);
		tmpNode->next = head;
		ListNode *p = tmpNode;
		while(nullptr != p->next)
		{
			ListNode *q = p->next;
			while(nullptr != q->next && q->val == q->next->val)
			{
				q = q->next;
			}
			if(q == p->next)
			{
				p = p->next;
			}
			else
				p->next = q->next;
		}
		return tmpNode->next;
	}
};

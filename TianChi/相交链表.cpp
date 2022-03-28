// 相交链表

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
/**
 * Definition for singly-linked list.

 */
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if(headA == nullptr || headB == nullptr) return nullptr;
		ListNode* p = headA; ListNode* q = headB;
		while(p != q)
		{
			p = p==nullptr ? headB : p->next;
			q = q==nullptr ? headA : q->next;
		}
		return p;
	}
};

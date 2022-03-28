// 旋转链表

#include<iostream>
#include<vector>
#include<algorithm>

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
	ListNode* rotateRight(ListNode* head, int k) {
		if(head == nullptr || k <=0 || head->next == nullptr)
			return head;
		ListNode *cur = head;
		int list_len = 1;
		while(cur->next)
		{
			cur = cur->next;
			list_len++;
		}
		cur->next = head;    //连成环
		
		k = list_len - k % list_len;      
		cur = head;
		for(int i = 0; i < k - 1; i++)
			cur = cur -> next;
		
		head = cur -> next;     //断开
		cur -> next = nullptr;
		return head;
	}
};

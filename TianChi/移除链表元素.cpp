// 移除链表元素

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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode *dumynode = new ListNode(0);
		dumynode->next = head; 
		ListNode *fast = dumynode->next;
		ListNode *slow = dumynode;
		while(fast != nullptr){
			if(fast->val == val){
				slow->next = slow->next->next;
			}
			else {
				slow = slow->next;
			}
			fast = fast->next;    //重点在此处，一开始将这一句写到了上面的else语句中导致错误
			//因为该句无论何时都要执行，不管是if还是else
		}
		ListNode *ret = dumynode->next;
		delete dumynode;
		return ret;
	}
};



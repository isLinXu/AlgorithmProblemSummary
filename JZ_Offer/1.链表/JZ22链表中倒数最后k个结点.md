# JZ22链表中倒数最后k个结点

---

## 描述

输入一个长度为 n 的链表，设链表中的元素的值为 ai ，返回该链表中倒数第k个节点。

如果该链表长度小于k，请返回一个长度为 0 的链表。

数据范围：0 \leq n \leq 10^50≤*n*≤105，0 \leq a_i \leq 10^90≤*a**i*≤109，0 \leq k \leq 10^90≤*k*≤109

要求：空间复杂度 O(n)*O*(*n*)，时间复杂度 O(n)*O*(*n*)

进阶：空间复杂度 O(1)*O*(1)，时间复杂度 O(n)*O*(*n*)

例如输入{1,2,3,4,5},2时，对应的链表结构如下图所示：

![img](https://uploadfiles.nowcoder.com/images/20211105/423483716_1636084313645/5407F55227804F31F5C5D73558596F2C)

其中蓝色部分为该链表的最后2个结点，所以返回倒数第2个结点（也即结点值为4的结点）即可，系统会打印后面所有的节点来比较。

## 示例1

输入：

```
{1,2,3,4,5},2
```

返回值：

```
{4,5}
```

说明：

```
返回倒数第2个节点4，系统会打印后面所有的节点来比较。 
```

## 示例2

输入：

```
{2},8
```

返回值：

```
{}
```





## 题解

![图解说明](https://uploadfiles.nowcoder.com/images/20210918/852692412_1631932228114/2F32D17E3E7D42627FCD6C1C6D02F1AC)

```cpp
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        if (pHead == NULL)
            return NULL;
        ListNode* first = pHead;
        ListNode* second = pHead;
        //第一个指针先走k步
        while (k-- > 0) {
            if (first == NULL)
                return NULL;
            first = first->next;
        }
        //然后两个指针在同时前进
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }
        return second;
    }
};
```




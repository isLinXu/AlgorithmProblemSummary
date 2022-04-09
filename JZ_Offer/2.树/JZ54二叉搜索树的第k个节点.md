# JZ54二叉搜索树的第k个节点

---

## 描述

给定一棵结点数为n 二叉搜索树，请找出其中的第 k 小的TreeNode结点值。

1.返回第k小的节点值即可

2.不能查找的情况，如二叉树为空，则返回-1，或者k大于n等等，也返回-1

3.保证n个节点的值不一样

数据范围：$0 \le n \le1000$，$0 \le k \le1000$，树上每个结点的值满足$0 \le val \le 1000$。
进阶：空间复杂度 O(n)*O*(*n*)，时间复杂度 O(n)*O*(*n*)

如输入{5,3,7,2,4,6,8},3时，二叉树{5,3,7,2,4,6,8}如下图所示：

![img](https://uploadfiles.nowcoder.com/images/20211117/392807_1637120852509/F732B49BA33ECC72FF97FF7BDE2ACF69)

该二叉树所有节点按结点值升序排列后可得[2,3,4,5,6,7,8]，所以第3个结点的结点值为4，故返回对应结点值为4的结点即可。

## 示例1

输入：

```
{5,3,7,2,4,6,8},3
```

返回值：

```
4
```

## 示例2

输入：

```
{},1
```

返回值：

```
-1
```



## 题解

```cpp
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
    int KthNode(TreeNode* proot, int k) {
        // write code here
        //todo K > treeNodeNumber
        if(NULL == proot ){
            return -1;
        }
         
        //stack<TreeNode*> s = new stack<TreeNode*>();
        //stack<TreeNode*> s = new stack<TreeNode*>();
         
        //C++ sytle declaration;
        stack<TreeNode*> s;
        int i =0;
        while( !s.empty()  || proot !=NULL ){
            if( NULL!= proot){
                s.push(proot);
                proot = proot->left;
            }else{
                //已经左到底了
                proot = s.top();//get top
                s.pop();
                //仅仅下面这4行是定制行为
                i++;
                if( k== i)
                {return proot->val;
                }
                proot = proot->right;
            }
        }
        return -1;
    }
};
```



```cpp
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
    int count=0;
    vector<int> res;
    int KthNode(TreeNode* proot, int k) {
        // write code here
        if (proot==nullptr||k==0) return -1;
        ++count;
        KthNode(proot->left,  k);
        res.push_back(proot->val);
        //if(count==k) return proot->val;
        KthNode(proot->right, k);
        return res.size()>=k?res[k-1]:-1;
    }
};
```




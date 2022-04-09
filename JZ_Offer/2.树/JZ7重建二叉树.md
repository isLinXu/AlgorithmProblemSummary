# JZ7重建二叉树

---

## 描述



给定节点数为 n 的二叉树的前序遍历和中序遍历结果，请重建出该二叉树并返回它的头结点。

例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建出如下图所示。

![img](https://uploadfiles.nowcoder.com/images/20210717/557336_1626504921458/776B0E5E0FAD11A6F15004B29DA5E628)

提示:

1.vin.length == pre.length

2.pre 和 vin 均无重复元素

3.vin出现的元素均出现在 pre里

4.只需要返回根结点，系统会自动输出整颗树做答案对比

数据范围：n \le 2000*n*≤2000，节点的值 -10000 \le val \le 10000−10000≤*v**a**l*≤10000

要求：空间复杂度 O(n)*O*(*n*)，时间复杂度 O(n)*O*(*n*)

## 示例1

输入：

```
[1,2,4,7,3,5,6,8],[4,7,2,1,5,3,8,6]
```

返回值：

```
{1,2,3,4,#,5,6,#,7,#,#,8}
```

说明：

```
返回根节点，系统会输出整颗二叉树对比结果，重建结果如题面图示    
```

## 示例2

输入：

```
[1],[1]
```

返回值：

```
{1}
```

## 示例3

输入：

```
[1,2,3,4,5,6,7],[3,2,4,1,6,5,7]
```

返回值：

```
{1,2,5,3,4,6,7}
```



## 题解

解题思路：在二叉树的前序遍历序列中，第一个数字总是树的根节点的值。但是在树的中序遍历中，根节点的值在序列的中间，左子树的节点的值位于根节点的值的左边，而右子树的节点的值位于根节点的值的右边。因此根据先序遍历第一个值为根节点的值，扫描中序遍历，找到根节点的值的位置，位于根节点位置的左边的是左子树的节点，位于根节点位置右边的是右子树的节点。在扫描完之后，我们分别找到了左右子树先序和中序的遍历，我们就可以用同样的方法分别构建左子树和右子树，接下来的事情可以用递归来实现。

时间复杂度：O(n)，在遍历的过程都是O(n)的数量级；

空间复杂度：O(n)，递归使用的栈的最大深度不超过n;

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
       //当前序或者中序遍历为空的情况
        if(pre.empty() || vin.empty()){
            return nullptr;
        }
        //建立根节点
        int root = pre[0];
        TreeNode *tree = new TreeNode(root);
        int length = pre.size();
        //如果长度为1，直接返回根节点
        if(length == 1){
            return tree;
        }
        auto posi = find(vin.begin(), vin.end(), root);
        //如果在中序中没有检测到根节点
        if(posi == vin.end()){
            return nullptr;
        }
        //计算左右子树的长度
        int num_left = posi - vin.begin();
        int num_right = vin.end() - posi - 1;
        vector<int> left_pre;
        vector<int> left_vin;
        vector<int> right_pre;
        vector<int> right_vin;
        //找左右子树对应的先序和中序遍历
        left_pre.assign(pre.begin()+1, pre.begin()+1+num_left);
        right_pre.assign(pre.end()-num_right, pre.end());
        left_vin.assign(vin.begin(), vin.begin()+num_left);
        right_vin.assign(vin.end()-num_right, vin.end());
        //递归的建立左右子树
        tree->left = reConstructBinaryTree(left_pre, left_vin);
        tree->right = reConstructBinaryTree(right_pre, right_vin);
        return tree;
    }
};
```


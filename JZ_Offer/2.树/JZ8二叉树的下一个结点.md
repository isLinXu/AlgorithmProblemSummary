# JZ8二叉树的下一个节点

---

## 描述

给定一个二叉树其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的next指针。下图为一棵有9个节点的二叉树。树中从父节点指向子节点的指针用实线表示，从子节点指向父节点的用虚线表示

![img](https://uploadfiles.nowcoder.com/images/20210616/557336_1623844408327/D03B8D5BB902D4516BB92CB216E58EC4)

示例:

输入:{8,6,10,5,7,9,11},8

返回:9

解析:这个组装传入的子树根节点，其实就是整颗树，中序遍历{5,6,7,8,9,10,11}，根节点8的下一个节点就是9，应该返回{9,10,11}，后台只打印子树的下一个节点，所以只会打印9，如下图，其实都有指向左右孩子的指针，还有指向父节点的指针，下图没有画出来

![img](https://uploadfiles.nowcoder.com/images/20210616/557336_1623845692021/E647707AEF2A4AE2C40F0FCCB549B6A5)

数据范围：节点数满足 $1 \le n \le 50$，节点上的值满足 $1 \le val \le 100$。

要求：空间复杂度 O(1)，时间复杂度 O(n)

### 输入描述：

输入分为2段，第一段是整体的二叉树，第二段是给定二叉树节点的值，后台会将这2个参数组装为一个二叉树局部的子树传入到函数GetNext里面，用户得到的输入只有一个子树根节点

### 返回值描述：

返回传入的子树根节点的下一个节点，后台会打印输出这个节点

## 示例1

输入：

```
{8,6,10,5,7,9,11},8
```

返回值：

```
9
```

## 示例2

输入：

```
{8,6,10,5,7,9,11},6
```

返回值：

```
7
```

## 示例3

输入：

```
{1,2,#,#,3,#,4},4
```

返回值：

```
1
```

## 示例4

输入：

```
{5},5
```

返回值：

```
"null"
```

说明：

```
不存在，后台打印"null"  
```



## 题解

### 解法一：暴力解法

据题意，「某结点的下一个结点」定义为「中序遍历」后的下一个结点。因此暴力解法的步骤为：

1. 根据输入的结点以及next指针，先求得二叉树的根结点root；
2. 利用root进行二叉树的中序遍历，并定义数组储存中序遍历的结果；
3. 遍历该数组，得到「下一个结点」。

**注意：二叉树的中序遍历步骤为：先遍历左子树，再访问根结点，再遍历右子树。因此可通过递归较为方便地实现二叉树的中序遍历。**

代码如下：

```cpp
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    void inorder(TreeLinkNode* root, vector<TreeLinkNode*> &nodeVec) {
        if (!root)
            return;
        inorder(root->left, nodeVec); // 访问左子树
        nodeVec.push_back(root);  // 访问根结点
        inorder(root->right, nodeVec); // 访问右子树
    }
    
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (!pNode)
            return NULL;
        // 寻找根结点
        TreeLinkNode* root = pNode;
        while (root->next) {
            root = root->next;
        } // 完成while循环后，root即指向根结点
        vector<TreeLinkNode*> nodeVec;
        inorder(root, nodeVec); // 中序遍历
        for (int i = 0; i < nodeVec.size(); i ++) {
            if (nodeVec[i] == pNode && i + 1 < nodeVec.size())
                return nodeVec[i + 1]; // 下一个结点为所求结点
        }
        return NULL; // 若该结点无下一结点，返回NULL
    }
};
```

在进行中序遍历时，遍历到树的所有结点，因此复杂度为O(N)；在进行数组遍历时，复杂度为O(N)，故总时间复杂度为O(N)。

此解法定义数组存储中序遍历结果，故空间复杂度为O(N)。

### 解法二：利用中序遍历性质

解法一进行了一整个中序遍历，然而题目仅要求「下一个结点」，因此进行「整个」中序遍历是不必要的。

解法二的思路利用了**中序遍历的性质**。**中序遍历的步骤可表示为LTR，其中L代表左子树，T代表根结点，R代表右子树，即：先访问某结点的左子树，再访问该结点，再访问该结点的右子树。**

「某结点的下一个结点」仅有二种情况：

1. **若该结点存在右子树，则「下一个结点」为「该结点右子树的最左孩子」；**
2. **若该结点不存在右子树，则「下一个结点」为「该结点的第一个右父结点」。**

下面结合图例分别对上述二种情况进行阐述。

对于情况一，步骤如下：

1. 结点1存在右子树，则在进行中序遍历时，在访问结点1后，必将访问「该结点的右子树」，即以2为根结点的子树。
2. 在访问该子树时，会先访问结点2的左子树，即以3为根结点的子树。
3. 在访问该子树时，会先访问结点3的左子树，即结点4。

![图片说明](https://uploadfiles.nowcoder.com/images/20210708/786963925_1625724060570/F140AF0663C0B170415B65EBFAE71A93)

**以此类推，在通过中序遍历访问某结点的右子树时，会从其「右子树的最左孩子开始」。**

对于情况二，步骤如下：

1. 结点1不存在右子树，则其『下一个结点』，设为p，一定满足条件：**结点1位于p结点的左子树上**。因此，需要寻找其**第一个「右父亲」**；
2. 结点1不存在右父亲，故向上寻找，即寻到结点2；
3. 结点2不存在右父亲，故向上寻找，即寻到结点3；
4. 结点3的右父亲为结点4。结点4即为所求。可见，待求结点（结点1）位于结点4的左子树上。

![图片说明](https://uploadfiles.nowcoder.com/images/20210707/786963925_1625670091841/5C227EE72B156822ADEF2E105B15F4EE)

**故得出结论：若该结点不存在右子树，则「下一个结点」为「该结点的第一个右父结点」。**

```cpp
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        if (!pNode)
            return NULL;
        // 若该结点存在右子树
        if (pNode->right) {
            TreeLinkNode* rightChild = pNode->right;
            // 寻找右子树上的最左孩子
            while (rightChild->left)
                rightChild = rightChild->left;
            return rightChild;
        }
        // 若不存在右子树，寻找第一个右父亲
        while (pNode->next) {
            if (pNode->next->left == pNode)
                return pNode->next;
            pNode = pNode->next;
        }
        return NULL;
    }
};
```

该方法最坏情况如图所示，对于1号结点，需要不断向上寻找其第一个右父亲，故需要遍历整棵树，时间复杂度为O(N)；该方法不需要引入额外空间，空间复杂度为O(1)。

![图片说明](https://uploadfiles.nowcoder.com/images/20210707/786963925_1625670104009/9D2F41E303BB1D3F85B14CD5647799B4)
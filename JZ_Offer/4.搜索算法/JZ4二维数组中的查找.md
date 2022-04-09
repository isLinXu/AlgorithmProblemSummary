JZ4二维数组中的查找
===

---

## 描述

在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

[

[1,2,8,9],
[2,4,9,12],
[4,7,10,13],
[6,8,11,15]

]

给定 target = 7，返回 true。

给定 target = 3，返回 false。

数据范围：矩阵的长宽满足 $0 \le n,m \le 500$， 矩阵中的值满足 $0 \le val \le 10^9$。
进阶：空间复杂度 O(1)，时间复杂度 O(n+m)

## 示例1

输入：

```
7,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
```

返回值：

```
true
```

说明：

```
存在7，返回true   
```

## 示例2

输入：

```
1,[[2]]
```

返回值：

```
false
```

## 示例3

输入：

```
3,[[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
```

返回值：

```
false
```

说明：

```
不存在3，返回false 
```





## 题解

### **方法1: 暴力算法**

1. 分析：直接遍历一遍数组，即可判断目标target是否存在。
2. 复杂度分析
   时间复杂度：O(n^2)，因为最坏情况下，数组中的元素都需要遍历一次。
   空间复杂度：O(1)
3. 代码：

```cpp
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
     // 判断数组是否为空
     if (array.size() ==0 || array[0].size() ==0) return false;
     for (const auto& vec : array) {
         for (const int val : vec) {
             if (val == target)
                 return true;
         }
     }
     return false;
    }
};
```



### **方法2:二分查找**

1. 分析：对于方法一，此题有额外信息没有利用上，数组从左到右递增，从上到下递增。有序的数组很显然应该想到二分。那么应该如何二分呢？
   回想一下一维有序数组查找某个值二分的过程，如下图所示：

   ![图片说明](https://uploadfiles.nowcoder.com/images/20200324/2071677_1585037212780_9BF69A168D3C0C671EA488B8442C0F3B)

   假设目标tar在arr[1]处，那么我们的二分过程就是：
   1）设初始值：定义一个二分的开始下标为l，结束下标为r，如图所示：
   2）二分一半，中间位置为 mid = l + （（r - l) >> 1)， val>>1, 表示val右移一位相当于val／2，相当于 l+(r-l)/2,这样的写法是防止溢出。如果写成 mid = （l+r)/2; l+r可能会溢出。
   3) 如果 tar == arr[mid]，说明找到tar
   4）比较：如果tar > arr[mid], 说明tar在区间[mid+1, r]中，l = mid + 1
   5）如果tar < arr[mid]，说明tar在区间[l, mid-1]中, r = mid - 1

图中的例子就是步骤4）的情况，一次比较之后，如图所示，表示找到了tar。

![ ](https://uploadfiles.nowcoder.com/images/20200324/2071677_1585038045409_F5314ED2154068AAB9CCF2F52EC56CAC)

### 错误的想法：将一维扩展到二维。照葫芦画瓢，

![ ](https://uploadfiles.nowcoder.com/images/20200324/2071677_1585038747806_4488F9CD3E01F462C19C075D5EF6EA16)

假设我们设二分的开始下标为左上角坐标（0，0）为上图的l，结束下标为（4,5)为图中的r，二分一次下标为（2，2）图中的mid，假设tar > arr[mid]，
由一维二分可知，接下来应该找大于arr[mid]的位置，可是根据图可知，？处可能大于，也可能小于，所以就不能按照之前的规则进行二分了。所以说，这样是错的。

**总结一下**：错误的原因是：之前二分之后，无法确定下一次二分应该往哪边分，由此无法进行二分下去。如果我们找个位置，每次都能确定的往哪个部分二分，即可达到我们想要的结果。

### 新想法

假设arr数组，val，tar如下图所示：
如果我们把二分值定在右上角或者左下角，就可以进行二分。这里以右上角为例，左下角可自行分析：

![图片说明](https://uploadfiles.nowcoder.com/images/20200324/2071677_1585021381982_89033DB5EFA905C7F9FCCA6E59C9BB2C)

1）我么设初始值为右上角元素，arr[0][5] = val，目标tar = arr[3][1]
2）接下来进行二分操作：
3）如果val == target,直接返回
4）如果 tar > val, 说明target在更大的位置，val左边的元素显然都是 < val，间接 < tar，说明第 0 行都是无效的，所以val下移到arr[1][5]
5）如果 tar < val, 说明target在更小的位置，val下边的元素显然都是 > val，间接 > tar，说明第 5 列都是无效的，所以val左移到arr[0][4]
6）继续步骤2）

1. 复杂度分析
   时间复杂度：O(m+n) ，其中m为行数，n为列数，最坏情况下，需要遍历m+n次。
   空间复杂度：O(1)
2. 代码

```cpp
class Solution {
public:
 bool Find(int target, vector<vector<int> > array) {
     // 判断数组是否为空
     int m = array.size();
     if (m == 0) return false;
     int n = array[0].size();
     if (n == 0) return false;
     int r = 0, c = n-1; // 右上角元素
     while (r<m && c>=0) {
         if (target == array[r][c]) {
             return true;
         }
         else if (target > array[r][c]) {
             ++r;
         }
         else {
             --c;
         }
     }
     return false;
 }
};
```
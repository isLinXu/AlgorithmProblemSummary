# JZ40最小的K个数

---

## 描述

给定一个长度为 n 的可能有重复值的数组，找出其中不去重的最小的 k 个数。例如数组元素是4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4(任意顺序皆可)。

数据范围：$0\le k,n \le 10000$，数组中每个数的大小$0 \le val \le 1000$。

要求：空间复杂度 O(n)，时间复杂度 O(nlogn)

## 示例1

输入：

```
[4,5,1,6,2,7,3,8],4 
```

返回值：

```
[1,2,3,4]
```

说明：

```
返回最小的4个数即可，返回[1,3,2,4]也可以        
```

## 示例2

输入：

```
[1],0
```

返回值：

```
[]
```

## 示例3

输入：

```
[0,1,2,1,2],3
```

返回值：

```
[0,1,1]
```





## 题解

题目抽象：求给定数组的topK小问题。

### 方法一：排序

直接排序，然后去前k小数据。

```cpp
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        if (k==0 || k>input.size()) return ret;
        sort(input.begin(), input.end());
        return vector<int>({input.begin(), input.begin()+k});   
    }
};
```

时间复杂度：O(nlongn)
空间复杂度：O(1)



### 方法二：堆排序

建立一个容量为k的大根堆的优先队列。遍历一遍元素，如果队列大小<k,就直接入队，否则，让当前元素与队顶元素相比，如果队顶元素大，则出队，将当前元素入队

```cpp
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        if (k==0 || k > input.size()) return ret;
        priority_queue<int, vector<int>> pq;
        for (const int val : input) {
            if (pq.size() < k) {
                pq.push(val);
            }
            else {
                if (val < pq.top()) {
                    pq.pop();
                    pq.push(val);
                }

            }
        }

        while (!pq.empty()) {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};
```




# JZ30包含min函数的栈

---

## 描述

定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数，输入操作时保证 pop、top 和 min 函数操作时，栈中一定有元素。

此栈包含的方法有：

push(value):将value压入栈中

pop():弹出栈顶元素

top():获取栈顶元素

min():获取栈中最小元素

数据范围：操作数量满足 0 \le n \le 300 \0≤*n*≤300 ，输入的元素满足 |val| \le 10000 \∣*v**a**l*∣≤10000 
进阶：栈的各个操作的时间复杂度是 O(1)\*O*(1) ，空间复杂度是 O(n)\*O*(*n*) 

示例:

输入:  ["PSH-1","PSH2","MIN","TOP","POP","PSH1","TOP","MIN"]

输出:  -1,2,1,-1

解析:

"PSH-1"表示将-1压入栈中，栈中元素为-1

"PSH2"表示将2压入栈中，栈中元素为2，-1

“MIN”表示获取此时栈中最小元素==>返回-1

"TOP"表示获取栈顶元素==>返回2

"POP"表示弹出栈顶元素，弹出2，栈中元素为-1

"PSH1"表示将1压入栈中，栈中元素为1，-1

"TOP"表示获取栈顶元素==>返回1

“MIN”表示获取此时栈中最小元素==>返回-1

## 示例1

输入：

```
 ["PSH-1","PSH2","MIN","TOP","POP","PSH1","TOP","MIN"]
```

返回值：

```
-1,2,1,-1
```





## 题解

题目抽象：要求实现一个O(1)时间复杂度的返回最小值的栈。正常情况下，栈的push，pop操作都为O(1),
但是返回最小值，需要遍历整个栈，时间复杂度为O(n)，所以这里需要空间换时间的思想。

### 方法：使用辅助栈

首先需要一个正常栈normal,用于栈的正常操作，然后需要一个辅助栈minval，专门用于获取最小值，具体操作如下

- push操作就如图片上操作。
- pop操作直接对应弹出就好了。
- top操作就返回normal的栈顶
- min操作就返回minval的栈顶

因此，代码如下：

```cpp
class Solution {
public:
    stack<int> normal, minval;
    void push(int value) {
        normal.push(value);
        if (minval.empty()) {
            minval.push(value);
        }
        else {
            if (value <= minval.top()) {
                minval.push(value);
            }
            else {
                minval.push(minval.top());
            }
        }
    }
    void pop() {
        normal.pop();
        minval.pop();
    }
    int top() {
        return normal.top();
    }
    int min() {
        return minval.top();
    }
};
```

时间复杂度：O(1)
空间复杂度：O(n), 开辟了一个辅助栈。
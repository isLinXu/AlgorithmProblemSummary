# JZ9用两个栈实现队列

---

## 描述

用两个栈来实现一个队列，使用n个元素来完成 n 次在队列尾部插入整数(push)和n次在队列头部删除整数(pop)的功能。 队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素。

数据范围： n$\le$1000

要求：存储n个元素的空间复杂度为 O(n)*O*(*n*) ，插入与删除的时间复杂度都是 O(1)*O*(1)

## 示例1

输入：

```
["PSH1","PSH2","POP","POP"]
```

返回值：

```
1,2
```

说明：

```
"PSH1":代表将1插入队列尾部
"PSH2":代表将2插入队列尾部
"POP“:代表删除一个元素，先进先出=>返回1
"POP“:代表删除一个元素，先进先出=>返回2    
```

## 示例2

输入：

```
["PSH2","POP","PSH1","POP"]
```

返回值：

```
2,1
```





## 题解

## 方法：模拟

如果我知道队列是FIFO，栈是FILO，但是这道题我还是不知道怎么写怎么办？
对于这种感觉不难，但是又不会写的，方法就是模拟。
比如有如下操作：(pop操作确保栈中有元素）

```cpp
push(1);push(2);pop(3);push(4);
```

![图片说明](https://uploadfiles.nowcoder.com/images/20200328/284295_1585400497769_0C4ABEBEC33645F04FC3BE80560A19CA)

根据队列的特性，只能pop(1),pop(2),pop之后的结果

![图片说明](https://uploadfiles.nowcoder.com/images/20200328/284295_1585400552969_2BD71B6015DA622EC901AE9E8EF11B09)

上述是队列的操作。
当push的时候，我们必须要用一个stack来存，假设用stack1来存。

![图片说明](https://uploadfiles.nowcoder.com/images/20200328/284295_1585400791591_E15AD689EC5617B74FCBAB036DB5F203)

那么push操作解决了。那么pop操作怎么办呢？
如果pop(1)，但是此时在stack1的栈底，如果要pop，必须再将stack1中的数据push到stack2中，然后在pop，如图

![ ](https://uploadfiles.nowcoder.com/images/20200328/284295_1585401602901_0711311756A500BE23FE8ED82FCA5FF3)

这样直接弹出stack2的栈顶就可以了。
如果要继续pop，那就继续弹出stack2就可以了

------

但是现在总感觉哪里还是有点问题。如果是这样就继续测试几个例子。
如果push(5)，

![图片说明](https://uploadfiles.nowcoder.com/images/20200328/284295_1585401399745_2DA9470B0EA9FAE77932FA8176C79036)

**所以最后总结一下**：push操作就直接往stack1中push， pop操作需要分类一下：如果stack2为空，那么需要将stack1中的数据转移到stack2中，然后在对stack2进行pop，如果stack2不为空，直接pop就ok。

```cpp
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
```

复杂度分析

时间复杂度：push操作为O(1),pop操作为O(1)
空间复杂度：需要stack来存，O(n)






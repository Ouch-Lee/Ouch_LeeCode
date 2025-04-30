# List

链表的核心为val和next，其中val是当前链表储存的值，而next是一个List类型的指针，指向下一个链表节点的地址。链表与之前数组不同的点在于，数组的地址是连续的，而链表的相邻元素地址不连续，而是用一个next的指针，指向下一个地址的位置，list的实现也非常简单，

```cpp
typedef Struct 
{
	int val;
	ListNode * next;
    ListNode(int x) : val(x), next(nullptr);
} ListNode;
```



## 链表类型

* 单向链表：上面说的就是
* 双向链表：除了next，还有一个last指向上一个
* 环形链表：最后一个节点指向第一个节点的地址
* 



## 链表删除元素

由于链表的地址不连续性，所以链表可以做到数组做不到的删除元素操作，原理如下：找到对应的元素tarNode，将tarNode的上一个节点指向next；因此需要保存上一个节点信息，同时要避免空指针，也即next是空的情况





### 构建自己的List


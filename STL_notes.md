

所有的容器无非是下面几种应用

* 创建

* 插入 :  有的容器叫insert，有的叫push，有的叫push_back，让AI总结一下

* 删除

* 查找

* 是否为空

  

## set

存储了一组**唯一**的元素，并按照**一定的顺序**进行排序。提供了高效的元素查找、插入和删除操作

* 声明 set<type> mySet;

* insert : 不同于vector，set会自动按照大小排序
* erase(a)：直接删除目标元素，相当于给你执行了一遍find，然后再删掉
* find(): 寻找目标元素，原理和大多数容器一样，通过迭代器，看会不会迭代到end
* size(): 这个每个容器原理基本都一样，返回元素个数
* empty：查看set是否为空

所以当需要构建唯一且自动排序的结构时可以使用set，相当于元素不重复，且自动排序的vector

一些题目：

* [**217. 存在重复元素**](https://leetcode.cn/problems/contains-duplicate/submissions/632816012/)
* [**219. 存在重复元素 II**](https://leetcode.cn/problems/contains-duplicate-ii/submissions/633097692/)
* [**202. 快乐数**](https://leetcode.cn/problems/happy-number/description/)



## map

map和set一样是在学哈希表的时候接触的的，比set多了一个键值对（一种关联容器，用于存储键值对），`map` 容器中的元素是按照键的**顺序**自动排序的，这使得它非常适合需要快速**查找**和有序数据的场景。

特性：

- **键值对**：`map` 存储的是键值对，其中每个键都是唯一的。
- **排序**：`map` 中的元素按照键的顺序自动排序，通常是升序。
- **唯一性**：每个键在 `map` 中只能出现一次。
- **双向迭代器**：`map` 提供了双向迭代器，可以向前和向后遍历元素。

API：

* 声明： std::map<key_type, value_type> myMap;

* **插入**：不用于set的insert用法，map是直接对键进行赋值： map[key] = val; 但是似乎也能用insert的方法：如map.insert(pair<int, int>(nums[i], i)); 

* 删除：erase(key);

* 清除：clear();

* **迭代**：

  ```
  for (map<key, val>::iterator it = myMap.begin(); it != myMap.end(); it++)
  {
  
  }
  ```

* size 

例题

* [**1. 两数之和**](https://leetcode.cn/problems/two-sum/)

## queue

队列算是我笔记熟悉的数据结构了，因为我脑子里面有一个可视化的FIFO模型，这个方法可以拓展到其它结构；队列主

* push()
* pop()
* front() / back()



### deque







## stack




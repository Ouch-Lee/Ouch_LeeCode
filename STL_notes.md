# STL基础

## Container

STL 中的容器可以分为三类：

1、序列容器：存储元素的序列，允许双向遍历。

* std::vector：动态数组，支持快速随机访问。
* std::deque：双端队列，支持快速插入和删除。
* std::list：链表，支持快速插入和删除，但不支持随机访问。

2、 关联容器：存储键值对，每个元素都有一个键（key）和一个值（value），并且通过键来组织元素。

* std::set：集合，不允许重复元素。
* std::multiset：多重集合，允许多个元素具有相同的键。
* std::map：映射，每个键映射到一个值。
* std::multimap：多重映射，存储了键值对（pair），其中键是唯一的，但值可以重复，允许一个键映射到多个值。

3、无序容器（C++11 引入）：哈希表，支持**快速的查找、插入和删除**。

- std::unordered_set：无序集合。
- std::unordered_multiset：无序多重集合。
- std::unordered_map：无序映射。
- std::unordered_multimap：无序多重映射。
=======


所有的容器无非是下面几种应用

* 创建

* 插入 :  有的容器叫insert，有的叫push，有的叫push_back，让AI总结一下

* 删除

* 查找

* 是否为空

  

## set

存储了一组**唯一**的元素，并按照**一定的顺序**进行排序。提供了高效的元素查找、插入和删除操作



* insert : 不同于vector，set会自动按照大小排序
* erase(a)：直接删除目标元素，相当于给你执行了一遍find，然后再删掉
* find(): 寻找目标元素，原理和大多数容器一样，通过迭代器，看会不会迭代到end
* size(): 这个每个容器原理基本都一样，返回元素个数
* empty：查看set是否为空

所以当需要构建唯一且自动排序的结构时可以使用set，相当于元素不重复，且自动排序的vector

一些题目：

* [**217. 存在重复元素**](https://leetcode.cn/problems/contains-duplicate/submissions/632816012/)
* 

## queue

队列算是我笔记熟悉的数据结构了，因为我脑子里面有一个可视化的FIFO模型，这个方法可以拓展到其它结构；队列主

* push()
* pop()
* front() / back()



### deque







## map



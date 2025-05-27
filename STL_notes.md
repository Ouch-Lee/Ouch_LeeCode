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
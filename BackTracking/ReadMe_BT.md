# 回溯算法

回溯算法是一种系统地搜索所有可能解的方法，通常用于解决组合、排列、分割等问题【通常只能使用for暴力遍历的问题】。它通过逐步构建候选解，一旦发现当前路径不符合条件或不可能有解，就立即回溯，尝试其他可能性。

回溯和递归的逻辑有点像，目前看来回溯里面包含了递归。回溯也可以做三部曲：

* 确定返回值和传参

* 回溯停止逻辑

  ```
  if (终止条件) {
          存放结果;
          return;
      }
  ```

* 单层回溯逻辑：

  ```
  for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
      处理节点;
      backtracking(路径，选择列表); // 递归
      回溯，撤销处理结果
  }
  ```



### 组合总和3



* 首先确定终止条件，就是path长度为3且和为n
* 返回参数，理论上来说用void就行，传参，n和k



### 电话号码组合

重点有两个：

* 找到映射关系，最先想到的是使用map，将数字映射到对应的string，官方给出了一个简单的方法，直接构建一个string的数组，下标可以对应num
* 什么

三部曲

* 传参和返回

* 终止条件：明显终止条件就是path的长度等于给定数字的个数，也即 path.size() == n; 但是官方没有直接使用path.size() ，而是用一个参数index，表示path已经放了几个数；这样做的好处是，能够获取当前对应的按键，通过映射得到对应的string，作为单层回溯的基础

* 单层回溯逻辑：

  每一层对应一个按键数字，每个数字有3/4个字母，需要把这些字母都遍历一遍



### 组合总和

关于回溯和递归的return，我感觉我还是没有完全明白，以递归来说，return了，代码就会回到进入这一层递归的位置，然后进行执行上一层没有执行完的代码。那回溯应该也一样，如果return会回到上一层并继续

* 仍然可以采用两个全局变量，所以返回类型void就好了，传参需要给的两个参数（candidate和target，以及单层遍历开始的位置start）
* 终止条件：path之和等于或大于target，等于就把path加进result然后return，大于就直接结束（关于这个结束，可以做一些剪枝优化，就是把大于最后一个值的数都跳过<但是怎么实现呢>）
* 单层递归：单层就是把所有candidate里面的数都遍历一遍，因为可以重复使用，所以层数并不像之前那样固定，而是根据终止条件结束



### 数组总和2

这题不一样的地方在于，有重复的数组，但是不可以一直拿一样的，

* 返回类型仍然是void，传参除了两个默认的，还需要start用于往下回溯，以及sum用来回溯时判断是否停止；为了避免重复的数字在同一层内再来一遍，还需要添加一个use数组，判断这个数字有没有被用过

* 终止条件：等于就return

* 单层递归：

  如果没有剪枝和优化操作，其实可以和之前一样，因此具体要做的两件事是：

  * 第一，如果当前的sum+candidate[i] > target了，那么就直接break，后面都不要管
  * 第二，如果当前的值[i] 等于上一个，那么可以直接跳过


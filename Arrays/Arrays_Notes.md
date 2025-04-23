



## 长度最小的子数组

很经典的双指针问题，一个指针从0移动到n-1，另外一个指针随i移动，当局部和大于sum时，记录tmpSum，并随i移动到下一步；

上面说的是暴力法【我是个傻逼】

真正的窗口法只用到了一个for循环，两个指针，当tmpSum没有到target之前，就一直 tmpSum累加，同时j++；当tmpSum大于tar时，就要调整i的位置了，一直i++同时把num[i]从tmpSum中减掉；



## [螺旋矩阵 II](https://leetcode.cn/problems/spiral-matrix-ii/)

我的思路：同样使用双指针 [left ，right) ,初始时，left = 0， right = n-1；每遍历完一圈，left++, right--;

循环条件：left < right；循环的终止有两种情况，当n为偶数时，循环结束于 left = right + 1，此时矩阵被填满了；当为奇数循环结束于 left = right；这个时候最终中间的还没填满，所有要单独处理


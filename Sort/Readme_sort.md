

## quickSort

快速排序的原理：找个一个pivot作为参考，把当前对象（数组）分成大于pivot和小于pivot的两部分，然后递归，继续对两个部分采用同样的原理进行排序，最终合起来就是排序好的序列

* 选择pivot，随便选一个都可以，通常是第一个 arr[0]

* 用两个指针left, right 把整个arr过一遍，具体来说，先把右边比pivot小的数移到left指针的位置；然后将左边比pivot大的数换到右边right的位置，对于出现在正确位置的数，不用管直接跳过（移动指针）

  ```C++
  while (L < R)
  {
  	while (L < R && arr[R] >= pivot)
      {
          R--;
      }
      arr[L] = arr[R]; // 出现右边比pivot小，移到左边去
      while ( arr[L] <= pivot)
      {
          L++;
      }
      arr[R] = arr[L];// 出现左边比pivot大，移到右边去
  }
  arr[L] = pivot;
  return L; // 返回此次分割的断开index
  ```

* 将上述过程进行递归即可以完成快速排序

  ```
  void QuickSort(int arr[], int left, int right)
  {
  	if (low < high) {
  	int pivot = Partial(arr, left, right);
  	QuciSort(arr, left, pivot - 1);
  	QucikSort(arr, pivot+1, right);
  	}
  }
  ```

  
# 调整数组顺序使奇数位于偶数前面
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，**并保证奇数和奇数，偶数和偶数之间的相对位置不变**。

## 分析
### 方法1：
如果遇到偶数，直接让偶数后面的数向前覆盖，然后插入最后

### 方法2：
双指针方法：1个在头，1个在尾，头尾相遇直接退出
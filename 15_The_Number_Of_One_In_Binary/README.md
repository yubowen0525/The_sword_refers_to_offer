# 题目描述

输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

## 分析
位操作
- 与 `&`  可以用来清0（& 0x0），或者提出来特定位(& 0x80)
- 或 `|`  用来置1(| 0xFF) , 或者用来置特殊位(| 0x80)
- 异或 `^`   可以用来swap，而不需要特殊空间
- `<<` 左移   x2
- `>>` 右移   /2  **但如果是有符号数，正数最高位补0，负数最高位补0**

### 方法1：
利用标置位从低位到高位检查1，是1就+1

循环次数：固定32次（unsigned int 的位数来决定）

### 方法2：
利用n & n-1  来清除1的个数，适用于正负数

循环次数：有多少个1，循环多少次
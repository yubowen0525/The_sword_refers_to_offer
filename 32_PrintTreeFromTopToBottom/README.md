# 从上往下打印二叉树 题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

## 分析
层次遍历，利用队列


# 分行从上到下打印二叉树
从上往下打印出二叉树的每个节点，同层节点从左至右打印。每一层打印一行

## 分析
加入两个标记，一个记录当前层需要打印的次数，一个记录下一层需要打印的次数

# 按之字形顺序打印二叉树 题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

## 分析
模拟发现，第一行的元素，需要加入堆栈中，先左后右，第二行的元素，需要加入第二个堆栈中，且加入顺序是 先右后左
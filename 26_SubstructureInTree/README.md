# 树的子结构 题目描述 
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）


## 分析
A,B两棵树，假设B是子树，那么A可以采用一种遍历方式，比如说先序遍历，若A的根节点，B的根节点相等，
那么进入下一个函数逻辑（子树是否也相等？）

需要注意的是flag标记的变化
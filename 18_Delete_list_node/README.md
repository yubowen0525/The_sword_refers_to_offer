# 题目1：在O(1) 时间内删除链表节点
给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内删除该节点。链表节点与函数的定义如下
```c
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
```

## 分析
正常情况下，需要知道删除节点的前一个节点，才可以删除

可以利用，下一个节点，将下一个节点的值拷贝到当前节点，然后在删除下一个节点


- 节点不是尾节点，下一个节点替换当前节点，删除下一个节点，O(1)
- 尾节点，需要找到当前节点的上一个节点删除，O(n)
- 头节点，删除下一个节点，头节点需要更改地址
- 只有一个节点，删除节点置空


# 题目二：删除链表中重复的节点
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

## 分析
- 
package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func NewList(vals []int) *ListNode {
	if len(vals) == 0 {
		return nil
	}

	head := new(ListNode)
	prev_node := head
	head.Val = vals[0]

	for i := 1; i < len(vals); i++ {
		node := new(ListNode)
		node.Val = vals[i]
		prev_node.Next = node
		prev_node = node
	}

	return head
}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * @param head ListNode类
 * @return int整型一维数组
 */
func PrintListFromTailToHead(head *ListNode) []int {
	// write code here
	if head == nil {
		return []int{}
	}

	target := make([]int, 10000)
	i := 9999

	for head != nil {
		target[i] = head.Val
		head = head.Next
		i--
	}

	return target[i+1:]
}

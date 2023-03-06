package main

import (
	"testing"
)

func TestRestore(t *testing.T) {

	input_parameter1_case := map[string][]int{
		"case1": {1, 2, 4, 7, 3, 5, 6, 8},
	}

	input_parameter2_case := map[string][]int{
		"case1": {4, 7, 2, 1, 5, 3, 8, 6},
	}

	output_case := map[string][]int{
		"case1": {1, 2, 3, 4, 5, 6, 7, 8},
	}

	for caseName, inputCase := range input_parameter1_case {
		t.Run(caseName, func(t *testing.T) {
			// intput := NewList(inputCase)
			output := ReConstructBinaryTree(inputCase, input_parameter2_case[caseName])
			if !IsEqualList(PrintTreeOut(output), output_case[caseName]) {
				t.Errorf("output:%+v != case output %+v", output, output_case[caseName])
			}
		})
	}
}

func PrintTree(output *TreeNode) []int {

	node := output
	target := make([]int, 0, 10)
	target = append(target, node.Val)

	index := 0
	nodeQueue := make([]*TreeNode, 0, 10)
	nodeQueue = append(nodeQueue, node)
	for index < len(nodeQueue) {
		if node.Left != nil {
			target = append(target, node.Left.Val)
			nodeQueue = append(nodeQueue, node.Left)
		}

		if node.Right != nil {
			target = append(target, node.Right.Val)
			nodeQueue = append(nodeQueue, node.Right)
		}

		index++
		if index < len(nodeQueue) {
			node = nodeQueue[index]
		}
	}

	return target
}

func PrintTreePre(output *TreeNode) (target []int) {
	stack := make([]*TreeNode, 0, 10)
	node := output
	for node != nil || len(stack) > 0 {
		if node != nil {
			target = append(target, node.Val)
			stack = append(stack, node)
			node = node.Left
		} else {
			node = stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			node = node.Right
		}
	}
	return
}

func PrintTreeIn(output *TreeNode) (target []int) {
	stack := make([]*TreeNode, 0, 10)
	preVisted := new(TreeNode)
	node := output
	for node != nil || len(stack) > 0 {
		for node != nil {
			stack = append(stack, node)
			node = node.Left
		}

		top := stack[len(stack)-1]

		if top.Left == nil && top.Right == nil || top.Right == nil && preVisted == top.Left || preVisted == top.Right {
			target = append(target, top.Val)
			preVisted = top
			stack = stack[:len(stack)-1]

		} else {
			node = top.Right
		}
	}
	return
}

func PrintTreeOut(output *TreeNode) (target []int) {
	stack := make([]*TreeNode, 0, 10)
	var preVisted *TreeNode
	node := output
	for node != nil || len(stack) > 0 {
		for node != nil {
			stack = append(stack, node)
			node = node.Left
		}

		top := stack[len(stack)-1]

		// 没有孩子的节点 ｜ 没有右孩子且左是上一个 ｜ 没有左孩子且右是上一个
		if (top.Left == nil && top.Right == nil) || (top.Right == nil && preVisted == top.Left) || preVisted == top.Right {
			target = append(target, top.Val)
			preVisted = top
			stack = stack[:len(stack)-1]

		} else {
			node = top.Right
		}
	}
	return
}

func IsEqualList(list1, list2 []int) bool {

	if len(list1) != len(list2) {
		return false
	}

	for i := 0; i < len(list1); i++ {
		if list1[i] != list2[i] {
			return false
		}
	}

	return true
}

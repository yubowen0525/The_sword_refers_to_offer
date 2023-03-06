package main

import "errors"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * @param pre int整型一维数组
 * @param vin int整型一维数组
 * @return TreeNode类
 */

func ReConstructBinaryTree(pre []int, vin []int) *TreeNode {
	// write code here
	root, err := coreReConstruct(pre, vin)
	if err != nil {
		return nil
	}

	return root
}

func coreReConstruct(pre []int, vin []int) (node *TreeNode, err error) {
	rootValue := pre[0]
	root := new(TreeNode)
	root.Val = rootValue

	if len(pre) == 0 {
		if len(vin) == 0 {
			return root, nil
		}
	}

	rootIndexInVin := 0
	for rootIndexInVin < len(vin) && rootValue != vin[rootIndexInVin] {
		rootIndexInVin++
	}

	if rootIndexInVin == len(vin)-1 && rootValue != vin[rootIndexInVin] {
		return nil, errors.New("input invalid")
	}

	leftLength := rootIndexInVin
	rightLength := len(vin) - rootIndexInVin - 1

	// left
	if leftLength > 0 {
		root.Left, err = coreReConstruct(pre[1:1+leftLength], vin[:leftLength])
		if err != nil {
			return nil, err
		}
	}

	// right
	if rightLength > 0 {
		root.Right, err = coreReConstruct(pre[1+leftLength:], vin[1+leftLength:])
		if err != nil {
			return nil, err
		}
	}

	return root, nil
}

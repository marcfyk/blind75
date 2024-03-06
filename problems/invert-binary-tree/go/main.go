package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	stack := []*TreeNode{root}
	for len(stack) > 0 {
		n := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		tmp := n.Left
		n.Left = n.Right
		n.Right = tmp
		if n.Left != nil {
			stack = append(stack, n.Left)
		}
		if n.Right != nil {
			stack = append(stack, n.Right)
		}
	}
	return root
}

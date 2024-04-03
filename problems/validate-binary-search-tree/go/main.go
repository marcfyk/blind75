package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isValidBST(root *TreeNode) bool {
	if root == nil {
		return false
	}
	n := root
	stack := make([]*TreeNode, 0)
	nodes := make([]*TreeNode, 0)
	for n != nil || len(stack) > 0 {
		for n != nil {
			stack = append(stack, n)
			n = n.Left
		}
		n = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		if len(nodes) > 0 && nodes[len(nodes)-1].Val >= n.Val {
			return false
		}
		nodes = append(nodes, n)
		n = n.Right
	}
	return true
}

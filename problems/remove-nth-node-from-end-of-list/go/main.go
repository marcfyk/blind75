package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head == nil {
		return nil
	}
	size := getListSize(head)
	m := size - n
	if m == 0 {
		return head.Next
	}
	node := head
	for range m - 1 {
		node = node.Next
	}
	if node != nil && node.Next != nil {
		node.Next = node.Next.Next
	}
	return head
}

func getListSize(head *ListNode) int {
	size := 0
	node := head
	for node != nil {
		size++
		node = node.Next
	}
	return size
}

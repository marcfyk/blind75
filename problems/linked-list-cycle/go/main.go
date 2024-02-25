package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return false
	}
	slow := head
	fast := head
	for fast != nil {
		if slow != nil {
			slow = slow.Next
		}
		if fast.Next != nil {
			fast = fast.Next.Next
		} else {
			fast = fast.Next
		}
		if slow == fast {
			return true
		}
	}
	return false
}

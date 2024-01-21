from typing import Optional


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next: Optional[ListNode] = None


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if head == None:
            return False
        slow = head
        fast = head.next
        while fast != None:
            if slow == fast:
                return True
            slow = slow.next if slow != None else slow
            fast = fast.next.next if fast.next != None else fast.next
        return False

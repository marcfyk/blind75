from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head == None:
            return None
        size = getListSize(head)
        m = size - n
        if m == 0:
            return head.next
        node = head
        for _ in range(m - 1):
            if node != None:
                node = node.next
        if node != None and node.next != None:
            node.next = node.next.next
        return head


def getListSize(head: Optional[ListNode]) -> int:
    size = 0
    node = head
    while node != None:
        size += 1
        node = node.next
    return size

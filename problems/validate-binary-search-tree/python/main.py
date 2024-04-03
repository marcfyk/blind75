from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if root == None:
            return True
        n = root
        nodes = []
        stack = []
        while n != None or stack:
            while n != None:
                stack.append(n)
                n = n.left
            n = stack.pop()
            if nodes and nodes[-1].val >= n.val:
                return False
            nodes.append(n)
            n = n.right
        return True

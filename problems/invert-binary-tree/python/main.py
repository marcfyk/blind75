from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root == None:
            return None
        stack = [root]
        while len(stack) > 0:
            n = stack.pop()
            n.left, n.right = n.right, n.left
            if n.left != None:
                stack.append(n.left)
            if n.right != None:
                stack.append(n.right)
        return root

# README

## Objective

Given the $root$ of a binary tree, return if it is a valid binary search tree (BST).

> A binary tree is a valid BST if the following conditions are upheld:
- $\forall m \in \text{left subtree of n} \imples m.val \lt n.val$
- $\forall m \in \text{right subtree of n} \imples m.val \gt n.val$
- left and right subtrees of $n$ must be a valid BST

## Solution

Time complexity: $O(n)$, where n is the number of nodes in the binary tree.

Space complexity: $O(n)$, where n is the number of nodes in the binary tree.

Auxiliary space: $O(n)$, where n is the number of nodes in the binary tree.
 
We can perform an inorder traversal on the tree, and validate that every node
is sorted by value.

> A BST forms a sorted array of values if we flatten it vertically, therefore,
the inorder traversal will visit each node in such a manner that is identical
to the flattened sorted nodes.

Inorder traversal is an $O(n)$ operation as it visits all nodes in the tree
and auxiliary space is $O(n)$ as we need to maintain a stack and the sequence
of nodes to keep track of what we have visited.

Alternatively, you can also use recursively traverse the BST in BFS order.
At each step of traversal, we maintain two values $low$ and $high$, which
are initially set to the lower and upper bound of possible values.

At each step of traversal at a node, $n$, we verify the 3 conditions:
- $low \lte n.val \lte high$
- n.left is also valid where $min = min, max = n.val - 1$
- n.right is also valid where $min = n.val + 1, max = max$

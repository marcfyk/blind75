# README

## Objective

Given the root of a binary tree, $root$, invert the tree and return $root$.

>Inverting the tree means swapping each node's left and right child nodes.

## Solution

Time complexity: $O(\log n)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$

> $n$ = number of nodes in the tree.


We can traverse the tree from $root$ through DFS/BFS, and swap the left and right child nodes
at each traversal step in place.

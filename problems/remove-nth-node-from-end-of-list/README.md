# README

## Objective

Given the $head$ of a linked list,
remove the $n^th$ node from the end of the list and return the head of the linked list.

> $n$ is 1 based index.

## Solution

Time complexity: $O(n)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$


Since the linked list is a singly linked list, we will need to traverse the list twice.
The first traversal is to find the $size$ of the list, while the second is to find $m = size - n$,
which is the equivalent offset from the start of the list.

> $m$ is a 1 based index, just like $n$.

On our second traversal, we just assign the $(m - 1)^th$ node's next node to be the $(m + 1)^th$ node (which may just be $NULL$).
There is an exception if $m = 0$, whereby we just return $head.next$.

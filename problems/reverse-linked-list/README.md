# README

## Objective

Given the head of a singly linked list, reverse the list and return it.

## Solution

Time complexity: $O(n)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$

We can reverse it by iterating through each node of the linked list,
while maintaining two pointers, $prev$ and $curr$.

$prev$ will be initially set to $NULL$ / $NONE$, while $curr$ will
initially be set to the head of the linked list.

As we iterate through each node, we set $curr.next = prev$ before updating
$prev$ and $curr$ to point to their respective next nodes from the original
ordering.

At the end of our iteration, $prev$ will be pointing to the new head of the
reversed linked list.

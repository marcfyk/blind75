# README

## Objective

Given an array of $nums$, check if there are any duplicate elements.

## Solution

Time complexity: $O(n)$

Space complexity: $O(n)$

Auxiliary complexity: $O(n)$

Traverse $nums$, maintaining a set of elements seen as we iterate through
$nums$. This allows for $O(1)$ verfication if an element has been seen before.

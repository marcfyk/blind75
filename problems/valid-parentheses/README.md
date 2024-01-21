# README

## Objective

Given a string $s$ containing only `(`, `)`, `{`, `}`, `[`, `]`,
determine if the $s$ is valid.

Conditions for validity:
1. Open brackets must be closed by the same type of brackets
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket.

## Solution

Time complexity: $O(n)$

Space complexity: $O(n)$

Auxiliary space: $O(n)$

We maintain a stack of open brackets as we iterate $s$.

Whenever we encounter an open bracket, we add it to the top of our stack.

Whenever we encounter a close bracket, we will check the top of our stack
to see if it is a matching open bracket of the same type.
If so, we pop the top of our stack and continue,
if not, either condition 1 or 2 is violated and we return false.
If the stack is empty and we have nothing to compare it to the current close bracket,
we return false as condition 3 is violated.

Once we are done iterating $s$, we check if the stack is empty.
If the stack is empty, it is valid and we return true.
If not, then condition 1 is violated and we return false.

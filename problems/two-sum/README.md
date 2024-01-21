# README

## Objective

Given an array, $nums$, and a target $target$, return the indexes of $ x, y \in nums \implies x + y = target$.

> The input is guaranteed to have a unique solution.

## Solution

Time complexity: $O(n)$

Space complexity: $O(n)$

Auxiliary space: $O(n)$

We iterate $n_i \in nums$ while maintaining a hashmap, $M$, $Map<n_i, i>$, which maps
each $n_i \in nums$ to its index.
As w iterate $n_i \in nums$, we look up $target - n_i$ in $M$ to see if there
exists an $m_j$ we have seen before in $nums$. 
If so, the output will be $(i, j)$.

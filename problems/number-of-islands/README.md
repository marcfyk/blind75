# README

## Objective

Given an $m \time n$ 2D array, $grid$, find the number of islands.

```math
grid[i][j] =
\begin{cases}
= '1', & \text{this cell is land}\\
= '0', & \text{this cell is water}
\end{cases}
```

> An island is formed by vertically and horizontally adjacent land.

## Solution

Time complexity: $O(mn)$

Space complexity: $O(mn)$

Auxiliary space: $O(mn)$


We iterate the cells of $grid$ by traversing $i \in |m|, j \in |n|$,
and the number of islands we have seen, $count$.
Whenever we find a piece of land, we perform Depth First Search (DFS) on possible land that would
form the same island, and increment the number of islands we have seen.
As we traverse $grid$ in our DFS, we mark visited land with a new value, $'2'$,
so that we do not revisit this land.
This prevents us from also performing DFS on a land cell belonging to an island
we have already counted.

# README

## Objective

There is an $M \times N$ matrix, $heights$, representing an island,
$heights[i][j] = h, h = height of the island$.

This island is adjacent to the pacific ocean on the top and left border,
and is adjacent to the atlantic ocean on the bottom and right border.

The island receives rain, and water flows along from $heights[i][j]$ to $heights[i\prime][j\prime]$ if $heights[i][j] \geq heights[i\prime][j\prime]$.

Find the locations in $heights$ where water can reach both the pacific and
atlantic oceans.

## Solution

Time complexity: $O((M + N)(MN)^2)$

Space complexity: $O(MN)$

Auxiliary space: $O(MN)$

The left-most column and top-most row is adjacent to the pacific ocean,
thus will always reach the pacific ocean.
Likewise, the right-most column and bottom-most row is adjacent to the atlantic ocean,
thus will always reach the atlantic ocean.

We can perform BFS/DFS on each of these columns/rows to see which locations in
$heights$ can reach it. (This is the opposite direction of water flow).
As we perform BFS/DFS, we track the visited locations, $heights[i][j]$.

> BFS/DFS for each grid location in $heights$ will be $O(MN)$.

We do this to the left-most column and top-most row to collect $A, \forall (i, j) \in A, heights[i][j] can reach the pacific ocean$.
We do this to the right-most column and top-most row to collect $B, \forall (i, j) \in B, heights[i][j] can reach the atlantic ocean$.

Lastly, the result is $A \cap B$.

> Naive solution of BFS/DFS each grid element in heights will be $O(MN)^2$ which is not as efficient as
the proposed solution.

Auxiliary space is $O(MN)$ as maintaining the visited elements in $A, B$ in some data structure such 
as a hashset or matrix is necessary.

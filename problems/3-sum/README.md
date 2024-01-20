# README

## Objective

Obtain all triplets of numbers $(x, y, z)$ in an array, $nums$, where $x + y + z = 0$.

The results of $(x_i, y_j, z_k)$ should not contain duplicates.

## Solution

Time complexity: $O(n^2)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$


Firstly, we sort the numbers in the list.
Since we are calculating for some $x + y + z = 0$, 
sorting the list of numbers provides us the property to collect all triplets 
easily without duplicates in one pass of the list without using additional space
to keep track of seen triplets.

By sorting the elements of the list, for each triplet candidate $(x, y, z)$,
all $x_i$ that have the same value will be adjacent to each other.

$\forall i$ where $nums[i] = x$, all possible values $y, z \implies x + y + z = 0$
exists in within $nums$ at indexes $j \implies i < j < \text{length of nums}$.

Therefore, for each repeated $x_i$ with the same value, we only need to compute the
triplets from $x_i$ and the right subarray starting from $[i + 1, \text{length of nums}]$.
After computing the triplets from $x_i$, we skip forward to the next $x_j$ such that
$x_i \ne x_j$, since computing those will contain duplicates from the previous computation 
of triplets with $x_i$.
This allows us to forego maintaining an auxiliary data structure such as a Set to
account for duplicates.

For the computation of the possible triplets $x, y, z$, where $y, z$ are in the right subarray
after $x$ is located in the array, we can loop once through the subarray using two pointers (indexes),
to the values in the subarray to find the combinations of $x, y, z$ such that $x + y + z = 0$.
Let these pointers be $left$ and $right$, where $left$ is the leftmost index and $right$ is the rightmost
index of the subarray. 
Due to the sorted nature of $nums$, there is a certain property held in the subarray.

```math
x + nums[left] + nums[right] = 
\begin{cases}
= 0, & \text{nums[left] and nums[right] form a valid triple (x, y, z)}\\
\lt 0, & \text{y and z must lie within [left+1, right] indexes}\\
\gt 0, & \text{y and z must lie within [left, right-1] indexes}
\end{cases}
```

When $x + nums[left] + nums[right] < 0$, $nums[left]$ must be the contributing factor since $nums[left] < nums[right]$.
Similarly, when $x + nums[left] + nums[right] > 0$, $nums[right]$ must be the contributing factor for the same reason.

After iterating all $x$ in $nums$ and computing the triplets for the first of each distinct $x$,
we will have found all triplets that satisfy $x + y + z = 0$.

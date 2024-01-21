# README

## Objective

Given a sorted array, $nums$, of distinct elements that is rotated at some
pivot index, find the index of the element in $nums$ matching $target$.

If $target$ does not exist in $nums$, then $-1$ is returned.

## Solution

Time complexity: $O(\log n)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$

We can directly search for $target$ using a modified binary search.

We keep track of two points during out search, $left$ and $right$, which will
be the left and right bounds of our search space within $nums$.

We start with $left = 0, right = \text{nums.length - 1}$, which means our
search space is the whole array.
Then, we compute the middle index, $mid$, between $left$ and $right$.
$mid = \floor{(left + right) / 2}$.
Then, we compare $nums[mid]$ to $target$ to see if we have found our result,
much like normal binary search.
If $nums[mid] = target$, then $mid$ is the answer.

However, if $nums[mid] \neq target$, then this is where our logic deviates
from normal binary search.
We want to utilize the fact that at each step of the binary search,
there are two partitions with respect to the index $mid$, 
$nums[left..mid]$ and $nums[mid..right]$.
At least 1 of these partitions is sorted, which we will utilize in our binary search
to maintain our $O(\log n)$ time complexity.
The overall strategy is that wherever the partition is sorted, 
the standard binary search will work as intended.
Therefore, if our $target$ is within the sorted limits of the sorted range,
we continue our binary search in that partition.
Conversely, if $target$ is not within the sorted limits of the sorted range,
it is either not present in the search space, or it must lie in the search space
of the other partition.
Even though the other partition may not be sorted, we can continue the next
step of our modified binary search on that search space.

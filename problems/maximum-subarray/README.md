# README

## Objective

Given an array $nums$, find the maximum sum from a subarray in $nums$.

## Solution

Time complexity: $O(n)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$

We can use Kadane's algorithm for this.

As we iterate through $n \in nums$, we keep track of two variables,
$overall$ which is the best sum so far, and $current$ which is the best sum
at each iteration.

At each iteration $i$, $current = max(current, nums[i])$ as the best sum at each
iteration is either taking $nums[i]$ with the subarray we are considering so far,
or start considering a new subarray from $nums[i]$.
Then, we just update $overall$ to be $overall = max(overall, current)$.

After iterating $nums$, $overall$ will be the largest subarray sum.


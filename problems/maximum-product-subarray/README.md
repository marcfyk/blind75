# README

## Objective

Given an array $nums$, find the largest product obtainable from a subarray of $nums$.

## Solution

Time complexity: $O(n)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$

We keep track of the 3 values as we iterate $nums$.
These are the smallest product so far using the subarray up to this step, $smallest$,
the largest product so far using the subarray up to this step, $largest$,
and the largest product so far, $best$.

At each iteration, $i$, there are 3 possible products:
- $nums[i]$
- $nums[i] \times largest$
- $nums[i] \times smallest$

Since we are calculating the product on subarrays, we either take $nums[i]$ 
in our existing subarray product, or we start a new subarray starting with $nums[i]$.

Therefore, we update $smallest$, $largest$, and $best$ at each iteration $i$.
$smallest$ is the $min(nums[i], nums[i] * smallest, nums[i] * largest)$,
$largest$ is the $max(nums[i], nums[i] * smallest, nums[i] * largest),
and $best$ is $max(best, largest)$.

This is similar to Kadane's algorithm, but since we are dealing with multiplication,
where a very large negative number can result the largest positive product due
to multiplying with another negative number several elements to the right,
we have to track $smallest$ along with $largest$ as $smallest$ multiplied with
some $nums[i]$ may be the largest product.

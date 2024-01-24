# README

## Objective

Given an array of sorted elements that is rotated about some pivot, 
find the smallest element in the array element in the array.

## Solution

Time complexity: $O($\log n$)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$

Since we are finding the smallest element, we are searching for the pivot.

We perform a modified binary search.
We start with 2 pointers, $left$ and $right$ at both ends of the array.

At each iteration of the binary search, 
where our search space is between the inclusive range of $array[left]$ and $array[right]$.
If $array[left] <= array[right]$, then the search space is sorted, and the smallest element and pivot is $array[left]$.

If $array[left] > array[right]$ is not true, then we split the $array$ into 2 equal halves using the middle, $mid$, of $left$ and $right$.
The pivot is either on the left or right (inclusive of the middle element).
The pivot if $array[left] <= array[mid]$, then the pivot must be within $array[mid+1, right]$ 
because the elements in $array[left, mid]$ are all larger than $array[mid+1, right]$,
therefore we continue our search in the in $array[mid+1, right]$.

If $array[left] > array[mid]$, then the pivot is within $array[left+1, mid]$.

We keep repeated these steps at each iteration until we find the pivot which is guaranteed on non-empty rotated sorted arrays.

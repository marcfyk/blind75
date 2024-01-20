# README

## Objective

Given an array of intervals, $intervals$ where $intervals[i] = [start_i, end_i]$, merge all overlapping intervals, 
and return an array of non-overlapping intervals that cover all the intervals of the input.

> $[1, 4] and [4, 5]$ are considered overlapping.

## Solution

Time complexity: $O(n\log n)$

Space complexity: $O(n)$

Auxiliary complexity: $O(1)$

First, we sort the intervals by their left bound, $start_i$.
This allows us to find the non-overlapping intervals in one pass.
Each $interval_i$ is either overlaps $interval_{i - 1}$ or it doesn't.

We collect our array of non-overlapping intervals in $output$.

As we iterate throught $intervals$, we only need to compare $interval_i$ with
the latest $interval \in output$ due to $intervals being sorted by their left
bound $start_i$.
Due of the way $intervals$ is sorted, we know that the latest $interval \in output$ is the only interval so far that can possibly overlap with $interval_i$.

Therefore, after a single iteration of $intervals$, we can identify the result
of non-overlapping intervals.

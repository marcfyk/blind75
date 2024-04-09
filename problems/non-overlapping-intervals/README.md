# README

## Objective

Given an array of $intervals$, where each $intervals[i] = [start_i, end_i]$,
return the minimum number of intervals needed to be removed from $intervals$
for it to only contain non-overlapping intervals.

> Given intervals, $x = [start_x, end_x], y = [start_y, end_y]$,
they are overlapping if and only if 
$start_x \lt start_y \lt end_x \or start_x \lt end_y \lt end_x$.
>
> Adjacent intervals where the adjacent start and end are the same value
are not considered as overlapping intervals.
For example, $[0, 10], [10, 20]$ are not overlapping intervals.

## Solution

Time complexity: $O(n \log n)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$

First, we sort the intervals by their starting point (left boundary).
This allows us to iteratively determine which intervals to remove in a greedy fashion.
Due to the sort we perform, we have the following exhaustive cases:

```
Given two intervals in the sorted intervals,
x = [start_x, end_x] and y = [start_y, end_y]
and start_x <= start_y.

***
for simplicity, < and <= scenarios are combined into a single case
where the overlapping condition remains unchanged regardless
***

case 1 (y is not overlapping x, start_y >= end_x):
x: +-----+
y:       +------+

case 2: (y overlaps x and potentially extends to the right, start_y < end_x and end_y >= end_x):
x: +-----+
y:   +------+

case 3: (y overlaps x and is contained strictly within x, start_y < end_x and end_y < end_x):
x: +-----+
y:  +---+
```

With case 1, we remove no interval since they are no overlapping intervals.
With cases 2 and 3, we must remove at least 1 interval, and we simply choose to remove the interval that
extends the furthest to the right, $max(end_i, end_j)$.
This is because removing the interval with the furthest to the right is greedily optimal.
Intuitively, the interval that extends furthest to the right has the highest chance of overlapping
subsequent intervals which would require more removals, while we want to find out the minimum removals required.

The above cases show the logic for pairwise interval comparisons.
For the whole algorithm, we maintain the right most boundary of the first interval, and iteratively apply our logic
covered in the described cases over the rest of the intervals.

The complexity is $O(n \log n)$ due to the sorting and the linear scan of the intervals.
Since sorting can be done in-place, and we iterate the existing intervals in-place no auxiliary space is used. 

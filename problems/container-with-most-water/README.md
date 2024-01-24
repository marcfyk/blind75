# README

## Objective

Given an integer array of heights, $height$, of length $n$.
There are $n$ vertical lines where the height of the $i^th$ line is $height[i]$.
Two lines together form a container along with the x-axis (the indexes of $height$).

Find the largest container possible with the given $height$ array.

## Objective

Time complexity: $O(n)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$


Maintain 2 pointers, $left$, and $right$, at the two ends of $height$, representing the walls of the container formed. 
We also maintain a highest volume we have seen, $MaxVolume$

We gradually increment $left$ and/or decrement $right$ when while calculating
the volume they form with the x-axis, updating the $MaxVolume$ we see as we go
until we the left pointer meets the right pointer.

During our iteration, we calculate the volume and update $MaxVolume$ accordingly,
then, we shift the pointer of the lower wall to the next adjacent wall closer
to the opposite wall.
The reasoning is that whichever wall is lower, the result of all subsequent
volumes with the opposite wall can only be strictly equal or lesser that
the current volume.
If both walls are of equal length, we can optimize and shift both walls
towards each other in one step.

# README

## Objective

Determine if 2 strings, $s, t$ are anagrams.

## Solution

Time complexity: $O(n)$

Space complexity: $O(n)$

Auxiliary space: $O(n)$

If $s$ and $t$ are of different length, we immediately return false as it
is impossible for $s$ and $t$ to have the same set of characters.

If $s$ and $t$ are of the same length, then we iterate the common length $L$,
and build a hashmap, $C$, $Map<c, counts>$, which maps each distinct character 
to the number of occurances in $s$.
At each $i^th$ iteration, we increment $C[s[i]]$ by 1, and decrement $C[t[i]]$ by 1.

Lastly, we return if all counts $C$ is 0.

This is because anagrams will have the same count of each distinct characters.

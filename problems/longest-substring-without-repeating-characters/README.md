# README

## Objective

Given a string $s$, find the longest substring without repeating characters.

> $\forall, c \in s, c \in C$, where $C$ is the set of english letters, digits, symbols and spaces.

## Solution

Time complexity: $O(n)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$

We maintain a sliding window starting from the start of $s$, $window$.
We maintain a hashset of seen characters in this window, $seen = HashSet<char>$.
We keep a reference to where the window starts, $left$ and a variable, $maxLength$,
that tracks the longest window seen.

We iterate $c \in s, c = s[right]$, where $right$ is the end of the window during each iteration step.

If the $c \in seen$, we iteratively shift $left$ to the right until we find
the duplicate $c \in window$, removing $s[left]$ from $seen$ as we go.
We are guaranteed that the duplicate $c$ in $window$ occurs at most once as
we apply this check at every iteration,
thus we only need to shift $left$ till $s[left] = c$ and shift 1 more position
to the right.
If $c \notin seen$, we just add $c$ to $seen$, and $left$ remains unchanged.

At the end of each iteration step, $|window| = right - left + 1$.
We update $maxLength = max(maxLength, |window|)$.
By the end of the iteration, $maxLength$ will have our answer.

> Auxiliary space is $O(1)$ as $seen$ has a fixed constant upperbound size.

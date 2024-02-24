# README

## Objective

Given two strings, $s, t$, return the minimum window substring of $s$ such that all characters in $t$,
including duplicates, is included in the window. If there is no such window substring, return $""$.

> It is guaranteed that the answer is unique.

## Solution

Time complexity: $O(|s|) + O(|t|)$

Space complexity: $O(|s|) + O(|t|)$

Auxiliary space: $O(|s|) + O(|t|)$

We first initialize our best window we have seen so far in $L, R$ which are the left and right indexes (inclusive)
of the smallest window we have seen.
We define $W$ to be the window of $s$ within $[L, R]$.
This is initially set to some empty value or invalid window size such as $|s| + 1$.

We initialize $l, r$ which are our current indexes (inclusive) of the window we are looking at, which we start
from $l = 0, r = 0$.
We define $w$ to be the window of $s$ within $[l, r]$

We define our condition $F$ satisified when $\forall a \in t \implies a \in w$.

The overall idea is that we want to iteratively expand $r$ to the right. At each iteration, we see if our current
$w$ satisfies the $F$, if so, we try to shift $l$ as far right as possible to make $w$ as small as possible while
satisfying $F$.

> A naive solution would have use maintain a histogram of character counts in $w$, $H$, and compare it to a histogram of character counts in $t$, $T$. 
Then to verify $F$, we check $\forall c, count \in T \implies c \in H \land count = H[c]$.
This will be costly as it will be $O(|T|)$ per verification.

There is an optimized way of verifying $F$ as we shift $l, r$.
We maintain a histogram character counts of $w$, $H$, and a historgram of character counts in $T$.
In addition, we have a variable $letters{\_}satisified$ which keeps track of the number of
characters in $H$ such that $\forall c \in H \land c \in T, \implies H[c] \geq T[c]$.
This means that it tracks the number of characters that are already satisifed in $T$.
Therefore, $letters{\_}satisifed = |T| \implies F$.

This helps reduce the complexity of verifying $F$.
Whenever we shift $l$ or $r$, instead of checking $\forall c \in T \implies c \in H \land H[c] \geq T[c]$ in $O(|T|)$,
we just need to check the latest addition/deletion of a character count in $H$, update $letters_{\_satisfied}$ and check if $letters{\_}satisifed = |T|$ in $O(1)$.

As we find new $w \implies F$, we just update $W$ if $w$ is a smaller window that $W$.

Since we slide our window $w$ along $s$, and verify $F$ in $O(1)$, our time complexity is linear at $O(|s|) + O(|t|)$.

Our auxiliary space is $O(|s|) + O(|t|)$ as we maintain our histograms $H$ and $T$.

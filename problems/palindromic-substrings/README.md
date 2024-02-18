# README

## Objective

Given a string, $s$, return the number of palindromic substrings contained in $s$.

## Solution

Time complexity: $O(n^2)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$

> Naively solving the number of palindromic substrings would be $O(n^3)$ by doing
the following steps,
>1. $\forall s[i] \in s, 0 \le i \lt length(s), c = s[i]$, 
>2. $\forall c[j], i \le j \lt length(s)$,
>3. $\forall c[i..j]$, we iterate all letters within these indexes to determine if $c[i..j]$ is a palindrome, and counting it if so.
>
> The naive solution seeks to iterate each $\forall c \in s$, and find all palindromic
substrings where $c$ is the left boundary of the palindromic substring.
(This is a naive approach if we think of iteration,and also the part of the
algorithm we can optimize upon.)

The optimization that can be yielded from the naive solution is from the step where
we try to "expand" our window of characters to find palindromic substrings.

In the **naive** method,
Every time we expand our candidate substring, we must perform palindromic verification in $O(n)$ (naive solution step 3).
This is because we have no information with each iteration of expanding our substring rightwards.

Therefore we propose a new way of expanding our candidate substrings
in our proposed *optimized* method.

> We can classify two different types of palindromes.
Odd and even length palindromes.
We will first explain only odd length palindromes for the concept,
then how it easily extends to even length palindromes.

Now in each $c \in s$, now $c$ is the **center** of the candidate palindromes.
We maintain two pointers $left, right$ which point to $c$.
We now iteratively shift $left = left - 1, right = right + 1$,
if $left$ or $right$ exceeds the boundaries of $s$, we stop.
At each iteration, we check if $s[left] = s[right]$.
While this remains true, the current window is a valid palindrome and we count it.
If $s[left] \neq s[right]$, we stop iteration.
This reduces the palindromic verification to $O(1)$ as compared to the naive solution's $O(n)$.
This is because whenever we expand our candidate substring, we know the previous
substring was already a palindrome.
Thus, we only need to check $s[left] = s[right]$ to determine if we can stop our search for
candidate palindromic substrings with $c$ as its center.
This, however, only solves for odd length palindromes.
As stated earlier, we can easily extend our optimized solution to even length palindromes.
For even length palindromes, we start with pairs of characters, $c, c\prime \in s where c = s[i], c\prime = s[i + 1]$.
Then we set $left = i, right = i + 1$.
The rest of the algorithm is the same.

Therefore, our **optimized** solution follows these steps,
1. $\forall s[i] \in s$
2. find all odd length palindromes with $s[i]$ as its center and count them.
3. find all even length palindromes with $s[i], s[i+1]$ as its center and count them.

Since verification of palindromic substrings is now $O(1)$, steps 2 and 3 are $O(n)$ each.
Thus, steps 1-3 will result in a time complexity of $O(n^2)$.
Auxiliary space is $O(1)$ since we only introduce $left, right$ pointers.

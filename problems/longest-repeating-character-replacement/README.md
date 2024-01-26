# README

## Objective

Given a string %s% and an integer %k%, find the longest substring in $s$
containing the same letter after a maximum of $k$ overwrites to elements in $s$.

> %s% contains only uppercased english letters.

## Solution

Time complexity: $O(n)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$


We maintain a sliding window, starting with the first element of $s$.
We maintain a variable $maxLength$ to track the longest substring (with up to $k$ overwrites) so far.
We also maintain a histogram of character occurences, $counts$.
$counts$ can either be represented as a $Map<char, int>$ which maps the 
character as keys and the counts as the values, 
or it can be represented as an $Array<int>$ where the index represents the
character as a index where $Index(A) = 0, Index(Z) = 26$ since the characters
are all uppercased english letters.

Since we can perform at most $k$ overwrites to letters to get the longest
substring of the same letter, the letter to form the substring would be
the character with the highest count in $counts$.

Therefore, as we iterate $c \in s$ while maintaining our sliding window,
we must ensure that $|window| - max(counts) <= k$.
This is because $|window|$ is the length of the candidate substring, and
$|window| - max(counts)$ represents the number of overwrites we can perform
on characters that are not the character in $counts$ that has the largest
frequency.
If $|window| - max(counts) <= k$, then we update $maxLength = max(maxLength, |window|)$.

At the end of our iteration, we will have the longest substring with up to $k$
overwrites in $maxLength$.

> We have $O(1)$ auxiliary space used due to $counts$ being bounded to 26 keys/indexes, which is a constant size.

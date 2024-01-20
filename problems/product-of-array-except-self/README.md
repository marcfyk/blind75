# README

## Objective

Given an array, $nums$, return an array $answer$ where $answer[i]$ is equal to
the product of all elements of $nums$ except $nums[i]$.

> Solution should not make use of the division operation.

## Solution

Time complexity: $O(n)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$

Firstly, we can think of solving this without optimizing for auxiliary space first,
and then optimize auxiliary space used while retaining the semantic strategy of
our solution.

We begin with computing $prefixes$ array, where $prefixes[n] = \prod_{i=0}^{n-1}nums[i]$.
This means that $prefixes[n]$ is the product of all elements in $nums$ between indexes $0 \leq i < n$.
Another way to put it is that $prefixes[n]$ is the product of all elements in $nums$ to the left of index $n$.
For example, $nums = \{5, 2, 4, 3\} \implies prefixes = \{1, 5, 10, 40\}$.
This can be done by keeping an variable across iterations that track the prefix product accumulated.

Then, we want to compute $postfixes$ array, which is something like a reflection
of how we computed $prefixes$, where $postfixes[n] = \prod_{i=n+1}^{\text{nums.length}}nums[i]$.
This means that $postfixes[n]$ is the product of all elements in $nums$ between indexes $n + 1 < i < \text{nums.length}$.
Another way to put it is that $postfixes[n]$ is the product of all elements in $nums$ to the right of index $n$.
For example, $nums = \{5, 2, 4, 3\} \implies postfixes = \{24, 12, 3, 1\}$.
This can be done by keeping an variable across iterations that track the postfix product accumulated.

Now $answers$ is computed where $answers[i] = prefixes[i] \times postfixes[i]$.

This will result in a time complexity, space complexity, and auxiliary space of $O(n)$. 
However, we can improve upon the auxiliary space to $O(1)$.
$answers[i] = prefix[i] \times postfix[i]$ but we can optimize by computing $answers[i]$ in place.

First, we initialize $answers$ to be an array of zeros of the same length as $nums$.
Then, we compute $prefixes[i]$ the same way, but using $answers$ array.
Then, we iterate backwards from indexes $(nums.length, 0]$, 
maintaining the same variable tracking the accumulated postfix product,
but instead of storing $postfix[i]$ in another array, we directly multiply the accumulated value
to $nums[i]$.
Then $answers[i]$ will contain the final product.
This results in $O(1)$ auxiliary space as all operations are done in the memory of the output.

> If we can use the division operator in our solution, then we just initialize $answers$ with the
product of all elements in $nums$ and then divide $answer[i]$ with $nums[i]$. This will have the
a time and space complexity of $O(n)$ and auxiliary space of $O(1)$.

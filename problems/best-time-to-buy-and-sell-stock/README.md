# README

## Objective

Given an array, $prices$ where $prices[i]$ is the price of a 
given stock on the $i^th$ day, find the maximum profit possible
from buying on a single day, and selling on a different day after
the day the stock was bought.

## Solution

Time Complexity: $O(n)$

Space Complexity: $O(n)$

Auxiliary Space: $O(1)$

Since we can only sell the stock after we have bought it, we can
iterate $prices$, keeping track of the cheapest so far and the highest
profit seen so far.

As we iterate $p_i \in prices$ in chronological order (left to right),
we calculate the current profit, $p_i - cheapest$ and update the highest profit so far, $profit = max(profit, current_profit)$.
Then, we update $cheapest = min(cheapest, p_i)$ since any future possible 
selling of the stock at this point $i$ will be maximised by buying the 
cheapest price seen so far.

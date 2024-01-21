# README

## Objective

Given the head of a linked list, detect if there is a cycle.

## Solution

Time complexity: $O(n)$

Space complexity: $O(n)$

Auxiliary space: $O(1)$

We maintain two pointers that traverse the linked list at different speeds in each step.
If there is a cycle, the faster pointer will reach the slower pointer at some step.
If not, the pointers will reach the end of the list.

# README

## Objective

Given an array of strings, $strs$, return an array of groups, where each group
is an array of anagrams.

## Solution

Time complexity: $O(n\log k)$, where $k$ is the length of the strings in $strs$

Space complexity: $O(n)$

Auxiliary space: $O(n)$

We should utilize the fact that all words that are anagrams with each other
form the same word when they are sorted lexicographically. 
This sorted word $k$ is a good fit as a hashing key to identify other similar
anagrams.

Therefore, we maintain a hashmap, $Map<string, Array<string>>$ that maps this sorted 
key $k$ to an array of anagrams that have $k$ after being sorted.

Then, we iterate $strs$ to add it to the correct $k$ in our hashmap.
After iteration, we can return the values of the hashmap in an array.

package main

func lengthOfLongestSubstring(s string) int {
	rs := []rune(s)
	maxLength := 0
	seen := make(map[rune]struct{})
	left := 0
	for right, r := range rs {
		if _, ok := seen[r]; ok {
			for rs[left] != r {
				delete(seen, rs[left])
				left++
			}
			left++
		} else {
			seen[r] = struct{}{}
		}
		maxLength = max(maxLength, right-left+1)
	}
	return maxLength
}

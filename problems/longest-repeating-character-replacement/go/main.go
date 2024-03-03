package main

import "slices"

func characterReplacement(s string, k int) int {
	rs := []rune(s)
	maxLength := 0
	counts := make([]int, 26)
	windowBegin := 0
	for windowEnd, r := range rs {
		counts[charIndex(r)]++
		windowLength := getWindowLength(windowBegin, windowEnd)
		if windowLength-slices.Max(counts) > k {
			counts[charIndex(rs[windowBegin])]--
			windowBegin++
		} else {
			maxLength = max(maxLength, windowLength)
		}
	}
	return maxLength
}

func charIndex(c rune) int {
	return int(c) - int('A')
}

func getWindowLength(start, end int) int {
	return end - start + 1
}

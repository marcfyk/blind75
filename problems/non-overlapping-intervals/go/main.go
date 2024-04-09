package main

import "slices"

func eraseOverlapIntervals(intervals [][]int) int {
	slices.SortFunc(intervals, func(x, y []int) int { return x[0] - y[0] })
	count := 0
	right := intervals[0][1]
	for i := 1; i < len(intervals); i++ {
		l := intervals[i][0]
		r := intervals[i][1]
		if l >= right {
			right = r
			continue
		}
		count++
		right = min(right, r)
	}
	return count
}

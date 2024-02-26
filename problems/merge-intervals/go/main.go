package main

import "sort"

func merge(intervals [][]int) [][]int {
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	results := [][]int{intervals[0]}
	for i := 1; i < len(intervals); i++ {
		left, right := intervals[i][0], intervals[i][1]
		prevResult := results[len(results)-1]
		prevLeft, prevRight := prevResult[0], prevResult[1]
		if left > prevRight {
			results = append(results, intervals[i])
		} else {
			results[len(results)-1] = []int{min(prevLeft, left), max(prevRight, right)}
		}
	}
	return results
}

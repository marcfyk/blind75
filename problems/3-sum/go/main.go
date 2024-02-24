package main

import "sort"

func threeSum(nums []int) [][]int {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	results := make([][]int, 0, len(nums))
	for i, n := range nums {
		if i != 0 && nums[i-1] == n {
			continue
		}
		left := i + 1
		right := len(nums) - 1
		for left < right {
			sum := n + nums[left] + nums[right]
			if sum < 0 {
				left++
			} else if sum > 0 {
				right--
			} else {
				results = append(results, []int{n, nums[left], nums[right]})
				left++
				for left < right && nums[left-1] == nums[left] {
					left++
				}
			}
		}
	}
	return results
}

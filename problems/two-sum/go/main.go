package main

func twoSum(nums []int, target int) []int {
	deltas := make(map[int]int)
	for i, n := range nums {
		delta := target - n
		if d, ok := deltas[delta]; ok {
			return []int{d, i}
		}
		deltas[n] = i
	}
	return make([]int, 0)
}

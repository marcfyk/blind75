package main

func maxSubArray(nums []int) int {
	const minimum = -100_000
	overallMax := minimum
	currMax := minimum
	for _, n := range nums {
		currMax = max(currMax+n, n)
		overallMax = max(overallMax, currMax)
	}
	return overallMax
}

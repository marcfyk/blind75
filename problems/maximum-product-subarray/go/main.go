package main

func maxProduct(nums []int) int {
	smallest := nums[0]
	largest := nums[0]
	best := nums[0]
	for i := 1; i < len(nums); i++ {
		n := nums[i]
		smallestWithN := smallest * n
		largestWithN := largest * n
		smallest = min(smallestWithN, largestWithN, n)
		largest = max(smallestWithN, largestWithN, n)
		best = max(best, largest)
	}
	return best
}

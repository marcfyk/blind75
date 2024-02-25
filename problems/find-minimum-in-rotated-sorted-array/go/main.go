package main

func findMin(nums []int) int {
	left := 0
	right := len(nums) - 1
	for left <= right {
		if nums[left] <= nums[right] {
			return nums[left]
		}
		mid := (left + right) / 2
		if nums[left] <= nums[mid] {
			left = mid + 1
		} else {
			left++
			right = mid
		}
	}
	return -1
}

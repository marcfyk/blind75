package main

func maxArea(height []int) int {
	left := 0
	right := len(height) - 1
	volume := 0
	for left < right {
		h := min(height[left], height[right])
		w := right - left
		v := h * w
		volume = max(volume, v)
		if height[left] < height[right] {
			left++
		} else if height[left] > height[right] {
			right--
		} else {
			left++
			right--
		}
	}
	return volume
}

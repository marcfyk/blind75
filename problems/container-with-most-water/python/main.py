from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        volume = 0
        while left < right:
            h = min(height[left], height[right])
            w = right - left
            v = h * w
            volume = max(volume, v)
            if height[left] < height[right]:
                left += 1
            elif height[left] > height[right]:
                right -= 1
            else:
                left += 1
                right -= 1
        return volume

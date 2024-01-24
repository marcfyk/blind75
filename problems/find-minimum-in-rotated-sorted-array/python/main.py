from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            if nums[left] <= nums[right]:
                return nums[left]
            mid = (left + right) // 2
            if nums[left] <= nums[mid]:
                left = mid + 1
            else:
                left += 1
                right = mid
        return -1

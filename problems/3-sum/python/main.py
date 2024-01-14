from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        results = []
        for i, n in enumerate(nums):
            if i != 0 and nums[i - 1] == n:
                continue
            left = i + 1
            right = len(nums) - 1
            while left < right:
                sum = n + nums[left] + nums[right]
                if sum < 0:
                    left += 1
                elif sum > 0:
                    right -= 1
                else:
                    results.append([n, nums[left], nums[right]])
                    left += 1
                    while left < right and nums[left - 1] == nums[left]:
                        left += 1
        return results

from typing import List


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        smallest = nums[0]
        largest = nums[0]
        best = nums[0]
        for i in range(1, len(nums)):
            n = nums[i]
            smallest_with_n = smallest * n
            largest_with_n = largest * n
            smallest = min(smallest_with_n, largest_with_n, n)
            largest = max(smallest_with_n, largest_with_n, n)
            best = max(best, largest)
        return best

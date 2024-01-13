from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        MIN = int(-10e4)
        overall_max = MIN
        curr_max = MIN
        for n in nums:
            curr_max = max(curr_max + n, n)
            overall_max = max(overall_max, curr_max)
        return overall_max

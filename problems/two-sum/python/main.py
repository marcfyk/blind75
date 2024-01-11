from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        deltas = {}
        for (i, n) in enumerate(nums):
            delta = target - n
            if delta in deltas:
                return [deltas[delta], i]
            deltas[n] = i
        return []

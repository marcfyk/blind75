from typing import List

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda k: k[0])
        count = 0
        right = intervals[0][1]
        for i in range(1, len(intervals)):
            [l, r] = intervals[i]
            if l >= right:
                right = r
                continue
            count += 1
            right = min(right, r)
        return count

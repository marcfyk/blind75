from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda k: k[0])
        results = [intervals[0]]
        for i in range(1, len(intervals)):
            [left, right] = intervals[i]
            [prev_left, prev_right] = results[-1]
            if left > prev_right:
                results.append(intervals[i])
            else:
                results[-1] = [min(prev_left, left), max(prev_right, right)]
        return results

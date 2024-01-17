from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        results = []
        intervals.sort(key=lambda k: k[0])
        for interval in intervals:
            if len(results) == 0:
                results.append(interval)
                continue
            [left, right] = interval
            [prev_left, prev_right] = results[-1]
            if left > prev_right:
                results.append(interval)
            else:
                results[-1] = [min(prev_left, left), max(prev_right, right)]
        return results

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        cheapest = int(1e4)
        profit = 0
        for p in prices:
            current_profit = p - cheapest
            cheapest = min(cheapest, p)
            profit = max(profit, current_profit)
        return profit

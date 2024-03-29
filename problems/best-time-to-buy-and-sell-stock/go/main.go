package main

func maxProfit(prices []int) int {
	cheapest := int(1e4)
	profit := 0
	for _, p := range prices {
		current_profit := p - cheapest
		cheapest = min(cheapest, p)
		profit = max(profit, current_profit)
	}
	return profit
}

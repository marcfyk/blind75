use std::cmp;

pub struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        const MAX_PROFIT: i32 = 1e4 as i32;
        let (_, profit) = prices
            .into_iter()
            .fold((MAX_PROFIT, 0), |(cheapest, profit), p| {
                let cheapest = cmp::min(cheapest, p);
                let current_profit = p - cheapest;
                let profit = cmp::max(profit, current_profit);
                (cheapest, profit)
            });
        profit
    }
}


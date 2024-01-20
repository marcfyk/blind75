pub struct Solution;

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut cheapest = 1e4 as i32;
        let mut profit = 0;
        for p in prices {
            let current_profit = p - cheapest;
            cheapest = cheapest.min(p);
            profit = profit.max(current_profit);
        }
        profit
    }
}

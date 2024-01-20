#include <algorithm>
#include <vector>

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    constexpr int max_price = 1e4;
    auto cheapest = max_price;
    auto profit = 0;
    for (const auto p : prices) {
      const auto current_profit = p - cheapest;
      cheapest = std::min(cheapest, p);
      profit = std::max(profit, current_profit);
    }
    return profit;
  }
};

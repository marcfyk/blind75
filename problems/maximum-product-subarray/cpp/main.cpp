#include <algorithm>
#include <vector>

class Solution {
public:
  int maxProduct(std::vector<int> &nums) {
    auto smallest = nums[0];
    auto largest = nums[0];
    auto best = nums[0];
    for (auto i = 1; i < nums.size(); ++i) {
      const auto n = nums[i];
      const auto smallest_with_n = smallest * n;
      const auto largest_with_n = largest * n;
      smallest = std::min({n, smallest_with_n, largest_with_n});
      largest = std::max({n, smallest_with_n, largest_with_n});
      best = std::max(best, largest);
    }
    return best;
  }
};

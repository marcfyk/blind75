#include <algorithm>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    constexpr int min = -10e4;
    int overall_max = min;
    int curr_max = min;
    for (const auto n : nums) {
      curr_max = std::max(curr_max + n, n);
      overall_max = std::max(overall_max, curr_max);
    }
    return overall_max;
  }
};

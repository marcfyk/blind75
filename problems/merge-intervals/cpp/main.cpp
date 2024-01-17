#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    std::vector<std::vector<int>> results;
    std::sort(intervals.begin(), intervals.end(),
              [](const auto x, const auto y) { return x[0] < y[0]; });
    for (const auto interval : intervals) {
      if (results.empty()) {
        results.push_back(interval);
        continue;
      }

      const auto left = interval[0];
      const auto right = interval[1];

      const auto prev_interval = results.back();
      const auto prev_left = prev_interval[0];
      const auto prev_right = prev_interval[1];

      if (left > prev_right) {
        results.push_back(interval);
      } else {
        results.back() = {std::min(left, prev_left),
                          std::max(right, prev_right)};
      }
    }
    return results;
  }
};

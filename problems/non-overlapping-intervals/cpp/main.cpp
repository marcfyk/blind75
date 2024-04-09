#include <algorithm>
#include <vector>

class Solution {
public:
  int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(),
              [](const auto &x, const auto &y) { return x[0] < y[0]; });
    auto count = 0;
    auto right = intervals[0][1];
    for (auto i = 1; i < intervals.size(); ++i) {
      const auto l = intervals[i][0];
      const auto r = intervals[i][1];
      if (l >= right) {
        right = r;
        continue;
      }
      ++count;
      right = std::min(right, r);
    }
    return count;
  }
};

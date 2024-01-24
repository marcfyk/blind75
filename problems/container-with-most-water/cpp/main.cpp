#include <algorithm>
#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    auto left = 0;
    auto right = height.size() - 1;
    auto volume = 0;
    while (left < right) {
      const auto h = std::min(height[left], height[right]);
      const auto w = right - left;
      const int v = h * w;
      volume = std::max(volume, v);
      if (height[left] < height[right]) {
        ++left;
      } else if (height[left] > height[right]) {
        --right;
      } else {
        ++left;
        --right;
      }
    }
    return volume;
  }
};

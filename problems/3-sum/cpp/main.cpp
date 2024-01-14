#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> results;
    for (auto i = 0; i < nums.size(); ++i) {
      if (i != 0 && nums[i - 1] == nums[i]) {
        continue;
      }
      auto left = i + 1;
      auto right = nums.size() - 1;
      while (left < right) {
        const auto sum = nums[i] + nums[left] + nums[right];
        if (sum < 0) {
          ++left;
        } else if (sum > 0) {
          --right;
        } else {
          results.push_back({nums[i], nums[left], nums[right]});
          while (++left < right && nums[left - 1] == nums[left])
            ;
        }
      }
    }
    return results;
  }
};

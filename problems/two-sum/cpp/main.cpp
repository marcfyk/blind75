#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> deltas(nums.size());
    for (auto i = 0; i < nums.size(); ++i) {
      const auto delta = target - nums[i];
      if (const auto found = deltas.find(delta); found != deltas.end()) {
        return std::vector<int>{found->second, i};
      }
      deltas.insert({nums[i], i});
    }
    return std::vector<int>();
  }
};

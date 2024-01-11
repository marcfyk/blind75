#include <unordered_set>
#include <vector>

class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    std::unordered_set<int> set(nums.size());
    for (const auto n : nums) {
      if (const auto found = set.find(n); found != set.end()) {
        return true;
      }
      set.insert(n);
    }
    return false;
  }
};

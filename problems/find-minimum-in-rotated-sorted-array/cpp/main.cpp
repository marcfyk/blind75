#include <vector>

class Solution {
public:
  int findMin(std::vector<int> &nums) {
    auto left = 0;
    auto right = nums.size() - 1;
    while (left <= right) {
      if (nums[left] <= nums[right]) {
        return nums[left];
      }
      const auto mid = (left + right) / 2;
      if (nums[left] <= nums[mid]) {
        left = mid + 1;
      } else {
        ++left;
        right = mid;
      }
    }
    return -1;
  }
};

#include <vector>

class Solution {
public:
  int search(std::vector<int> &nums, int target) {
    auto left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      const auto mid = (left + right) / 2;
      if (target == nums[mid]) {
        return mid;
      }
      if (nums[left] <= nums[mid]) {
        if (nums[left] <= target && target <= nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        if (nums[mid] < target && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }
    return -1;
  }
};

#include <vector>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums) {
    std::vector<int> products(nums.size());
    auto prefix_acc = 1;
    for (auto i = 0; i < nums.size(); ++i) {
      products[i] = prefix_acc;
      prefix_acc *= nums[i];
    }
    auto postfix_acc = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
      products[i] *= postfix_acc;
      postfix_acc *= nums[i];
    }
    return products;
  }
};

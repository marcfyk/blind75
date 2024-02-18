#include <string>

class Solution {
public:
  int countSubstrings(std::string s) {
    auto count = 0;
    for (auto i = 0; i < s.size(); ++i) {
      const auto odd = expandAndCount(i, i, s);
      const auto even = expandAndCount(i, i + 1, s);
      count += odd + even;
    }
    return count;
  }

  int expandAndCount(const int left, const int right, const std::string &s) {
    auto count = 0;
    auto l = left;
    auto r = right;
    while (0 <= l && r < s.size() && s[l--] == s[r++]) {
      ++count;
    }
    return count;
  }
};

#include <algorithm>
#include <string>
#include <unordered_set>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    auto max_length = 0;
    auto left = 0;
    std::unordered_set<char> seen;
    for (auto right = 0; right < s.size(); ++right) {
      if (const auto found = seen.find(s[right]); found != seen.end()) {
        while (s[left] != s[right]) {
          seen.erase(s[left]);
          ++left;
        }
        ++left;
      } else {
        seen.insert(s[right]);
      }
      max_length = std::max(max_length, right - left + 1);
    }
    return max_length;
  }
};

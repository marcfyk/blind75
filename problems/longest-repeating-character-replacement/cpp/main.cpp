#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int characterReplacement(std::string s, int k) {
    auto max_length = 0;
    std::vector<int> counts(26, 0);
    auto window_begin = 0;
    for (auto window_end = 0; window_end < s.size(); ++window_end) {
      ++counts[charIndex(s[window_end])];
      const auto window_length = windowLength(window_begin, window_end);
      const auto max_count = std::max_element(counts.begin(), counts.end());
      if (window_length - *max_count > k) {
        --counts[charIndex(s[window_begin++])];
      } else {
        max_length = std::max(max_length, window_length);
      }
    }
    return max_length;
  }

  constexpr int charIndex(char c) { return c - 'A'; }

  constexpr int windowLength(int start, int end) { return end - start + 1; }
};

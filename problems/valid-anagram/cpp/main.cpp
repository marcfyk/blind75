#include <string>
#include <unordered_map>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) {
      return false;
    }
    std::unordered_map<char, uint> counts(s.size());
    for (auto i = 0; i < s.size(); ++i) {
      ++counts[s[i]];
      --counts[t[i]];
    }
    for (const auto [_, v] : counts) {
      if (v != 0) {
        return false;
      }
    }
    return true;
  }
};

#include <string>
#include <vector>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) {
      return false;
    }
    std::vector<uint> counts(26, 0);
    std::unordered_map<char, uint> counts(s.size());
    for (const auto c : s) {
      if (const auto found = counts.find(c); found == counts.end()) {
        counts.insert({c, 1});
      } else {
        ++found->second;
      }
    }
    for (const auto c : t) {
      const auto found = counts.find(c);
      if (found == counts.end()) {
        return false;
      }
      if (--found->second == 0) {
        counts.erase(found);
      }
    }
    return counts.size() == 0;
  }
};

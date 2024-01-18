#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::vector<std::string>>
  groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> groups;
    for (const auto s : strs) {
      auto key = s;
      std::sort(key.begin(), key.end());
      if (const auto found = groups.find(key); found == groups.end()) {
        std::vector<std::string> data{s};
        groups[key] = data;
      } else {
        found->second.push_back(s);
      }
    }
    std::vector<std::vector<std::string>> anagram_groups;
    anagram_groups.reserve(groups.size());
    for (const auto pair : groups) {
      anagram_groups.push_back(pair.second);
    }
    return anagram_groups;
  }
};

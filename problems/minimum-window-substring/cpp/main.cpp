#include <string>
#include <unordered_map>

class Window {
public:
  size_t left;
  size_t right;
  Window(size_t l, size_t r) : left(l), right(r) {}

  size_t size() { return right - left + 1; }
};

class Solution {
public:
  std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, int> targets;
    for (const auto c : t) {
      ++targets[c];
    }
    const auto target_size = targets.size();

    std::unordered_map<char, int> current_window;
    size_t letters_satisfied = 0;

    Window best_window(0, s.size() + 1);

    size_t left = 0;
    for (size_t right = 0; right < s.size(); ++right) {
      const auto c = s[right];
      ++current_window[c];
      if (current_window[c] == targets[c]) {
        ++letters_satisfied;
      }
      while (letters_satisfied == target_size) {
        const auto window_size = right - left + 1;
        if (window_size < best_window.size()) {
          best_window = Window(left, right);
        }
        --current_window[s[left]];
        if (current_window[s[left]] < targets[s[left]]) {
          --letters_satisfied;
        }
        ++left;
      }
    }
    return best_window.size() > s.size()
               ? ""
               : s.substr(best_window.left, best_window.size());
  }
};

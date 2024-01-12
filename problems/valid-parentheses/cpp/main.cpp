#include <string>
#include <vector>

class Solution {
public:
  bool isValid(std::string s) {
    constexpr char paren_open = '(';
    constexpr char paren_close = ')';
    constexpr char bracket_open = '[';
    constexpr char bracket_close = ']';
    constexpr char brace_open = '{';
    constexpr char brace_close = '}';

    std::vector<char> stack;
    stack.reserve(s.size());

    for (const auto c : s) {
      switch (c) {
      case paren_open:
        stack.push_back(c);
        break;
      case bracket_open:
        stack.push_back(c);
        break;
      case brace_open:
        stack.push_back(c);
        break;
      case paren_close:
        if (stack.empty()) {
          return false;
        } else if (const auto last = stack.back(); last != paren_open) {
          return false;
        }
        stack.pop_back();
        break;
      case bracket_close:
        if (stack.empty()) {
          return false;
        } else if (const auto last = stack.back(); last != bracket_open) {
          return false;
        }
        stack.pop_back();
        break;
      case brace_close:
        if (stack.empty()) {
          return false;
        } else if (const auto last = stack.back(); last != brace_open) {
          return false;
        }
        stack.pop_back();
        break;
      default:
        return false;
      }
    }
    return stack.empty();
  }
};

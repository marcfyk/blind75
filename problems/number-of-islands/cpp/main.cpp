#include <vector>

constexpr char WATER = '0';
constexpr char LAND = '1';
constexpr char EXPLORED = '2';

class Solution {
public:
  int numIslands(std::vector<std::vector<char>> &grid) {
    auto count = 0;
    for (auto i = 0; i < grid.size(); ++i) {
      for (auto j = 0; j < grid[i].size(); ++j) {
        if (grid[i][j] == LAND) {
          ++count;
          dfs(grid, i, j);
        }
      }
    }
    return count;
  }

  void dfs(std::vector<std::vector<char>> &grid, int i, int j) {
    std::vector<std::pair<int, int>> stack;
    stack.push_back({i, j});
    while (!stack.empty()) {
      const auto p = stack.back();
      stack.pop_back();
      const auto i = p.first;
      const auto j = p.second;
      if (grid[i][j] == LAND) {
        grid[i][j] = EXPLORED;
        if (0 <= (i - 1) && grid[i - 1][j] == LAND) {
          stack.push_back({i - 1, j});
        }
        if (i + 1 < grid.size() && grid[i + 1][j] == LAND) {
          stack.push_back({i + 1, j});
        }
        if (0 <= (j - 1) && grid[i][j - 1] == LAND) {
          stack.push_back({i, j - 1});
        }
        if (j + 1 < grid[i].size() && grid[i][j + 1] == LAND) {
          stack.push_back({i, j + 1});
        }
      }
    }
  }
};

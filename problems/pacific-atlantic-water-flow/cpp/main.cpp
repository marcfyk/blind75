#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  pacificAtlantic(std::vector<std::vector<int>> &heights) {
    const auto rows = heights.size();
    const auto cols = heights[0].size();
    const auto pacific =
        bfs(rows, cols, heights, pacificInitialCoords(rows, cols));
    const auto atlantic =
        bfs(rows, cols, heights, atlanticInitialCoords(rows, cols));
    return coordIntersection(pacific, atlantic);
  }

  std::vector<std::pair<int, int>> pacificInitialCoords(const int rows,
                                                        const int cols) {
    std::vector<std::pair<int, int>> coords{{0, 0}};
    for (auto i = 1; i < rows; ++i) {
      coords.push_back({i, 0});
    }
    for (auto i = 1; i < cols; ++i) {
      coords.push_back({0, i});
    }
    return coords;
  }

  std::vector<std::pair<int, int>> atlanticInitialCoords(const int rows,
                                                         const int cols) {
    std::vector<std::pair<int, int>> coords{{rows - 1, cols - 1}};
    for (auto i = 0; i < rows - 1; ++i) {
      coords.push_back({i, cols - 1});
    }
    for (auto i = 0; i < cols - 1; ++i) {
      coords.push_back({rows - 1, i});
    }
    return coords;
  }

  std::vector<std::pair<int, int>>
  adjacentCoords(const int x, const int y, const int rows, const int cols) {
    std::vector<std::pair<int, int>> coords;
    if (x - 1 >= 0) {
      coords.push_back({x - 1, y});
    }
    if (x + 1 < rows) {
      coords.push_back({x + 1, y});
    }
    if (y - 1 >= 0) {
      coords.push_back({x, y - 1});
    }
    if (y + 1 < cols) {
      coords.push_back({x, y + 1});
    }
    return coords;
  }

  std::vector<std::vector<int>>
  bfs(const int rows, const int cols,
      const std::vector<std::vector<int>> &heights,
      const std::vector<std::pair<int, int>> &coords) {
    std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, 0));
    std::queue<std::pair<int, int>> queue;
    for (const auto coord : coords) {
      queue.push(coord);
    }

    while (!queue.empty()) {
      const auto coord = queue.front();
      queue.pop();
      if (visited[coord.first][coord.second] == 1) {
        continue;
      }
      visited[coord.first][coord.second] = 1;
      for (const auto next :
           adjacentCoords(coord.first, coord.second, rows, cols)) {
        if (heights[coord.first][coord.second] <=
            heights[next.first][next.second]) {
          queue.push(next);
        }
      }
    }
    return visited;
  }

  std::vector<std::vector<int>>
  coordIntersection(const std::vector<std::vector<int>> &a,
                    const std::vector<std::vector<int>> &b) {
    std::vector<std::vector<int>> results;
    for (auto i = 0; i < a.size(); ++i) {
      for (auto j = 0; j < a[i].size(); ++j) {
        if (a[i][j] == 1 && b[i][j] == 1) {
          results.push_back({i, j});
        }
      }
    }
    return results;
  }
};

//[1,2,2,3,5]
//[3,2,3,4,4]
//[2,4,5,3,1]
//[6,7,1,4,5]
//[5,1,1,2,4]

#include <iostream>
int main() {

  std::vector<std::vector<int>> grid{
      {1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1},
      {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4},
  };
  Solution s;
  for (const auto p : s.pacificInitialCoords(5, 5)) {
    std::cout << "[" << p.first << "," << p.second << "] ";
  }
  std::cout << std::endl;
  for (const auto p : s.atlanticInitialCoords(5, 5)) {
    std::cout << "[" << p.first << "," << p.second << "] ";
  }
  std::cout << std::endl;
  for (const auto [k, vs] : s.bfs(5, 5, grid, s.atlanticInitialCoords(5, 5))) {
    for (const auto v : vs) {
      std::cout << "[" << k << "," << v << "] ";
    }
  }
  std::cout << std::endl;
  for (const auto [k, vs] : s.bfs(5, 5, grid, s.pacificInitialCoords(5, 5))) {
    for (const auto v : vs) {
      std::cout << "[" << k << "," << v << "] ";
    }
  }
  std::cout << std::endl;
}

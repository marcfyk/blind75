from typing import List

WATER = "0"
LAND = "1"
EXPLORED = "2"


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == LAND:
                    count += 1
                    dfs(grid, i, j)
        return count


def dfs(grid: List[List[str]], i: int, j: int):
    stack = [(i, j)]
    while len(stack) > 0:
        (i, j) = stack.pop()
        if grid[i][j] == LAND:
            grid[i][j] = EXPLORED
            if 0 <= i - 1 and grid[i - 1][j] == LAND:
                stack.append((i - 1, j))
            if i + 1 < len(grid) and grid[i + 1][j] == LAND:
                stack.append((i + 1, j))
            if 0 <= j - 1 and grid[i][j - 1] == LAND:
                stack.append((i, j - 1))
            if j + 1 < len(grid[i]) and grid[i][j + 1] == LAND:
                stack.append((i, j + 1))

from typing import List, Set, Tuple
from collections import deque


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows, cols = len(heights), len(heights[0])
        pacific = bfs(
            rows, cols, heights, pacificInitialCoords(rows, cols)
        )
        atlantic = bfs(
            rows, cols, heights, atlanticInitialCoords(rows, cols)
        )
        return [[x, y] for (x, y) in pacific.intersection(atlantic)]


def pacificInitialCoords(rows: int, cols: int) -> List[Tuple[int, int]]:
    coords = [(int(0), int(0))]
    for i in range(1, rows):
        coords.append((i, 0))
    for i in range(1, cols):
        coords.append((0, i))
    return coords


def atlanticInitialCoords(rows: int, cols: int) -> List[Tuple[int, int]]:
    coords = [(rows - 1, cols - 1)]
    for i in range(rows - 1):
        coords.append((i, cols - 1))
    for i in range(cols - 1):
        coords.append((rows - 1, i))
    return coords


def adjacentCoords(x: int, y: int, rows: int, cols: int) -> List[Tuple[int, int]]:
    coords = []
    if x - 1 >= 0:
        coords.append((x - 1, y))
    if x + 1 < rows:
        coords.append((x + 1, y))
    if y - 1 >= 0:
        coords.append((x, y - 1))
    if y + 1 < cols:
        coords.append((x, y + 1))
    return coords


def bfs(
    rows: int, cols: int, heights: List[List[int]], coords: List[Tuple[int, int]]
) -> Set[Tuple[int, int]]:
    visited = set()
    queue = deque()
    for coord in coords:
        queue.append(coord)
    while queue:
        coord = queue.popleft()
        if coord in visited:
            continue
        (x, y) = coord
        visited.add((x, y))
        queue.extend(
            (i, j)
            for (i, j) in adjacentCoords(x, y, rows, cols)
            if heights[x][y] <= heights[i][j]
        )
    return visited

package main

const (
	Water    = '0'
	Land     = '1'
	Explored = '2'
)

func numIslands(grid [][]byte) int {
	count := 0
	for i := range grid {
		for j := range grid[i] {
			if grid[i][j] == Land {
				count++
				dfs(grid, i, j)
			}
		}
	}
	return count
}

type coord struct{ x, y int }

func dfs(grid [][]byte, i, j int) {
	stack := []coord{{i, j}}
	for len(stack) > 0 {
		c := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		if grid[c.x][c.y] == Land {
			grid[c.x][c.y] = Explored
			stack = append(stack, adjacentLand(grid, c.x, c.y)...)
		}
	}
}

func adjacentLand(grid [][]byte, x, y int) []coord {
	coords := make([]coord, 0, 4)
	if 0 <= x-1 && grid[x-1][y] == Land {
		coords = append(coords, coord{x: x - 1, y: y})
	}
	if x+1 < len(grid) && grid[x+1][y] == Land {
		coords = append(coords, coord{x: x + 1, y: y})
	}
	if 0 <= y-1 && grid[x][y-1] == Land {
		coords = append(coords, coord{x: x, y: y - 1})
	}
	if y+1 < len(grid[x]) && grid[x][y+1] == Land {
		coords = append(coords, coord{x: x, y: y + 1})
	}
	return coords
}

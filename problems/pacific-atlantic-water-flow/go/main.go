package main

func pacificAtlantic(heights [][]int) [][]int {
	rows, cols := len(heights), len(heights[0])
	pacific := dfs(rows, cols, heights, pacificInitialCoords(rows, cols))
	atlantic := dfs(rows, cols, heights, atlanticInitialCoords(rows, cols))
	result := make([][]int, 0, max(len(pacific), len(atlantic)))
	for i := range pacific {
		for j := range pacific[i] {
			if pacific[i][j] && atlantic[i][j] {
				result = append(result, []int{i, j})
			}
		}
	}
	return result
}

type coord struct{ x, y int }

func pacificInitialCoords(rows, cols int) []coord {
	coords := make([]coord, 0, rows+cols-1)
	coords = append(coords, coord{x: 0, y: 0})
	for i := 1; i < rows; i++ {
		coords = append(coords, coord{x: i, y: 0})
	}
	for i := 1; i < cols; i++ {
		coords = append(coords, coord{x: 0, y: i})
	}
	return coords
}

func atlanticInitialCoords(rows, cols int) []coord {
	coords := make([]coord, 0, rows+cols-1)
	coords = append(coords, coord{x: rows - 1, y: cols - 1})
	for i := range rows - 1 {
		coords = append(coords, coord{x: i, y: cols - 1})
	}
	for i := range cols - 1 {
		coords = append(coords, coord{x: rows - 1, y: i})
	}
	return coords
}

func adjacentCoords(x, y, rows, cols int) []coord {
	coords := make([]coord, 0, 4)
	if x-1 >= 0 {
		coords = append(coords, coord{x: x - 1, y: y})
	}
	if x+1 < rows {
		coords = append(coords, coord{x: x + 1, y: y})
	}
	if y-1 >= 0 {
		coords = append(coords, coord{x: x, y: y - 1})
	}
	if y+1 < cols {
		coords = append(coords, coord{x: x, y: y + 1})
	}
	return coords
}

func dfs(rows, cols int, heights [][]int, coords []coord) [][]bool {
	visited := make([][]bool, rows)
	for i := range visited {
		visited[i] = make([]bool, cols)
	}
	stack := make([]coord, 0, rows*cols)
	for _, c := range coords {
		stack = append(stack, c)
	}
	for len(stack) > 0 {
		c := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		if visited[c.x][c.y] {
			continue
		}
		visited[c.x][c.y] = true
		for _, next := range adjacentCoords(c.x, c.y, rows, cols) {
			if heights[c.x][c.y] <= heights[next.x][next.y] {
				stack = append(stack, next)
			}
		}
	}
	return visited
}

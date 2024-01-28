pub struct Solution;

#[allow(dead_code)]
const WATER: char = '0';
const LAND: char = '1';
const EXPLORED: char = '2';

impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let mut count = 0;
        for i in 0..grid.len() {
            for j in 0..grid[i].len() {
                if grid[i][j] == LAND {
                    count += 1;
                    dfs(&mut grid, i, j);
                }
            }
        }
        count
    }
}

fn dfs(grid: &mut Vec<Vec<char>>, i: usize, j: usize) {
    let mut stack = vec![(i, j)];
    while !stack.is_empty() {
        let (i, j) = stack.pop().unwrap();
        if grid[i][j] == LAND {
            grid[i][j] = EXPLORED;
            if let Some(next_i) = i.checked_sub(1) {
                if grid[next_i][j] == LAND {
                    stack.push((next_i, j));
                }
            }
            if i + 1 < grid.len() && grid[i + 1][j] == LAND {
                stack.push((i + 1, j));
            }
            if let Some(next_j) = j.checked_sub(1) {
                if grid[i][next_j] == LAND {
                    stack.push((i, next_j));
                }
            }
            if j + 1 < grid[i].len() && grid[i][j + 1] == LAND {
                stack.push((i, j + 1));
            }
        }
    }
}

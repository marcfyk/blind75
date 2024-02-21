use std::{
    collections::{HashSet, VecDeque},
    iter,
};

pub struct Solution;

impl Solution {
    pub fn pacific_atlantic(heights: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (rows, cols) = (heights.len(), heights[0].len());
        let pacific = bfs(rows, cols, &heights, &pacific_initial_coords(rows, cols));
        let atlantic = bfs(rows, cols, &heights, &atlantic_initial_coords(rows, cols));
        pacific
            .intersection(&atlantic)
            .copied()
            .map(|(x, y)| vec![x as i32, y as i32])
            .collect()
    }
}

fn pacific_initial_coords(rows: usize, cols: usize) -> Vec<(usize, usize)> {
    iter::once((0, 0))
        .chain((1..rows).map(|i| (i, 0)))
        .chain((1..cols).map(|i| (0, i)))
        .collect()
}

fn atlantic_initial_coords(rows: usize, cols: usize) -> Vec<(usize, usize)> {
    iter::once((rows - 1, cols - 1))
        .chain((0..rows - 1).map(|i| (i, cols - 1)))
        .chain((0..cols - 1).map(|i| (rows - 1, i)))
        .collect()
}

fn adjacent_coords(x: usize, y: usize, rows: usize, cols: usize) -> Vec<(usize, usize)> {
    let mut coords = Vec::new();
    if let Some(x) = x.checked_sub(1) {
        coords.push((x, y));
    }
    if x + 1 < rows {
        coords.push((x + 1, y));
    }
    if let Some(y) = y.checked_sub(1) {
        coords.push((x, y));
    }
    if y + 1 < cols {
        coords.push((x, y + 1));
    }
    coords
}

fn bfs(
    rows: usize,
    cols: usize,
    heights: &[Vec<i32>],
    coords: &[(usize, usize)],
) -> HashSet<(usize, usize)> {
    let mut visited = HashSet::new();
    let mut queue = VecDeque::new();
    coords.into_iter().for_each(|c| queue.push_back(*c));
    while let Some(coord @ (x, y)) = queue.pop_front() {
        if visited.contains(&coord) {
            continue;
        }
        visited.insert(coord);
        adjacent_coords(x, y, rows, cols)
            .into_iter()
            .filter(|(i, j)| heights[x][y] <= heights[*i][*j])
            .for_each(|next| queue.push_back(next));
    }
    visited
}

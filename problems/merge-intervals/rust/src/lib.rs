use std::cmp;

pub struct Solution;

impl Solution {
    pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        intervals.sort_by(|x, y| x[0].cmp(&y[0]));
        let results = vec![vec![intervals[0][0], intervals[0][1]]];
        intervals
            .into_iter()
            .skip(1)
            .fold(results, |mut results, interval| {
                match results.last_mut() {
                    None => {
                        results.push(interval);
                    }
                    Some(prev_interval) => {
                        let (left, right) = (interval[0], interval[1]);
                        let (prev_left, prev_right) = (prev_interval[0], prev_interval[1]);

                        if left > prev_right {
                            results.push(interval);
                        } else {
                            prev_interval[0] = cmp::min(left, prev_left);
                            prev_interval[1] = cmp::max(right, prev_right);
                        }
                    }
                }
                results
            })
    }
}

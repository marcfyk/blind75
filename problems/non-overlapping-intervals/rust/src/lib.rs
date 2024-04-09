pub struct Solution;

impl Solution {
    pub fn erase_overlap_intervals(mut intervals: Vec<Vec<i32>>) -> i32 {
        intervals.sort_by_key(|x| x[0]);
        let mut count = 0;
        let mut right = intervals[0][1];
        for interval in intervals.iter().skip(1) {
            let l = interval[0];
            let r = interval[1];
            if l >= right {
                right = r;
                continue;
            }
            count += 1;
            right = right.min(r);
        }
        count
    }
}


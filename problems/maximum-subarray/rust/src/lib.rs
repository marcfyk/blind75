use std::cmp;

pub struct Solution;

impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        const MIN: i32 = -100_000;
        let mut overall_max = MIN;
        let mut curr_max = MIN;
        for n in nums {
            curr_max = cmp::max(curr_max+n, n);
            overall_max=cmp::max(overall_max, curr_max);
        }
        overall_max
    }
}

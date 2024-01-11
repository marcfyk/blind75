use std::collections::HashSet;

pub struct Solution;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut set = HashSet::new();
        for n in nums.into_iter() {
            if set.contains(&n) {
                return true;
            }
            set.insert(n);
        }
        false
    }
}


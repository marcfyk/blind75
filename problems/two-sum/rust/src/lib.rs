use std::collections::HashMap;

pub struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut deltas: HashMap<i32, i32> = HashMap::new();
        for (i, n) in nums.into_iter().enumerate() {
            let i = i.try_into().unwrap();
            let delta = target - n;
            if let Some(&j) = deltas.get(&delta) {
                return vec![i, j];
            }
            deltas.insert(n, i);
        }
        Vec::new()
    }
}

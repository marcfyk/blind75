use std::cmp::Ordering;

pub struct Solution;

impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort();
        let mut results = Vec::new();
        for (i, n) in nums.iter().enumerate() {
            if i != 0 && nums[i - 1] == nums[i] {
                continue;
            }
            let mut left = i + 1;
            let mut right = nums.len() - 1;
            while left < right {
                let sum = n + nums[left] + nums[right];
                match sum.cmp(&0) {
                    Ordering::Less => {
                        left += 1;
                    }
                    Ordering::Greater => {
                        right -= 1;
                    }
                    Ordering::Equal => {
                        results.push(vec![*n, nums[left], nums[right]]);
                        left += 1;
                        while left < right && nums[left - 1] == nums[left] {
                            left += 1;
                        }
                    }
                }
            }
        }
        results
    }
}


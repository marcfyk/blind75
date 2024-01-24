use std::cmp::Ordering;

pub struct Solution;

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = height.len() - 1;
        let mut volume = 0;
        while left < right {
            let h = height[left].min(height[right]);
            let w = (right - left) as i32;
            let v = h * w;
            volume = volume.max(v);
            match height[left].cmp(&height[right]) {
                Ordering::Less => {
                    left += 1;
                }
                Ordering::Greater => {
                    right -= 1;
                }
                Ordering::Equal => {
                    left += 1;
                    right -= 1;
                }
            }
        }
        volume
    }
}

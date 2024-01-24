pub struct Solution;

impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = nums.len() - 1;
        while left <= right {
            if nums[left] <= nums[right] {
                return nums[left];
            }
            let mid = (left + right) / 2;
            if nums[left] <= nums[mid] {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        -1
    }
}

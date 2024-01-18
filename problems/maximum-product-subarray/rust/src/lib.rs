pub struct Solution;

impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut smallest = nums[0];
        let mut largest = nums[0];
        let mut best = nums[0];
        for n in nums.into_iter().skip(1) {
            let smallest_with_n = smallest * n;
            let largest_with_n = largest * n;
            let elements = [smallest_with_n, largest_with_n, n];
            smallest = *elements.iter().min().unwrap();
            largest = *elements.iter().max().unwrap();
            best = best.max(largest);
        }
        best
    }
}


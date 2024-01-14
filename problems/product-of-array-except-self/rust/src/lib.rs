pub struct Solution;

impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let mut products = vec![0; nums.len()];
        let mut prefix_acc = 1;
        for (n, p) in nums.iter().zip(products.iter_mut()) {
            *p = prefix_acc;
            prefix_acc *= n;
        }
        let mut postfix_acc = 1;
        for (n, p) in nums.iter().rev().zip(products.iter_mut().rev()) {
            *p *= postfix_acc;
            postfix_acc *= n;
        }
        products
    }
}

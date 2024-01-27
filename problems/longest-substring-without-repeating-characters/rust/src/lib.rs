use std::collections::HashSet;

pub struct Solution;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut max_length = 0;
        let mut seen = HashSet::new();
        let mut left = 0;
        let letters = s.chars().collect::<Vec<_>>();
        for (right, c) in letters.iter().enumerate() {
            if seen.contains(c) {
                while letters[left] != *c {
                    seen.remove(&letters[left]);
                    left += 1;
                }
                left += 1;
            } else {
                seen.insert(c);
            }
            max_length = max_length.max(right - left + 1)
        }
        max_length as i32
    }
}

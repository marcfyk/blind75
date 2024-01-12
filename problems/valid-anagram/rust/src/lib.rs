use std::collections::HashMap;

pub struct Solution;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut counts = HashMap::new();
        for c in s.chars() {
            *counts.entry(c).or_insert(0) += 1;
        }
        for c in t.chars() {
            match counts.get_mut(&c) {
                None => return false,
                Some(count) => {
                    *count -= 1;
                    if *count == 0 {
                        counts.remove(&c);
                    }
                }
            }
        }
        counts.len() == 0
    }
}


use std::collections::HashMap;

pub struct Solution;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut groups = HashMap::new();
        for s in strs {
            let mut chars = s.chars().collect::<Vec<_>>();
            chars.sort();
            let key = chars.into_iter().collect::<String>();
            groups.entry(key).or_insert(Vec::new()).push(s);
        }
        groups.into_values().collect()
    }
}


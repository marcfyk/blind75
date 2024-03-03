use std::collections::HashMap;

pub struct Solution;

impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }
        let sb = s.into_bytes();
        let tb = t.into_bytes();
        (0..sb.len())
            .fold(HashMap::new(), |mut acc, i| {
                *acc.entry(sb[i]).or_insert(0) += 1;
                *acc.entry(tb[i]).or_insert(0) -= 1;
                acc
            })
            .into_values()
            .all(|count| count == 0)
    }
}

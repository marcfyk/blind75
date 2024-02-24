use std::collections::HashMap;

pub struct Solution;

impl Solution {
    pub fn min_window(s: String, t: String) -> String {
        let targets = t
            .into_bytes()
            .into_iter()
            .fold(HashMap::new(), |mut acc, c| {
                *acc.entry(c).or_insert(0) += 1;
                acc
            });

        let mut current_window = HashMap::new();
        let mut letters_satisfied = 0;

        let mut best_window: Option<(usize, usize)> = None;

        let s_chars = s.into_bytes();
        let mut left = 0;
        s_chars.iter().enumerate().for_each(|(right, c)| {
            *current_window.entry(c).or_insert(0) += 1;
            if current_window[&c] == *targets.get(&c).unwrap_or(&0) {
                letters_satisfied += 1;
            }
            while letters_satisfied == targets.len() {
                best_window = best_window.map_or(Some((left, right)), |(l, r)| {
                    Some(if (right - left + 1) < (r - l + 1) {
                        (left, right)
                    } else {
                        (l, r)
                    })
                });
                current_window.get_mut(&s_chars[left]).map(|count| {
                    *count -= 1;
                    if *count < *targets.get(&s_chars[left]).unwrap_or(&0) {
                        letters_satisfied -= 1;
                    }
                });
                left += 1;
            }
        });

        match best_window {
            None => "",
            Some((l, r)) => std::str::from_utf8(&s_chars[l..r + 1]).unwrap(),
        }
        .to_string()
    }
}


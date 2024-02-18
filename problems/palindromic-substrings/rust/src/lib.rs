pub struct Solution;

impl Solution {
    pub fn count_substrings(s: String) -> i32 {
        let bytes = s.into_bytes();
        (0..bytes.len())
            .map(|i| {
                let odd = expand_and_count(i, i, &bytes);
                let even = expand_and_count(i, i + 1, &bytes);
                odd + even
            })
            .sum::<usize>() as i32
    }
}

fn expand_and_count(left: usize, right: usize, chars: &[u8]) -> usize {
    (0..=left)
        .rev()
        .zip(right..chars.len())
        .try_fold(0, |acc, (l, r)| {
            if chars[l] == chars[r] {
                Ok(acc + 1)
            } else {
                Err(acc)
            }
        })
        .unwrap_or_else(|count| count)
}

pub struct Solution;

impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let mut max_length = 0;
        let mut counts = vec![0; 26];
        let mut window_start = 0;
        let letters = s.chars().collect::<Vec<_>>();
        for (window_end, c) in letters.iter().enumerate() {
            counts[char_index(*c)] += 1;
            let window_length = get_window_length(window_start, window_end);
            if window_length - counts.iter().max().unwrap() > k as usize {
                counts[char_index(letters[window_start])] -= 1;
                window_start += 1;
            } else {
                max_length = max_length.max(window_length);
            }
        }
        max_length as i32
    }
}

fn char_index(c: char) -> usize {
    c as usize - 'A' as usize
}

fn get_window_length(start: usize, end: usize) -> usize {
    end - start + 1
}

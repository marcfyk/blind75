pub struct Solution;

impl Solution {
    pub fn is_valid(s: String) -> bool {
        const PAREN_OPEN: char = '(';
        const PAREN_CLOSE: char = ')';
        const BRACKET_OPEN: char = '[';
        const BRACKET_CLOSE: char = ']';
        const BRACE_OPEN: char = '{';
        const BRACE_CLOSE: char = '}';

        let mut stack = Vec::with_capacity(s.len());
        for c in s.chars() {
            match c {
                PAREN_OPEN | BRACKET_OPEN | BRACE_OPEN => {
                    stack.push(c);
                }
                _ => {
                    let matching = match c {
                        PAREN_CLOSE => PAREN_OPEN,
                        BRACKET_CLOSE => BRACKET_OPEN,
                        BRACE_CLOSE => BRACE_OPEN,
                        _ => return false,
                    };
                    match stack.pop() {
                        None => {
                            return false;
                        }
                        Some(x) => {
                            if x != matching {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        stack.is_empty()
    }
}


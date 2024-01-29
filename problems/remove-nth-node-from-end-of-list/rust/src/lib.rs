#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub struct Solution;

impl Solution {
    pub fn remove_nth_from_end(mut head: Option<Box<ListNode>>, n: i32) -> Option<Box<ListNode>> {
        if let None = head {
            return None;
        }
        let size = get_list_size(&head);
        let m = size - n as usize;
        if m == 0 {
            return head.unwrap().next;
        }
        let mut node = &mut head;
        for _ in 0..m - 1 {
            if let Some(n) = node {
                node = &mut n.next;
            }
        }
        if let Some(n) = node {
            if let Some(next_n) = n.next.take() {
                n.next = next_n.next;
            }
        }
        head
    }
}

fn get_list_size(head: &Option<Box<ListNode>>) -> usize {
    let mut count = 0;
    let mut node = head;
    while let Some(n) = node {
        count += 1;
        node = &n.next;
    }
    count
}


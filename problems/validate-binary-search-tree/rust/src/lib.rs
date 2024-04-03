use std::cell::RefCell;
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

pub struct Solution;

impl Solution {
    pub fn is_valid_bst(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        validate(root, i32::MIN, i32::MAX)
    }
}

fn validate(node: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> bool {
    if let None = node {
        return true;
    }
    if low > high {
        return false;
    }
    let n = node.unwrap();
    let val = n.borrow().val;
    let left = if val == i32::MIN { n.borrow().left.is_none() } else {
        validate(n.borrow().left.clone(), low, val - 1)
    };
    let right = if val == i32::MAX { n.borrow().right.is_none() } else {
        validate(n.borrow().right.clone(), val + 1, high)
    };
    low <= val && val <= high && left && right
}

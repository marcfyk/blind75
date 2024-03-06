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
    pub fn invert_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        if let None = root {
            return None;
        }
        let n = root.as_ref().unwrap();
        let left = Self::invert_tree(n.borrow().left.clone());
        let right = Self::invert_tree(n.borrow().right.clone());
        Some(Rc::new(RefCell::new(TreeNode {
            val: n.borrow().val,
            left: right,
            right: left,
        })))
    }
}

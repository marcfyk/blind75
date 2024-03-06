#include <vector>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
      return root;
    }
    std::vector<TreeNode *> stack{root};
    while (!stack.empty()) {
      const auto n = stack.back();
      stack.pop_back();
      const auto tmp = n->left;
      n->left = n->right;
      n->right = tmp;
      if (n->left != nullptr) {
        stack.push_back(n->left);
      }
      if (n->right != nullptr) {
        stack.push_back(n->right);
      }
    }
    return root;
  }
};

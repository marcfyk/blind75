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
  bool isValidBST(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    auto n = root;
    std::vector<TreeNode *> stack, nodes;
    while (n != nullptr || !stack.empty()) {
      while (n != nullptr) {
        stack.push_back(n);
        n = n->left;
      }
      n = stack.back();
      stack.pop_back();
      if (!nodes.empty() && nodes.back()->val >= n->val) {
        return false;
      }
      nodes.push_back(n);
      n = n->right;
    }
    return true;
  }
};

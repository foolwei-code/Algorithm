// 求二叉树的最大、最小深度
// 测试链接 : https://leetcode.cn/problems/maximum-depth-of-binary-tree/
// 测试链接 : https://leetcode.cn/problems/minimum-depth-of-binary-tree/
#include <iostream>
#include <limits>
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
  int maxDepth(TreeNode *root) { return f(root); }
  int f(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return std::max(f(root->left), f(root->right)) + 1;
  }
  int minDepth(TreeNode *root) {
    if (root == nullptr)
      return 0;
    return f2(root);
  }
  int f2(TreeNode *root) {
    if (root->left == nullptr && root->right == nullptr)
      return 1;
    int res1 = std::numeric_limits<int>::max();
    int res2 = std::numeric_limits<int>::max();
    if (root->left != nullptr)
      res1 = f2(root->left);
    if (root->right != nullptr)
      res2 = f2(root->right);
    return std::min(res1, res2) + 1;
  }
};

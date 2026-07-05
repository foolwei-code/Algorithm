// 验证完全二叉树
// 测试链接 : https://leetcode.cn/problems/check-completeness-of-a-binary-tree/
#include <queue>
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
  bool isCompleteTree(TreeNode *root) {
    if (root == nullptr)
      return true;
    leaf = false;
    queue.push(root);
    while (!queue.empty()) {
      TreeNode *front = queue.front();
      queue.pop();
      if ((front->left == nullptr && front->right != nullptr) ||
          (leaf && (front->left != nullptr || front->right != nullptr)))
        return false;
      if (front->left != nullptr)
        queue.push(front->left);
      if (front->right != nullptr)
        queue.push(front->right);
      if (front->left == nullptr||front->right==nullptr)
        leaf = true;
    }
    return true;
  }

private:
  std::queue<TreeNode *> queue;
  bool leaf;
};
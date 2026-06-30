// 二叉树的层序遍历
// 测试链接 : https://leetcode.cn/problems/binary-tree-level-order-traversal/
#include <queue>
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
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> ans;
    if (root == nullptr)
      return ans;
    queue.push(root);
    while (!queue.empty()) {
      std::vector<int> nodes;
      int size = queue.size();
      for (int i = 0; i < size; i++) {
        TreeNode *front = queue.front();
        queue.pop();
        if (front->left != nullptr)
          queue.push(front->left);
        if (front->right != nullptr)
          queue.push(front->right);
        nodes.emplace_back(front->val);
      }
      ans.emplace_back(nodes);
    }
    return ans;
  }

private:
  std::queue<TreeNode *> queue;
};

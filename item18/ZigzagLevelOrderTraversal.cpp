// 二叉树的锯齿形层序遍历
// 测试链接 :
// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
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
  Solution() {
    queue.resize(2005);
    l = r = 0;
  }
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    std::vector<std::vector<int>> ans;
    if (root == nullptr)
      return ans;
    reverse = false;
    queue[r++] = root;
    while (l != r) {
      int size = r - l;
      std::vector<int> nodes;
      if (!reverse) {
        // 正常遍历
        for (int i = l; i < r; i++) {
          nodes.emplace_back(queue[i]->val);
        }
      } else {
        // 倒序遍历
        for (int i = r - 1; i >= l; i--) {
          nodes.emplace_back(queue[i]->val);
        }
      }
      reverse = !reverse;
      ans.emplace_back(nodes);
      // 正序添加子孩子
      for (int i = 0; i < size; i++) {
        TreeNode *front = queue[l++];
        if (front->left != nullptr)
          queue[r++] = front->left;
        if (front->right != nullptr)
          queue[r++] = front->right;
      }
    }
    return ans;
  }

private:
  bool reverse;
  std::vector<TreeNode *> queue;
  int l;
  int r;
};
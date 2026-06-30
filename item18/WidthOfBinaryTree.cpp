// 二叉树的最大特殊宽度
// 测试链接 : https://leetcode.cn/problems/maximum-width-of-binary-tree/
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
    trees.resize(3005);
    ids.resize(3005);
    l = r = 0;
  }
  int widthOfBinaryTree(TreeNode *root) {
    if (root == nullptr)
      return 0;
    trees[r] = root;
    ids[r++] = 0;
    unsigned long long ans = 1;
    while (l < r) {
      ans = std::max(ans, ids[r - 1] - ids[l] + 1);
      int size = r - l;
      for (int i = 0; i < size; i++) {
        TreeNode *front = trees[l];
        unsigned long long frontId = ids[l++];
        if (front->left != nullptr) {
          trees[r] = front->left;
          ids[r++] = frontId * 2;
        }
        if (front->right != nullptr) {
          trees[r] = front->right;
          ids[r++] = frontId * 2 + 1;
        }
      }
    }
    return ans;
  }
  std::vector<TreeNode *> trees;
  std::vector<unsigned long long> ids;
  int l;
  int r;
};

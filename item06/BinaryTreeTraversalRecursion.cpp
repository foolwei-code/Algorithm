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
// 二叉树的先序遍历
//  https://leetcode.cn/problems/binary-tree-preorder-traversal/description/
class Solution1 {
public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> ans;
    f(ans, root);
    return ans;
  }
  void f(std::vector<int> &ans, TreeNode *root) {
    if (root == nullptr)
      return;
    ans.emplace_back(root->val);
    f(ans, root->left);
    f(ans, root->right);
  }
};
// 二叉树的中序遍历
// https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
class Solution2 {
public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> ans;
    f(ans, root);
    return ans;
  }
  void f(std::vector<int> &ans, TreeNode *root) {
    if (root == nullptr)
      return;
    f(ans, root->left);
    ans.emplace_back(root->val);
    f(ans, root->right);
  }
};

// 二叉树的后序遍历
// https://leetcode.cn/problems/binary-tree-postorder-traversal/
class Solution3 {
public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> ans;
    f(ans, root);
    return ans;
  }
  void f(std::vector<int> &ans, TreeNode *root) {
    if (root == nullptr)
      return;
    f(ans, root->left);
    f(ans, root->right);
    ans.emplace_back(root->val);
  }
};
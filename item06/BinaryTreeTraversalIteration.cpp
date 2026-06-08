#include <stack>
#include <unordered_set>
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
class Solution1 {
public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> ans;
    if (root == nullptr)
      return ans;
    stack.push(root);
    while (!stack.empty()) {
      TreeNode *top = stack.top();
      stack.pop();
      ans.emplace_back(top->val);
      if (top->right != nullptr)
        stack.push(top->right);
      if (top->left != nullptr)
        stack.push(top->left);
    }
    return ans;
  }

private:
  std::stack<TreeNode *> stack;
};

class Solution2 {
public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> ans;
    if (root == nullptr)
      return ans;
    stack.push(root);
    while (!stack.empty()) {
      TreeNode *top = stack.top();
      while (top->left != nullptr && !set.count(top->left)) {
        stack.push(top->left);
        set.insert(top->left);
        top = stack.top();
      }
      ans.emplace_back(top->val);
      stack.pop();
      if (top->right != nullptr)
        stack.push(top->right);
    }
    return ans;
  }

private:
  std::stack<TreeNode *> stack;
  std::unordered_set<TreeNode *> set;
};

class Solution {
public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> ans;
    if (root == nullptr)
      return ans;
    stack.push(root);
    while (!stack.empty()) {
      TreeNode *top = stack.top();
      if (f(top, set)) {
        ans.emplace_back(top->val);
        stack.pop();
        continue;
      }
      while (top->left != nullptr && !set.count(top->left)) {
        stack.push(top->left);
        set.insert(top->left);
        top = top->left;
      }

      if (top->right != nullptr && !set.count(top->right)) {
        stack.push(top->right);
        set.insert(top->right);
      }
    }
    return ans;
  }
  bool f(TreeNode *root, std::unordered_set<TreeNode *> &set) {
    if (root->left == nullptr && root->right == nullptr)
      return true;
    if (root->left == nullptr && set.count(root->right))
      return true;
    if (set.count(root->left) && root->right == nullptr)
      return true;
    if (set.count(root->left) && set.count(root->right))
      return true;
    return false;
  }

private:
  std::stack<TreeNode *> stack;
  std::unordered_set<TreeNode *> set;
};
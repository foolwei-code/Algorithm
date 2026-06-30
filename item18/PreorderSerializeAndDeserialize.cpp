// 二叉树先序序列化和反序列化
// 测试链接 :
// https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
#include <string>
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

class Codec {
public:
  // Encodes a tree to a single string.
  std::string serialize(TreeNode *root) {
    std::string ans;
    if (root == nullptr)
      return ans;
    f(ans, root);
    return ans;
  }
  void f(std::string &ans, TreeNode *root) {
    if (root == nullptr) {
      ans += "#,";
      return;
    }
    ans += std::to_string(root->val) + ",";
    f(ans, root->left);
    f(ans, root->right);
  }
  // Decodes your encoded data to tree.
  TreeNode *deserialize(std::string data) {
    if (data == "")
      return nullptr;
    where = 0;
    std::vector<std::string> strs;
    for (int i = 0; i < data.size(); i++) {
      std::string str;
      while (data[i] != ',') {
        str.push_back(data[i]);
        i++;
      }
      strs.push_back(str);
    }
    return g(strs);
  }
  TreeNode *g(std::vector<std::string> &data) {
    if (data[where] == "#")
      return nullptr;
    TreeNode *root = new TreeNode{std::stoi(data[where])};
    where++;
    root->left = g(data);
    where++;
    root->right = g(data);
    return root;
  }

private:
  int where;
};
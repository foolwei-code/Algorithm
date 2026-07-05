// 利用先序与中序遍历序列构造二叉树
// 测试链接 :
// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include <pthread.h>
#include <vector>
#include<unordered_map>
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
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); i++)
      hashMap.insert({inorder[i],i});
    if (preorder.empty() && inorder.empty())
      return nullptr;
    return f(0, preorder.size() - 1, preorder, 0, inorder.size() - 1, inorder);
  }
  TreeNode *f(int l1, int r1, std::vector<int> &preorder, int l2, int r2,
              std::vector<int> &inorder) {
    if (l1 > r1)
      return nullptr;
    if (l1 == r1)
      return new TreeNode(preorder[l1]);
    TreeNode *head = new TreeNode(preorder[l1]);
    int k = hashMap[preorder[l1]];
    head->left = f(l1 + 1, l1 + k - l2, preorder, l2, k - 1, inorder);
    head->right = f(l1 + k - l2 + 1, r1,preorder, k + 1, l2, inorder);
    return head;
  }
private:
  std::unordered_map<int, int>hashMap;
};

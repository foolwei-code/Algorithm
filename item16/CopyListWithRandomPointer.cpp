// 复制带随机指针的链表
// 测试链接 : https://leetcode.cn/problems/copy-list-with-random-pointer/
#include <unordered_map>
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};
class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr)
      return head;
    bool flag = false;
    Node *cur = head;
    Node *pre = nullptr, *copyHead = nullptr;
    while (cur != nullptr) {
      Node *node = new Node(cur->val);
      if (!flag) {
        pre = node;
        copyHead = node;
        flag = true;
      } else {
        pre->next = node;
        pre = node;
      }
      hashMap.insert({cur, node});
      cur = cur->next;
    }
    cur = head;
    Node *copyCur = copyHead;
    while (cur != nullptr) {
      Node *copyRandom = hashMap[cur->random];
      copyCur->random = copyRandom;
      cur = cur->next;
      copyCur = copyCur->next;
    }
    return copyHead;
  }

private:
  std::unordered_map<Node *, Node *> hashMap;
};

// 反转单链表
//测试链接:https://leetcode.cn/problems/reverse-linked-list/
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode* reverseList(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *pre = nullptr, *cur = head;
    while (cur != nullptr) {
      ListNode *temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur=temp;
    }
    return pre;
  }
};

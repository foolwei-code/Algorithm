// 判断链表是否是回文结构
// 测试链接 : https://leetcode.cn/problems/palindrome-linked-list/
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return true;
    if (head->next->next == nullptr) {
      if (head->val == (head->next)->val)
        return true;
      return false;
    }
    ListNode *slow = head, *fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    // 将slow后面的节点全部逆序
    ListNode *pre = slow, *cur = slow->next;
    //将中点的指针指向nullptr
    pre->next = nullptr;
    while (cur != nullptr) {
      ListNode *temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }
    slow = head, fast = pre;
    while (slow != nullptr && fast != nullptr) {
      if (slow->val != fast->val)
        return false;
      slow = slow->next;
      fast = fast->next;
    }
    return true;
  }
};

// 返回链表的第一个入环节点
// 测试链接 : https://leetcode.cn/problems/linked-list-cycle-ii/

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return nullptr;
    ListNode *slow = head->next, *fast = head->next->next;
    while (fast != nullptr && fast != slow) {
      slow = slow->next;
      fast = fast->next == nullptr ? nullptr : fast->next->next;
    }
    if (fast == nullptr)
      return nullptr;
    // 一定有环
    fast = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};
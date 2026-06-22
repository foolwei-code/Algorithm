// 每k个节点一组翻转链表
// 测试链接：https://leetcode.cn/problems/reverse-nodes-in-k-group/
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (head == nullptr)
      return head;
    // 先处理第一批节点，因为涉及到换头操作
    ListNode *cur = head;
    int cnt = 0;
    // 先判断一下是否够k个
    while (cur != nullptr) {
      cnt++;
      cur = cur->next;
    }
    if (cnt < k)
      return head;
    cur = head;
    ListNode *pre = nullptr;
    for (int i = 0; i < k; i++) {
      ListNode *temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }
    head->next = cur;
    ListNode *lastHead = cur, *lastTail = head;
    head = pre;
    while (cur != nullptr) {
      // 先判断个数够不够
      ListNode *res = cur;
      cnt = 0;
      while (cur != nullptr) {
        cnt++;
        cur = cur->next;
      }
      if (cnt < k)
        return head;
      cur = res;
      for (int i = 0; i < k; i++) {
        ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
      }
      lastHead->next = cur;
      lastTail->next = pre;
      lastTail = lastHead;
      lastHead = cur;
      pre = nullptr;
    }
    return head;
  }
};

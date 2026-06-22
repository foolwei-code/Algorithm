// 返回两个无环链表相交的第一个节点
// 测试链接 : https://leetcode.cn/problems/intersection-of-two-linked-lists/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr)
      return nullptr;
    int countA = 0, countB = 0;
    ListNode *curA = headA, *curB = headB, *ans = nullptr;
    while (curA != nullptr) {
      countA++;
      curA = curA->next;
    }
    while (curB != nullptr) {
      countB++;
      curB = curB->next;
    }
    curA = headA, curB = headB;
    if (countA >= countB) {
      int step = countA - countB;
      for (int i = 0; i < step; i++) {
        curA = curA->next;
      }
      while (curA != nullptr && curB != nullptr && (curA != curB)) {
        curA = curA->next;
        curB = curB->next;
      }
      if (curA == nullptr || curB == nullptr)
        ans = nullptr;
      else
        ans = curA;
    } else {
      int step = countB - countA;
      for (int i = 0; i < step; i++) {
        curB = curB->next;
      }
      while (curA != nullptr && curB != nullptr && (curA != curB)) {
        curA = curA->next;
        curB = curB->next;
      }
      if (curA == nullptr || curB == nullptr)
        ans = nullptr;
      else
        ans = curA;
    }
    return ans;
  }
};

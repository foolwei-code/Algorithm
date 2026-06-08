// 将两个升序链表合并为一个新的 升序 链表并返回
// 新链表是通过拼接给定的两个链表的所有节点组成的
// 测试链接 : https://leetcode.cn/problems/merge-two-sorted-lists/
#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr || list2 == nullptr) {
      return (list1 == nullptr) ? list2 : list1;
    }
    if (list1->val > list2->val) {
      std::swap(list1, list2);
    }
    ListNode *head = list1, *cur = list1;
    list1 = list1->next;
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        cur->next = list1;
        cur = cur->next;
        list1 = list1->next;
      } else {
        cur->next = list2;
        cur = cur->next;
        list2 = list2->next;
      }
    }
    if (list1 != nullptr)
      cur->next = list1;
    if (list2 != nullptr)
      cur->next = list2;
    return head;
  }
};
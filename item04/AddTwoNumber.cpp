// 给你两个 非空 的链表，表示两个非负的整数
// 它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字
// 请你将两个数相加，并以相同形式返回一个表示和的链表。
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头
// 测试链接：https://leetcode.cn/problems/add-two-numbers/
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = nullptr, *cur = nullptr;
    int number = 0, carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
      number = ((l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) +
                carry);
      carry = number / 10;
      ListNode *temp = new ListNode{number % 10};
      if (head == nullptr)
        head = temp, cur = temp;
      else {
        cur->next = temp;
        cur = cur->next;
      }
      l1 = l1 == nullptr ? nullptr : l1->next;
      l2 = l2 == nullptr ? nullptr : l2->next;
    }
    if (carry) {
      ListNode *temp = new ListNode{1};
      cur->next = temp;
    }
    return head;
  }
};
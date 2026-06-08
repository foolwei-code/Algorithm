// 给你一个链表的头节点 head 和一个特定值 x
// 请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
// 你应当 保留 两个分区中每个节点的初始相对位置
// 测试链接 : https://leetcode.cn/problems/partition-list/
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    if (head == nullptr)
      return head;
    ListNode *smallHead = nullptr, *smallTail = nullptr;
    ListNode *bigHead = nullptr, *bigTail = nullptr;
    // 将小于x的挂到small上，大于等于x的挂在big上
    while (head != nullptr) {
      if (head->val < x) {
        if (smallHead == nullptr) {
          smallHead = smallTail = head;
        } else {
          smallTail->next = head;
          smallTail = smallTail->next;
        }
      } else {
        if (bigHead == nullptr) {
          bigHead = bigTail = head;
        } else {
          bigTail->next = head;
          bigTail = bigTail->next;
        }
      }
      head = head->next;
    }
    // 如果small为空
    if (smallHead == nullptr)
      return bigHead;
    // 如果big为空
    if (bigHead == nullptr)
      return smallHead;
    // 将smallTal与bigHead对接，并且将bigTail->next=nullptr
    smallTail->next = bigHead;
    bigTail->next = nullptr;
    return smallHead;
  }
};
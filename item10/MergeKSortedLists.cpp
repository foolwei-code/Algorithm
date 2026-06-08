// 合并K个有序链表
// 测试链接：https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6
#include <queue>
#include <vector>
struct ListNode {
  int val;
  struct ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    // write code here
    for (auto &elem : lists)
      if (elem != nullptr)
        heap.push(elem);
    ListNode *head = nullptr, *cur = nullptr;
    while (!heap.empty()) {
      ListNode *top = heap.top();
      heap.pop();
      if (top->next != nullptr)
        heap.push(top->next);
      if (head == nullptr) {
        head = cur = top;
      } else {
        cur->next = top;
        cur = cur->next;
      }
    }
    return head;
  }

private:
  struct cmp {
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
  };
  std::priority_queue<ListNode *, std::vector<ListNode *>, cmp> heap;
};
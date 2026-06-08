// 用栈实现队列
// 测试链接 : https://leetcode.cn/problems/implement-queue-using-stacks/
#include <queue>
#include <stack>
class MyQueue {
public:
  MyQueue() {}

  void push(int x) { stack1.push(x); }

  int pop() {
    if (stack2.empty()) {
      while (!stack1.empty()) {
        int top = stack1.top();
        stack1.pop();
        stack2.push(top);
      }
    }
    int top = stack2.top();
    stack2.pop();
    return top;
  }

  int peek() {
    if (stack2.empty()) {
      while (!stack1.empty()) {
        int top = stack1.top();
        stack1.pop();
        stack2.push(top);
      }
    }
    return stack2.top();
  }

  bool empty() { return stack1.empty() && stack2.empty(); }

private:
  std::stack<int> stack1;
  std::stack<int> stack2;
};

class MyStack {
public:
  MyStack() {}

  void push(int x) {
    queue.push(x);
    for (int i = 0; i < queue.size() - 1; i++) {
      int front = queue.front();
      queue.pop();
      queue.push(front);
    }
  }

  int pop() {
    int front = top();
    queue.pop();
    return front;
  }

  int top() {
    return queue.front();
  }

  bool empty() { return queue.empty(); }

private:
  std::queue<int> queue;
};
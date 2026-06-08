// 最小栈
// 测试链接 : https://leetcode.cn/problems/min-stack/
#include <stack>
class MinStack {
public:
  MinStack() {}

  void push(int value) {
    stack1.push(value);
    if (stack2.empty()) {
      stack2.push(value);
    } else {
      int top = stack2.top();
      if (value < top)
        stack2.push(value);
      else
        stack2.push(top);
    }
  }

  void pop() {
    stack1.pop();
    stack2.pop();
  }

  int top() { return stack1.top(); }

  int getMin() { return stack2.top(); }

private:
  std::stack<int> stack1;
  std::stack<int> stack2;
};
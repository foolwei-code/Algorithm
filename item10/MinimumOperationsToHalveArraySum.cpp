// 将数组和减半的最少操作次数
// 测试链接 :
// https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/
#include <queue>
#include <vector>
class Solution {
public:
  int halveArray(std::vector<int> &nums) {
    double sum = 0;
    double target = 0;
    for (auto elem : nums) {
      heap.push(elem);
      sum += elem;
    }
    target = (double)sum / 2;
    int ans = 0;
    while (sum > target) {
      double top = heap.top();
      heap.pop();
      top /= 2;
      sum -= top;
      ans++;
      heap.push(top);
    }
    return ans;
  }

private:
  std::priority_queue<double> heap;
};
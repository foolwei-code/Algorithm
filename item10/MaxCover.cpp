// 最多线段重合问题
// 测试链接 : https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37
// 测试链接 : https://leetcode.cn/problems/meeting-rooms-ii/
//可以使用heap,可以用差分，可以用线段树，树状数组，扫描线
#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>
struct cmp {
  bool operator()(int a, int b) { return a > b; }
};
const int N = 1e4 + 5;
std::array<std::array<int, 2>, N> lines;
std::priority_queue<int, std::vector<int>, cmp> heap;
int n;
uint64_t ans;
int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> lines[i][0] >> lines[i][1];
  }
  std::sort(
      lines.begin(), lines.begin()+n,
      [](std::array<int, 2> &a, std::array<int, 2> &b) { return a[0] < b[0]; });
  for (int i = 0; i < n; i++) {
    while (!heap.empty() && lines[i][0] >= heap.top())
      heap.pop();
    heap.push(lines[i][1]);
    ans = std::max(ans, heap.size());
  }
  std::cout << ans << std::endl;
}
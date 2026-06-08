// 随机快速排序，acm练习风格
// 测试链接 : https://www.luogu.com.cn/problem/P1177
#include <array>
#include <ctime>
#include <iostream>
#include <random>
const int N = 1e5 + 5;
std::array<int, N> nums;
std::mt19937 mt{static_cast<unsigned>(std::time(nullptr))};
int n;
void quickSort(int l, int r) {
  if (l >= r)
    return;
  std::uniform_int_distribution<int> dist(l, r);
  int value = nums[dist(mt)];
  int first = l, last = r, cur = l;
  while (cur <= last) {
    if (nums[cur] < value)
      std::swap(nums[cur++], nums[first++]);
    else if (nums[cur] == value) {
      cur++;
    } else {
      std::swap(nums[cur], nums[last--]);
    }
  }
  quickSort(l, first - 1);
  quickSort(last + 1, r);
}
int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> nums[i];
  quickSort(0, n - 1);
  for (int i = 0; i < n; i++)
    std::cout << nums[i] << " ";
  std::cout << std::endl;
}
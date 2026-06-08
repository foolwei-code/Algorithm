// 堆结构和堆排序，acm练习风格
// 测试链接 : https://www.luogu.com.cn/problem/P1177
#include <array>
#include <iostream>
const int N = 1e5 + 5;
std::array<int, N> nums;
int n, size, number;
void heapInsert(int val) {
  nums[size++] = val;
  int i = size - 1;
  while (nums[(i - 1) / 2] < nums[i]) {
    std::swap(nums[(i - 1) / 2], nums[i]);
    i = (i - 1) / 2;
  }
}
void heapify() {
  int i = 0;
  while ((2 * i + 1) < size) {
    int val = nums[i];
    int best = (2 * i + 2) < size && nums[2 * i + 2] > nums[2 * i + 1]
                   ? nums[2 * i + 2]
                   : nums[2 * i + 1];
    if (val < best) {
      if (best == nums[2 * i + 1]) {
        std::swap(nums[i], nums[2 * i + 1]);
        i = 2 * i + 1;
      } else {
        std::swap(nums[i], nums[2 * i + 2]);
        i = 2 * i + 2;
      }
    } else {
      break;
    }
  }
}
int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> number;
    heapInsert(number);
  }
  while (size > 0) {
    std::swap(nums[0], nums[size - 1]);
    size--;
    heapify();
  }
  for (int i = 0; i < n; i++)
    std::cout << nums[i] << " ";
  std::cout << std::endl;
}
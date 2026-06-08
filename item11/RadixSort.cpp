#include <array>
#include <iostream>
#include <limits>
const int N = 1e5 + 5;
const int BASE = 10;
std::array<int, N> nums;
std::array<int, N> help;
std::array<int, BASE> cnt;
int n;
int maxValue = std::numeric_limits<int>::min();
int minValue = std::numeric_limits<int>::max();
int getBits(int num) {
  if (num == 0)
    return 0;
  int ans = 0;
  while (num != 0) {
    ans++;
    num /= 10;
  }
  return ans;
}
void radixSort(int counts) {
  for (int k = 0, offset = 1; k < counts; k++, offset *= BASE) {
    cnt.fill(0);
    for (int i = 0; i < n; i++) {
      cnt[(nums[i] / offset) % BASE]++;
    }
    for (int i = 1; i < BASE; i++) {
      cnt[i] += cnt[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
      help[--cnt[(nums[i] / offset) % BASE]] = nums[i];
    }
    for (int i = 0; i < n; i++) {
      nums[i] = help[i];
    }
  }
}
int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
    maxValue = std::max(maxValue, nums[i]);
    minValue = std::min(minValue, nums[i]);
  }
  // 将数组中的所有数变成非负数
  for (int i = 0; i < n; i++)
    nums[i] -= minValue;
  maxValue -= minValue;
  // 获取maxValue在BASE进制下的位数，以确定循环的次数
  radixSort(getBits(maxValue));
  // 恢复原数组
  for (int i = 0; i < n; i++)
    nums[i] += minValue;
  for (int i = 0; i < n; i++) {
    std::cout << nums[i] << " ";
  }
  std::cout << std::endl;
}

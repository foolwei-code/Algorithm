#include <array>
#include <iostream>
const int N = 1e5 + 5;
std::array<int, N> nums;
std::array<int, N> help;
int n;
void merge(int l, int mid, int r) {
  int left = l, right = mid + 1, k = l;
  while (left <= mid && right <= r) {
    if (nums[left] <= nums[right])
      help[k++] = nums[left++];
    else
      help[k++] = nums[right++];
  }
  while (left <= mid)
    help[k++] = nums[left++];
  while (right <= r)
    help[k++] = nums[right++];
  for (int i = l; i <= r; i++)
    nums[i] = help[i];
}
int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> nums[i];
  int l = 0, r = 0;
  for (int step = 1; step < n; step <<= 1) {
    l = 0;
    while (l < n) {
      int m = l + step - 1;
      if (m + 1 >= n)
        break;
      r = std::min(l + (step << 1) - 1, n - 1);
      merge(l, m, r);
      l = r + 1;
    }
  }
  for (int i = 0; i < n; i++)
    std::cout << nums[i] << " ";
  std::cout << std::endl;
}
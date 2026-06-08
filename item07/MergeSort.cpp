#include <array>
#include <iostream>
const int N = 1e5 + 5;
std::array<int, N> nums;
std::array<int, N> help;
int n;
void mergeSort(int l, int r) {
  if (l >= r)
    return;
  int mid = l + ((r - l) >> 1);
  mergeSort(l, mid);
  mergeSort(mid + 1, r);
  int left = l, right = mid + 1, k = l;
  while (left <= mid && right <= r) {
    if (nums[left] <= nums[right]) {
      help[k++] = nums[left++];
    } else {
      help[k++] = nums[right++];
    }
  }
  while (left <= mid)
    help[k++] = nums[left++];
  while (right <= r)
    help[k++] = nums[right++];
  for (int i = l; i <= r; i++) {
    nums[i] = help[i];
  }
}
int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> nums[i];
  mergeSort(0, n - 1);
  for (int i = 0; i < n; i++)
    std::cout << nums[i] << " ";
  std::cout << std::endl;
}
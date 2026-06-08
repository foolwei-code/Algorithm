#include <array>
// 有序数组中找>=num的最左位置
const int N = 10;
std::array<int, N> arr;
int BinarySearch(std::array<int, N> &arr, int num) {
  int l = 0, r = arr.size() - 1;
  int ans = -1;
  while (l <= r) {
    int mid = l + ((r - l) >> 1);
    if (arr[mid] >= num) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return ans;
}
int StandardSearch(std::array<int, N> &arr, int num) {
  int ans = -1;
  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] >= num) {
      ans = i;
      break;
    }
  }
  return ans;
}
int main() {}
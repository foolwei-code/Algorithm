#include <array>
#include <random>
#include<ctime>
const int N = 10;
std::array<int, N> arr;
// 有序数组中是否存在一个数字
bool BinarySearch(std::array<int, N> &arr,int num) {
  int l = 0, r = arr.size() - 1;
  while (l <= r) {
    int mid = (l + ((r - l) >> 1));
    if (arr[mid] == num)
      return true;
    else if (arr[mid] > num) {
      r=mid-1;
    } else {
      l=mid+1;
    }
  }
  return false;
}
bool StandardSearch(std::array<int, N> &arr, int num) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == num)
      return true;
  }
  return false;
}
int main() {
  std::mt19937 mt(static_cast<unsigned>(std::time(nullptr)));
  std::uniform_int_distribution<int> dist(0, 99);
  for (int i = 0; i < 10; i++) {
    arr[i]=dist(mt);
  }
  int number = dist(mt);
  std::sort(arr.begin(), arr.end());
  
}
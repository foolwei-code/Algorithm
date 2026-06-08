// 无序数组中第K大的元素
// 测试链接 : https://leetcode.cn/problems/kth-largest-element-in-an-array/
#include <ctime>
#include <random>
#include <vector>
class Solution {
public:
  int findKthLargest(std::vector<int> &nums, int k) {
    int n = nums.size();
    quickSort(nums, 0, n - 1, k, n);
    return ans;
  }
  void quickSort(std::vector<int> &nums, int l, int r, int num, int n) {
    if (l > r)
      return;
    if (l == r) {
      ans = nums[l];
      return;
    }
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
    if (n - num >= first && n - num <= last) {
      ans = nums[first];
      return;
    } else if (n - num < first) {
      quickSort(nums, l, first - 1, num, n);
    } else {
      quickSort(nums,last+1,r, num, n);
    }
  }

private:
  std::mt19937 mt{static_cast<unsigned>(std::time(nullptr))};
  int ans;
};
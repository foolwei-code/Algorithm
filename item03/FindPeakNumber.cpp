// 测试链接 : https://leetcode.cn/problems/find-peak-element/
#include <vector>
class Solution {
public:
  int findPeakElement(std::vector<int> &nums) {
    // 1.先排除第一个元素和最后一个元素
    if (nums.size() == 1)
      return 0;
    int n = nums.size();
    if (nums[0] > nums[1])
      return 0;
    if (nums[n - 1] > nums[n - 2])
      return n - 1;
    int l = 1, r = n - 2;
    int ans = -1;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (nums[mid] > nums[mid + 1] && nums[mid] < nums[mid - 1]) {
        r = mid - 1;
      } else if (nums[mid] < nums[mid + 1] && nums[mid - 1] < nums[mid]) {
        l = mid + 1;
      } else if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
        ans = mid;
        break;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  }
};
int main() {}

// 翻转对数量
// 测试链接 : https://leetcode.cn/problems/reverse-pairs/
#include <vector>
class Solution {
public:
  int reversePairs(std::vector<int> &nums) {
    int n = nums.size();
    help.resize(n);
    return counts(0, n - 1, nums);
  }
  int counts(int l, int r, std::vector<int> &nums) {
    if (l == r)
      return 0;
    int mid = l + ((r - l) >> 1);
    return counts(l, mid, nums) + counts(mid + 1, r, nums) +
           merge(l, r, mid, nums);
  }
  int merge(int l, int r, int mid, std::vector<int> &nums) {
    int ans = 0;
    for (int i = l, j = mid + 1; i <= mid; i++) {
      while (j <= r && (long long)nums[i] > (long long)2 * nums[j])
        j++;
      ans += j - mid - 1;
    }
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
    return ans;
  }

private:
  std::vector<int> help;
};
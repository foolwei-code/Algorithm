// 数组中1种数出现了奇数次，其他的数都出现了偶数次
// 返回出现了奇数次的数
// 测试链接 : https://leetcode.cn/problems/single-number/
#include <vector>
class Solution {
public:
  int singleNumber(std::vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      ans ^= nums[i];
    }
    return ans;
  }
};

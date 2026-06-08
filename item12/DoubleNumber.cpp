#include <vector>
// 数组中有2种数出现了奇数次，其他的数都出现了偶数次
// 返回这2种出现了奇数次的数
// 测试链接 : https://leetcode.cn/problems/single-number-iii/
class Solution {
public:
  std::vector<int> singleNumber(std::vector<int> &nums) {
    std::vector<int> ans;
    long long res = 0;
    for (int i = 0; i < nums.size(); i++)
      res ^= nums[i];
    long long num = lowbit(res);
    int number = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (num & nums[i]) {
        number ^= nums[i];
      }
    }
    ans.emplace_back(number);
    ans.emplace_back(res ^ number);
    return ans;
  }
  long long lowbit(long long num) { return num & (-num); }
};
// 找到缺失的数字
// 测试链接 : https://leetcode.cn/problems/missing-number/
#include <vector>
class Solution {
public:
  int missingNumber(std::vector<int> &nums) {
    int n = nums.size();
    int number1 = 0, number2 = 0;
    for (int i = 0; i <= n; i++)
      number1 ^= i;
    for (int i = 0; i < n; i++)
      number2 ^= nums[i];
    return number1 ^ number2;
  }
};
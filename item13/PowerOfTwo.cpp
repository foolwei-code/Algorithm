// Brian Kernighan算法
// 提取出二进制里最右侧的1
// 判断一个整数是不是2的幂
// 测试链接 : https://leetcode.cn/problems/power-of-two/
class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n <= 0)
      return false;
    return n == lowbit(n);
  }
  int lowbit(int n) { return n & (-n); }
};
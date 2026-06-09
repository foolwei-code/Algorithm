// 位图的实现
// Bitset是一种能以紧凑形式存储位的数据结构
// Bitset(int n) : 初始化n个位，所有位都是0
// void fix(int i) : 将下标i的位上的值更新为1
// void unfix(int i) : 将下标i的位上的值更新为0
// void flip() : 翻转所有位的值
// bool all() : 是否所有位都是1
// bool one() : 是否至少有一位是1
// int count() : 返回所有位中1的数量
// string toString() : 返回所有位的状态
// 测试链接 : https://leetcode-cn.com/problems/design-bitset/
#include <string>
#include <vector>
class Bitset {
public:
  Bitset(int size) { bitSet.resize((size + 31) / 32); }

  void fix(int idx) { bitSet[idx / 32] |= 1 << (idx % 32); }

  void unfix(int idx) {
    bitSet[idx / 32] &= ~(1 << (idx % 32));
  }

  void flip() {

  }

  bool all() {
    return true;
  }

  bool one() {
    return true;
  }

  int count() {
    return 1;
  }

  std::string toString() {
    return "";
  }

private:
  std::vector<int> bitSet;
};
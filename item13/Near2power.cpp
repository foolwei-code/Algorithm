// 输出>=n的2的幂
#include <iostream>
int n;
int main() {
  std::cin >> n;
  if (n <= 0) {
    std::cout << 1 << std::endl;
  } else {
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    std::cout << n << std::endl;
  }
}
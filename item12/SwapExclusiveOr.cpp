#include <iostream>
// 使用异或运算来让两个变量交换值(注意，一定是两个空间，一个空间是错误的)
int a, b;
void mySwap(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
int main() {
  std::cin >> a >> b;
  mySwap(a, b);
  std::cout << a << " " << b << std::endl;
}
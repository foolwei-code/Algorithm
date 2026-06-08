//打印一个整数的二进制位(以int32举例)
#include <iostream>
int main() {
  int num;
  std::cin >> num;
  for (int i = 31; i >= 0; i--) {
    if (((num >> i) & 1)) {
      std::cout<<1;
    } else {
      std::cout<<0;
    }
  }
  std::cout<<std::endl;
}
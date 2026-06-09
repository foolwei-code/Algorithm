// 位图的实现
// Bitset(int size)
// void add(int num)
// void remove(int num)
// void reverse(int num)
// bool contains(int num)
#include <array>
const int N = 1e5 + 5;
int n;
std::array<int, N> bitSet;
void add(int num) { bitSet[num / 32] |= 1 << (num % 32); }
void remove(int num) { bitSet[num / 32] &= ~(1 << (num % 32)); }
void reverse(int num) { bitSet[num / 32] ^= (1 << (num % 32)); }
bool contains(int num) { return (bitSet[num / 32] & (1 << (num) % 32)) != 0; }
int main() {
  
}

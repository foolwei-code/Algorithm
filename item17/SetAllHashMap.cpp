// setAll功能的哈希表
// 测试链接 : https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967
#include <ctime>
#include <iostream>
#include <unordered_map>
#include <utility>
int m, operation;
int x, y, timestamp;
int timeKey = -1, timeValue;
std::unordered_map<int, std::pair<int, int>> hashMap;
int main() {
  std::cin >> m;
  while (m--) {
    std::cin >> operation;
    if (operation == 1) {
      std::cin >> x >> y;
      hashMap[x] = {y, timestamp++};
    } else if (operation == 2) {
      std::cin >> x;
      if (!hashMap.count(x))
        std::cout << -1 << std::endl;
      else {
        int value = hashMap[x].first, time = hashMap[x].second;
        if (time > timeKey)
          std::cout << value << std::endl;
        else
          std::cout << timeValue << std::endl;
      }
    } else {
      std::cin >> timeValue;
      timeKey = timestamp++;
    }
  }
}
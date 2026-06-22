// 插入、删除和获取随机元素O(1)时间的结构
// 测试链接 : https://leetcode.cn/problems/insert-delete-getrandom-o1/
#include <ctime>
#include <random>
#include <unordered_map>
#include <vector>
class RandomizedSet {
public:
  RandomizedSet():rng(std::random_device{}()) {}

  bool insert(int val) {
    if (hashMap.count(val))
      return false;
    nums.emplace_back(val);
    hashMap.insert({val, nums.size() - 1});
    return true;
  }

  bool remove(int val) {
    if (!hashMap.count(val))
      return false;
    int index = hashMap[val];
    std::swap(nums[index], nums[nums.size() - 1]);
    hashMap[nums[index]] = index;
    nums.pop_back();
    hashMap.erase(val);
    return true;
  }

  int getRandom() {
    std::uniform_int_distribution<int> dist(0, nums.size() - 1);
    return nums[dist(rng)];
  }

private:
  std::unordered_map<int, int> hashMap;
  std::vector<int> nums;
  std::mt19937 rng;
};

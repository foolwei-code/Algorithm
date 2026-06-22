// 插入、删除和获取随机元素O(1)时间且允许有重复数字的结构
// 测试链接 :
// https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/
#include <ctime>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class RandomizedCollection {
public:
  RandomizedCollection() : rng(std::random_device{}()) {}

  bool insert(int val) {
    nums.emplace_back(val);
    if (!hashMap.count(val)) {
      std::unordered_set<int> hashSet;
      hashSet.insert(nums.size() - 1);
      hashMap.insert({val, hashSet});
      return true;
    }
    hashMap[val].insert(nums.size() - 1);
    return false;
  }

  bool remove(int val) {
    if (!hashMap.count(val))
      return false;
    std::unordered_set<int> &set = hashMap[val];
    auto index = *(set.begin());
    std::swap(nums[index], nums[nums.size() - 1]);
    set.erase(index);
    if (set.empty())
      hashMap.erase(val);
    // 修改nums[index]所在的set中的index
    if (hashMap.count(nums[index])) {
      hashMap[nums[index]].erase(nums.size() - 1);
      hashMap[nums[index]].insert(index);
    }
    nums.pop_back();
    return true;
  }

  int getRandom() {
    std::uniform_int_distribution<int> dist(0, nums.size() - 1);
    return nums[dist(rng)];
  }
  std::vector<int> nums;
  std::unordered_map<int, std::unordered_set<int>> hashMap;
  std::mt19937 rng;
};
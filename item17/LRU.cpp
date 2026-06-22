// 实现LRU结构
// 测试链接 : https://leetcode.cn/problems/lru-cache/
// 使用双向链表+哈希表
#include <unordered_map>
class LRUCache {
public:
  LRUCache(int capacity) {
    this->capacity = capacity;
    size = 0;
    first = last = nullptr;
  }

  int get(int key) {
    // 分两种情况：key存在和key不存在
    if (!hashMap.count(key))
      return -1;
    // 存在分三种情况:对头，队中，队尾
    DoubleListNode *node = hashMap[key];
    if (node == first) {
      if (first != last) {
        node->next->pre = nullptr;
        first = node->next;
        node->next = nullptr;
        node->pre = last;
        last->next = node;
        last = last->next;
      }
    } else if (node == last) {

    } else {
      node->pre->next = node->next;
      node->next->pre = node->pre;
      node->next = nullptr;
      node->pre = last;
      last->next = node;
      last = last->next;
    }
    return node->val;
  }

  void put(int key, int value) {
    // 分两种情况：key存在和key不存在
    // 1.key存在:从hash中找到对应node的地址，对其val进行修改，将其移至队尾
    if (hashMap.count(key)) {
      DoubleListNode *node = hashMap[key];
      node->val = value;
      // 将其移至到队尾：分三种情况:1.对头，队中，队尾
      if (node == first) {
        if (first != last) {
          node->next->pre = nullptr;
          first = node->next;
          node->next = nullptr;
          node->pre = last;
          last->next = node;
          last = last->next;
        }
      } else if (node == last) {

      } else {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->next = nullptr;
        node->pre = last;
        last->next = node;
        last = last->next;
      }
    } else {
      DoubleListNode *node = new DoubleListNode{key, value};
      hashMap.insert({key, node});
      if (first == nullptr) {
        first = last = node;
        size++;
      } else {
        // 接到队尾
        last->next = node;
        node->pre = last;
        last = last->next;
        size++;
        if (size > capacity) {
          // 移除对头
          hashMap.erase(first->key);
          first->next->pre = nullptr;
          DoubleListNode *temp = first->next;
          delete first;
          first = temp;
          size--;
        }
      }
    }
  }

private:
  struct DoubleListNode {
    int key;
    int val;
    DoubleListNode *pre;
    DoubleListNode *next;
    DoubleListNode(int key, int value)
        : key(key), val(value), pre(nullptr), next(nullptr) {}
  };
  int size;
  int capacity;
  std::unordered_map<int, DoubleListNode *> hashMap;
  DoubleListNode *first;
  DoubleListNode *last;
};
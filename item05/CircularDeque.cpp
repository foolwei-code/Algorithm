#include <vector>
class MyCircularDeque {
public:
  MyCircularDeque(int k) {
    deque.resize(k);
    l = r = size = 0;
    capacity = k;
  }

  bool insertFront(int value) {
    if (isFull())
      return false;
    l = l == 0 ? capacity - 1 : l - 1;
    deque[l] = value;
    size++;
    return true;
  }

  bool insertLast(int value) {
    if (isFull())
      return false;
    deque[r] = value;
    r = r == capacity - 1 ? 0 : r + 1;
    size++;
    return true;
  }

  bool deleteFront() {
    if (isEmpty())
      return false;
    l = l == capacity - 1 ? 0 : l + 1;
    size--;
    return true;
  }

  bool deleteLast() {
    if (isEmpty())
      return false;
    r = r == 0 ? capacity - 1 : r - 1;
    size--;
    return true;
  }

  int getFront() {
    if (isEmpty())
      return -1;
    return deque[l];
  }

  int getRear() {
    if (isEmpty())
      return -1;
    return deque[(r == 0 ? capacity - 1 : r - 1)];
  }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == capacity; }

private:
  std::vector<int> deque;
  int l;
  int r;
  int capacity;
  int size;
};
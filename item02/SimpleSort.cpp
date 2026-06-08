#include <array>
#include <ctime>
#include <iostream>
#include <random>
#include<algorithm>
std::array<int, 10> arr1;
void BubbleSort(std::array<int, 10> &arr) {
  int n = arr.size();
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
      }
    }
  }
}
void SelectSort(std::array<int, 10> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (arr[i] > arr[j]) {
        std::swap(arr[i],arr[j]);
      }
    }
  }
}
void InsertSort(std::array<int, 10> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j - 1 >= 0 && arr[j - 1] > arr[j]) {
      std::swap(arr[j - 1], arr[j]);
      j--;
    }
  }
}
void StandardSort(std::array<int, 10> &arr) {
  std::sort(arr.begin(),arr.end());
}
int main() {
  std::mt19937 mt(static_cast<unsigned>(std::time(nullptr)));
  std::uniform_int_distribution<int> dist(0, 99);
  for (int i = 0; i < 10; i++) {
    arr1[i] = dist(mt);
  }
  for (auto &elem : arr1) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
  InsertSort(arr1);
  for (auto &elem : arr1) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}
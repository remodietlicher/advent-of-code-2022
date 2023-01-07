#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iterator>
#include <vector>

#include "../my_util/swap.h"
#include "maxHeap.h"

template <typename T> class MaxHeap {
 private:
  std::vector<T> vec;

 public:
  explicit MaxHeap(std::vector<T> original);

  void maxHeapify(int i);

  int parent(int i);
  int left(int i);
  int right(int i);
  void decreaseKey(int i, int new_val);

  T getMax();
  T popMax();
  void insertKey(int k);

  void printHeap();
};

template <typename T> MaxHeap<T>::MaxHeap(std::vector<T> original) {
  vec = std::vector<T>(original);
}

template <typename T> int MaxHeap<T>::left(int i) { return 2 * i + 1; }
template <typename T> int MaxHeap<T>::right(int i) { return 2 * i + 2; }
template <typename T> int MaxHeap<T>::parent(int i) { return (i - 1) / 2; }

template <typename T> void MaxHeap<T>::maxHeapify(int i) {
  int l = left(i);
  int r = right(i);
  int largest = i;

  if (l < vec.size() && vec[l] > vec[largest]) {
    largest = l;
  }
  if (r < vec.size() && vec[r] > vec[largest]) {
    largest = r;
  }
  if (largest != i) {
    my_util::swap(&vec[i], &vec[largest]);
    maxHeapify(largest);
  }
}

template <typename T> void MaxHeap<T>::printHeap() {
  for (int i = 0; i < vec.size(); i++) {
    std::printf("%d\n", vec[i]);
  }
}

template <typename T> T MaxHeap<T>::getMax() { return vec[0]; }
template <typename T> T MaxHeap<T>::popMax() {
  if (vec.size() <= 0)
    return 999;
  if (vec.size() == 1) {
    T ret = vec.back();
    vec.pop_back();
    return ret;
  }

  int root = vec[0];
  vec[0] = vec.back();
  vec.pop_back();
  maxHeapify(0);
  return root;
}

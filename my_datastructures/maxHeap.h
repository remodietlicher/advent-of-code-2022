#pragma once

#include <cstddef>
class MaxHeap {
 private:
  int *harr;
  int capacity;
  int heap_size;

 public:
  // constructor
  MaxHeap(std::size_t capacity, int *array, std::size_t array_size);

  void maxHeapify(int i);

  int parent(int i);
  int left(int i);
  int right(int i);
  void decreaseKey(int i, int new_val);

  int getMax();
  int popMax();
  int insertKey(int k);

  void printHeap();
};


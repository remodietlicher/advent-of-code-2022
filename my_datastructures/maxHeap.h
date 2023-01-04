#pragma once

class MaxHeap {
 private:
  int *harr;
  int capacity;
  int heap_size;

 public:
  // constructor
  MaxHeap(int capacity, int *array);

  void maxHeapify(int i);

  int parent(int i);
  int left(int i);
  int right(int i);
  int extractMax();
  void decreaseKey(int i, int new_val);

  int getMax();
  int insertKey(int k);
};

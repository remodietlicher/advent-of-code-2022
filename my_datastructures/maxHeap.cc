/**
The GPLv2 License (GPLv2)

Copyright (c) 2023 Remo Dietlicher

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

#include "maxHeap.h"
#include "../my_util/swap.h"
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iterator>

MaxHeap::MaxHeap(std::size_t capacity, int *array, std::size_t array_size) {
  heap_size = array_size;
  capacity = capacity;
  harr = new int[capacity];
  std::copy(&array[0], &array[array_size], harr);
}

int MaxHeap::left(int i) { return 2 * i + 1; }
int MaxHeap::right(int i) { return 2 * i + 2; }
int MaxHeap::parent(int i) { return (i - 1) / 2; }

void MaxHeap::maxHeapify(int i) {
  int l = left(i);
  int r = right(i);
  int largest = i;

  if (l < heap_size && harr[l] > harr[largest]) {
    largest = l;
  }
  if (r < heap_size && harr[r] > harr[largest]) {
    largest = r;
  }
  if (largest != i) {
    my_util::swap(&harr[i], &harr[largest]);
    maxHeapify(largest);
  }
}

void MaxHeap::printHeap() {
  for (int i = 0; i < heap_size; i++) {
    std::printf("%d\n", harr[i]);
  }
}

int MaxHeap::getMax() { return harr[0]; }
int MaxHeap::popMax() {
  if (heap_size <= 0)
    return 999;
  if (heap_size == 1) {
    heap_size--;
    return harr[0];
  }

  int root = harr[0];
  harr[0] = harr[heap_size - 1];
  heap_size--;
  maxHeapify(0);
  return root;
}

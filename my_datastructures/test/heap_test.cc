/**
The GPLv3 License (GPLv3)

Copyright (c) 2023 Remo Dietlicher

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

#include "../maxHeap.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <gtest/gtest.h>
#include <vector>

TEST(TestHeap, TestHeapify) {
  const int kSize = 5;
  std::vector<int> a{0, 1, 2, 3, 4};
  std::vector<int> r{4, 3, 2, 1, 0};

  MaxHeap<int> heap(a);

  for (int i = kSize; i >= 0; i--) {
    heap.maxHeapify(i);
  }

  for (int i = 0; i < kSize; i++) {
    EXPECT_EQ(heap.popMax(), r[i]);
  }
}

TEST(TestHeap, TestHeapLong) {
  const int kSize = 1000;

  srand(65498);
  std::vector<int> a(kSize);

  for (int i = 0; i < kSize; i++) {
    a[i] = rand();
  }

  std::vector<int> r(a);
  std::sort(r.begin(), r.end(), std::greater<int>());

  MaxHeap<int> heap(a);

  for (int i = kSize; i >= 0; i--) {
    heap.maxHeapify(i);
  }

  for (int i = 0; i < kSize; i++) {
    EXPECT_EQ(heap.popMax(), r[i]);
  }
}

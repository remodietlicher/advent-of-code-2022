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
#include <cstdio>
#include <gtest/gtest.h>

TEST(TestHeap, TestHeapify) {
  int a[5] = {0, 1, 2, 3, 4};
  int r[5] = {4, 3, 2, 1, 0};

  MaxHeap *heap = new MaxHeap(5, a, 5);

  for (int i = 5; i >= 0; i--) {
    heap->maxHeapify(i);
  }

  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(heap->popMax(), r[i]);
  }
}

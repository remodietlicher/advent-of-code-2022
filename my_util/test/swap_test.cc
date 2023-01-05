// Copyright [2022] <Remo Dietlicher>
//

#include "../swap.h"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(SwapTest, TestIntegers) {
  int a = 5;
  int b = 8;

  my_util::swap(&a, &b);
  EXPECT_EQ(a, 8);
  EXPECT_EQ(b, 5);
}

TEST(SwapTest, TestArrayElement) {
  int a[2] = {5, 8};


  my_util::swap(&a[0], &a[1]);
  EXPECT_EQ(a[0], 8);
  EXPECT_EQ(a[1], 5);
}
